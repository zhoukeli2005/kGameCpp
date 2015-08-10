#include "kNode.h"

#include "debug/kStat.h"

#include "kEngine.h"

k_namespace_begin
node_namespace_begin

kNode::kNode()
: transformDirty_(false)
, position_(0, 0, 0)
, scale_(1, 1, 1)
, rotation_(0, 0, 0)
{
	debug::kStat::instance().kNode_count++;
}

kNode::~kNode()
{
	debug::kStat::instance().kNode_count--;
}

void kNode::addChild(boost::shared_ptr<kNode> child)
{
	kNode * p = child.get();
	p->removeFromParent();
	p->parent_ = shared_from_this();
	children_.push_back(child);
}

void kNode::removeFromParent()
{
	if(!this->parent_.expired()) {
		this->parent_.lock()->removeChild(shared_from_this());
	}
}

void kNode::removeChild(boost::shared_ptr<kNode> child)
{
	kNode * p = child.get();
	if(p->parent_.lock().get() != this) {
		return;
	}
	for(auto it = children_.begin(); it != children_.end(); ++it) {
		if(it->get() == p) {
			children_.erase(it);
			break;
		}
	}
	p->parent_.reset();
}

void kNode::removeAllChildren()
{
	for(auto it = children_.begin(); it != children_.end(); ++it) {
		it->get()->parent_.reset();
	}
	
	std::vector<boost::shared_ptr<kNode> >().swap(children_);
}

void kNode::_transform()
{
	if(transformDirty_) {
		transformDirty_ = false;
		math::kMatrix4x4 scale = math::kMatrix4x4::scale(scale_.x, scale_.y, scale_.z);
		math::kMatrix4x4 rotate = math::kMatrix4x4::rotate(rotation_.x, rotation_.y, rotation_.z);
		math::kMatrix4x4 translate = math::kMatrix4x4::translate(position_.x, position_.y, position_.z);
		localTransform_ = translate * rotate * scale;
	}
}

void kNode::transform_and_draw(math::kMatrixStack & matrixStack)
{
	_transform();
	
	matrixStack.push();
	matrixStack.multiply(localTransform_);
	
	draw(matrixStack.peek());
	
	for(auto it = children_.begin(); it != children_.end(); ++it) {
		it->get()->transform_and_draw(matrixStack);
	}
	
	matrixStack.pop();
}


node_namespace_end
k_namespace_end