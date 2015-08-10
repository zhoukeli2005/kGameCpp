#ifndef _kCameraManager_h_
#define _kCameraManager_h_

#include "kCamera.h"

#include <vector>

k_namespace_begin
render_namespace_begin

class kCameraManager : public boost::noncopyable, public boost::enable_shared_from_this<kCameraManager>
{
public:
	kCameraManager();
	
public:
	virtual ~kCameraManager();
	
public:
	void register_camera(boost::shared_ptr<kCamera> camera);
	
	void unreg_camera(boost::shared_ptr<kCamera> camera);
	
public:
	void draw();
	
private:
	std::vector<boost::shared_ptr<kCamera>> cameras_;
};

render_namespace_end
k_namespace_end

#endif

