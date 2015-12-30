#include "kNodeBox.h"
#include "util/kUtil.h"

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
	
	uv_[0] = {0, 1};
	uv_[1] = {1, 1};
	uv_[2] = {1, 0};
	uv_[3] = {0, 0};
	uv_[4] = {0, 0};
	uv_[5] = {1, 0};
	uv_[6] = {1, 1};
	uv_[7] = {0, 1};
	
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

void kNodeBox::draw(const math::kMatrix4x4 & mvpMatrix)
{
	if(!texture_) {
		texture_ = boost::make_shared<render::kTexture>("res/test.jpg");
	}
	
	if(!program_) {
		program_ = boost::make_shared<render::kProgram>();
		program_->attach("shader/simple.vs", "shader/simple.fs");

		program_->bind_attrib(0, "a_position");
		program_->bind_attrib(1, "a_uv0");
		
		program_->link();
		program_->bind_uniform(0, "u_mvp");
		program_->bind_uniform(1, "u_texture0");
	}
	program_->use();

	if(1)
	{
		points_[0] = {-1, -1, -1};
		points_[1] = {1, -1, 1};
		points_[2] = {1, 1, 1};
		points_[3] = {-1, -1, -1};
		points_[4] = {1, 1, 1};
		points_[5] = {-1, 1, -1};
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, points_);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		return;
	}
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture_->glName());
	
	glUniformMatrix4fv(program_->get_uniform_pos(0), 1, 0, mvpMatrix.m);
	glUniform1i(program_->get_uniform_pos(1), 0);
		
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, points_);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, uv_);
	
	glDrawElements(GL_TRIANGLES, sizeof(indexes_) / sizeof(indexes_[0]), GL_UNSIGNED_SHORT, indexes_);
}

node_namespace_end
k_namespace_end