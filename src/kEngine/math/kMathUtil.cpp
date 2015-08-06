#include "kMathUtil.h"

#include <math.h>

k_namespace_begin
math_namespace_begin

float sin(float radian)
{
	return ::sin(radian);
}

float cos(float radian)
{
	return ::cos(radian);
}

float tan(float radian)
{
	return ::tan(radian);
}

float ctan(float radian)
{
	return 1.0 / tan(radian);
}


math_namespace_end
k_namespace_end