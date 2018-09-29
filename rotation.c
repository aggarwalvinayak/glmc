#include "glmc.h"
//Rotation
inline void glmc_mat4f_rotation(mat4f dest, float src_a, float src_b, float src_c, float theta)
{
	float c = cos(theta);
	float s = sin(theta);

	dest[0][0] = c + src_a*src_a*(1-c);
	dest[0][1] = src_b*src_a*(1-c) + src_c*s;
	dest[0][2] = src_c*src_a*(1-c) - src_b*s;
	dest[0][3] = 0.0f;

	dest[1][0] = src_a*src_b*(1-c) - src_c*s;
	dest[1][1] = c + src_b*src_b*(1-c);
	dest[1][2] = src_c*src_b*(1-c) + src_a*(s);
	dest[1][3] = 0.0f;

	dest[2][0] = src_a*src_c*(1-c) + src_b*s;
	dest[2][1] = src_b*src_c*(1-c) - src_a*s;
	dest[2][2] = c + src_c*src_c*(1-c);
	dest[2][3] = 0.0f;

	dest[3][0] = 0.0f;
	dest[3][1] = 0.0f;
	dest[3][2] = 0.0f;
	dest[3][3] = 1.0f;
}