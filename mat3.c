#include "glmc.h"
// Mat 3x3

void glmc_mat3f_from_4f(mat3f dest, mat4f src){
	for(int i=0;i<3;i++)
		for(int j=0;i<3;j++)
				dest[i][j]=src[i][j];
}

void glmc_mat3f_copy(mat3f dest, mat3f src){
	for(int i=0;i<3;i++)
		for(int j=0;i<3;j++)
				dest[i][j]=src[i][j];
}

float glmc_mat3f_determinant(mat3f src){
	float temp1,temp2,temp3,det=0;
	temp1=src[1][1]*src[2][2]-src[1][2]*src[2][1];
	temp2=src[1][0]*src[2][2]-src[1][2]*src[2][0];
	temp3=src[1][0]*src[2][1]-src[1][1]*src[2][0];
	det=src[0][0]*temp1-src[0][1]*temp2+src[0][2]*temp3;
	return det;
}
void glmc_mat3f_transpose(mat3f dest, mat3f src){
	for(int i=0; i<3;i++)
		for(int j=0; j<3;j++)
			dest[j][i]=src[i][j];
}
void glmc_mat3f_inverse(mat3f dest,mat3f src){
	float det;
	det=glmc_mat3f_determinant(src);
	mat3f m,adj;
	m[0][0]=src[1][1]*src[2][2]-src[1][2]*src[2][1];
	m[0][1]=src[1][0]*src[2][2]-src[1][2]*sr c[2][0];
	m[0][2]=src[1][0]*src[2][1]-src[1][1]*src[2][0];
	m[1][0]=src[0][1]*src[2][2]-src[0][2]*src[2][1];
	m[1][1]=src[0][0]*src[2][2]-src[0][2]*src[2][0];
	m[1][2]=src[0][0]*src[2][1]-src[0][1]*src[2][0];
	m[2][0]=src[0][1]*src[1][2]-src[0][2]*src[1][1];
	m[2][1]=src[0][0]*src[1][2]-src[0][2]*src[1][0];
	m[2][2]=src[0][0]*src[1][1]-src[0][1]*src[1][0];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			if((i+j)%2!=0)
				adj[i][j]=-1*m[i][j];
			else
				adj[i][j]=m[i][j];
		}
	glmc_mat3f_div_s(dest,adj,det);
}

int  glmc_mat3f_is_normalized(mat3f src){
	float min=1 - 1e-7;
	float max=1 + 1e+7;
	float det;
	det=glmc_mat3f_determinant(src);
	if(min<det && max>det)
		return 1;
	return 0;
}
void glmc_mat3f_normlize(mat3f dest, mat3f src){
	float det;
	det=glmc_mat3f_determinant(src);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			dest[i][j]=src[i][j]/det;
}

void glmc_mat3f_add(mat3f dest, mat3f src_a, mat3f src_b){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			dest[i][j]=src_a[i][j]+src_b[i][j];
}
void glmc_mat3f_add_dest(mat3f src_dest, mat3f src_b){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			src_dest[i][j]+=src_b[i][j];
}

void glmc_mat3f_sub(mat3f dest, mat3f src_a, mat3f src_b){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			dest[i][j]=src_a[i][j]-src_b[i][j];
}
void glmc_mat3f_sub_dest(mat3f src_dest, mat3f src_b){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			src_dest[i][j]-=src_b[i][j];
}

void glmc_mat3f_mul(mat3f dest, mat3f src_a, mat3f src_b){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			dest[i][j]=src_a[i][0]*src_b[0][j]+src_a[i][1]*src_b[1][j]+src_a[i][2]*src_b[2][j];
}
void glmc_mat3f_mul_dest(mat3f src_dest, mat3f src_b){
	mat3f temp;
	glmc_mat3f_mul(temp,src_dest,src_b);
	glmc_mat3f_copy(src_dest,temp);
}
void glmc_mat3f_mul_s(mat3f dest, mat3f src_a, float src_b){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			dest[i][j]=src_a[i][j]*src_b;
}

void glmc_mat3f_div(mat3f dest, mat3f src_a, mat3f src_b){
	mat3f inv;
	glmc_mat3f_inverse(inv,src_b);
	glmc_mat3f_mul(dest,src_a,inv);
} 
void glmc_mat3f_div_dest(mat3f src_dest, mat3f src_b){
	 mat3f inv;
	 glmc_mat3f_inverse(inv,src_b);
	 glmc_mat3f_mul_dest(src_dest,src_b);
}
void glmc_mat3f_div_s(mat3f dest, mat3f src_a, float src_b){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			dest[i][j]=src_a[i][j]/ src_b;
}

void glmc_mat3f_addadd(mat3f dest, mat3f src_a, mat3f src_b){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			dest[i][j]+=src_a[i][j]+src_b[i][j];
}
void glmc_mat3f_subadd(mat3f dest, mat3f src_a, mat3f src_b){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			dest[i][j]+=src_a[i][j]-src_b[i][j];
}

void glmc_mat3f_madd(mat3f dest, mat3f src_a, mat3f src_b){
	mat3f temp;
	glmc_mat3f_mul(temp,src_a,src_b);
	glmc_mat3f_add_dest(dest,temp);
}
void glmc_mat3f_msub(mat3f dest, mat3f src_a, mat3f src_b){
	mat3f temp;
	glmc_mat3f_mul(temp,src_a,src_b);
	glmc_mat3f_sub_dest(dest,temp);
}
