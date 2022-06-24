#include "LinkList.h"


/*
��ʼ��һ��ͷ���
ע��˼���β��β�Ҫ�� LinkList*  
(*L)�Ǵ���ĵ�ַnext������*Ҳ�ǵ�ַֻ�Ǹı䲻��ֵ 
*/
Status InitList(LinkList* L)
{
	(*L) = (LinkList) malloc(sizeof(LNode));
	if(*L == NULL)
		exit(1);
	
	(*L)->next = NULL;
	
	return OK;
}


/*
��������
�ͷ�������ռ�ڴ棬������ͷ��� 
����� LinkList֮����Ҫ��* ������Ϊ��Ҫ�ı� next�����ֵ 
*/
Status DestroyList(LinkList* L)
{
	LinkList p;
	
	/*ȷ������ṹ����*/
	if(*L == NULL)
		return FALSE;
	
	/*��ͷ��㿪ʼ*/
	p = *L;
	
	while(p != NULL)
	{
		p = (*L)->next;
		free(*L);
		(*L) = p; 
	} 
	
	*L = NULL;
	
	return OK;
}


/*
�ÿգ����ݣ�
��Ҫ�ͷ������з�ͷ��㴦�Ŀռ� 
*/
Status ClearList(LinkList L)
{
	LinkList pre, p;
	
	/*ȷ���������*/
	if(L == NULL)
		return FALSE;
	
	//�ӵ�һ����㿪ʼ 
	p = L->next;
	
	/*�ͷ����������н����ռ�ڴ�*/
	while(p != NULL)
	{
		pre = p;
		p = p->next;
		free(pre);
	}
	
	L->next = NULL;
	
	return OK;
} 


/*
�ж������Ƿ�Ϊ�� 
*/
Status ListEmpty(LinkList L)
{
	/*����ֻ��ͷ���ʱ����Ϊ������Ϊ��*/
	if(L->next == NULL)
		return OK;
	else
		return FALSE; 
} 


/*
����
���������������ЧԪ�ظ��� 
*/
int ListLength(LinkList L)
{
	LinkList p;
	int i;
	
	/*ȷ���������*/
	if(L == NULL)
		return 0;
		
	i = 0;
	p = L->next;
	
	/*�������н��*/
	while(p != NULL)
	{
		i++;
		p = p->next;
	} 
	
	return i;
}


/*
ȡֵ 
*/
Status GetElem(LinkList L, int i, ElemType* e)
{
	LinkList p;
	int j;
	
	/*ȷ����������Ҳ�Ϊ�ձ�*/
	if(L == NULL || L->next ==NULL)
		return FALSE;
		
	p = L;
	j = 0;
	
	 /*Ѱ�ҵ�i-1����㣬�ұ�֤�ý��ĺ�̲�ΪNULL*/
	 while(p->next != NULL && j < i - 1)
	 {
	 	p = p->next;
	 	++j;
	 }
	 
	 /*���������ͷ�ˣ�����i��ֵ���Ϲ�(����i<=0)��˵��û�ҵ��Ϻ�Ŀ��Ľ��*/
	 if(p->next == NULL || j > i - 1)
	 	return FALSE;
	 	
	*e = p->next->data;
	 
	return OK;
}


/*
���� 
�����������׸���e����Compare��ϵ��Ԫ��λ��
���������������Ԫ�أ��򷵻�0��
*/
int LocateElem(LinkList L, ElemType e)
{
	int i;
	LinkList p;
	
	/*ȷ����������Ҳ�Ϊ�ձ�*/
	if(L == NULL || L->next ==NULL)
		return FALSE;
		
	i = 1;			// i�ĳ�ֵΪ��1��Ԫ�ص�λ��
	p = L->next;	// p�ĳ�ֵΪ��1��Ԫ�ص�ָ��
	
	while(p != NULL && e != p->data)
	{
		i++;
		p = p->next;
	}
	
	if(p != NULL)
		return i;
	else
		return 0;
} 


/*
ǰ�� 
*/
Status PriorElem(LinkList L, ElemType cur_e, ElemType* pre_e)
{
	LinkList pre, next;
	
	/*ȷ����������Ҳ�Ϊ�ձ�*/
	if(L == NULL || L->next ==NULL)
		return FALSE;
		
	/*ָ���һ��Ԫ��*/
	pre = L->next;
	
	/*��һ��Ԫ��û��ǰ��*/ 
	if(pre->data == cur_e)
		return FALSE; 
	
	/*ָ��ڶ���Ԫ��*/
	next = pre->next;
	
	/*�ӵ�2��Ԫ�ؿ�ʼ������cur_e��λ��*/ 
	while(next != NULL && next->data != cur_e)
	{
		pre = next;
		next = next->next;
	}
	
	/*���û�ҵ�Ԫ��cur_e������ʧ�ܣ�����ERROR*/
	if(next == NULL)
		return FALSE;
		
	*pre_e = pre->data;
	
	return OK;
}


/*
���
*/
Status NextElem(LinkList L, ElemType cur_e, ElemType* next_e)
{
	LinkList pre;
	
	/*ȷ����������Ҳ�Ϊ�ձ�*/
	if(L == NULL || L->next ==NULL)
		return FALSE;
		
	/*ָ���һ��Ԫ��*/
	pre = L->next;
	
	/*�ӵ�1��Ԫ�ؿ�ʼ������cur_e��λ�ã��ұ�֤�ý��ĺ�̲�ΪNULL*/
	while(pre->next != NULL && pre->data != cur_e)
		pre = pre->next;
		
	/*���û�ҵ�cur_e�������ҵ��ˣ�����û�к�̣�������ERROR*/
	if(pre->next == NULL)
		return FALSE;
	
	*next_e = pre->next->data;
	
	return OK;
}


/*
���� 
*/
Status ListInsert(LinkList L, int i, ElemType e)
{
	LinkList p, s;
	int j;
	
	/*ȷ���������*/
	if(L == NULL)
		return FALSE;
	
	p = L;
	j = 0;
	
	/*Ѱ�ҵ�i-1����㣬�ұ�֤�ý�㱾��ΪNULL*/
	while(p != NULL && j < i - 1)
	{
		p = p->next;
		++j;
	}
	
	/*�����½��*/
	s = (LinkList) malloc(sizeof(LNode));
	if(s == NULL)
		exit(1);
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	return OK;
} 


/*
ɾ�� 
*/
Status ListDelete(LinkList L, int i, ElemType* e)
{
	LinkList p, q;
	int j;
	
	/*ȷ����������Ҳ�Ϊ�ձ�*/
	if(L == NULL || L->next ==NULL)
		return FALSE;
		
	p = L;
	j = 0;
	
	/*Ѱ�ҵ�i-1����㣬�ұ�֤�ý��ĺ�̲�ΪNULL*/
	while(p->next != NULL && j < i - 1)
	{
		p = p->next;
		++j;
	}
	
	/*���������ͷ�ˣ�����i��ֵ���Ϲ�(����i<=0)��˵��û�ҵ��Ϻ�Ŀ��Ľ��*/
	if(p->next ==NULL || j > i - 1)
		return FALSE;
	
	/*ɾ����i�����*/
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	
	return OK;
}


/*��ӡ�鿴*/
Status ListVisit(LinkList L)
{
	LinkList p;
	
	if(L->next ==NULL)
		return FALSE;
	
	p = L->next;
	
	while(p->next != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	
	/*�����ǲ���Ӧ�ô�ӡ���һ��Ԫ��*/
	printf("%d\r\n", p->data);
	
	return OK;	
} 








