#include "kCamera.h"
#include "render/kRender.h"
#include "kEngine.h"

#include "math/kSize.h"

k_namespace_begin
render_namespace_begin

kCamera::kCamera()
{
	setCamera(math::kVec3(0, 0, 0), math::kVec3(0, 0, -1), math::kVec3(0, 1, 0), 45);
	
	math::kSize sz = kEngine::instance().screenSize();
	setViewPort(0, 0, sz.w, sz.h);
}

kCamera::~kCamera()
{
	
}

void kCamera::enable()
{
	render::get_render()->cameraManager()->register_camera(shared_from_this());
}

void kCamera::discard()
{
	render::get_render()->cameraManager()->unreg_camera(shared_from_this());
}

void kCamera::moveTo(const math::kVec3 &pos)
{
	position_ = pos;
	dirty_ = true;
}

void kCamera::lookAt(const math::kVec3 &center)
{
	center_ = center;
	dirty_ = true;
}

void kCamera::up(const math::kVec3 &up)
{
	up_ = up;
	dirty_ = true;
}

void kCamera::fov(float fovDegree)
{
	fov_ = fovDegree;
	dirty_ = true;
}

void kCamera::setCamera(const math::kVec3 &pos, const math::kVec3 &center, const math::kVec3 &up, float fovDegree)
{
	position_ = pos;
	center_ = center;
	up_ = up;
	fov_ = fovDegree;
	dirty_ = true;
}

void kCamera::setViewPort(int x, int y, int w, int h)
{
	viewPort_ = math::kRect(x, y, w, h);
}

void kCamera::draw()
{
	if(dirty_) {
		math::kSize screenSize = kengine::kEngine::instance().screenSize();
		projectMatrix_ = math::kMatrix4x4::project(fov_, screenSize.w / screenSize.h, 1, 1000);
		viewMatrix_ = math::kMatrix4x4::lookAt(position_, center_, up_);
		dirty_ = false;
		matrixStack_.clear(projectMatrix_ * viewMatrix_);
	}
	
	glViewport(viewPort_.x, viewPort_.y, viewPort_.w, viewPort_.h);
	glClear(GL_COLOR | GL_DEPTH);
	
	kEngine::instance().rootNode()->transform_and_draw(matrixStack_);
}

render_namespace_end
k_namespace_end