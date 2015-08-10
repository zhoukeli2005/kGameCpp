#ifndef _kMathUtil_h_
#define _kMathUtil_h_

#include "core/kConfig.h"

k_namespace_begin
math_namespace_begin

#define PI 3.1415926

#define degreeToRadian(f) ((f) * PI / 180.0)
#define radianToDegree(f) ((f) * 180.0 / PI)

float sin(float radian);

float cos(float radian);

float tan(float radian);

float ctan(float radian);

math_namespace_end
k_namespace_end

#endif
