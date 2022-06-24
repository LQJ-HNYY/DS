#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	/*声明单链表*/
	LinkList L;
	/*存放各类取值*/
	int e = 0;
	
	if(InitList(&L) == OK)
		printf("头结点初始化成功\r\n");
	
	printf("插入元素之前：");
	if(ListEmpty(L) == OK)
		printf("链表为空\r\n");

	ListInsert(L, 1, 1);
	ListInsert(L, 2, 66);
	ListInsert(L, 3, -3);
	ListInsert(L, 4, 124);
	ListInsert(L, 5, 8);

	printf("插入元素之后：");
	if(ListEmpty(L) != OK)
		printf("链表不为空\r\n");
	printf("链表为：");
	ListVisit(L);
	
	printf("链表元素个数为：%d\r\n", ListLength(L));
	
	GetElem(L, 4, &e);
	printf("取出第四个元素e = %d\r\n", e);
	
	e = LocateElem(L, 66);
	printf("66在第%d个位置上\r\n", e); 
	
	PriorElem(L, -3, &e);
	printf("-3的前驱为：%d\r\n", e);
	NextElem(L, -3, &e);
	printf("-3的后继为：%d\r\n", e);
	
	printf("插入一个新元素在3号位置：");
	ListInsert(L, 3, 888); 
	ListVisit(L);
	
	printf("删除4号元素：");
	ListDelete(L, 4, &e);
	ListVisit(L);
	
	printf("清空链表\r\n");
	ClearList(L); 
	ListVisit(L);
	
	if(DestroyList(&L) == OK)
		printf("链表销毁成功\r\n");
		
	
	return 0;
}





