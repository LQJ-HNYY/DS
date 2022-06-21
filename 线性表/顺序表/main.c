#include <stdio.h>
#include "SqList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char QQ_NUM[9] = {1, 9, 2, 1, 4, 1, 4, 7, 7};

int main(int argc, char *argv[]) 
{
	/*����˳���ṹ��*/
	SqList L;
	/*���Ԫ�ر���*/
	Elem_Type e;
	/*����*/
	int i = 0;
	
	SqList_Init(&L); 
	
	printf("δ����Ԫ��֮ǰ��"); 
	if(List_Empty(L) == OK)
		printf("˳���Ϊ��\r\n");
	
	for(i=0; i<sizeof(QQ_NUM)/sizeof(QQ_NUM[0]); i++)
	{
		List_Insert(&L, i+1, QQ_NUM[i]);
	}
	
	printf("����Ԫ��֮��");
	if(List_Empty(L) == OK)
		printf("˳���Ϊ��\r\n");
	else
		printf("˳���Ϊ��\r\n");	
	List_Visit(L);
	
	printf("˳�����Ϊ��%d\r\n", List_Length(L)); 
	
	printf("ɾ���ھŸ�Ԫ�ش�ŵ�e�У�\r\n"); 
	List_Delete(&L, 9, &e);
	List_Visit(L);
	printf("e = %d\r\n", e);
	
	printf("����2��Ԫ�طŵ�e�У�\r\n");
	Get_Elem(L, 2, &e);
	printf("e = %d\r\n", e);
	
	printf("���9�ĺ�̷���e�У�\r\n");
	Next_Elem(L, 9, &e);
	printf("e = %d\r\n", e);
	
	printf("���9��ǰ������e�У�\r\n");
	Prior_Elem(L, 9, &e);
	printf("e = %d\r\n", e);
	
	printf("���ص�һ��4��λ�ã�%d\r\n", Locate_Elem(L, 4));
	
	List_Clear(&L);

	SqList_Destroy(&L);

	return 0;
}
