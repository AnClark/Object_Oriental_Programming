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
    
    // �������׶�β
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
    // ��ֵ��Ķ��н��������һ�ʼ��֯
    
    // ��ȡs��ʵ��Ԫ�ظ�������׼�����ݱ���s_elems 
    int s_size = (int) s;
    int *s_elems = new int[s_size]; 
     
    
    // ��s������Ԫ��һһ���ӣ����ݵ�����s_elems�� 
    int i, num;
    for(i=1; i<=s_size; i++)
    {
        s>>num;
        s_elems[i] = num;
    }
    
    // ��s_elems��ֵ����elems
    for(i=0; i<max && i<s_size; i++)
        elems[i] = s_elems[i];
    // ����head��tail
    head = 0; 
    tail = i;
    
    // ��ԭs
    for(i=0; i<s_size; i++)
        s<<s_elems[i];
    
    
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
    //delete elems;
}

