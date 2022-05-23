#ifndef __COMPLEX_H
#define __COMPLEX_H

/*角度弧度互相转化*/
#define		R2G		(180.0/3.1415926)
#define		G2R		(3.1415926/180.0)

//typedef重新声明类型 
typedef struct
{
	float Re;
	float Im;
}Complex;


void Complex_Create(Complex *C, float Re, float Im);

float Complex_Get_Re(Complex C);
float Complex_Get_Im(Complex C);
Complex Complex_Add(Complex C1, Complex C2);
Complex Complex_Sub(Complex C1, Complex C2);
Complex Complex_Mul(Complex C1, Complex C2); 
Complex Complex_Dev(Complex C1, Complex C2);
float Complex_Norm(Complex C1);
float Complex_Phase(Complex C1);


#endif
