#include "queue.hpp"
#include<cstdio>

QUEUE::QUEUE(int m):elems(new int[m]), max(m)						//��ʼ�����У����m��Ԫ��
{
    // ��ʼ�����׶�βָ�� 
    head = tail = 0;
}

QUEUE::QUEUE(const QUEUE &s):elems(new int[s.max]), max(s.max) 			//�ö���s������ʼ������
{
    // ��������Ԫ��
    for(int i=0; i<max; i++)
        elems[i] = s.elems[i];
    
    // �������׶�βָ��ֵ 
    head = s.head;
    tail = s.tail;
}


QUEUE::operator int ( ) const			//���ض��е�ʵ��Ԫ�ظ���
{   
    // ����������Ԫ�ظ��� 
    if(head < tail)
        return tail - head; 
    else if(head > tail)
        return (max - head) + tail;
        
    return 0;
}

QUEUE &QUEUE::operator <<(int e) 	//��e�����,�����ض���
{
    // ������ǰ���ǣ����в��������Զ�����ʱֱ�Ӹ���������ʾ������ 
    if(isFull())
    {
        fprintf(stderr, "ע�⣺����������Ԫ�� %d �������\n", e);
        return *this;
    }
    
    // ֱ�ӽ�e��ֵ������β���ڵ�λ�á���һ������ռ� 
    elems[tail] = e;
    
    // ���¶�βָ�� 
    tail = (tail + 1) % max;
    
    return *this;
}

QUEUE &QUEUE::operator >>(int &e)	//�����е�e,�����ض���
{
    // ������ǰ���ǣ����в�Ϊ�ա����Զ���Ϊ��ʱֱ�Ӹ���������ʾ������ 
    if(isEmpty())
    {
        fprintf(stderr, "ע�⣺������Ϊ�գ�Ԫ�ز��ܳ���\n");
        return *this; 
    }
    
    // ��ȡ���׵�ֵ������e
    e = elems[head];
    
    // ���¶���ָ��
    head = (head + 1) % max; 
     
    
    return *this;
}
 
QUEUE &QUEUE::operator =(const QUEUE &s) //��s������,�����ر���ֵ�Ķ���
{
    /** ˵������ֵ��Ķ��н��������һ�ʼ��֯ **/
    int i,j;
    
    // ��ȡs��ʵ��Ԫ�ظ���
    int s_size = (int) s;
    
    // ����s����ȡs�еĶ���Ԫ�أ�������ǰ���elems��
    for(i=s.head, j=0; i!=s.tail && j<max-1; i=(i+1)%s.max, j++)
    {
        elems[j] = s.elems[i];
    }
    
    // ���ö��׶�β 
    head = 0;
    tail = j;
    
    return *this;
}

void QUEUE::print( ) const			//��ӡ����
{
    // ���еķ�Χ��head��tail���ŵ�����
    int i = head;
    
    while(i != tail)
    {
        printf("%d\t", elems[i]);
        i = (i + 1) % max;
    }
    printf("\n");
}

QUEUE::~QUEUE( )					//���ٶ���
{
    delete[] elems;
}

