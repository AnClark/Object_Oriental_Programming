#include<stdio.h>
#include "stack.h"
#define NEWLINE printf("\n");

int main()
{
    STACK s, t; 
    int e;
    
    // initSTACK（空栈初始化版本）
    printf("初始化空栈s，栈容量为5\n");
    initSTACK(&s, 5);
    
    printf("当前共有 %d 个元素，容量为 %d \n", howMany(&s), size(&s));
    NEWLINE;
    
    printf("5个元素入栈\n");
    push(&s, 111);
    push(&s, 222);
    push(&s, 333);
    push(&s, 444);
    push(&s, 555);
    printf("当前共有 %d 个元素，容量为 %d \n", howMany(&s), size(&s));
    NEWLINE;
    
    printf("多push几个元素，检查越界处理\n");
    push(&s, 666);
    push(&s, 777);
    push(&s, 888);
    printf("当前共有 %d 个元素，容量为 %d \n", howMany(&s), size(&s));
    NEWLINE;
    
    printf("打印输出当前栈s\n");
    print(&s);
    NEWLINE;
    
    printf("用栈 s 初始化栈 t\n");
    initSTACK(&t, s);
    printf("当前栈 t 共有 %d 个元素，容量为 %d \n", howMany(&t), size(&t));
    NEWLINE;
    
    printf("打印输出栈t\n");
    print(&t); 
    NEWLINE;
    
    
    printf("栈 s 出栈，并输出出栈的元素\n");
    pop(&s, e);     printf("\t输出元素：%d\n", e);
    pop(&s, e);     printf("\t输出元素：%d\n", e);
    pop(&s, e);     printf("\t输出元素：%d\n", e);
    pop(&s, e);     printf("\t输出元素：%d\n", e);
    pop(&s, e);     printf("\t输出元素：%d\n", e);
    printf("当前共有 %d 个元素，容量为 %d \n", howMany(&s), size(&s));
    NEWLINE; 
    
    printf("多pop几个元素，检查越界处理\n");
    pop(&s, e);     printf("\t输出元素：%d\n", e);
    pop(&s, e);     printf("\t输出元素：%d\n", e);
    pop(&s, e);     printf("\t输出元素：%d\n", e);
    NEWLINE; NEWLINE;
    
    
    printf("栈 t 出栈，并输出出栈的元素\n");
    pop(&t, e);     printf("\t输出元素：%d\n", e);
    pop(&t, e);     printf("\t输出元素：%d\n", e);
    pop(&t, e);     printf("\t输出元素：%d\n", e);
    pop(&t, e);     printf("\t输出元素：%d\n", e);
    pop(&t, e);     printf("\t输出元素：%d\n", e);
    printf("当前共有 %d 个元素，容量为 %d \n", howMany(&t), size(&t));
    NEWLINE; 
    
    printf("多pop几个元素，检查越界处理\n");
    pop(&t, e);     printf("\t输出元素：%d\n", e);
    pop(&t, e);     printf("\t输出元素：%d\n", e);
    pop(&t, e);     printf("\t输出元素：%d\n", e);
    NEWLINE;
    
    
    printf("销毁栈 s\n");
    destroySTACK(&s);
    printf("销毁栈 t\n");
    destroySTACK(&t);
    
    return 0;
}
