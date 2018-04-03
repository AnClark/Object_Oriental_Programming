#include "queue.hpp"
#include<malloc.h>
#include<cstdio>

QUEUE::QUEUE(int m):elems(new int[m]), max(m)						//初始化队列：最多m个元素
{
    
}

QUEUE::QUEUE(const QUEUE &s):elems(new int[s.max]), max(s.max) 			//用队列s拷贝初始化队列
{
    
}

operator QUEUE::int ( ) const			//返回队列的实际元素个数
{
    
}

QUEUE &QUEUE::operator <<(int e) 	//将e入队列,并返回队列
{
    
}

QUEUE &QUEUE::operator >>(int &e)	//出队列到e,并返回队列
{
    
}

QUEUE &QUEUE::operator =(const QUEUE &s) //赋s给队列,并返回被赋值的队列
{
    
}

void QUEUE::print( ) const			//打印队列
{
    
}

QUEUE::~QUEUE( )					//销毁队列
{
    
}

