#include "LinkList.h"


/*
初始化一个头结点
注意思考形参形参要用 LinkList*  
(*L)是代表的地址next，不加*也是地址只是改变不了值 
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
销毁链表
释放链表所占内存，并清理头结点 
这里的 LinkList之所以要带* 就是因为需要改变 next里面的值 
*/
Status DestroyList(LinkList* L)
{
	LinkList p;
	
	/*确保链表结构存在*/
	if(*L == NULL)
		return FALSE;
	
	/*从头结点开始*/
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
置空（内容）
需要释放链表中非头结点处的空间 
*/
Status ClearList(LinkList L)
{
	LinkList pre, p;
	
	/*确保链表存在*/
	if(L == NULL)
		return FALSE;
	
	//从第一个结点开始 
	p = L->next;
	
	/*释放链表上所有结点所占内存*/
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
判断链表是否为空 
*/
Status ListEmpty(LinkList L)
{
	/*链表只有头结点时，认为该链表为空*/
	if(L->next == NULL)
		return OK;
	else
		return FALSE; 
} 


/*
计数
返回链表包含的有效元素个数 
*/
int ListLength(LinkList L)
{
	LinkList p;
	int i;
	
	/*确保链表存在*/
	if(L == NULL)
		return 0;
		
	i = 0;
	p = L->next;
	
	/*遍历所有结点*/
	while(p != NULL)
	{
		i++;
		p = p->next;
	} 
	
	return i;
}


/*
取值 
*/
Status GetElem(LinkList L, int i, ElemType* e)
{
	LinkList p;
	int j;
	
	/*确保链表存在且不为空表*/
	if(L == NULL || L->next ==NULL)
		return FALSE;
		
	p = L;
	j = 0;
	
	 /*寻找第i-1个结点，且保证该结点的后继不为NULL*/
	 while(p->next != NULL && j < i - 1)
	 {
	 	p = p->next;
	 	++j;
	 }
	 
	 /*如果遍历到头了，或者i的值不合规(比如i<=0)，说明没找到合乎目标的结点*/
	 if(p->next == NULL || j > i - 1)
	 	return FALSE;
	 	
	*e = p->next->data;
	 
	return OK;
}


/*
查找 
返回链表中首个与e满足Compare关系的元素位序。
如果不存在这样的元素，则返回0。
*/
int LocateElem(LinkList L, ElemType e)
{
	int i;
	LinkList p;
	
	/*确保链表存在且不为空表*/
	if(L == NULL || L->next ==NULL)
		return FALSE;
		
	i = 1;			// i的初值为第1个元素的位序
	p = L->next;	// p的初值为第1个元素的指针
	
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
前驱 
*/
Status PriorElem(LinkList L, ElemType cur_e, ElemType* pre_e)
{
	LinkList pre, next;
	
	/*确保链表存在且不为空表*/
	if(L == NULL || L->next ==NULL)
		return FALSE;
		
	/*指向第一个元素*/
	pre = L->next;
	
	/*第一个元素没有前驱*/ 
	if(pre->data == cur_e)
		return FALSE; 
	
	/*指向第二个元素*/
	next = pre->next;
	
	/*从第2个元素开始，查找cur_e的位置*/ 
	while(next != NULL && next->data != cur_e)
	{
		pre = next;
		next = next->next;
	}
	
	/*如果没找到元素cur_e，查找失败，返回ERROR*/
	if(next == NULL)
		return FALSE;
		
	*pre_e = pre->data;
	
	return OK;
}


/*
后继
*/
Status NextElem(LinkList L, ElemType cur_e, ElemType* next_e)
{
	LinkList pre;
	
	/*确保链表存在且不为空表*/
	if(L == NULL || L->next ==NULL)
		return FALSE;
		
	/*指向第一个元素*/
	pre = L->next;
	
	/*从第1个元素开始，查找cur_e的位置，且保证该结点的后继不为NULL*/
	while(pre->next != NULL && pre->data != cur_e)
		pre = pre->next;
		
	/*如果没找到cur_e，或者找到了，但它没有后继，均返回ERROR*/
	if(pre->next == NULL)
		return FALSE;
	
	*next_e = pre->next->data;
	
	return OK;
}


/*
插入 
*/
Status ListInsert(LinkList L, int i, ElemType e)
{
	LinkList p, s;
	int j;
	
	/*确保链表存在*/
	if(L == NULL)
		return FALSE;
	
	p = L;
	j = 0;
	
	/*寻找第i-1个结点，且保证该结点本身不为NULL*/
	while(p != NULL && j < i - 1)
	{
		p = p->next;
		++j;
	}
	
	/*生成新结点*/
	s = (LinkList) malloc(sizeof(LNode));
	if(s == NULL)
		exit(1);
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	return OK;
} 


/*
删除 
*/
Status ListDelete(LinkList L, int i, ElemType* e)
{
	LinkList p, q;
	int j;
	
	/*确保链表存在且不为空表*/
	if(L == NULL || L->next ==NULL)
		return FALSE;
		
	p = L;
	j = 0;
	
	/*寻找第i-1个结点，且保证该结点的后继不为NULL*/
	while(p->next != NULL && j < i - 1)
	{
		p = p->next;
		++j;
	}
	
	/*如果遍历到头了，或者i的值不合规(比如i<=0)，说明没找到合乎目标的结点*/
	if(p->next ==NULL || j > i - 1)
		return FALSE;
	
	/*删除第i个结点*/
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	
	return OK;
}


/*打印查看*/
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
	
	/*这里是不是应该打印最后一个元素*/
	printf("%d\r\n", p->data);
	
	return OK;	
} 








