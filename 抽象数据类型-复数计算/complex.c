#include "complex.h"
#include <assert.h>
#include <math.h>

//����ָ�����ֱ����ȫ�ַ�Χ��ʵ��ֵ����
//�������ָ��Ļ����������ڴ��ͷ�ֵ����ʧ�� 
/*����������ֵ*/
void Complex_Create(Complex *C, float Re, float Im)
{
	C->Re = Re;
	C->Im = Im;
}


//��Щ�з���ֵ�Ŀ��Բ���ָ�봫��ֵ 
/*���ظ���ʵ��*/
float Complex_Get_Re(Complex C)
{
	return C.Re;
}

/*���ظ����鲿*/
float Complex_Get_Im(Complex C)
{
	return C.Im;
}


/*�����ӷ�*/
Complex Complex_Add(Complex C1, Complex C2)
{
	Complex sum;
	sum.Re = C1.Re + C2.Re;
	sum.Im = C1.Im + C2.Im;
	return sum;
}

/*��������*/
Complex Complex_Sub(Complex C1, Complex C2) 
{
	Complex sub;
	sub.Re = C1.Re - C2.Re;
	sub.Im = C1.Im - C2.Im;
	return sub;
}


/*�����˷�*/
//(a+bi)(c+di)=(ac-bd)+(bc+ad)i
Complex Complex_Mul(Complex C1, Complex C2)
{
	Complex mul;
	mul.Re = (C1.Re*C2.Re) - (C1.Im*C2.Im);
	mul.Im = (C1.Im*C2.Re) + (C1.Re*C2.Im);
	return mul;
}


/*��������*/
//(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +((bc-ad)/(c^2+d^2))i
Complex Complex_Dev(Complex C1, Complex C2) 
{
	Complex dev;
	//��������������assert��Ҫ�󱻳�������Ϊ0 
	assert(C2.Re*C2.Re + C2.Im*C2.Im != 0); 
	dev.Re = ( (C1.Re*C2.Re) + (C1.Im*C2.Im) ) / ( C2.Re*C2.Re + C2.Im*C2.Im );
	dev.Im = ( (C1.Im*C2.Re) - (C1.Re*C2.Im) ) / ( C2.Re*C2.Re + C2.Im*C2.Im );
	return dev;
}


/*����ģ��*/
float Complex_Norm(Complex C1)
{
	float norm;
	norm = sqrt(C1.Re*C1.Re + C1.Im*C1.Im);	
	return norm;
} 


/*�������*/
float Complex_Phase(Complex C1)
{
	float phase;
	phase = atan(C1.Im / C1.Re) * R2G;
	return phase;
} 
