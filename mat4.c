#include "glmc.h"

//mat 4x4

inline void glmc_mat4f_copy(mat4f dest, mat4f src){
	for(int i=0;i<4;i++)
		for(int j=0;i<4;j++)
				dest[i][j]=src[i][j];
}

inline float glmc_mat4f_determinant(mat4f src){
	mat4f temp1,temp2,temp3,temp4;
	float ans;
	float det1,det2,det3,det4;
	for(int i=1;i<4;i++)
		for(int j=1;j<4;j++)
			temp1[i-1][j-1]=src[i][j];
			temp4[i-1][j-1]=src[i][j-1];
	temp2[0][0]=src[1][0];
	temp2[1][0]=src[2][0];
	temp2[2][0]=src[3][0];
	for(int i=1;i<4;i++)
		for(int j=2;j<4;j++)
			temp2[i-1][j-1]=src[i][j];
			temp3[i-1][j-2]=src[i][j-2]
	temp3[0][2]=src[1][3];
	temp3[1][2]=src[2][3];
	temp3[2][2]=src[3][3];
	ans=src[0][0]*temp1-src[0][1]*temp2+src[0][2]*temp3-src[0][3]*temp4;
	return ans;
}
inline void glmc_mat4f_transpose(mat4f dest, mat4f src){
	for(int i=0; i<4;i++)
		for(int j=0; j<4;j++)
			dest[j][i]=src[i][j];
}
inline void glmc_mat4f_inverse(mat4f dest,mat4f src){
	float mat4f_det_inv;
	mat4f_det_inv = 1.0f/(glmc_mat4f_determinant(src));

	dest[0][0] = ((src[1][1]*((src[2][2]*src[3][3])-(src[3][2]*src[2][3]))) - (src[2][1]*((src[1][2]*src[3][3])-(src[3][2]*src[1][3]))) + (src[3][1]*((src[1][2]*src[2][3])-(src[2][2]*src[1][3]))))*mat4f_det_inv;
	dest[0][1] = -1.0f*((src[0][1]*((src[2][2]*src[3][3])-(src[3][2]*src[2][3]))) - (src[2][1]*((src[0][2]*src[3][3])-(src[3][2]*src[0][3]))) + (src[3][1]*((src[0][2]*src[2][3])-(src[2][2]*src[0][3]))))*mat4f_det_inv;
	dest[0][2] = ((src[0][1]*((src[1][2]*src[3][3])-(src[3][2]*src[1][3]))) - (src[1][1]*((src[0][2]*src[3][3])-(src[3][2]*src[0][3]))) + (src[3][1]*((src[0][2]*src[1][3])-(src[1][2]*src[0][3]))))*mat4f_det_inv;
	dest[0][3] = -1.0f*((src[0][1]*((src[1][2]*src[2][3])-(src[2][2]*src[1][3]))) - (src[1][1]*((src[0][2]*src[2][3])-(src[2][2]*src[0][3]))) + (src[2][1]*((src[0][2]*src[1][3])-(src[1][2]*src[0][3]))))*mat4f_det_inv;

	dest[1][0] = -1.0f*((src[1][0]*((src[2][2]*src[3][3])-(src[3][2]*src[2][3]))) - (src[2][0]*((src[1][2]*src[3][3])-(src[3][2]*src[1][3]))) + (src[3][0]*((src[1][2]*src[2][3])-(src[2][2]*src[1][3]))))*mat4f_det_inv;
	dest[1][1] = ((src[0][0]*((src[2][2]*src[3][3])-(src[3][2]*src[2][3]))) - (src[2][0]*((src[0][2]*src[3][3])-(src[3][2]*src[0][3]))) + (src[3][0]*((src[0][2]*src[2][3])-(src[2][2]*src[0][3]))))*mat4f_det_inv;
	dest[1][2] = -1.0f*((src[0][0]*((src[1][2]*src[3][3])-(src[3][2]*src[1][3]))) - (src[1][0]*((src[0][2]*src[3][3])-(src[3][2]*src[0][3]))) + (src[3][0]*((src[0][2]*src[1][3])-(src[1][2]*src[0][3]))))*mat4f_det_inv;
	dest[1][3] = ((src[0][0]*((src[1][2]*src[2][3])-(src[2][2]*src[1][3]))) - (src[1][0]*((src[0][2]*src[2][3])-(src[2][2]*src[0][3]))) + (src[2][0]*((src[0][2]*src[1][3])-(src[1][2]*src[0][3]))))*mat4f_det_inv;

	dest[2][0] = ((src[1][0]*((src[2][1]*src[3][3])-(src[3][1]*src[2][3]))) - (src[2][0]*((src[1][1]*src[3][3])-(src[3][1]*src[1][3]))) + (src[3][0]*((src[1][1]*src[2][3])-(src[2][1]*src[1][3]))))*mat4f_det_inv;
	dest[2][1] = -1.0f*((src[0][0]*((src[2][1]*src[3][3])-(src[3][1]*src[2][3]))) - (src[2][0]*((src[0][1]*src[3][3])-(src[3][1]*src[0][3]))) + (src[3][0]*((src[0][1]*src[2][3])-(src[2][1]*src[0][3]))))*mat4f_det_inv;
	dest[2][2] = ((src[0][0]*((src[1][1]*src[3][3])-(src[3][1]*src[1][3]))) - (src[1][0]*((src[0][1]*src[3][3])-(src[3][1]*src[0][3]))) + (src[3][0]*((src[0][1]*src[1][3])-(src[1][1]*src[0][3]))))*mat4f_det_inv;
	dest[2][3] = -1.0f*((src[0][0]*((src[1][1]*src[2][3])-(src[2][1]*src[1][3]))) - (src[1][0]*((src[0][1]*src[2][3])-(src[2][1]*src[0][3]))) + (src[2][0]*((src[0][1]*src[1][3])-(src[1][1]*src[0][3]))))*mat4f_det_inv;

	dest[3][0] = -1.0f*((src[1][0]*((src[2][1]*src[3][2])-(src[3][1]*src[2][2]))) - (src[2][0]*((src[1][1]*src[3][2])-(src[3][1]*src[1][2]))) + (src[3][0]*((src[1][1]*src[2][2])-(src[2][1]*src[1][2]))))*mat4f_det_inv;
	dest[3][1] = ((src[0][0]*((src[2][1]*src[3][2])-(src[3][1]*src[2][2]))) - (src[2][0]*((src[0][1]*src[3][2])-(src[3][1]*src[0][2]))) + (src[3][0]*((src[0][1]*src[2][2])-(src[2][1]*src[0][2]))))*mat4f_det_inv;
	dest[3][2] = -1.0f*((src[0][0]*((src[1][1]*src[3][2])-(src[3][1]*src[1][2]))) - (src[1][0]*((src[0][1]*src[3][2])-(src[3][1]*src[0][2]))) + (src[3][0]*((src[0][1]*src[1][2])-(src[1][1]*src[0][2]))))*mat4f_det_inv;
	dest[3][3] = ((src[0][0]*((src[1][1]*src[2][2])-(src[2][1]*src[1][2]))) - (src[1][0]*((src[0][1]*src[2][2])-(src[2][1]*src[0][2]))) + (src[2][0]*((src[0][1]*src[1][2])-(src[1][1]*src[0][2]))))*mat4f_det_inv;
	
}

