#ifndef _kMathUtil_h_
#define _kMathUtil_h_

#include "core/kConfig.h"

k_namespace_begin
math_namespace_begin

#define PI 3.1415926

#define degreeToRadian(f) ((f) * PI / 180.0)
#define radianToDegree(f) ((f) * 180.0 / PI)

float sin(float f);

float cos(float f);

float tan(float f);

float ctan(float f);

math_namespace_end
k_namespace_end

#endif
