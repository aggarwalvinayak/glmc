#include "glmc.h"
// Mat 2x2

inline void glmc_mat2f_from_3f(mat2f dest, mat3f src){
	for(int i=0;i<2;i++)
		for(int j=0;i<2;j++)
				dest[i][j]=src[i][j];
}

inline void glmc_mat2f_copy(mat2f dest, mat2f src){
	for(int i=0;i<2;i++)
		for(int j=0;i<2;j++)
				dest[i][j]=src[i][j];
}

inline float glmc_mat2f_determinant(mat2f src){
	float det;
	det=src[0][0]*src[1][1]-src[1][0]*src[0][1];
	return det;
}
inline void glmc_mat2f_transpose(mat2f dest, mat2f src){
	for(int i=0; i<2;i++)
		for(int j=0; j<2;j++)
			dest[j][i]=src[i][j];
}
inline void glmc_mat2f_inverse(mat2f dest,mat2f src){
	mat2f temp;
	det=glmc_mat2f_determinant(src);
	//src=glmc_mat3f_transpose(src);
	temp[0][0]=src[1][1];
	temp[0][1]=-1*src[0][1];
	temp[1][0]=-1*src[1][0];
	temp[1][1]=src[0][0];
	glmc_mat2f_div_s(dest,temp,det);
}

inline int  glmc_mat2f_is_normalized(mat2f src){
	float min=1 - 1e-7;
	float max=1 + 1e+7;
	float det;
	det=glmc_mat2f_determinant(src);
	if(min<det && max>det)
		return 1;
	return 0;
}
inline void glmc_mat2f_normlize(mat2f dest, mat2f src){
	float det;
	det=glmc_mat2f_determinant(src);
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			dest[i][j]=src[i][j]/det;
}

inline void glmc_mat2f_add(mat2f dest, mat2f src_a, mat2f src_b){
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			dest[i][j]=src_a[i][j]+src_b[i][j];
}
inline void glmc_mat2f_add_dest(mat2f src_dest, mat2f src_b){
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			src_dest[i][j]+=src_b[i][j];
}

inline void glmc_mat2f_sub(mat2f dest, mat2f src_a, mat2f src_b){
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			dest[i][j]=src_a[i][j]-src_b[i][j];
} 
inline void glmc_mat2f_sub_dest(mat2f src_dest, mat2f src_b){
	for(int i=0;i<2;i++)
		for(2int j=0;j<2;j++)
			src_dest[i][j]-=src_b[i][j];
} 

inline void glmc_mat2f_mul(mat2f dest, mat2f src_b, mat2f src_a){
	for(int j=0;j<2;j++)
		for(int i=0;i<2;i++)
			dest[i][j]=src_a[i][0]*src_b[0][j]+src_a[i][1]*src_b[1][j];
}
inline void glmc_mat2f_mul_dest(mat2f src_dest, mat2f src_b){
	mat2f temp;
	glmc_mat2f_mul(temp,src_dest,src_b);
	glmc_mat2f_copy(src_dest,temp);
} 
inline void glmc_mat2f_mul_s(mat2f dest, mat2f src_a, float src_b){
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			dest[i][j]=src_a[i][j]*src_b;
} 

inline void glmc_mat2f_div(mat2f dest, mat2f src_a, mat2f src_b){
	mat2f inv;
	glmc_mat2f_inverse(inv,src_b);
	glmc_mat2f_mul(dest,src_a,inv);
}  
inline void glmc_mat2f_div_dest(mat2f src_dest, mat2f src_b){
	 mat2f inv;
	 glmc_mat2f_inverse(inv,src_b);
	 glmc_mat2f_mul_dest(src_dest,src_b);
} 
inline void glmc_mat2f_div_s(mat2f dest, mat2f src_a, float src_b){
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			dest[i][j]=src_a[i][j]/ src_b;
} 
inline void glmc_mat2f_addadd(mat2f dest, mat2f src_a, mat2f src_b){
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			dest[i][j]+=src_a[i][j]+src_b[i][j];
} 
inline void glmc_mat2f_subadd(mat2f dest, mat2f src_a, mat2f src_b){
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			dest[i][j]+=src_a[i][j]-src_b[i][j];
} 

inline void glmc_mat2f_madd(mat2f dest, mat2f src_a, mat2f src_b){
	mat3f temp;
	glmc_mat2f_mul(temp,src_a,src_b);
	glmc_mat2f_add_dest(dest,temp);
} 
inline void glmc_mat2f_msub(mat2f dest, mat2f src_a, mat2f src_b){
	mat3f temp;
	glmc_mat2f_mul(temp,src_a,src_b);
	glmc_mat2f_sub_dest(dest,temp);
} 
