#include "stack.h"
#include<malloc.h>
#include<stdio.h>

void initSTACK(STACK *const p, int m)	//初始化p指向的空栈：最多m个元素
{
    // 分配内存空间
    p->elems = (int*) malloc(m * sizeof(int));
     
    // 设置栈的元素上限 
    p->max = m;
    
    // 初始化栈的已有元素数
    p->pos = 0;
}

void initSTACK(STACK *const p, const STACK &s) //用栈s初始化p指向的空栈
{
    // 给新栈p分配内存空间
    p->elems = (int*) malloc(s.max * sizeof(int));
    
    // 将s的元素复制到p中
    int i;
    for(i=0; i<s.pos; i++)
        p->elems[i] = s.elems[i];
    
    // 设置p的元素上限
    p->max = s.max;
    
    // 设置p的已有元素数 
    p->pos = s.pos;
    
    
}


int  size (const STACK *const p)		//返回p指向的栈的最大元素个数max
{
    return p->max;  
}
 
int  howMany (const STACK *const p)	//返回p指向的栈的实际元素个数pos
{
    return p->pos;    
}

int  getelem (const STACK *const p, int x)	//取下标x处的栈元素
{
    if(x>=0 && x<p->pos)
        return p->elems[x];
    
    return -1;
}

STACK *const push(STACK *const p, int e) 	//将e入栈，并返回p
{
    // 将e加入栈中，并更新pos值
    // 前提是没有越界 
    if(p->pos < p->max)
    {
        p->elems[p->pos] = e;
        p->pos++; 
    }
    
    // 返回p    
    return p; 
}

STACK *const pop(STACK *const p, int &e) 	//出栈到e，并返回p
{
    // 以下的前提都是没有越界 
    if(p->pos > 0)
    {
        // 获取栈顶的值，输送到e
        e = p->elems[p->pos-1];
        
        // 将栈顶移除，并更新pos值
        p->elems[p->pos-1] = 0;
        p->pos--;
    }
    else
        e = -1;
     
    // 返回p 
    return p;
}

STACK *const assign(STACK *const p, const STACK &s) //赋s给p指的栈,并返回p
{
    // 先清除p所指的栈
    p-> 
    
}

void print(const STACK *const p)			//打印p指向的栈
{
    int i;
    for(i=0; i<p->pos; i++)
        printf("%d\t", p->elems[i]);
    printf("\n");    
    
}

void destroySTACK(STACK *const p)		//销毁p指向的栈
{
    free(p->elems);
    p->pos = 0;
    p->max = 0;    
    
}

