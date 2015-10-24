#include "kOpenGLCapability.h"

#include "log/kLog.h"

k_namespace_begin
render_namespace_begin

kOpenGLCapability::kOpenGLCapability()
{	
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxVertexAttribs);
	
	log::info("OpenGL Capacity :\n"
			  "maxVertexAttribs:%d\n"
			  , maxVertexAttribs);
	
	// enable
	glEnable(GL_DEPTH_TEST);
}

render_namespace_end
k_namespace_end
