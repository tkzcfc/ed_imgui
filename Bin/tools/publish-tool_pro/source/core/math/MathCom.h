#pragma once

#include <math.h>
#include <iostream>

/**Util macro for conversion from degrees to radians.*/
#define MH_DEG_TO_RAD(x)          ((x) * 0.0174532925f)
/**Util macro for conversion from radians to degrees.*/
#define MH_RAD_TO_DEG(x)          ((x)* 57.29577951f)
/**
@{ Util macro for const float such as epsilon, small float and float precision tolerance.
*/
#define MH_FLOAT_SMALL            1.0e-37f
#define MH_TOLERANCE              2e-37f
#define MH_PIOVER2                1.57079632679489661923f
#define MH_EPSILON                0.000001f




#define MH_ASSERT(con)
#define MH_LOG(format,...)

#define MH_MAX(a, b) ((b) < (a) ? (a) : (b))
#define MH_MIN(a, b) ((a) < (b) ? (a) : (b))