#include "stack.hpp"
#include<iostream>
using namespace std; 

int main()
{
    STACK *s, *t;
    int e, i;
    
    cout<<"建立新栈"<<endl; 
    s = new STACK(5);
    cout<<endl;
    
    cout<<"5个元素入栈"<<endl;
    s->push(111);
    s->push(222);
    s->push(333);
    s->push(444);
    s->push(555);
    cout<<"当前共有 "<<s->howMany()<<" 个元素，栈的容量为 "<<s->size()<<endl;
    cout<<endl;
    
    cout<<"多入栈2个元素，检查边界限制"<<endl;
    s->push(999);
    s->push(888);
    cout<<"当前共有 "<<s->howMany()<<" 个元素，栈的容量为 "<<s->size()<<endl;
    cout<<endl;
    
    cout<<"打印输出当前栈"<<endl;
    s->print();
    cout<<endl<<endl;
    
    cout<<"用栈s拷贝初始化栈t"<<endl;
    t = new STACK(*s);
    cout<<endl;
    
    cout<<"打印输出栈t"<<endl;
    t->print();
    cout<<endl;
    
    cout<<"3个元素出栈s"<<endl;
    s->pop(e);  cout<<'\t'<<"出栈元素："<<e<<endl;
    s->pop(e);  cout<<'\t'<<"出栈元素："<<e<<endl;
    s->pop(e);  cout<<'\t'<<"出栈元素："<<e<<endl;
    cout<<"此时的栈：";
    s->print();
    cout<<endl;
    cout<<"当前共有 "<<s->howMany()<<" 个元素，栈的容量为 "<<s->size()<<endl;
    cout<<endl; 
    
    cout<<"再出栈四个元素，以此来检查边界"<<endl;
    s->pop(e);  cout<<'\t'<<"出栈元素："<<e<<endl;
    s->pop(e);  cout<<'\t'<<"出栈元素："<<e<<endl;
    s->pop(e);  cout<<'\t'<<"出栈元素："<<e<<endl;
    s->pop(e);  cout<<'\t'<<"出栈元素："<<e<<endl;
    cout<<"此时的栈：";
    s->print();
    cout<<endl;
    cout<<"当前共有 "<<s->howMany()<<" 个元素，栈的容量为 "<<s->size()<<endl;
    cout<<endl;
    
    cout<<"3个元素入栈s"<<endl;
    s->push(9999);
    s->push(8888);
    s->push(7777);
    cout<<"当前共有 "<<s->howMany()<<" 个元素，栈的容量为 "<<s->size()<<endl;
    cout<<"此时的s为：";
    s->print();
    cout<<endl<<endl;
    
    cout<<"将s赋给t"<<endl;
    cout<<"赋值前的t：";
    t->print();
    cout<<endl;
    cout<<"当前t共有 "<<s->howMany()<<" 个元素，t的容量为 "<<s->size()<<endl;
    
    t->assign(*s);
    
    cout<<"赋值后的t：";
    t->print();
    cout<<endl;
    cout<<"当前t共有 "<<s->howMany()<<" 个元素，t的容量为 "<<s->size()<<endl;
    
    cout<<endl<<endl;
    
    cout<<"销毁栈s"<<endl;
    delete s;
    cout<<"销毁栈t"<<endl;
    delete t;
    
    return 0;
}

