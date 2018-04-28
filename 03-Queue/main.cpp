#include<iostream>
#include "queue.hpp"

#define PRINT(x) cout<<x<<endl
#define NEWSECTION cout<<endl<<endl
#define COUNT(x) cout<<"���� "<<(int)*x<<" ��Ԫ��\n"

using namespace std;

int main()
{
    QUEUE *s = new QUEUE(5+1); 
    int i, num;
    
    PRINT("====== һ�����Ӳ��� ======");
    
    PRINT("3��Ԫ�����s");
    *s<<111<<222<<333;
    PRINT("��ʱ�Ķ����ǣ�");
    s->print(); 
    COUNT(s);
    
    
    PRINT("2��Ԫ�س���s");
    for(i=1; i<=2; i++)
    {
        *s>>num;
        cout<<"\t��ǰ����Ԫ�أ�"<<num<<endl; 
    }
    
    PRINT("��ʱ�Ķ����ǣ�");
    s->print();
    COUNT(s);
    
    PRINT("4��Ԫ�����s");
    *s<<444<<555<<666<<777;
    PRINT("��ʱ�Ķ����ǣ�");
    s->print(); 
    COUNT(s);
    
    NEWSECTION;
    
    PRINT("===== Խ���� =====");
    PRINT("�����10��Ԫ�أ�����������⹦��");
    *s<<1111<<2222<<3333<<4444<<5555<<6666<<7777<<8888<<9999<<10000; 
    cout<<endl;
    
    PRINT("��������10��Ԫ�أ������пռ�⹦��");
    for(i=1; i<=10; i++)
    {
        *s>>num;
        
        if(!s->isEmpty())
            cout<<"\t��ǰ����Ԫ�أ�"<<num<<endl; 
    }
    
    NEWSECTION;
    
    PRINT("===== Ԫ�ظ������ =====");
    PRINT("4��Ԫ�����s");
    *s<<1111<<2222<<3333<<4444;
    PRINT("��ʱ�Ķ����ǣ�");
    s->print(); 
    COUNT(s);
    
    PRINT("3��Ԫ�س���s");
    *s>>num; *s>>num; *s>>num;
    PRINT("��ʱ�Ķ����ǣ�");
    s->print(); 
    COUNT(s);
    
    PRINT("3��Ԫ�����s");
    *s<<5555<<6666<<7777;
    PRINT("��ʱ�Ķ����ǣ�");
    s->print(); 
    COUNT(s);

    NEWSECTION;
   
    PRINT("===== �¶��г�ʼ������ =====");
    PRINT("----- �����ж���s��ʼ���¶���t -----");
    PRINT("����s������Ϊ��");
    s->print();
    PRINT("��ʼ��ʼ������t");
    QUEUE *t = new QUEUE(*s);
    PRINT("����t������Ϊ��");
    t->print();

    NEWSECTION;
    
    PRINT("===== ���и�ֵ����һ =====");
    PRINT("----- ������t��������s -----");
    
    PRINT("���t����������֯t��ֵ");
    while(!t->isEmpty())
        *t>>num;
    *t<<123<<345<<456<<678<<789;
    PRINT("����t��������Ϊ��");
    t->print();
    
    PRINT("����s��ֵǰ������Ϊ��");
    s->print();
    
    PRINT("��ʼ��ֵ");
    *s = *t;
    
    PRINT("����s��ֵ�������Ϊ��");
    s->print();
    
    
    NEWSECTION;
    
    PRINT("===== ���и�ֵ���Զ� =====");
    PRINT("----- ������t�����¶���r��r������С��t -----");
    
    PRINT("��ʼ������r�����и�ֵ");
    QUEUE *r = new QUEUE(4);
    *r = *t;
    
    PRINT("����r��ֵ�������Ϊ��");
    r->print();
    PRINT("���һ�¶���t��������û�б䣺");
    t->print(); 
    
    NEWSECTION;
     
    PRINT("===== ���ٶ��� =====");
    PRINT("���ٶ���s");
    delete s;
    PRINT("���ٶ���t");
    delete t; 
    PRINT("���ٶ���r");
    delete r; 
    
    
    return 0;
}
