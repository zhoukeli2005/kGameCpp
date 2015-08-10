#ifndef _kMatrixStack_h_
#define _kMatrixStack_h_

#include "core/kConfig.h"
#include "kMatrix4x4.h"

#include <vector>

k_namespace_begin
math_namespace_begin

class kMatrixStack : public boost::noncopyable, public boost::enable_shared_from_this<kMatrixStack>
{
public:
	kMatrixStack() { clear(); }
	
public:
	~kMatrixStack() {}
	
public:
	void clear()
	{
		stack_.clear();
		stack_.push_back(kMatrix4x4::identity());
	}
	void clear(const kMatrix4x4 & m)
	{
		stack_.clear();
		stack_.push_back(m);
	}
	
	void push()
	{
		stack_.push_back(stack_.back());
	}
	
	void multiply(const kMatrix4x4 & m)
	{
		stack_.back() = stack_.back() * m;
	}

	void pop()
	{
		stack_.pop_back();
		if(stack_.size() <= 0) {
			clear();
		}
	}
	
	const kMatrix4x4 & peek()
	{
		return stack_.back();
	}
	
private:
	std::vector<math::kMatrix4x4> stack_;
};

math_namespace_end
k_namespace_end

#endif
