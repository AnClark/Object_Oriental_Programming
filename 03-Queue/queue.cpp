#include "queue.hpp"
#include<malloc.h>
#include<cstdio>

QUEUE::QUEUE(int m):elems(new int[m]), max(m)						//��ʼ�����У����m��Ԫ��
{
    
}

QUEUE::QUEUE(const QUEUE &s):elems(new int[s.max]), max(s.max) 			//�ö���s������ʼ������
{
    
}

virtual operator QUEUE::int ( ) const			//���ض��е�ʵ��Ԫ�ظ���
{
    
}

virtual QUEUE &operator QUEUE::<<(int e) 	//��e�����,�����ض���
{
    
}

virtual QUEUE &operator QUEUE::>>(int &e)	//�����е�e,�����ض���
{
    
}

virtual QUEUE &operator QUEUE::=(const QUEUE &s) //��s������,�����ر���ֵ�Ķ���
{
    
}

virtual void QUEUE::print( ) const			//��ӡ����
{
    
}

virtual QUEUE::~QUEUE( )					//���ٶ���
{
    
}

