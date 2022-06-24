#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <stdlib.h>
#include <stdio.h>

#define		OK		1	
#define		FALSE	0

/*单链表元素类型定义*/
typedef int ElemType;
typedef char Status;

/*
单链表结构
（这里的单链表存在头结点） 
*/
typedef struct LNode
{
	ElemType data;			//数据结点 
	/*这里是一个嵌套定义*/
	struct LNode* next;		//结构体的自引用，相当于与LNode一样结构体的地址 
}LNode; 

/*指向单链表结点的指针*/
typedef LNode* LinkList; 

/*初始化链表头*/
Status InitList(LinkList* L); 

/*销毁链表，清空内存*/
Status DestroyList(LinkList* L);

/*链表置空*/
Status ClearList(LinkList L);

/*判断链表是否为空*/
Status ListEmpty(LinkList L);

/*计数*/
int ListLength(LinkList L);

/*取值*/
Status GetElem(LinkList L, int i, ElemType* e); 

/*查找*/
int LocateElem(LinkList L, ElemType e);

/*前驱*/
Status PriorElem(LinkList L, ElemType cur_e, ElemType* pre_e);

/*后继*/
Status NextElem(LinkList L, ElemType cur_e, ElemType* next_e);

/*插入*/
Status ListInsert(LinkList L, int i, ElemType e);

/*删除*/
Status ListDelete(LinkList L, int i, ElemType* e); 

/*打印查看*/
Status ListVisit(LinkList L);

#endif 
