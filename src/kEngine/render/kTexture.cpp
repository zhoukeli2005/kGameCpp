#include "kTexture.h"

k_namespace_begin
render_namespace_begin

kTexture::kTexture(const std::string & filename)
{
	glGenTextures(1, &texture_);
	
	filename_ = filename;
	if(filename_.size() == 0) {
		_load_empty();
	} else {
		_load_file();
	}
}

kTexture::~kTexture()
{
	glDeleteTextures(1, &texture_);
}

void kTexture::_load_empty()
{
	static GLubyte pixels[4 * 4] = {
		255, 0, 0, 255,	// red
		0, 255, 0, 255,	// green
		0, 0, 255, 255,	// blue
		255, 255, 0, 255	// yellow
	};
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texture_);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	
	glBindTexture(GL_TEXTURE_2D, 0);
}

void kTexture::_load_file()
{
	
	
}

render_namespace_end
k_namespace_end