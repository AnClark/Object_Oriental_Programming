#include "matrix.hpp"
#include<cstdio>
#include<malloc.h>

MAT::MAT(int r, int c):r(r), c(c), e(new int[r * c])            // 初始化空矩阵 
{
    
}

MAT::MAT(const MAT &a):r(a.r), c(a.c), e(new int[a.r * a.c])    // 用现有矩阵初始化新矩阵 
{
    // 拷贝矩阵的内容
    for(int i=0; i<a.r * a.c; i++)
        e[i] = a.e[i]; 
}
    
MAT::~MAT( )        // 销毁矩阵 
{
    delete e; 
}
    
int *const MAT::operator[](int r)				//取矩阵r行的第1个元素地址
{
    if(r < 0 || r >= MAT::r)
    {
        fprintf(stderr, "错误：当前输入的行数 %d 已越界\n", r);
        return 0;
    }
    
    return e + (r * MAT::c);
}

MAT MAT::operator+(const MAT& a) const	//矩阵加法
{
    if(r != a.r  &&  c != a.c)
    {
        fprintf(stderr, "错误：两矩阵不同型，无法进行加法运算\n");
        return MAT(r, c);
    }
    
    MAT m(r, c);
            
    for(int i=0; i<r*c; i++)
        m.e[i] = MAT::e[i] + a.e[i];
        
            
    return m;
}

MAT MAT::operator-(const MAT& a) const	//矩阵减法
{
    if(r != a.r  &&  c != a.c)
    {
        fprintf(stderr, "错误：两矩阵不同型，无法进行减法运算\n");
        return MAT(r, c);
    }
    
    MAT m(r, c);
            
    for(int i=0; i<r*c; i++)
        m.e[i] = MAT::e[i] - a.e[i];
        
            
    return m;
}

MAT MAT::operator*(const MAT& a) const	//矩阵乘法
{
    
    // 矩阵乘法成立前提：左矩阵的列数 = 右矩阵的行数
    if(MAT::c != a.r)
    {
        fprintf(stderr, "错误：矩阵不满足乘法运算性质，无法进行乘法运算\n");
        return MAT(r, c);
    } 
    
    // 建立新矩阵，行数与左矩阵相同，列数与右矩阵相同
    MAT m(MAT::r, a.c);
    
    // 新矩阵第i行j列的元素，由左矩阵的第i行元素与右矩阵的第j列元素对应相乘，再取乘积之和 
    int i, j, k, v1, v2;
    
    
    for(i=0; i<m.r; i++)        // 遍历到新矩阵第i行 
    {  
        for(j=0; j<m.c; j++)    // 遍历到新矩阵第j列 
        {
            int item_sum = 0;
            for(k=0; k<MAT::c; k++)     
            {
                // 找出左矩阵第i行中的对应元素 
                v1 = MAT::e[i * c + k];
                
                // 找出右矩阵第j列中的对应元素 
                v2 = a.e[k * c + j];
                
                // 两者相乘，加和
                item_sum += v1 * v2; 
            }
            
            // 将结果赋到矩阵的对应位置中
            m.e[i * m.c + j] = item_sum;
        }
    }
    
    return m;
}

MAT MAT::operator~()const				//矩阵转置
{
    // 建立新矩阵，行数为源矩阵的列数，列数为源矩阵的行数
    MAT m(c, r);
    
    // 将源矩阵的行赋给新矩阵的列
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            m.e[j * r + i] = e[i * c + j];
        }
    }
    
    return m;
}

MAT& MAT::operator=(const MAT &a)		//赋值运算
{
    // 如果当前矩阵与源矩阵规模不匹配，则报错
    if(a.r != r && a.c != c)
    {
        fprintf(stderr, "错误：矩阵规模不匹配，无法进行赋值\n");
        return *this;    
    } 
    
    // 将源矩阵的元素赋给被赋值矩阵
    for(int i=0; i<r*c; i++)
        e[i] = a.e[i]; 
    
    
    return *this; 
}

MAT& MAT::operator+=(const MAT& a)		//+=运算
{
    if(r != a.r  &&  c != a.c)
    {
        fprintf(stderr, "错误：两矩阵不同型，无法进行加法运算\n");
        return *this;
    }
            
    for(int i=0; i<r*c; i++)
        e[i] += a.e[i];
        
            
    return *this;
}

MAT& MAT::operator-=(const MAT& a)		//-=运算
{
    if(r != a.r  &&  c != a.c)
    {
        fprintf(stderr, "错误：两矩阵不同型，无法进行减法运算\n");
        return *this;
    }
            
    for(int i=0; i<r*c; i++)
        e[i] -= a.e[i];
        
            
    return *this;
}

MAT& MAT::operator*=(const MAT& a)		//*=运算
{
    // 矩阵乘法成立前提：左矩阵的列数 = 右矩阵的行数
    if(MAT::c != a.r)
    {
        fprintf(stderr, "错误：矩阵不满足乘法运算性质，无法进行乘法运算\n");
        return *this;
    } 
    
    
    // 建立新矩阵，行数与左矩阵相同，列数与右矩阵相同
    MAT m(MAT::r, a.c);
    
    // 新矩阵第i行j列的元素，由左矩阵的第i行元素与右矩阵的第j列元素对应相乘，再取乘积之和 
    int i, j, k, v1, v2;
    
    
    for(i=0; i<m.r; i++)        // 遍历到新矩阵第i行 
    {  
        for(j=0; j<m.c; j++)    // 遍历到新矩阵第j列 
        {
            int item_sum = 0;
            for(k=0; k<MAT::c; k++)     
            {
                // 找出左矩阵第i行中的对应元素 
                v1 = MAT::e[i * c + k];
                
                // 找出右矩阵第j列中的对应元素 
                v2 = a.e[k * c + j];
                
                // 两者相乘，加和
                item_sum += v1 * v2; 
            }
            
            // 将结果赋到矩阵的对应位置中
            m.e[i * m.c + j] = item_sum;
        }
    }
    
    *this = m;
    return *this;
}

void MAT::print( )const					//打印矩阵的r行、c列元素
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

