#include "matrix.hpp"
#include<cstdio>
#include<malloc.h>

MAT::MAT(int r, int c):r(r), c(c), e(new int[r * c])            // ��ʼ���վ��� 
{
    
}

MAT::MAT(const MAT &a):r(a.r), c(a.c), e(new int[a.r * a.c])    // �����о����ʼ���¾��� 
{
    // �������������
    for(int i=0; i<a.r * a.c; i++)
        e[i] = a.e[i]; 
}
    
MAT::~MAT( )        // ���پ��� 
{
    delete e; 
}
    
int *const MAT::operator[](int r)				//ȡ����r�еĵ�1��Ԫ�ص�ַ
{
    if(r < 0 || r >= MAT::r)
    {
        fprintf(stderr, "���󣺵�ǰ��������� %d ��Խ��\n", r);
        return 0;
    }
    
    return e + (r * MAT::c);
}

MAT MAT::operator+(const MAT& a) const	//����ӷ�
{
    if(r != a.r  &&  c != a.c)
    {
        fprintf(stderr, "����������ͬ�ͣ��޷����мӷ�����\n");
        return MAT(r, c);
    }
    
    MAT m(r, c);
            
    for(int i=0; i<r*c; i++)
        m.e[i] = MAT::e[i] + a.e[i];
        
            
    return m;
}

MAT MAT::operator-(const MAT& a) const	//�������
{
    if(r != a.r  &&  c != a.c)
    {
        fprintf(stderr, "����������ͬ�ͣ��޷����м�������\n");
        return MAT(r, c);
    }
    
    MAT m(r, c);
            
    for(int i=0; i<r*c; i++)
        m.e[i] = MAT::e[i] - a.e[i];
        
            
    return m;
}

MAT MAT::operator*(const MAT& a) const	//����˷�
{
    
    // ����˷�����ǰ�᣺���������� = �Ҿ��������
    if(MAT::c != a.r)
    {
        fprintf(stderr, "���󣺾�������˷��������ʣ��޷����г˷�����\n");
        return MAT(r, c);
    } 
    
    // �����¾����������������ͬ���������Ҿ�����ͬ
    MAT m(MAT::r, a.c);
    
    // �¾����i��j�е�Ԫ�أ��������ĵ�i��Ԫ�����Ҿ���ĵ�j��Ԫ�ض�Ӧ��ˣ���ȡ�˻�֮�� 
    int i, j, k, v1, v2;
    
    
    for(i=0; i<m.r; i++)        // �������¾����i�� 
    {  
        for(j=0; j<m.c; j++)    // �������¾����j�� 
        {
            int item_sum = 0;
            for(k=0; k<MAT::c; k++)     
            {
                // �ҳ�������i���еĶ�ӦԪ�� 
                v1 = MAT::e[i * c + k];
                
                // �ҳ��Ҿ����j���еĶ�ӦԪ�� 
                v2 = a.e[k * c + j];
                
                // ������ˣ��Ӻ�
                item_sum += v1 * v2; 
            }
            
            // �������������Ķ�Ӧλ����
            m.e[i * m.c + j] = item_sum;
        }
    }
    
    return m;
}

MAT MAT::operator~()const				//����ת��
{
    // �����¾�������ΪԴ���������������ΪԴ���������
    MAT m(c, r);
    
    // ��Դ������и����¾������
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            m.e[j * r + i] = e[i * c + j];
        }
    }
    
    return m;
}

MAT& MAT::operator=(const MAT &a)		//��ֵ����
{
    // �����ǰ������Դ�����ģ��ƥ�䣬�򱨴�
    if(a.r != r && a.c != c)
    {
        fprintf(stderr, "���󣺾����ģ��ƥ�䣬�޷����и�ֵ\n");
        return *this;    
    } 
    
    // ��Դ�����Ԫ�ظ�������ֵ����
    for(int i=0; i<r*c; i++)
        e[i] = a.e[i]; 
    
    
    return *this; 
}

MAT& MAT::operator+=(const MAT& a)		//+=����
{
    if(r != a.r  &&  c != a.c)
    {
        fprintf(stderr, "����������ͬ�ͣ��޷����мӷ�����\n");
        return *this;
    }
            
    for(int i=0; i<r*c; i++)
        e[i] += a.e[i];
        
            
    return *this;
}

MAT& MAT::operator-=(const MAT& a)		//-=����
{
    if(r != a.r  &&  c != a.c)
    {
        fprintf(stderr, "����������ͬ�ͣ��޷����м�������\n");
        return *this;
    }
            
    for(int i=0; i<r*c; i++)
        e[i] -= a.e[i];
        
            
    return *this;
}

MAT& MAT::operator*=(const MAT& a)		//*=����
{
    // ����˷�����ǰ�᣺���������� = �Ҿ��������
    if(MAT::c != a.r)
    {
        fprintf(stderr, "���󣺾�������˷��������ʣ��޷����г˷�����\n");
        return *this;
    } 
    
    
    // �����¾����������������ͬ���������Ҿ�����ͬ
    MAT m(MAT::r, a.c);
    
    // �¾����i��j�е�Ԫ�أ��������ĵ�i��Ԫ�����Ҿ���ĵ�j��Ԫ�ض�Ӧ��ˣ���ȡ�˻�֮�� 
    int i, j, k, v1, v2;
    
    
    for(i=0; i<m.r; i++)        // �������¾����i�� 
    {  
        for(j=0; j<m.c; j++)    // �������¾����j�� 
        {
            int item_sum = 0;
            for(k=0; k<MAT::c; k++)     
            {
                // �ҳ�������i���еĶ�ӦԪ�� 
                v1 = MAT::e[i * c + k];
                
                // �ҳ��Ҿ����j���еĶ�ӦԪ�� 
                v2 = a.e[k * c + j];
                
                // ������ˣ��Ӻ�
                item_sum += v1 * v2; 
            }
            
            // �������������Ķ�Ӧλ����
            m.e[i * m.c + j] = item_sum;
        }
    }
    
    *this = m;
    return *this;
}

void MAT::print( )const					//��ӡ�����r�С�c��Ԫ��
{
    int i, j;
    for(i=0; i<r*c; i++)
    {
        if(i % c == 0 && i > 0)
            printf("\n");
        printf("%d\t", *(e+i));
    }
    
    printf("\n\n");
}

