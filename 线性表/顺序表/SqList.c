#include "SqList.h"

/*
��ʼ��˳���
Ϊ˳�������ڴ棬ע��(*L)��������� 
*/
Status SqList_Init(SqList *L)
{
	//�����ڴ� 
	(*L).elem = (Elem_Type*) malloc(LIST_INIT_SIZE * sizeof(Elem_Type));
	//���ָ��Ϊ�վʹ������ʧ�� 
	if((*L).elem == NULL)
	{
		#if	DEBUG_INFO
		printf("˳����ڴ��ʼ��ʧ�ܣ��쳣�˳�\r\n");
		#endif
		exit(OVERFLOW);
	}
	
	//��ʼ������Ϊ0 
	(*L).length = 0;
	//��ʼ��������Ϊ�����ڴ��С 
	(*L).listsize = LIST_INIT_SIZE;
	
	#if	DEBUG_INFO
	printf("˳����ڴ��ʼ���ɹ�\r\n");
	#endif
	
	return OK;
}


/*
����˳��� 
*/
Status SqList_Destroy(SqList *L)
{
	//ȷ�����Ա���� 
	if((*L).elem == NULL)
	{
		#if	DEBUG_INFO
		printf("˳������ڣ����ٳ��ִ���\r\n");
		#endif
		return FALSE;
	}
	
	//�ͷų�ʼ��������ڴ� 
	free((*L).elem);
	//�����Ⱥͱ��������� 
	(*L).length = 0;
	(*L).listsize = 0;
	
	#if	DEBUG_INFO
	printf("˳������ٳɹ�\r\n");
	#endif
	
	return OK;
}


/*
���˳����������ݣ�������ڴ� 
*/
Status List_Clear(SqList *L)
{
	if((*L).elem == NULL)
		return FALSE;
	
	//Ϊɶ�ѳ�������Ϳ����ˣ� 
	(*L).length = 0;
	
	#if	DEBUG_INFO
	printf("˳�������������ճɹ�\r\n");
	#endif
	
	return OK;
} 



/*
˳����п� 
���洫����βζ���ָ��������ΪҪ�ı�ʵ�ε�����
���ﴫ�������ͨ��������Ϊֻ���жϲ����ı�ԭʼ���� 
*/
Status List_Empty(SqList L)
{
	//��Ŀ���� 
	return L.length == 0 ? OK : FALSE; 
} 


/*
����������˳�������Ч����Ԫ�ظ��� 
*/
int List_Length(SqList L)
{
	return L.length;
} 



/*
��˳�����ȡ��һ��Ԫ��
 i�ǵڼ���λ�� ��e�����ȡ��ֵ 
*/
Status Get_Elem(SqList L, int i, Elem_Type* e)
{
	if(i < 1 || i > L.length)
	{
		#if DEBUG_INFO
		printf("ȡֵ��������\r\n");
		#endif
		
		return FALSE;
	}
	
	*e = L.elem[i-1];
	
	return OK;
}


/*
���� 
����˳����е�һ����e��ͬ��ֵ��λ��
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
ǰ��

*/
Status Prior_Elem(SqList L, Elem_Type cur_e, Elem_Type* pre_e)
{
	int i;
	
	//ȷ��˳���ṹ���ڣ������ٴ�������Ԫ�� 
	if(L.elem == NULL || L.length < 2)
		return FALSE;
	
	//��ʼ������ 
	i = 0;
	
	//�ӵ�һ��Ԫ�ؿ�ʼ�����ҵ�ǰԪ�ص����� 
	while(i < L.length && L.elem[i] != cur_e)
	{
		++i;
	} 
	
	//���cur_e���׸�Ԫ�ػ���û���ҵ�cur_e������FALSE 
	if(i == 0 || i >= L.length)
		return FALSE;
	
	*pre_e = L.elem[i-1];
	
	return OK;
}


/*
��� 
*/
Status Next_Elem(SqList L, Elem_Type cur_e, Elem_Type* next_e)
{
	int i;
	
	//ȷ��˳���ṹ���ڣ������ٴ�������Ԫ�� 
	if(L.elem == NULL || L.length < 2)
		return FALSE;
	
	//��ʼ������ 
	i = 0;
	
	//�ӵ�һ��Ԫ�ؿ�ʼ�����һ������Ҫ���ң������ҵ�ǰԪ�ص����� 
	while(i < L.length-1 && L.elem[i] != cur_e)
	{
		++i;
	} 
	
	//���cur_e�����Ԫ�ػ���û���ҵ�cur_e������FALSE 
	if(i >= L.length-1)
		return FALSE;
	
	*next_e = L.elem[i+1];
	
	return OK;
} 


/*
���� 
*/
Status List_Insert(SqList* L, int i, Elem_Type e)
{
	Elem_Type * newbase;
	Elem_Type *p, *q;
	
	if((*L).elem == NULL)
		return FALSE;
		
	//iֵԽ�磬���ܲ�������һ��λ��  1 1 1 ��x 
	if(i < 1 || i > (*L).length+1) 
		return FALSE;
	
	//���洢�ռ��������������¿ռ�
	if((*L).length >= (*L).listsize)
	{
		newbase = (Elem_Type*) realloc((*L).elem, ((*L).listsize + LIST_INCREMENT) * sizeof(Elem_Type));
		if(newbase == NULL)
			exit(OVERFLOW);
		
		//�µĻ���ַ
		(*L).elem = newbase;
		
		//�µĴ洢�ռ�
		(*L).listsize += LIST_INCREMENT;
	}
	
	//qΪ������Ԫ��λ��
	q = &(*L).elem[i-1];
	
	//����Ԫ�أ��ڳ�λ��
	for(p = &(*L).elem[(*L).length-1]; p >= q; p--)
	{
		*(p + 1) = *p;
	} 
	
	//����e
	*q = e;
	
	//������
	(*L).length++;
	
	return OK; 
} 



/*
ɾ�� 
����ɾ���ĵ�i��Ԫ�ش洢��e��
*/
Status List_Delete(SqList* L, int i, Elem_Type* e) 
{
	Elem_Type *p, *q; 
	
	if((*L).elem == NULL)
		return FALSE;
		
	//iֵԽ��
	if(i < 1 || i > (*L).length) 
		return FALSE;
		
	//pΪ��ɾ��Ԫ�ص�λ��
	p = &(*L).elem[i-1];
	
	//��ȡ��ɾ��Ԫ��
	*e = *p;
	
	//��βԪ��λ�ã�����ַ+����-1����0��ʼ�� 
	q = (*L).elem + (*L).length - 1; 
	
	//����Ԫ�ز��룬ÿ��ѭ�����׵�ַ��� 
	for(++p; p<=q; ++p)
	{
		*(p -1) = *p;
	} 
	
	//��-1
	(*L).length--;
	
	return OK; 
}


/*
��ӡ��ʾ˳��� 
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
