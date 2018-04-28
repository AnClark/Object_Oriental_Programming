class MAT{
    int *const e;	//指向所有整型矩阵元素的指针
    const int r, c;	//矩阵的行r和列c大小
public:
    MAT(int r, int c);      // 初始化空矩阵 
    MAT(const MAT &a);      // 用现有矩阵初始化新矩阵 
    virtual ~MAT( );        // 销毁矩阵 
    virtual int *const operator[](int r);				//取矩阵r行的第1个个元素地址
    virtual MAT operator+(const MAT& a) const;	//矩阵加法
    virtual MAT operator-(const MAT& a) const;	//矩阵减法
    virtual MAT operator*(const MAT& a) const;	//矩阵乘法
    virtual MAT operator~()const;				//矩阵转置
    virtual MAT& operator=(const MAT &a);		//赋值运算
    virtual MAT& operator+=(const MAT& a);		//+=运算
    virtual MAT& operator-=(const MAT& a);		//-=运算
    virtual MAT& operator*=(const MAT& a);		//*=运算
    virtual void print( )const;					//打印矩阵的r行、c列元素
};

