#ifndef	__SQLIST_H
#define __SQLIST_H
#include <stdlib.h>
#include <stdio.h>


typedef		int		Elem_Type;

//顺序表存储空间的初始分配量
#define 	LIST_INIT_SIZE 	100
 //顺序表存储空间的分配增量
#define 	LIST_INCREMENT	10

#define 	Status			char		
#define 	OK				1
#define		FALSE			0
#define 	OVERFLOW		1
#define 	DEBUG_INFO		1


typedef struct
{
	//顺序表存储空间的基址（指向顺序表所占内存的起始位置）
	Elem_Type *elem;
	//当前顺序表长度（包含多少元素）
	int length;
	//当前分配的存储容量（可以存储多少元素）
	int listsize;
}SqList;


/*初始化顺序表*/
Status SqList_Init(SqList *L);

/*销毁顺序表，清空内存 */
Status SqList_Destroy(SqList *L); 

/*清空顺序表，不清空内存*/
Status List_Clear(SqList *L);

/*判断顺序表是否为空*/
Status List_Empty(SqList L); 

/*返回顺序表元素个数*/
int List_Length(SqList L);

/*获取顺序表中的第i个元素值放到e中*/
Status Get_Elem(SqList L, int i, Elem_Type* e); 

/*返回顺序表中第一个与e相同的值的位置*/
int Locate_Elem(SqList L, Elem_Type e);

/*将顺序表中cur_e的前驱元素放到pre_e中*/
Status Prior_Elem(SqList L, Elem_Type cur_e, Elem_Type* pre_e);

/*将顺序表中cur_e的后继元素放到next_e中*/
Status Next_Elem(SqList L, Elem_Type cur_e, Elem_Type* next_e);

/*在顺序表的第i个位置插入e*/
Status List_Insert(SqList* L, int i, Elem_Type e);

/*在顺序表的第i个位置删除元素并存到e中*/
Status List_Delete(SqList *L, int i, Elem_Type* e);

/*打印显示顺序表*/
Status List_Visit(SqList L);


#endif
