#include "kRender.h"
#include "math/kSize.h"
#include "kEngine.h"

k_namespace_begin
render_namespace_begin

boost::shared_ptr<kRender> get_render()
{
	return kengine::kEngine::instance().render();
}

void kRender::start()
{
	// Project Matrix
	math::kSize sz = kengine::kEngine::instance().screenSize();
	projectMatrix_ = math::kMatrix4x4::project(45, sz.w / sz.h, 1, 1000);
	
	// Camera Manager
	cameraManager_ = boost::make_shared<kCameraManager>();
}

void kRender::draw()
{
	cameraManager_->draw();
}

render_namespace_end
k_namespace_end