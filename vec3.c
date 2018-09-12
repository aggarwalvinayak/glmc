/* 
 * Copyright 2018 Anish Bhobe, glmc Contributors
 * 
 * Permission is hereby granted, free of charge, 
 * to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the 
 * ollowing conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "glmc.h"


void glmc_vec3f_from_2f(vec3f dest, vec2f src_a, float src_b){
	dest[0]=src_a[0];
	dest[1]=src_a[1];
	dest[2]=src_b;
}
void glmc_vec3f_from_4f(vec3f dest, vec4f src){
	for(int i=0;i<3;i++){
			dest[i]=src[i];
	}
}

void glmc_vec3f_copy(vec3f dest, vec3f src){
	for(int i=0;i<3;i++){
			dest[i]=src[i];
	}
}

float glmc_vec3f_sqrlength(vec3f vec){
	int sqrlen=0;
	for(int i=0;i<3;i++){
		sqrlen+=vec[i]*vec[i];
	}
	return sqrlen;
}
float glmc_vec3f_length(vec3f vec){
	int len=0;
	len=sqrt(glmc_vec3f_sqrlength(vec));
	return len;
}

int  glmc_vec3f_is_normalized(vec3f src){
	float min=1 - 1e-14;
	float max=1 + 1e+14;
	if(min<glmc_vec3f_length(src) && max>glmc_vec3f_length(src))
		return 1;
	return 0;
}
void glmc_vec3f_normlize(vec3f dest, vec3f src){
	float len;
	len=glmc_vec3f_length(src);
	for(int i=0;i<3;i++){
		dest[i]=dest[i]/len;
	}
}

void glmc_vec3f_add(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0;i<3;i++)
		dest[i]=src_a[i]+src_b[i];
} // dest = src_a + src_b;
void glmc_vec3f_add_dest(vec3f src_dest, vec3f src_b){
	for(int i=0;i<3;i++)
		src_dest[i]+=src_b[i];
} // dest += src_a;

void glmc_vec3f_sub(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0;i<3;i++)
		dest[i]=src_a[i]-src_b[i];
} // dest = src_a - src_b;
void glmc_vec3f_sub_dest(vec3f src_dest, vec3f src_b){
	for(int i=0;i<3;i++)
		src_dest[i]-=src_b[i];
} // dest -= src_a;

void glmc_vec3f_mul(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0;i<3;i++)
		dest[i]=src_a[i]*src_b[i];
} // dest = src_a * src_b;
void glmc_vec3f_mul_dest(vec3f src_dest, vec3f src_b){
	for(int i=0;i<3;i++)
		src_dest[i]*=src_b[i];
} // dest *= src_a;
void glmc_vec3f_mul_s(vec3f dest, vec3f src_a, float src_b){
	for(int i=0;i<3;i++)
		dest[i]=src_a[i]*src_b;
} // dest = src_a * scalar

void glmc_vec3f_div(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0;i<3;i++)
		dest[i]=src_a[i]/src_b[i];
} // dest = src_a / src_b;
void glmc_vec3f_div_dest(vec3f src_dest, vec3f src_b){
	for(int i=0;i<3;i++)
		src_dest[i]/=src_b[i];
} // dest /= src_a;
void glmc_vec3f_div_s(vec3f dest, vec3f src_a, float src_b){
	for(int i=0;i<3;i++)
		dest[i]=src_a[i]/src_b;
} // dest = src_a / scalar

void glmc_vec3f_addadd(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0;i<3;i++)
		dest[i]+=src_a[i]+src_b[i];
} // dest += src_a + src_b;
void glmc_vec3f_subadd(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0;i<3;i++)
		dest[i]+=src_a[i]-src_b[i];
} // dest += src_a - src_b;

void glmc_vec3f_madd(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0;i<3;i++)
		dest[i]*=src_a[i]*src_b[i];
} // dest += src_a * src_b;
void glmc_vec3f_msub(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0;i<3;i++)
		dest[i]-=src_a[i]*src_b[i];
} // dest -= src_a * src_b;

float glmc_vec3f_dot(vec3f src_a, vec3f src_b){
	float dot=0;
	for(int i=0;i<3;i++)
		dot+=src_a[i]*src_b[i];
	return dot;
}
void  glmc_vec3f_cross(vec3f dest, vec3f src_a, vec3f src_b){
	dest[0]=src_a[1]*src_b[2]-src_a[2]*src_b[1];
	dest[1]=src_a[2]*src_b[0]-src_a[0]*src_b[2];
	dest[2]=src_a[0]*src_b[1]-src_a[1]*src_b[0];
}

// vec4f

void glmc_vec4f_from_2f(vec4f dest, vec2f src_a, float src_b, float src_c){
	dest[0]=src_a[0];
	dest[1]=src_a[1];
	dest[2]=src_b;
	dest[3]=src_c;
}
void glmc_vec4f_from_3f(vec4f dest, vec3f src_a, float src_b){
	for(int i=0;i<3;i++)
		dest[i]=src[i];
	dest[3]=src_c;
}

void glmc_vec4f_copy(vec4f dest, vec4f src){
	for(int i=0;i<4;i++)
		dest[i]=src[i];
}

float glmc_vec4f_sqrlength(vec4f vec){
	int sqrlen=0;
	for(int i=0;i<4;i++){
		sqrlen+=vec[i]*vec[i];
	}
	return sqrlen;
}
float glmc_vec4f_length(vec4f vec){
	int len=0;
	len=sqrt(glmc_vec4f_sqrlength(vec));
	return len;
}

int  glmc_vec4f_is_normalized(vec4f src){
	float min=1 - 1e-14;
	float max=1 + 1e+14;
	if(min<glmc_vec4f_length(src) && max>glmc_vec4f_length(src))
		return 1;
	return 0;
}
void glmc_vec4f_normlize(vec4f dest, vec4f src){
	float len;
	len=glmc_vec4f_length(src);
	for(int i=0;i<4;i++){
		dest[i]=dest[i]/len;
	}
}

void glmc_vec4f_add(vec4f dest, vec4f src_a, vec4f src_b){
	for(int i=0;i<4;i++)
		dest[i]=src_a[i]+src_b[i];
} // dest = src_a + src_b;
void glmc_vec4f_add_dest(vec4f src_dest, vec4f src_b){
	for(int i=0;i<4;i++)
		src_dest[i]+=src_b[i];
} // dest += src_a;

void glmc_vec4f_sub(vec4f dest, vec4f src_a, vec4f src_b){
	for(int i=0;i<4;i++)
		dest[i]=src_a[i]-src_b[i];
} // dest = src_a - src_b;
void glmc_vec4f_sub_dest(vec4f src_dest, vec4f src_b){
	for(int i=0;i<4;i++)
		src_dest[i]-=src_b[i];
} // dest -= src_a;

void glmc_vec4f_mul(vec4f dest, vec4f src_a, vec4f src_b){
	for(int i=0;i<4;i++)
		dest[i]=src_a[i]*src_b[i];
} // dest = src_a * src_b;
void glmc_vec4f_mul_dest(vec4f src_dest, vec4f src_b){
	for(int i=0;i<4;i++)
		src_dest[i]*=src_b[i];
} // dest *= src_a;
void glmc_vec4f_mul_s(vec4f dest, vec4f src_a, float src_b){
	for(int i=0;i<4;i++)
		dest[i]=src_a[i]*src_b;
} // dest = src_a * scalar

void glmc_vec4f_div(vec4f dest, vec4f src_a, vec4f src_b){
	for(int i=0;i<4;i++)
		dest[i]=src_a[i]/src_b[i];
} // dest = src_a / src_b;
void glmc_vec4f_div_dest(vec4f src_dest, vec4f src_b){
	for(int i=0;i<4;i++)
		src_dest[i]/=src_b[i];
} // dest /= src_a;
void glmc_vec4f_div_s(vec4f dest, vec4f src_a, float src_b){
	for(int i=0;i<4;i++)
		dest[i]=src_a[i]/src_b;
} // dest = src_a / scalar

void glmc_vec4f_addadd(vec4f dest, vec4f src_a, vec4f src_b){
	for(int i=0;i<4;i++)
		dest[i]+=src_a[i]+src_b[i];
} // dest += src_a + src_b;
void glmc_vec4f_subadd(vec4f dest, vec4f src_a, vec4f src_b){
	for(int i=0;i<4;i++)
		dest[i]+=src_a[i]-src_b[i];
} // dest += src_a - src_b;

void glmc_vec4f_madd(vec4f dest, vec4f src_a, vec4f src_b){
	for(int i=0;i<4;i++)
		dest[i]+=src_a[i]*src_b[i];
} // dest += src_a * src_b;
void glmc_vec4f_msub(vec4f dest, vec4f src_a, vec4f src_b){
	for(int i=0;i<4;i++)
		dest[i]-=src_a[i]*src_b[i];
} // dest -= src_a * src_b;

float glmc_vec4f_dot(vec4f src_a, vec4f src_b){
	float dot=0;
	for(int i=0;i<4;i++)
		dot+=src_a[i]*src_b[i];
	return dot;
}

// vec2f

void glmc_vec2f_from_3f(vec2f dest, vec3f src);
void glmc_vec2f_from_4f(vec2f dest, vec2f src);

void glmc_vec2f_copy(vec2f dest, vec2f src);

float glmc_vec2f_sqrlength(vec2f vec);
float glmc_vec2f_length(vec2f vec);

int  glmc_vec2f_is_normalized(vec2f src);
void glmc_vec2f_normlize(vec2f dest, vec2f src);

void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b); // dest = src_a + src_b;
void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_b); // dest += src_a;

void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b); // dest = src_a - src_b;
void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_b); // dest -= src_a;

void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b); // dest = src_a * src_b;
void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_b); // dest *= src_a;
void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b); // dest = src_a * scalar

void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b); // dest = src_a / src_b;
void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_b); // dest /= src_a;
void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b); // dest = src_a / scalar

void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b); // dest += src_a + src_b;
void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b); // dest += src_a - src_b;

void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b); // dest += src_a * src_b;
void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b); // dest -= src_a * src_b;

float glmc_vec2f_dot(vec2f src_a, vec2f src_b);