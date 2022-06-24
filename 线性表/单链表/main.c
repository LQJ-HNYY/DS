#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	/*����������*/
	LinkList L;
	/*��Ÿ���ȡֵ*/
	int e = 0;
	
	if(InitList(&L) == OK)
		printf("ͷ����ʼ���ɹ�\r\n");
	
	printf("����Ԫ��֮ǰ��");
	if(ListEmpty(L) == OK)
		printf("����Ϊ��\r\n");

	ListInsert(L, 1, 1);
	ListInsert(L, 2, 66);
	ListInsert(L, 3, -3);
	ListInsert(L, 4, 124);
	ListInsert(L, 5, 8);

	printf("����Ԫ��֮��");
	if(ListEmpty(L) != OK)
		printf("����Ϊ��\r\n");
	printf("����Ϊ��");
	ListVisit(L);
	
	printf("����Ԫ�ظ���Ϊ��%d\r\n", ListLength(L));
	
	GetElem(L, 4, &e);
	printf("ȡ�����ĸ�Ԫ��e = %d\r\n", e);
	
	e = LocateElem(L, 66);
	printf("66�ڵ�%d��λ����\r\n", e); 
	
	PriorElem(L, -3, &e);
	printf("-3��ǰ��Ϊ��%d\r\n", e);
	NextElem(L, -3, &e);
	printf("-3�ĺ��Ϊ��%d\r\n", e);
	
	printf("����һ����Ԫ����3��λ�ã�");
	ListInsert(L, 3, 888); 
	ListVisit(L);
	
	printf("ɾ��4��Ԫ�أ�");
	ListDelete(L, 4, &e);
	ListVisit(L);
	
	printf("�������\r\n");
	ClearList(L); 
	ListVisit(L);
	
	if(DestroyList(&L) == OK)
		printf("�������ٳɹ�\r\n");
		
	
	return 0;
}





