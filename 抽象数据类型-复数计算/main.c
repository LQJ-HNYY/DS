#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

/*2022.5.23.lqj.hufe.lab*/


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[])
{
	Complex		Complex_1, 
				Complex_2,
				Complex_sum,
				Complex_sub,
				Complex_mul,
				Complex_dev; 
	
	//��������ֵ
	Complex_Create(&Complex_1, 2.0, 2.0); 
	Complex_Create(&Complex_2, 4.0, 3.0);

	//�Ӽ��˳����� 
	Complex_sum = Complex_Add(Complex_1, Complex_2);
	Complex_sub = Complex_Sub(Complex_1, Complex_2);
	Complex_mul = Complex_Mul(Complex_1, Complex_2);
	Complex_dev = Complex_Dev(Complex_1, Complex_2);
	
	//����ӡ������ˡ�����ģ������� 
	printf("%.2f+(%.2f)i\n", Complex_Get_Re(Complex_sum), Complex_Get_Im(Complex_sum));
	printf("%.2f+(%.2f)i\n", Complex_Get_Re(Complex_sub), Complex_Get_Im(Complex_sub));
	printf("%.2f+(%.2f)i\n", Complex_Get_Re(Complex_mul), Complex_Get_Im(Complex_mul));
	printf("%.2f+(%.2f)i\n", Complex_Get_Re(Complex_dev), Complex_Get_Im(Complex_dev));
	printf("%.2f\n", Complex_Norm(Complex_2));
	printf("%.2f\n", Complex_Phase(Complex_1));
	
	return 0;
}