inline int glmc_mat4f_is_normalized(mat4f src){
	float min=1 - 1e-7;
	float max=1 + 1e+7;
	float det;
	det=glmc_mat4f_determinant(src);
	if(min<det && max>det)
		return 1;
	return 0;
}
inline void glmc_mat4f_normlize(mat4f dest, mat4f src){
	float det;
	det=glmc_mat4f_determinant(src);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			dest[i][j]=src[i][j]/det;
}

inline void glmc_mat4f_add(mat4f dest, mat4f src_a, mat4f src_b){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			dest[i][j]=src_a[i][j]+src_b[i][j];
}
inline void glmc_mat4f_add_dest(mat4f src_dest, mat4f src_b){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			src_dest[i][j]+=src_b[i][j];
} 

inline void glmc_mat4f_sub(mat4f dest, mat4f src_a, mat4f src_b){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			dest[i][j]=src_a[i][j]-src_b[i][j];
} 
inline void glmc_mat4f_sub_dest(mat4f src_dest, mat4f src_b){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			src_dest[i][j]-=src_b[i][j];
} 

inline void glmc_mat4f_mul(mat4f dest, mat4f src_a, mat4f src_b){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			dest[i][j]=src_a[i][0]*src_b[0][j]+src_a[i][1]*src_b[1][j]+src_a[i][2]*src_b[2][j]+src_a[i][3]*src_b[3][j];
} 
inline void glmc_mat4f_mul_dest(mat4f src_dest, mat4f src_b){
	mat4f temp;
	glmc_mat4f_mul(temp,src_dest,src_b);
	glmc_mat4f_copy(src_dest,temp);
} 
inline void glmc_mat4f_mul_s(mat4f dest, mat4f src_a, float src_b){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			dest[i][j]=src_a[i][j]*src_b;
} 

