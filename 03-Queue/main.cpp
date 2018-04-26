#include<iostream>
#include "queue.hpp"

#define PRINT(x) cout<<x<<endl
#define NEWSECTION cout<<endl<<endl
#define COUNT(x) cout<<"共有 "<<(int)*x<<" 个元素\n"

using namespace std;

int main()
{
    QUEUE *s = new QUEUE(5+1); 
    int i, num;
    
    PRINT("====== 一般出入队测试 ======");
    
    PRINT("3个元素入队s");
    *s<<111<<222<<333;
    PRINT("此时的队列是：");
    s->print(); 
    COUNT(s);
    
    
    PRINT("2个元素出队s");
    for(i=1; i<=2; i++)
    {
        *s>>num;
        cout<<"\t当前出队元素："<<num<<endl; 
    }
    
    PRINT("此时的队列是：");
    s->print();
    COUNT(s);
    
    PRINT("4个元素入队s");
    *s<<444<<555<<666<<777;
    PRINT("此时的队列是：");
    s->print(); 
    COUNT(s);
    
    NEWSECTION;
    
    PRINT("===== 越界检测 =====");
    PRINT("再入队10个元素，检查队列满检测功能");
    *s<<1111<<2222<<3333<<4444<<5555<<6666<<7777<<8888<<9999<<10000; 
    cout<<endl;
    
    PRINT("连续出队10个元素，检查队列空检测功能");
    for(i=1; i<=10; i++)
    {
        *s>>num;
        
        if(!s->isEmpty())
            cout<<"\t当前出队元素："<<num<<endl; 
    }
    
    NEWSECTION;
    
    PRINT("===== 元素个数检测 =====");
    PRINT("4个元素入队s");
    *s<<1111<<2222<<3333<<4444;
    PRINT("此时的队列是：");
    s->print(); 
    COUNT(s);
    
    PRINT("3个元素出队s");
    *s>>num; *s>>num; *s>>num;
    PRINT("此时的队列是：");
    s->print(); 
    COUNT(s);
    
    PRINT("3个元素入队s");
    *s<<5555<<6666<<7777;
    PRINT("此时的队列是：");
    s->print(); 
    COUNT(s);

    NEWSECTION;
   
    PRINT("===== 新队列初始化测试 =====");
    PRINT("----- 用现有队列s初始化新队列t -----");
    PRINT("队列s的内容为：");
    s->print();
    PRINT("开始初始化队列t");
    QUEUE *t = new QUEUE(*s);
    PRINT("队列t的内容为：");
    t->print();

    NEWSECTION;
    
    PRINT("===== 队列赋值测试一 =====");
    PRINT("----- 将队列t赋给队列s -----");
    
    PRINT("清空t，并重新组织t的值");
    while(!t->isEmpty())
        *t>>num;
    *t<<123<<345<<456<<678<<789;
    PRINT("队列t的新内容为：");
    t->print();
    
    PRINT("队列s赋值前的内容为：");
    s->print();
    
    PRINT("开始赋值");
    *s = *t;
    
    PRINT("队列s赋值后的内容为：");
    s->print();
    
    
    NEWSECTION;
    
    PRINT("===== 队列赋值测试二 =====");
    PRINT("----- 将队列t赋给新队列r，r的容量小于t -----");
    
    PRINT("初始化队列r并进行赋值");
    QUEUE *r = new QUEUE(4);
    *r = *t;
    
    PRINT("队列r赋值后的内容为：");
    r->print();
    PRINT("检查一下队列t的内容有没有变：");
    t->print(); 
    
    NEWSECTION;
     
    PRINT("===== 销毁队列 =====");
    PRINT("销毁队列s");
    delete s;
    PRINT("销毁队列t");
    delete t; 
    
    
    return 0;
}
