class MAT{
    int *const e;	//ָ���������;���Ԫ�ص�ָ��
    const int r, c;	//�������r����c��С
public:
    MAT(int r, int c);      // ��ʼ���վ��� 
    MAT(const MAT &a);      // �����о����ʼ���¾��� 
    virtual ~MAT( );        // ���پ��� 
    virtual int *const operator[](int r);				//ȡ����r�еĵ�1����Ԫ�ص�ַ
    virtual MAT operator+(const MAT& a) const;	//����ӷ�
    virtual MAT operator-(const MAT& a) const;	//�������
    virtual MAT operator*(const MAT& a) const;	//����˷�
    virtual MAT operator~()const;				//����ת��
    virtual MAT& operator=(const MAT &a);		//��ֵ����
    virtual MAT& operator+=(const MAT& a);		//+=����
    virtual MAT& operator-=(const MAT& a);		//-=����
    virtual MAT& operator*=(const MAT& a);		//*=����
    virtual void print( )const;					//��ӡ�����r�С�c��Ԫ��
};

