#ifndef _kVertexShader_h_
#define _kVertexShader_h_

#include "kShader.h"

k_namespace_begin
render_namespace_begin

class kVertexShader : public kShader
{
public:
	kVertexShader(const std::string & filename) : kShader(filename, GL_VERTEX_SHADER) {}
};

render_namespace_end
k_namespace_end

#endif
