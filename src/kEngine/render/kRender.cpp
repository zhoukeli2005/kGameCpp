#include "kRender.h"
#include "math/kSize.h"
#include "kEngine.h"

k_namespace_begin
render_namespace_begin

void kRender::start()
{
	// 1. ViewPort
	math::kSize sz = kengine::kEngine::instance().screenSize();
	glViewport(100, 50, sz.w, sz.h);
	GLenum err = glGetError();
	log::info("glViewPort err:%d", err);
	
	float v[4];
	glGetFloatv(GL_VIEWPORT, v);
	log::info("glViewPort x:%f, y:%f, w:%f, h:%f", v[0], v[1], v[2], v[3]);
	
	// 2. Project Matrix
}

render_namespace_end
k_namespace_end