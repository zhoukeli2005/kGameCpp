#ifndef _kOpenGLCapability_h_
#define _kOpenGLCapability_h_

#include "core/kConfig.h"

k_namespace_begin
render_namespace_begin

struct kOpenGLCapability
{
	GLint maxVertexAttribs;
	
	// constructor
	kOpenGLCapability();
};

render_namespace_end
k_namespace_end

#endif

