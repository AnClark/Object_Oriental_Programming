#include "stack.hpp"
#include<cstdio>
#include<malloc.h>

STACK::STACK(int m):max(m), elems(new int[m])				//��ʼ��ջ�����m��Ԫ��
{   
    // ��ʼ��posֵ
    pos = 0;
}

STACK::STACK(const STACK &s):max(s.max), elems(new int[s.max]) 	//��ջs������ʼ��ջ
{
    // ����posֵ
    pos = s.pos;
    
    // ����ջ�ĳ�Ա
    for(int i=0; i<pos; i++)
        elems[i] = s.elems[i]; 
    
}

int  STACK::size() const				//����ջ�����Ԫ�ظ���max
{
    return max;
}

int  STACK::howMany ( ) const		//����ջ��ʵ��Ԫ�ظ���pos
{
    return pos;
}

int  STACK::getelem (int x) const	//ȡ�±�x����ջԪ��
{
    if(x>=0 && x<pos)
        return elems[x];
    
    return -1;
}

STACK &STACK::push(int e) 		//��e��ջ,������ջ
{
    // ��ջ��ǰ���ǣ�û��Խ��
    if(pos < max)
    {
        elems[pos++] = e;
    } 
    
    return *this;
}

STACK &STACK::pop(int &e) 		//��ջ��e,������ջ
{
    // ��ջ��ǰ���ǣ�ջ����Ԫ��
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

STACK &STACK::assign(const STACK &s) //��s��ջ,�����ر���ֵ��ջ
{
    delete elems;
    realloc(elems, s.size() * sizeof(int));
    
    // TODO: ��ʵ�� 
    
    return *this;
}

void STACK::print( ) const			//��ӡջ
{
    for(int i=0; i<pos; i++)
        printf("%d\t", elems[i]);
}

STACK::~STACK( )					//����ջ
{
    delete elems;
}


