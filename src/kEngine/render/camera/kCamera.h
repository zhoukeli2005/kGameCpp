#ifndef _kCamera_h_
#define _kCamera_h_

#include "core/kConfig.h"
#include "math/kVec3.h"
#include "math/kMatrixStack.h"
#include "math/kRect.h"

k_namespace_begin
render_namespace_begin

class kCamera : public boost::noncopyable, public boost::enable_shared_from_this<kCamera>
{
public:
	kCamera();
	
public:
	~kCamera();
	
public:
	void enable();
	void discard();
	
public:
	void set_name(int name) { name_ = name; }
	int get_name() { return name_; }
	
public:
	void moveTo(const math::kVec3 & pos);
	void lookAt(const math::kVec3 & center);
	void up(const math::kVec3 & up);
	void fov(float fovDegree);
	void setViewPort(int x, int y, int w, int h);
	
public:
	void setCamera(const math::kVec3 & pos, const math::kVec3 & center, const math::kVec3 & up, float fovDegree);
	
public:
	void draw();
	
private:
	bool dirty_;
	math::kVec3 position_;
	math::kVec3 center_;
	math::kVec3 up_;
	float fov_;
	
	math::kMatrix4x4 projectMatrix_;
	math::kMatrix4x4 viewMatrix_;
	math::kRect viewPort_;
	
	int name_;
	
	math::kMatrixStack matrixStack_;
};

render_namespace_end
k_namespace_end

#endif

