#include "complex.h"
#include <assert.h>
#include <math.h>

//利用指针可以直接在全局范围内实现值传递
//如果不用指针的话函数结束内存释放值就消失了 
/*给复数赋初值*/
void Complex_Create(Complex *C, float Re, float Im)
{
	C->Re = Re;
	C->Im = Im;
}


//这些有返回值的可以不用指针传递值 
/*返回复数实部*/
float Complex_Get_Re(Complex C)
{
	return C.Re;
}

/*返回复数虚部*/
float Complex_Get_Im(Complex C)
{
	return C.Im;
}


/*复数加法*/
Complex Complex_Add(Complex C1, Complex C2)
{
	Complex sum;
	sum.Re = C1.Re + C2.Re;
	sum.Im = C1.Im + C2.Im;
	return sum;
}

/*复数减法*/
Complex Complex_Sub(Complex C1, Complex C2) 
{
	Complex sub;
	sub.Re = C1.Re - C2.Re;
	sub.Im = C1.Im - C2.Im;
	return sub;
}


/*复数乘法*/
//(a+bi)(c+di)=(ac-bd)+(bc+ad)i
Complex Complex_Mul(Complex C1, Complex C2)
{
	Complex mul;
	mul.Re = (C1.Re*C2.Re) - (C1.Im*C2.Im);
	mul.Im = (C1.Im*C2.Re) + (C1.Re*C2.Im);
	return mul;
}


/*复数除法*/
//(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +((bc-ad)/(c^2+d^2))i
Complex Complex_Dev(Complex C1, Complex C2) 
{
	Complex dev;
	//条件不成立运行assert，要求被除数不能为0 
	assert(C2.Re*C2.Re + C2.Im*C2.Im != 0); 
	dev.Re = ( (C1.Re*C2.Re) + (C1.Im*C2.Im) ) / ( C2.Re*C2.Re + C2.Im*C2.Im );
	dev.Im = ( (C1.Im*C2.Re) - (C1.Re*C2.Im) ) / ( C2.Re*C2.Re + C2.Im*C2.Im );
	return dev;
}


/*复数模长*/
float Complex_Norm(Complex C1)
{
	float norm;
	norm = sqrt(C1.Re*C1.Re + C1.Im*C1.Im);	
	return norm;
} 


/*复数相角*/
float Complex_Phase(Complex C1)
{
	float phase;
	phase = atan(C1.Im / C1.Re) * R2G;
	return phase;
} 
