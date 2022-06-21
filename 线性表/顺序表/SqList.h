#ifndef	__SQLIST_H
#define __SQLIST_H
#include <stdlib.h>
#include <stdio.h>


typedef		int		Elem_Type;

//˳���洢�ռ�ĳ�ʼ������
#define 	LIST_INIT_SIZE 	100
 //˳���洢�ռ�ķ�������
#define 	LIST_INCREMENT	10

#define 	Status			char		
#define 	OK				1
#define		FALSE			0
#define 	OVERFLOW		1
#define 	DEBUG_INFO		1


typedef struct
{
	//˳���洢�ռ�Ļ�ַ��ָ��˳�����ռ�ڴ����ʼλ�ã�
	Elem_Type *elem;
	//��ǰ˳����ȣ���������Ԫ�أ�
	int length;
	//��ǰ����Ĵ洢���������Դ洢����Ԫ�أ�
	int listsize;
}SqList;


/*��ʼ��˳���*/
Status SqList_Init(SqList *L);

/*����˳�������ڴ� */
Status SqList_Destroy(SqList *L); 

/*���˳���������ڴ�*/
Status List_Clear(SqList *L);

/*�ж�˳����Ƿ�Ϊ��*/
Status List_Empty(SqList L); 

/*����˳���Ԫ�ظ���*/
int List_Length(SqList L);

/*��ȡ˳����еĵ�i��Ԫ��ֵ�ŵ�e��*/
Status Get_Elem(SqList L, int i, Elem_Type* e); 

/*����˳����е�һ����e��ͬ��ֵ��λ��*/
int Locate_Elem(SqList L, Elem_Type e);

/*��˳�����cur_e��ǰ��Ԫ�طŵ�pre_e��*/
Status Prior_Elem(SqList L, Elem_Type cur_e, Elem_Type* pre_e);

/*��˳�����cur_e�ĺ��Ԫ�طŵ�next_e��*/
Status Next_Elem(SqList L, Elem_Type cur_e, Elem_Type* next_e);

/*��˳���ĵ�i��λ�ò���e*/
Status List_Insert(SqList* L, int i, Elem_Type e);

/*��˳���ĵ�i��λ��ɾ��Ԫ�ز��浽e��*/
Status List_Delete(SqList *L, int i, Elem_Type* e);

/*��ӡ��ʾ˳���*/
Status List_Visit(SqList L);


#endif
