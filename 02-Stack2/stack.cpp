#include "stack.hpp"
#include<cstdio>
#include<malloc.h>

STACK::STACK(int m):max(m), elems(new int[m])				//��ʼ��ջ�����m��Ԫ��
{   
    // ��ʼ��posֵ
    STACK::pos = 0;
}

STACK::STACK(const STACK &s) 	//��ջs������ʼ��ջ
{
    
    
}

int  STACK::size() const				//����ջ�����Ԫ�ظ���max
{
    
}

int  STACK::howMany ( ) const		//����ջ��ʵ��Ԫ�ظ���pos
{
    
}

int  STACK::getelem (int x) const	//ȡ�±�x����ջԪ��
{
    
}

STACK &STACK::push(int e) 		//��e��ջ,������ջ
{
    
}

STACK &STACK::pop(int &e) 		//��ջ��e,������ջ
{
    
}

STACK &STACK::assign(const STACK &s) //��s��ջ,�����ر���ֵ��ջ
{
    
}

void STACK::print( ) const			//��ӡջ
{
    
}

STACK::~STACK( )					//����ջ
{
    
}


