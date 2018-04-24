// 实现方法：循环队列
// 参考文献：循环队列的c语言实现 - CSDN博客
// https://blog.csdn.net/silent123go/article/details/52643262 
/**
基本要素：
    a、队列初始化时，front和rear值都为零。
    b、当队列为空时，front与rear的值相等，但不一定为零。
    c、当队列不为空时，front指向队列的第一个元素，rear指向队列最后一个元素的下一个位置。

队列空判断： 
    若front与rear的值相等（不一定为零）则队列为空。
队列满判断：
    少用一个存储空间，也就是数组的最后一个存数空间不用，当（rear+1）%maxsiz=front时，队列满。
    
循环队列入队
        （1）把值存在rear所在的位置；
        （2）rear=（rear+1）%maxsize ，其中maxsize代表数组的长度；
循环队列出队
        （1）先保存出队的值；
        （2）front=（front+1）%maxsize ，其中maxsize代表数组的长度； 
**/ 

class QUEUE {
    int    *const elems;    //申请内存用于存放队列的元素
    const  int max;	        //队列能存放的最大元素个数
    int     head, tail;     //队列头和尾
    
public:
    QUEUE(int m);                           //初始化队列：最多m个元素
    QUEUE(const QUEUE &s);                  //用队列s拷贝初始化队列
    virtual operator int ( ) const;         //返回队列的实际元素个数
    virtual QUEUE &operator<<(int e);       //将e入队列,并返回队列
    virtual QUEUE &operator>>(int &e);      //出队列到e,并返回队列
    virtual QUEUE &operator=(const QUEUE &s);   //赋s给队列,并返回被赋值的队列
    virtual void print( ) const;            //打印队列 
    virtual ~QUEUE( );                      //销毁队列
    
    inline bool isEmpty()  // 检测队列是否为空 
    {
        return head==tail;
    } 
    inline bool isFull()   // 检测队列是否为满 
    {
        return (tail+1) % max == head;
    }
};

