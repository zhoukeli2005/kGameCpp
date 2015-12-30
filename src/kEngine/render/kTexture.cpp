#include "kTexture.h"

#include "log/kLog.h"

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
	
	// init TextureInfo
	info_.width = 2;
	info_.height = 2;
	info_.format = E_TEXTURE_FORMAT::E_MEM;
	
	_init_with_data(pixels);
}

void kTexture::_init_with_data(const unsigned char *pixels)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture_);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	
	GLsizei width = (GLsizei)info_.width;
	GLsizei height = (GLsizei)info_.height;
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	
	glBindTexture(GL_TEXTURE_2D, 0);
}

render_namespace_end
k_namespace_end