inline void glmc_mat4f_div(mat4f dest, mat4f src_a, mat4f src_b){
	mat4f inv;
	glmc_mat4f_inverse(inv,src_b);
	glmc_mat4f_mul(dest,src_a,inv);
}  
inline void glmc_mat4f_div_dest(mat4f src_dest, mat4f src_b){
	 mat4f inv;
	 glmc_mat4f_inverse(inv,src_b);
	 glmc_mat4f_mul_dest(src_dest,src_b);
} 
inline void glmc_mat4f_div_s(mat4f dest, mat4f src_a, float src_b){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			dest[i][j]=src_a[i][j]/ src_b;
} 
inline void glmc_mat4f_addadd(mat4f dest, mat4f src_a, mat4f src_b){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			dest[i][j]+=src_a[i][j]+src_b[i][j];
} 
inline void glmc_mat4f_subadd(mat4f dest, mat4f src_a, mat4f src_b){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			dest[i][j]+=src_a[i][j]-src_b[i][j];
} 

inline void glmc_mat4f_madd(mat4f dest, mat4f src_a, mat4f src_b){
	mat4f temp;
	glmc_mat4f_mul(temp,src_a,src_b);
	glmc_mat4f_add_dest(dest,temp);
} 
inline void glmc_mat4f_msub(mat4f dest, mat4f src_a, mat4f src_b){
	mat4f temp;
	glmc_mat4f_mul(temp,src_a,src_b);
	glmc_mat4f_sub_dest(dest,temp);
} 
inline void glmc_mat4f_perspective_projection(mat4f dest, float src_fovy, float src_aspect, float src_zNear, float src_zFar)
{
	float tanHalfFovy = tan(src_fovy/2);
 	dest[0][0] = 1.0f/(src_aspect*tanHalfFovy);
	dest[0][1] = 0;
	dest[0][2] = 0;
	dest[0][3] = 0;
 	dest[1][0] = 0;
	dest[1][1] = 1.0f/tanHalfFovy;
	dest[1][2] = 0;
	dest[1][3] = 0;
 	dest[2][0] = 0;
	dest[2][1] = 0;
	dest[2][2] = src_zFar/(src_zFar - src_zNear);
	dest[2][3] = 1.0f;
 	dest[3][0] = 0;
	dest[3][1] = 0;
	dest[3][2] = 0;
	dest[3][3] = -1.0f*(src_zFar*src_zNear)/(src_zFar - src_zNear);
}
inline void glmc_mat4f_ortho_projection(mat4f dest, float src_left, float src_right, float src_bottom, float src_top)
{
	dest[0][0] = 2.0f/(src_right - src_left);
	dest[0][1] = 1.0f;
	dest[0][2] = 1.0f;
	dest[0][3] = 1.0f;
 	dest[1][0] = 1.0f;
	dest[1][1] = 2.0f/(src_top - src_bottom);
	dest[1][2] = 1.0f;
	dest[1][3] = 1.0f;
 	dest[2][0] = 1.0f;
	dest[2][1] = 1.0f;
	dest[2][2] = 1.0f;
	dest[2][3] = 1.0f;
 	dest[3][0] = -1.0f*(src_right + src_left)/(src_right - src_left);
	dest[3][1] = -1.0f*(src_top + src_bottom)/(src_top - src_bottom);
	dest[3][2] = 1.0f;
	dest[3][3] = 1.0f;
}