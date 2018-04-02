#include "stack.hpp"
#include<cstdio>
#include<malloc.h>

STACK::STACK(int m):max(m), elems(new int[m])				//初始化栈：最多m个元素
{   
    // 初始化pos值
    pos = 0;
}

STACK::STACK(const STACK &s):max(s.max), elems(new int[s.max]) 	//用栈s拷贝初始化栈
{
    // 设置pos值
    pos = s.pos;
    
    // 复制栈的成员
    for(int i=0; i<pos; i++)
        elems[i] = s.elems[i]; 
    
}

int  STACK::size() const				//返回栈的最大元素个数max
{
    return max;
}

int  STACK::howMany ( ) const		//返回栈的实际元素个数pos
{
    return pos;
}

int  STACK::getelem (int x) const	//取下标x处的栈元素
{
    if(x>=0 && x<pos)
        return elems[x];
    
    return -1;
}

STACK &STACK::push(int e) 		//将e入栈,并返回栈
{
    // 入栈的前提是：没有越界
    if(pos < max)
    {
        elems[pos++] = e;
    } 
    
    return *this;
}

STACK &STACK::pop(int &e) 		//出栈到e,并返回栈
{
    // 出栈的前提是：栈中有元素
    if(pos > 0)
    {
        e = elems[pos-1];
        elems[pos-1] = 0;
        pos--;
    } 
    else
        e = -1;
    
    return *this;
}

STACK &STACK::assign(const STACK &s) //赋s给栈,并返回被赋值的栈
{
    delete elems;
    realloc(elems, s.size() * sizeof(int));
    
    // TODO: 待实现 
    
    return *this;
}

void STACK::print( ) const			//打印栈
{
    for(int i=0; i<pos; i++)
        printf("%d\t", elems[i]);
}

STACK::~STACK( )					//销毁栈
{
    delete elems;
}


