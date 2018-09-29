#include "glmc.h"
//Translation

inline void glmc_mat3f_translation(mat3f dest, float src_a, float src_b)
{
	dest[0][0] = dest[2][2] = dest[1][1] = 1.0f;
	dest[0][1] = dest[2][0] = dest[2][1] = dest[1][0] = 0;
	
	dest[0][2] = src_a;
	dest[1][2] = src_b;
}
inline void glmc_mat4f_translation(mat4f dest, float src_a, float src_b,float src_c)
{
	dest[0][0] = dest[2][2] = dest[1][1] = dest[3][3] = 1.0f;
	dest[0][1] = dest[2][0] = dest[2][1] = dest[1][0] = dest[0][2] = dest[1][2] = dest[3][0] = dest[3][1] = dest[3][2] = 0;
	
	dest[0][3] = src_a;
	dest[1][3] = src_b;
	dest[2][3] = src_c;
}
