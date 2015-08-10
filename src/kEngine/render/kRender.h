#ifndef _kRender_h_
#define _kRender_h_

#include "core/kConfig.h"
#include "math/kMatrix4x4.h"
#include "camera/kCameraManager.h"

k_namespace_begin
render_namespace_begin

class kRender : public boost::noncopyable, public boost::enable_shared_from_this<kRender>
{
public:
	kRender() {}
	
public:
	virtual ~kRender() {}
	
public:
	void start();
	
public:
	void draw();
	
public:
	boost::shared_ptr<kCameraManager> cameraManager() { return cameraManager_; }
	
private:
	math::kMatrix4x4 projectMatrix_;
	boost::shared_ptr<kCameraManager> cameraManager_;
};

boost::shared_ptr<kRender> get_render();

render_namespace_end
k_namespace_end

#endif

