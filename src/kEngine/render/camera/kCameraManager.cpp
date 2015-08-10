#include "kCameraManager.h"
#include "log/kLog.h"

k_namespace_begin
render_namespace_begin

kCameraManager::kCameraManager()
{
	
}

kCameraManager::~kCameraManager()
{
	
}

void kCameraManager::register_camera(boost::shared_ptr<kCamera> camera)
{
#ifdef kDEBUG
	for(auto it : cameras_) {
		if(it->get_name() == camera->get_name()) {
			log::error("Cannot register a camera(%d) twice!", camera->get_name());
			return;
		}
	}
#endif
	cameras_.push_back(camera);
}

void kCameraManager::unreg_camera(boost::shared_ptr<kCamera> camera)
{
	for(auto it = cameras_.begin(); it != cameras_.end(); ++it) {
		if((*it)->get_name() == camera->get_name()) {
			cameras_.erase(it);
			return;
		}
	}
}

void kCameraManager::draw()
{
	for(auto camera : cameras_) {
		camera->draw();
	}
}

render_namespace_end
k_namespace_end