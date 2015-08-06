#ifndef _kShader_h_
#define _kShader_h_

#include "core/kConfig.h"
#include <boost/noncopyable.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <string>

k_namespace_begin
render_namespace_begin

class kShader : public boost::noncopyable, public boost::enable_shared_from_this<kShader>
{
public:
	kShader(const std::string & filename, GLuint type);
	
public:
	virtual ~kShader();
	
public:
	bool compile();
	
	GLuint get_GL_name() { return shader_; }
	
private:
	GLuint type_;
	GLuint shader_;
	std::string filename_;
};

render_namespace_end
k_namespace_end

#endif
