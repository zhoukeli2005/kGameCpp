#include "kShader.h"
#include "io/kFile.h"
#include "log/kLog.h"

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

k_namespace_begin
render_namespace_begin

kShader::kShader(const std::string & filename, GLuint type)
: shader_(0)
{
	filename_ = filename;
	type_ = type;
}

kShader::~kShader()
{
	if(shader_ > 0) {
		glDeleteShader(shader_);
		shader_ = 0;
	}
}

bool kShader::compile()
{
	if(shader_ > 0) {
		return false;
	}
	
	boost::shared_ptr<io::kFile> file = boost::make_shared<io::kFile>(filename_);
	
	if(!file->exist()) {
		return false;
	}
	std::string content = file->read();
	
	const char * pstr = content.c_str();
	
	shader_ = glCreateShader(type_);
	glShaderSource(shader_, 1, &pstr, NULL);
	glCompileShader(shader_);
	
	GLint params;
	
	glGetShaderiv(shader_, GL_COMPILE_STATUS, &params);
	
	if(params == GL_TRUE) {
		return true;
	}
	
	glGetShaderiv(shader_, GL_INFO_LOG_LENGTH, &params);
	std::string info;
	info.resize(params);
	
	glGetShaderInfoLog(shader_, params, NULL, const_cast<char *>(info.data()));
	
	log::info("Shader Compiler Info(%s):%s", filename_.c_str(), info.c_str());
	
	return false;
}

render_namespace_end
k_namespace_end
