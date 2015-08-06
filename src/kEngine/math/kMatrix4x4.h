#ifndef _kMatrix_h_
#define _kMatrix_h_

#include "core/kConfig.h"
#include "debug/kStat.h"

#include "math/kVec3.h"
#include "kMathUtil.h"

#include <string.h>

k_namespace_begin
math_namespace_begin

struct kMatrix4x4
{
	float m[16];
	
	// constructor
	kMatrix4x4()
	{
		memset(m, 0, sizeof(m));
		m[0] = m[5] = m[10] = m[15] = 1;
		
		debug::kStat::instance().kMatrix4x4_count++;
	}
	
	kMatrix4x4(const kMatrix4x4 & o)
	{
		if(&o == this) {
			return;
		}
		memcpy(m, o.m, sizeof(m));
	}
	
	kMatrix4x4(kMatrix4x4 && o)
	{
		memcpy(m, o.m, sizeof(m));
	}
	
	// destructor
	~kMatrix4x4()
	{
		debug::kStat::instance().kMatrix4x4_count--;
	}
	
	// operator
	kMatrix4x4 & operator *= (const kMatrix4x4 & o)
	{
		float tmp_m[16];
		memcpy(tmp_m, m, sizeof(m));
		for(int row = 0; row < 4; ++row) {
			for(int line = 0; line < 4; ++line) {
				m[row * 4 + line] = 0;
				for(int i = 0; i < 4; ++i) {
					m[row * 4 + line] += tmp_m[row * 4 + i] * o.m[line + i * 4];
				}
			}
		}
		return *this;
	}
	
	float & operator [] (int idx)
	{
		return m[idx];
	}
	
	// aip
	float & get(int row, int line)
	{
		return m[row * 4 + line];
	}
	
	// factory api
	static kMatrix4x4 identity()
	{
		kMatrix4x4 tmp;
		return tmp;
	}
	
	static kMatrix4x4 transform(float x, float y, float z)
	{
		kMatrix4x4 tmp;
		tmp.m[3] = x;
		tmp.m[7] = y;
		tmp.m[11] = z;
		return tmp;
	}
	
	static kMatrix4x4 rotateX(float radian)
	{
		kMatrix4x4 tmp;
		
		float sinX = math::sin(radian);
		float cosX = math::cos(radian);
		
		tmp.get(1, 1) = cosX;
		tmp.get(1, 2) = -sinX;
		tmp.get(2, 1) = sinX;
		tmp.get(2, 2) = cosX;
		
		return tmp;
	}
	
	static kMatrix4x4 rotateY(float radian)
	{
		kMatrix4x4 tmp;
		
		float sinX = math::sin(radian);
		float cosX = math::cos(radian);
		
		tmp.get(0, 0) = sinX;
		tmp.get(0, 2) = cosX;
		tmp.get(2, 0) = cosX;
		tmp.get(2, 2) = -sinX;
		
		return tmp;
	}
	
	static kMatrix4x4 rotateZ(float radian)
	{
		kMatrix4x4 tmp;
		
		float sinX = math::sin(radian);
		float cosX = math::cos(radian);
		
		tmp.get(0, 0) = cosX;
		tmp.get(0, 1) = -sinX;
		tmp.get(1, 0) = sinX;
		tmp.get(1, 1) = cosX;
		
		return tmp;
	}
	
	static kMatrix4x4 scale(float x, float y, float z)
	{
		kMatrix4x4 tmp;
		tmp.m[0] = x;
		tmp.m[5] = y;
		tmp.m[10] = z;
		return tmp;
	}
	
	static kMatrix4x4 lookAt(kVec3 eye, kVec3 direct, kVec3 up)
	{
		kMatrix4x4 tmp;
		
		return  tmp;
	}
	
	static kMatrix4x4 project()
	{
		kMatrix4x4 tmp;
		
		return tmp;
	}
};

inline kVec3 operator * (const kMatrix4x4 & m, const kVec3 & v)
{
	kVec3 tmp;
	tmp.x = m.m[0] * v.x + m.m[1] * v.y + m.m[2] * v.z + m.m[3];
	tmp.y = m.m[4] * v.x + m.m[5] * v.y + m.m[6] * v.z + m.m[7];
	tmp.z = m.m[8] * v.x + m.m[9] * v.y + m.m[10] * v.z + m.m[11];
	return tmp;
}

inline kMatrix4x4 operator * (const kMatrix4x4 & a, const kMatrix4x4 & b)
{
	kMatrix4x4 tmp = a;
	tmp *= b;
	return tmp;
}

math_namespace_end
k_namespace_end

#endif
