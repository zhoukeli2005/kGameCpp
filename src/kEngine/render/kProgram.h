#ifndef _kPrograme_h_
#define _kPrograme_h_

#include "core/kConfig.h"
#include "kVertexShader.h"
#include "kFragmentShader.h"

#include <boost/noncopyable.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

#include <vector>

k_namespace_begin
render_namespace_begin

class kProgram : public boost::noncopyable, public boost::enable_shared_from_this<kProgram>
{
public:
	kProgram();
	
public:
	virtual ~kProgram();
	
public:
	
	// Attach Vertex & Fragment Shader
	void attach(boost::shared_ptr<kVertexShader> vertex, boost::shared_ptr<kFragmentShader> fragment);
	
	void attach(boost::shared_ptr<kVertexShader> vertex);
	
	void attach(boost::shared_ptr<kFragmentShader> fragment);
	
	void attach(const std::string & vsfilename, const std::string & fsfilename);
	
	// Vertex Attribs
	void bind_attrib(GLint index, const std::string & name);
	
	void bind_uniform(GLint index, const std::string & name);
	
	GLint get_uniform_pos(GLint index);
	
	// Link
	bool link();
		
	// Use
	void use();
	
private:
	GLuint program_;
	
	boost::shared_ptr<kVertexShader> vertex_;
	boost::shared_ptr<kFragmentShader> fragment_;
	
	std::vector<GLint> uniform_names_;
};

render_namespace_end
k_namespace_end

#endif
