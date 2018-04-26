#include "queue.hpp"
#include<cstdio>

QUEUE::QUEUE(int m):elems(new int[m]), max(m)						//初始化队列：最多m个元素
{
    // 初始化队首队尾指针 
    head = tail = 0;
}

QUEUE::QUEUE(const QUEUE &s):elems(new int[s.max]), max(s.max) 			//用队列s拷贝初始化队列
{
    // 拷贝队列元素
    for(int i=0; i<max; i++)
        elems[i] = s.elems[i];
    
    // 拷贝队首队尾指针值 
    head = s.head;
    tail = s.tail;
}


QUEUE::operator int ( ) const			//返回队列的实际元素个数
{   
    // 分类讨论求元素个数 
    if(head < tail)
        return tail - head; 
    else if(head > tail)
        return (max - head) + tail;
        
    return 0;
}

QUEUE &QUEUE::operator <<(int e) 	//将e入队列,并返回队列
{
    // 操作的前提是：队列不满。所以队列满时直接给出错误提示并返回 
    if(isFull())
    {
        fprintf(stderr, "注意：队列已满，元素 %d 不能入队\n", e);
        return *this;
    }
    
    // 直接将e的值赋给队尾所在的位置——一个空余空间 
    elems[tail] = e;
    
    // 更新队尾指针 
    tail = (tail + 1) % max;
    
    return *this;
}

QUEUE &QUEUE::operator >>(int &e)	//出队列到e,并返回队列
{
    // 操作的前提是：队列不为空。所以队列为空时直接给出错误提示并返回 
    if(isEmpty())
    {
        fprintf(stderr, "注意：队列已为空，元素不能出队\n");
        return *this; 
    }
    
    // 提取队首的值，赋给e
    e = elems[head];
    
    // 更新队首指针
    head = (head + 1) % max; 
     
    
    return *this;
}
 
QUEUE &QUEUE::operator =(const QUEUE &s) //赋s给队列,并返回被赋值的队列
{
    /** 说明：赋值后的队列将从数组第一项开始组织 **/
    int i,j;
    
    // 获取s的实际元素个数
    int s_size = (int) s;
    
    // 遍历s，提取s中的队列元素，赋到当前类的elems中
    for(i=s.head, j=0; i!=s.tail && j<max-1; i=(i+1)%s.max, j++)
    {
        elems[j] = s.elems[i];
    }
    
    // 设置队首队尾 
    head = 0;
    tail = j;
    
    return *this;
}

void QUEUE::print( ) const			//打印队列
{
    // 队列的范围：head和tail夹着的区域
    int i = head;
    
    while(i != tail)
    {
        printf("%d\t", elems[i]);
        i = (i + 1) % max;
    }
    printf("\n");
}

QUEUE::~QUEUE( )					//销毁队列
{
    delete[] elems;
}

