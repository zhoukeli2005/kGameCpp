#ifndef _kFragmentShader_h_
#define _kFragmentShader_h_

#include "kShader.h"

k_namespace_begin
render_namespace_begin

class kFragmentShader : public kShader
{
public:
	kFragmentShader(const std::string & filename) : kShader(filename, GL_FRAGMENT_SHADER) {}
};

render_namespace_end
k_namespace_end

#endif
