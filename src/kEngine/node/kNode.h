#ifndef _kNode_h_
#define _kNode_h_

#include "core/kConfig.h"
#include "math/kVec3.h"

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
	void scale(float x, float y, float z);
	void scaleX(float x);
	void scaleY(float y);
	void scaleZ(float z);
	
	void scaleBy(float x, float y, float z);
	void scaleXBy(float x);
	void scaleYBy(float y);
	void scaleZBy(float z);
	
	math::kVec3 scale();
	float scaleX();
	float scaleY();
	float scaleZ();
	
public:
	void rotate(float x, float y, float z);
	void rotateX(float x);
	void rotateY(float y);
	void rotateZ(float z);
	
	void rotateBy(float x, float y, float z);
	void rotateXBy(float x);
	void rotateYBy(float y);
	void rotateZBy(float z);
	
	math::kVec3 rotate();
	float rotateX();
	float rotateY();
	float rotateZ();
	
public:
	void move(float x, float y, float z);
	void moveX(float x);
	void moveY(float y);
	void moveZ(float z);
	
	void moveBy(float x, float y, float z);
	void moveXBy(float x);
	void moveYBy(float y);
	void moveZBy(float z);
	
	math::kVec3 position();
	float positionX();
	float positionY();
	float positionZ();
	
public:
	virtual void visit();
	
	virtual void draw() {}
	
// members
private:
	// tranformation
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
