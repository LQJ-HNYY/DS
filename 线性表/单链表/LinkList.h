#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <stdlib.h>
#include <stdio.h>

#define		OK		1	
#define		FALSE	0

/*������Ԫ�����Ͷ���*/
typedef int ElemType;
typedef char Status;

/*
������ṹ
������ĵ��������ͷ��㣩 
*/
typedef struct LNode
{
	ElemType data;			//���ݽ�� 
	/*������һ��Ƕ�׶���*/
	struct LNode* next;		//�ṹ��������ã��൱����LNodeһ���ṹ��ĵ�ַ 
}LNode; 

/*ָ���������ָ��*/
typedef LNode* LinkList; 

/*��ʼ������ͷ*/
Status InitList(LinkList* L); 

/*������������ڴ�*/
Status DestroyList(LinkList* L);

/*�����ÿ�*/
Status ClearList(LinkList L);

/*�ж������Ƿ�Ϊ��*/
Status ListEmpty(LinkList L);

/*����*/
int ListLength(LinkList L);

/*ȡֵ*/
Status GetElem(LinkList L, int i, ElemType* e); 

/*����*/
int LocateElem(LinkList L, ElemType e);

/*ǰ��*/
Status PriorElem(LinkList L, ElemType cur_e, ElemType* pre_e);

/*���*/
Status NextElem(LinkList L, ElemType cur_e, ElemType* next_e);

/*����*/
Status ListInsert(LinkList L, int i, ElemType e);

/*ɾ��*/
Status ListDelete(LinkList L, int i, ElemType* e); 

/*��ӡ�鿴*/
Status ListVisit(LinkList L);

#endif 
