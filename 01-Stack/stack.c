#include "stack.h"
#include<malloc.h>
#include<stdio.h>

void initSTACK(STACK *const p, int m)	//��ʼ��pָ��Ŀ�ջ�����m��Ԫ��
{
    // �����ڴ�ռ�
    p->elems = (int*) malloc(m * sizeof(int));
     
    // ����ջ��Ԫ������ 
    p->max = m;
    
    // ��ʼ��ջ������Ԫ����
    p->pos = 0;
}

void initSTACK(STACK *const p, const STACK &s) //��ջs��ʼ��pָ��Ŀ�ջ
{
    // ����ջp�����ڴ�ռ�
    p->elems = (int*) malloc(s.max * sizeof(int));
    
    // ��s��Ԫ�ظ��Ƶ�p��
    int i;
    for(i=0; i<s.pos; i++)
        p->elems[i] = s.elems[i];
    
    // ����p��Ԫ������
    p->max = s.max;
    
    // ����p������Ԫ���� 
    p->pos = s.pos;
    
    
}


int  size (const STACK *const p)		//����pָ���ջ�����Ԫ�ظ���max
{
    return p->max;  
}
 
int  howMany (const STACK *const p)	//����pָ���ջ��ʵ��Ԫ�ظ���pos
{
    return p->pos;    
}

int  getelem (const STACK *const p, int x)	//ȡ�±�x����ջԪ��
{
    if(x>=0 && x<p->pos)
        return p->elems[x];
    
    return -1;
}

STACK *const push(STACK *const p, int e) 	//��e��ջ��������p
{
    // ��e����ջ�У�������posֵ
    // ǰ����û��Խ�� 
    if(p->pos < p->max)
    {
        p->elems[p->pos] = e;
        p->pos++; 
    }
    
    // ����p    
    return p; 
}

STACK *const pop(STACK *const p, int &e) 	//��ջ��e��������p
{
    // ���µ�ǰ�ᶼ��û��Խ�� 
    if(p->pos > 0)
    {
        // ��ȡջ����ֵ�����͵�e
        e = p->elems[p->pos-1];
        
        // ��ջ���Ƴ���������posֵ
        p->elems[p->pos-1] = 0;
        p->pos--;
    }
    else
        e = -1;
     
    // ����p 
    return p;
}

STACK *const assign(STACK *const p, const STACK &s) //��s��pָ��ջ,������p
{
    // �����p��ָ��ջ
    free(p->elems);
	p->pos = 0;
    p->max = 0; 
    
    // ����ջp�����ڴ�ռ�
    p->elems = (int*) malloc(s.max * sizeof(int));
    
    // ��s��Ԫ�ظ��Ƶ�p��
    int i;
    for(i=0; i<s.pos; i++)
        p->elems[i] = s.elems[i];
    
    // ����p��Ԫ������
    p->max = s.max;
    
    // ����p������Ԫ���� 
    p->pos = s.pos;
    
}

void print(const STACK *const p)			//��ӡpָ���ջ
{
    int i;
    for(i=0; i<p->pos; i++)
        printf("%d\t", p->elems[i]);
    printf("\n");    
    
}

void destroySTACK(STACK *const p)		//����pָ���ջ
{
    free(p->elems);
    p->pos = 0;
    p->max = 0;    
    
}

