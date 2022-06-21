#include <stdio.h>
#include "SqList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char QQ_NUM[9] = {1, 9, 2, 1, 4, 1, 4, 7, 7};

int main(int argc, char *argv[]) 
{
	/*定义顺序表结构体*/
	SqList L;
	/*存放元素变量*/
	Elem_Type e;
	/*索引*/
	int i = 0;
	
	SqList_Init(&L); 
	
	printf("未插入元素之前："); 
	if(List_Empty(L) == OK)
		printf("顺序表为空\r\n");
	
	for(i=0; i<sizeof(QQ_NUM)/sizeof(QQ_NUM[0]); i++)
	{
		List_Insert(&L, i+1, QQ_NUM[i]);
	}
	
	printf("插入元素之后：");
	if(List_Empty(L) == OK)
		printf("顺序表为空\r\n");
	else
		printf("顺序表不为空\r\n");	
	List_Visit(L);
	
	printf("顺序表长度为：%d\r\n", List_Length(L)); 
	
	printf("删除第九个元素存放到e中：\r\n"); 
	List_Delete(&L, 9, &e);
	List_Visit(L);
	printf("e = %d\r\n", e);
	
	printf("将第2个元素放到e中：\r\n");
	Get_Elem(L, 2, &e);
	printf("e = %d\r\n", e);
	
	printf("获得9的后继放入e中：\r\n");
	Next_Elem(L, 9, &e);
	printf("e = %d\r\n", e);
	
	printf("获得9的前驱放入e中：\r\n");
	Prior_Elem(L, 9, &e);
	printf("e = %d\r\n", e);
	
	printf("返回第一个4的位置：%d\r\n", Locate_Elem(L, 4));
	
	List_Clear(&L);

	SqList_Destroy(&L);

	return 0;
}
