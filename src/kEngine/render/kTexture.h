#ifndef _kTexture_h_
#define _kTexture_h_

#include "core/kConfig.h"

k_namespace_begin
render_namespace_begin

class kTexture : public boost::noncopyable, public boost::enable_shared_from_this<kTexture>
{
public:
	// constructor : must create with filename or otherwise create an empty texture
	// when kTexture has been created, its content cannot be changed
	kTexture(const std::string & filename = "");
	
public:
	~kTexture();
	
public:
	GLuint glName() { return texture_; }
	
private:
	void _load_empty();
	void _load_file();
	
private:
	GLuint texture_;
	std::string filename_;
};

render_namespace_end
k_namespace_end

#endif
