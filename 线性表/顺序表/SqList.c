#include "SqList.h"

/*
初始化顺序表
为顺序表分配内存，注意(*L)必须带括号 
*/
Status SqList_Init(SqList *L)
{
	//分配内存 
	(*L).elem = (Elem_Type*) malloc(LIST_INIT_SIZE * sizeof(Elem_Type));
	//如果指针为空就代表分配失败 
	if((*L).elem == NULL)
	{
		#if	DEBUG_INFO
		printf("顺序表内存初始化失败，异常退出\r\n");
		#endif
		exit(OVERFLOW);
	}
	
	//初始化表长度为0 
	(*L).length = 0;
	//初始化表容量为分配内存大小 
	(*L).listsize = LIST_INIT_SIZE;
	
	#if	DEBUG_INFO
	printf("顺序表内存初始化成功\r\n");
	#endif
	
	return OK;
}


/*
销毁顺序表 
*/
Status SqList_Destroy(SqList *L)
{
	//确认线性表存在 
	if((*L).elem == NULL)
	{
		#if	DEBUG_INFO
		printf("顺序表不存在，销毁出现错误\r\n");
		#endif
		return FALSE;
	}
	
	//释放初始化分配的内存 
	free((*L).elem);
	//将表长度和表容量清零 
	(*L).length = 0;
	(*L).listsize = 0;
	
	#if	DEBUG_INFO
	printf("顺序表销毁成功\r\n");
	#endif
	
	return OK;
}


/*
清空顺序表数据内容，不清空内存 
*/
Status List_Clear(SqList *L)
{
	if((*L).elem == NULL)
		return FALSE;
	
	//为啥把长度清零就可以了？ 
	(*L).length = 0;
	
	#if	DEBUG_INFO
	printf("顺序表数据内容清空成功\r\n");
	#endif
	
	return OK;
} 



/*
顺序表判空 
上面传入的形参都是指针型是因为要改变实参的内容
这里传入的是普通的类型因为只做判断不做改变原始内容 
*/
Status List_Empty(SqList L)
{
	//三目运算 
	return L.length == 0 ? OK : FALSE; 
} 


/*
计数：返回顺序表中有效数据元素个数 
*/
int List_Length(SqList L)
{
	return L.length;
} 



/*
从顺序表中取出一个元素
 i是第几个位置 ，e来存放取出值 
*/
Status Get_Elem(SqList L, int i, Elem_Type* e)
{
	if(i < 1 || i > L.length)
	{
		#if DEBUG_INFO
		printf("取值索引出错！\r\n");
		#endif
		
		return FALSE;
	}
	
	*e = L.elem[i-1];
	
	return OK;
}


/*
查找 
返回顺序表中第一个与e相同的值的位置
*/
int Locate_Elem(SqList L, Elem_Type e)
{
	int i;
	Elem_Type* p;
	
	if(L.elem == NULL)
		return FALSE;
	
	i = 1;
	p = L.elem;
	
	while(i <= L.length)
	{
		if(*(p++) == e)
			return i;
		++i;
	}
	
	return 0; 
}


/*
前驱

*/
Status Prior_Elem(SqList L, Elem_Type cur_e, Elem_Type* pre_e)
{
	int i;
	
	//确保顺序表结构存在，且至少存在两个元素 
	if(L.elem == NULL || L.length < 2)
		return FALSE;
	
	//初始化索引 
	i = 0;
	
	//从第一个元素开始，查找当前元素的索引 
	while(i < L.length && L.elem[i] != cur_e)
	{
		++i;
	} 
	
	//如果cur_e是首个元素或者没有找到cur_e，返回FALSE 
	if(i == 0 || i >= L.length)
		return FALSE;
	
	*pre_e = L.elem[i-1];
	
	return OK;
}


/*
后继 
*/
Status Next_Elem(SqList L, Elem_Type cur_e, Elem_Type* next_e)
{
	int i;
	
	//确保顺序表结构存在，且至少存在两个元素 
	if(L.elem == NULL || L.length < 2)
		return FALSE;
	
	//初始化索引 
	i = 0;
	
	//从第一个元素开始（最后一个不需要查找），查找当前元素的索引 
	while(i < L.length-1 && L.elem[i] != cur_e)
	{
		++i;
	} 
	
	//如果cur_e是最后元素或者没有找到cur_e，返回FALSE 
	if(i >= L.length-1)
		return FALSE;
	
	*next_e = L.elem[i+1];
	
	return OK;
} 


/*
插入 
*/
Status List_Insert(SqList* L, int i, Elem_Type e)
{
	Elem_Type * newbase;
	Elem_Type *p, *q;
	
	if((*L).elem == NULL)
		return FALSE;
		
	//i值越界，不能插在最后隔一个位置  1 1 1 √x 
	if(i < 1 || i > (*L).length+1) 
		return FALSE;
	
	//若存储空间已满，则增加新空间
	if((*L).length >= (*L).listsize)
	{
		newbase = (Elem_Type*) realloc((*L).elem, ((*L).listsize + LIST_INCREMENT) * sizeof(Elem_Type));
		if(newbase == NULL)
			exit(OVERFLOW);
		
		//新的基地址
		(*L).elem = newbase;
		
		//新的存储空间
		(*L).listsize += LIST_INCREMENT;
	}
	
	//q为被插入元素位置
	q = &(*L).elem[i-1];
	
	//右移元素，腾出位置
	for(p = &(*L).elem[(*L).length-1]; p >= q; p--)
	{
		*(p + 1) = *p;
	} 
	
	//插入e
	*q = e;
	
	//表长增加
	(*L).length++;
	
	return OK; 
} 



/*
删除 
将被删除的第i个元素存储到e中
*/
Status List_Delete(SqList* L, int i, Elem_Type* e) 
{
	Elem_Type *p, *q; 
	
	if((*L).elem == NULL)
		return FALSE;
		
	//i值越界
	if(i < 1 || i > (*L).length) 
		return FALSE;
		
	//p为被删除元素的位置
	p = &(*L).elem[i-1];
	
	//获取被删除元素
	*e = *p;
	
	//表尾元素位置，基地址+长度-1（从0开始） 
	q = (*L).elem + (*L).length - 1; 
	
	//左移元素补齐，每次循环的首地址会变 
	for(++p; p<=q; ++p)
	{
		*(p -1) = *p;
	} 
	
	//表长-1
	(*L).length--;
	
	return OK; 
}


/*
打印显示顺序表 
*/
Status List_Visit(SqList L)
{
	int i = 0;
	
	if(L.length == 0)
		return FALSE;

	for(i=0; i<L.length; i++)
		printf("%d\t", L.elem[i]);
	
	printf("\r\n");
}
