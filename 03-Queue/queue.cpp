#include "queue.hpp"
#include<malloc.h>
#include<cstdio>

QUEUE::QUEUE(int m):elems(new int[m]), max(m)						//��ʼ�����У����m��Ԫ��
{
    
}

QUEUE::QUEUE(const QUEUE &s):elems(new int[s.max]), max(s.max) 			//�ö���s������ʼ������
{
    
}

operator QUEUE::int ( ) const			//���ض��е�ʵ��Ԫ�ظ���
{
    
}

QUEUE &QUEUE::operator <<(int e) 	//��e�����,�����ض���
{
    
}

QUEUE &QUEUE::operator >>(int &e)	//�����е�e,�����ض���
{
    
}

QUEUE &QUEUE::operator =(const QUEUE &s) //��s������,�����ر���ֵ�Ķ���
{
    
}

void QUEUE::print( ) const			//��ӡ����
{
    
}

QUEUE::~QUEUE( )					//���ٶ���
{
    
}

