#include "kNodeBox.h"

#include <boost/make_shared.hpp>

k_namespace_begin
node_namespace_begin

kNodeBox::kNodeBox(int size)
: kNode{}
{
	resize(size);
}

void kNodeBox::resize(int size)
{
	float half_size = size / 2;
	points_[0] = { -half_size, -half_size, half_size };
	points_[1] = { half_size, -half_size, half_size };
	points_[2] = { half_size, half_size, half_size };
	points_[3] = { -half_size, half_size, half_size };
	points_[4] = { -half_size, -half_size, -half_size };
	points_[5] = { half_size, -half_size, -half_size };
	points_[6] = { half_size, half_size, -half_size };
	points_[7] = { -half_size, half_size, -half_size };
	
	// front
	int idx = 0;
	indexes_[idx++] = 0;
	indexes_[idx++] = 1;
	indexes_[idx++] = 3;
	
	indexes_[idx++] = 1;
	indexes_[idx++] = 2;
	indexes_[idx++] = 3;
	
	// back
	indexes_[idx++] = 5;
	indexes_[idx++] = 4;
	indexes_[idx++] = 6;
	
	indexes_[idx++] = 4;
	indexes_[idx++] = 7;
	indexes_[idx++] = 6;
	
	// top
	indexes_[idx++] = 3;
	indexes_[idx++] = 2;
	indexes_[idx++] = 7;
	
	indexes_[idx++] = 2;
	indexes_[idx++] = 6;
	indexes_[idx++] = 7;
	
	// bottom
	indexes_[idx++] = 0;
	indexes_[idx++] = 4;
	indexes_[idx++] = 1;
	
	indexes_[idx++] = 1;
	indexes_[idx++] = 4;
	indexes_[idx++] = 5;
	
	// left
	indexes_[idx++] = 0;
	indexes_[idx++] = 3;
	indexes_[idx++] = 4;
	
	indexes_[idx++] = 3;
	indexes_[idx++] = 7;
	indexes_[idx++] = 4;
	
	// right
	indexes_[idx++] = 1;
	indexes_[idx++] = 5;
	indexes_[idx++] = 2;
	
	indexes_[idx++] = 5;
	indexes_[idx++] = 6;
	indexes_[idx++] = 2;
}

void kNodeBox::draw()
{
	if(!program_) {
		program_ = boost::make_shared<render::kProgram>();
		program_->attach("shader/simple.vs", "shader/simple.fs");
		program_->bind_attrib(0, "a_position");
		program_->link();
	}
	{
		points_[0] = { -1, -0.5, 0 };
		points_[1] = { 0.5, -0.5, 0 };
		points_[2] = { 0.5, 0.5, 0 };
	}
	program_->use();
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, points_);
	
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

node_namespace_end
k_namespace_end