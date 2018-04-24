// ʵ�ַ�����ѭ������
// �ο����ף�ѭ�����е�c����ʵ�� - CSDN����
// https://blog.csdn.net/silent123go/article/details/52643262 
/**
����Ҫ�أ�
    a�����г�ʼ��ʱ��front��rearֵ��Ϊ�㡣
    b��������Ϊ��ʱ��front��rear��ֵ��ȣ�����һ��Ϊ�㡣
    c�������в�Ϊ��ʱ��frontָ����еĵ�һ��Ԫ�أ�rearָ��������һ��Ԫ�ص���һ��λ�á�

���п��жϣ� 
    ��front��rear��ֵ��ȣ���һ��Ϊ�㣩�����Ϊ�ա�
�������жϣ�
    ����һ���洢�ռ䣬Ҳ������������һ�������ռ䲻�ã�����rear+1��%maxsiz=frontʱ����������
    
ѭ���������
        ��1����ֵ����rear���ڵ�λ�ã�
        ��2��rear=��rear+1��%maxsize ������maxsize��������ĳ��ȣ�
ѭ�����г���
        ��1���ȱ�����ӵ�ֵ��
        ��2��front=��front+1��%maxsize ������maxsize��������ĳ��ȣ� 
**/ 

class QUEUE {
    int    *const elems;    //�����ڴ����ڴ�Ŷ��е�Ԫ��
    const  int max;	        //�����ܴ�ŵ����Ԫ�ظ���
    int     head, tail;     //����ͷ��β
    
public:
    QUEUE(int m);                           //��ʼ�����У����m��Ԫ��
    QUEUE(const QUEUE &s);                  //�ö���s������ʼ������
    virtual operator int ( ) const;         //���ض��е�ʵ��Ԫ�ظ���
    virtual QUEUE &operator<<(int e);       //��e�����,�����ض���
    virtual QUEUE &operator>>(int &e);      //�����е�e,�����ض���
    virtual QUEUE &operator=(const QUEUE &s);   //��s������,�����ر���ֵ�Ķ���
    virtual void print( ) const;            //��ӡ���� 
    virtual ~QUEUE( );                      //���ٶ���
    
    inline bool isEmpty()  // �������Ƿ�Ϊ�� 
    {
        return head==tail;
    } 
    inline bool isFull()   // �������Ƿ�Ϊ�� 
    {
        return (tail+1) % max == head;
    }
};

