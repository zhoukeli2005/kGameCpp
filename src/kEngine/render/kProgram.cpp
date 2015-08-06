#include "kProgram.h"
#include "log/kLog.h"

k_namespace_begin
render_namespace_begin

kProgram::kProgram()
: program_{0}
{
	program_ = glCreateProgram();
}

kProgram::~kProgram()
{
	if(program_ > 0) {
		glDeleteProgram(program_);
	}
}

void kProgram::attach(boost::shared_ptr<kVertexShader> vertex, boost::shared_ptr<kFragmentShader> fragment)
{
	this->attach(vertex);
	this->attach(fragment);
}

void kProgram::attach(boost::shared_ptr<kVertexShader> vertex)
{
	if(vertex_) {
		glDetachShader(program_, vertex_->get_GL_name());
	}
	vertex_ = vertex;
	glAttachShader(program_, vertex_->get_GL_name());
}

void kProgram::attach(boost::shared_ptr<kFragmentShader> fragment)
{
	if(fragment_) {
		glDetachShader(program_, fragment_->get_GL_name());
	}
	fragment_ = fragment;
	glAttachShader(program_, fragment_->get_GL_name());
}


void kProgram::attach(const std::string &vsfilename, const std::string &fsfilename)
{
	boost::shared_ptr<kVertexShader> vertex = boost::make_shared<kVertexShader>(vsfilename);
	if(!vertex->compile()) {
		return;
	}
	
	boost::shared_ptr<kFragmentShader> fragment = boost::make_shared<kFragmentShader>(fsfilename);
	if(!fragment->compile()) {
		return;
	}
	
	this->attach(vertex, fragment);
}

void kProgram::bind_attrib(GLint index, const std::string &name)
{
	glBindAttribLocation(program_, index, name.data());
}

bool kProgram::link()
{
	if(!vertex_ || !fragment_) {
		log::warn("miss vertex shader or fragment shader");
		return false;
	}
	
	glLinkProgram(program_);
	
	GLint params;
	
	glGetProgramiv(program_, GL_LINK_STATUS, &params);
	if(params == GL_TRUE) {
		return true;
	}
	
	glGetProgramiv(program_, GL_INFO_LOG_LENGTH, &params);
	
	std::string info;
	info.resize(params);
	
	glGetProgramInfoLog(program_, params, NULL, const_cast<char *>(info.data()));
	
	log::error("%s", info.c_str());
	
	return false;
}

void kProgram::use()
{
	glUseProgram(program_);
}

render_namespace_end
k_namespace_end
