#ifndef _kNode_h_
#define _kNode_h_

#include "core/kConfig.h"
#include "math/kVec3.h"
#include "math/kMatrix4x4.h"
#include "math/kMatrixStack.h"

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <vector>

k_namespace_begin
node_namespace_begin

class kNode : public boost::noncopyable, public boost::enable_shared_from_this<kNode>
{
public:
	kNode();
	
public:
	virtual ~kNode();
	
public:
	void addChild(boost::shared_ptr<kNode> child);
	
	void removeChild(boost::shared_ptr<kNode> child);
	
	void removeFromParent();
	
	void removeAllChildren();
	
	boost::shared_ptr<kNode> parent() { return parent_.lock(); }
	
public:
	void scale(float x, float y, float z) { scale_.x = x; scale_.y = y; scale_.z = z; transformDirty_ = true; }
	void scaleX(float x) { scale_.x = x; transformDirty_ = true; }
	void scaleY(float y) { scale_.y = y; transformDirty_ = true; }
	void scaleZ(float z) { scale_.z = z; transformDirty_ = true; }
	
	void scaleBy(float x, float y, float z) { scale_.x += x; scale_.y += y; scale_.z += z; transformDirty_ = true; }
	void scaleXBy(float x) { scale_.x += x; transformDirty_ = true; }
	void scaleYBy(float y) { scale_.y += y; transformDirty_ = true; }
	void scaleZBy(float z) { scale_.z += z; transformDirty_ = true; }
	
	const math::kVec3 & scale() { return scale_; }
	float scaleX() { return scale_.x; }
	float scaleY() { return scale_.y; }
	float scaleZ() { return scale_.z; }
	
public:
	void rotate(float x, float y, float z) { rotation_.x = x; rotation_.y = y; rotation_.z = z; transformDirty_ = true; }
	void rotateX(float x) { rotation_.x = x; transformDirty_ = true; }
	void rotateY(float y) { rotation_.y = y; transformDirty_ = true; }
	void rotateZ(float z) { rotation_.z = z; transformDirty_ = true; }
	
	void rotateBy(float x, float y, float z) { rotation_.x += x; rotation_.y += y; rotation_.z += z; transformDirty_ = true; }
	void rotateXBy(float x) { rotation_.x += x; transformDirty_ = true; }
	void rotateYBy(float y) { rotation_.y += y; transformDirty_ = true; }
	void rotateZBy(float z) { rotation_.z += z; transformDirty_ = true; }
	
	const math::kVec3 & rotate() { return rotation_; }
	float rotateX() { return rotation_.x; }
	float rotateY() { return rotation_.y; }
	float rotateZ() { return rotation_.z; }
	
public:
	void move(float x, float y, float z) { position_.x = x; position_.y = y; position_.z = z; transformDirty_ = true; }
	void moveX(float x) { position_.x = x; transformDirty_ = true; }
	void moveY(float y) { position_.y = y; transformDirty_ = true; }
	void moveZ(float z) { position_.z = z; transformDirty_ = true; }
	
	void moveBy(float x, float y, float z) { position_.x += x; position_.y += y; position_.z += z; transformDirty_ = true; }
	void moveXBy(float x) { position_.x += x; transformDirty_ = true; }
	void moveYBy(float y) { position_.y += y; transformDirty_ = true; }
	void moveZBy(float z) { position_.z += z; transformDirty_ = true; }
	
	const math::kVec3 & position() { return position_; }
	float positionX() { return position_.x; }
	float positionY() { return position_.y; }
	float positionZ() { return position_.z; }
	
public:
	virtual void transform_and_draw(math::kMatrixStack & matrixStack);
	
public:
	virtual void draw(const math::kMatrix4x4 & mvpMatrix) {}
	
protected:
	void _transform();
	
	math::kMatrix4x4 localTransform_;

// members
private:
	// tranformation
	bool transformDirty_;
	
	math::kVec3 position_;
	math::kVec3 scale_;
	math::kVec3 rotation_;
	
	// parent & children
	std::vector<boost::shared_ptr<kNode> > children_;
	boost::weak_ptr<kNode> parent_;
};

node_namespace_end
k_namespace_end

#endif
