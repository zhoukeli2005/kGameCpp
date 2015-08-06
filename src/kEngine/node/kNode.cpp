#include "kNode.h"

#include "debug/kStat.h"

k_namespace_begin
node_namespace_begin

kNode::kNode()
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

void kNode::visit()
{
	draw();
	
	for(auto it = children_.begin(); it != children_.end(); ++it) {
		it->get()->visit();
	}
}


node_namespace_end
k_namespace_end