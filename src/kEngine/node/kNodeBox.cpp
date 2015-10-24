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
	
	// front
	int idx = 0, uv_idx = 0;
	indexes_[idx++] = 0;
	indexes_[idx++] = 1;
	indexes_[idx++] = 3;
	uv_[uv_idx++] = {0, 0};
	uv_[uv_idx++] = {1, 0};
	uv_[uv_idx++] = {0, 1};
	
	indexes_[idx++] = 1;
	indexes_[idx++] = 2;
	indexes_[idx++] = 3;
	uv_[uv_idx++] = {0, 0};
	uv_[uv_idx++] = {1, 0};
	uv_[uv_idx++] = {0, 1};
	
	// back
	indexes_[idx++] = 5;
	indexes_[idx++] = 4;
	indexes_[idx++] = 6;
	uv_[uv_idx++] = {0, 0};
	uv_[uv_idx++] = {1, 0};
	uv_[uv_idx++] = {0, 1};
	
	indexes_[idx++] = 4;
	indexes_[idx++] = 7;
	indexes_[idx++] = 6;
	uv_[uv_idx++] = {0, 0};
	uv_[uv_idx++] = {1, 0};
	uv_[uv_idx++] = {0, 1};
	
	// top
	indexes_[idx++] = 3;
	indexes_[idx++] = 2;
	indexes_[idx++] = 7;
	uv_[uv_idx++] = {0, 0};
	uv_[uv_idx++] = {1, 0};
	uv_[uv_idx++] = {0, 1};
	
	indexes_[idx++] = 2;
	indexes_[idx++] = 6;
	indexes_[idx++] = 7;
	uv_[uv_idx++] = {0, 0};
	uv_[uv_idx++] = {1, 0};
	uv_[uv_idx++] = {0, 1};
	
	// bottom
	indexes_[idx++] = 0;
	indexes_[idx++] = 4;
	indexes_[idx++] = 1;
	uv_[uv_idx++] = {0, 0};
	uv_[uv_idx++] = {1, 0};
	uv_[uv_idx++] = {0, 1};
	
	indexes_[idx++] = 1;
	indexes_[idx++] = 4;
	indexes_[idx++] = 5;
	uv_[uv_idx++] = {0, 0};
	uv_[uv_idx++] = {1, 0};
	uv_[uv_idx++] = {0, 1};
	
	// left
	indexes_[idx++] = 0;
	indexes_[idx++] = 3;
	indexes_[idx++] = 4;
	uv_[uv_idx++] = {0, 0};
	uv_[uv_idx++] = {1, 0};
	uv_[uv_idx++] = {0, 1};
	
	indexes_[idx++] = 3;
	indexes_[idx++] = 7;
	indexes_[idx++] = 4;
	uv_[uv_idx++] = {0, 0};
	uv_[uv_idx++] = {1, 0};
	uv_[uv_idx++] = {0, 1};
	
	// right
	indexes_[idx++] = 1;
	indexes_[idx++] = 5;
	indexes_[idx++] = 2;
	uv_[uv_idx++] = {0, 0};
	uv_[uv_idx++] = {1, 0};
	uv_[uv_idx++] = {0, 1};
	
	indexes_[idx++] = 5;
	indexes_[idx++] = 6;
	indexes_[idx++] = 2;
	uv_[uv_idx++] = {0, 0};
	uv_[uv_idx++] = {1, 0};
	uv_[uv_idx++] = {0, 1};
}

void kNodeBox::draw(const math::kMatrix4x4 & mvpMatrix)
{
	if(!texture_) {
		texture_ = boost::make_shared<render::kTexture>();
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