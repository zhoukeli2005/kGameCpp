#ifndef _kNodeBox_h_
#define _kNodeBox_h_

#include "kNode.h"
#include "math/kVec3.h"
#include "render/kProgram.h"


k_namespace_begin
node_namespace_begin

class kNodeBox : public kNode
{
public:
	kNodeBox(int size);
	
public:
	virtual ~kNodeBox() {}
	
public:
	void resize(int size);
	
public:
	void draw(const math::kMatrix4x4 &);
	
private:
	math::kVec3 points_[8];
	unsigned short int indexes_[36];

	boost::shared_ptr<render::kProgram> program_;
};

node_namespace_end
k_namespace_end

#endif
