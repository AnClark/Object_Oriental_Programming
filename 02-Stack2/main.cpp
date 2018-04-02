#include "stack.hpp"
#include<iostream>
using namespace std; 

int main()
{
    STACK *s, *t;
    int e, i;
    
    cout<<"������ջ"<<endl; 
    s = new STACK(5);
    cout<<endl;
    
    cout<<"5��Ԫ����ջ"<<endl;
    s->push(111);
    s->push(222);
    s->push(333);
    s->push(444);
    s->push(555);
    cout<<"��ǰ���� "<<s->howMany()<<" ��Ԫ�أ�ջ������Ϊ "<<s->size()<<endl;
    cout<<endl;
    
    cout<<"����ջ2��Ԫ�أ����߽�����"<<endl;
    s->push(999);
    s->push(888);
    cout<<"��ǰ���� "<<s->howMany()<<" ��Ԫ�أ�ջ������Ϊ "<<s->size()<<endl;
    cout<<endl;
    
    cout<<"��ӡ�����ǰջ"<<endl;
    s->print();
    cout<<endl<<endl;
    
    cout<<"��ջs������ʼ��ջt"<<endl;
    t = new STACK(*s);
    cout<<endl;
    
    cout<<"��ӡ���ջt"<<endl;
    t->print();
    cout<<endl;
    
    cout<<"3��Ԫ�س�ջs"<<endl;
    s->pop(e);  cout<<'\t'<<"��ջԪ�أ�"<<e<<endl;
    s->pop(e);  cout<<'\t'<<"��ջԪ�أ�"<<e<<endl;
    s->pop(e);  cout<<'\t'<<"��ջԪ�أ�"<<e<<endl;
    cout<<"��ʱ��ջ��";
    s->print();
    cout<<endl;
    cout<<"��ǰ���� "<<s->howMany()<<" ��Ԫ�أ�ջ������Ϊ "<<s->size()<<endl;
    cout<<endl; 
    
    cout<<"�ٳ�ջ�ĸ�Ԫ�أ��Դ������߽�"<<endl;
    s->pop(e);  cout<<'\t'<<"��ջԪ�أ�"<<e<<endl;
    s->pop(e);  cout<<'\t'<<"��ջԪ�أ�"<<e<<endl;
    s->pop(e);  cout<<'\t'<<"��ջԪ�أ�"<<e<<endl;
    s->pop(e);  cout<<'\t'<<"��ջԪ�أ�"<<e<<endl;
    cout<<"��ʱ��ջ��";
    s->print();
    cout<<endl;
    cout<<"��ǰ���� "<<s->howMany()<<" ��Ԫ�أ�ջ������Ϊ "<<s->size()<<endl;
    cout<<endl;
    
    cout<<"3��Ԫ����ջs"<<endl;
    s->push(9999);
    s->push(8888);
    s->push(7777);
    cout<<"��ǰ���� "<<s->howMany()<<" ��Ԫ�أ�ջ������Ϊ "<<s->size()<<endl;
    cout<<endl;
    
    cout<<"��s����t"<<endl;
    cout<<"��ֵǰ��t��";
    t->print();
    cout<<endl;
    cout<<"��ǰt���� "<<s->howMany()<<" ��Ԫ�أ�t������Ϊ "<<s->size()<<endl;
    
    t->assign(*s);
    
    cout<<"��ֵ���t��";
    t->print();
    cout<<endl;
    cout<<"��ǰt���� "<<s->howMany()<<" ��Ԫ�أ�t������Ϊ "<<s->size()<<endl;
    
    cout<<endl<<endl;
    
    cout<<"����ջs"<<endl;
    delete s;
    cout<<"����ջt"<<endl;
    delete t;
    
    return 0;
}

