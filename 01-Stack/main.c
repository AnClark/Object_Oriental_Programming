#include<stdio.h>
#include "stack.h"
#define NEWLINE printf("\n");

int main()
{
    STACK s, t; 
    int e;
    
    // initSTACK����ջ��ʼ���汾��
    printf("��ʼ����ջs��ջ����Ϊ5\n");
    initSTACK(&s, 5);
    
    printf("��ǰ���� %d ��Ԫ�أ�����Ϊ %d \n", howMany(&s), size(&s));
    NEWLINE;
    
    printf("5��Ԫ����ջ\n");
    push(&s, 111);
    push(&s, 222);
    push(&s, 333);
    push(&s, 444);
    push(&s, 555);
    printf("��ǰ���� %d ��Ԫ�أ�����Ϊ %d \n", howMany(&s), size(&s));
    NEWLINE;
    
    printf("��push����Ԫ�أ����Խ�紦��\n");
    push(&s, 666);
    push(&s, 777);
    push(&s, 888);
    printf("��ǰ���� %d ��Ԫ�أ�����Ϊ %d \n", howMany(&s), size(&s));
    NEWLINE;
    
    printf("��ӡ�����ǰջs\n");
    print(&s);
    NEWLINE;
    
    printf("��ջ s ��ʼ��ջ t\n");
    initSTACK(&t, s);
    printf("��ǰջ t ���� %d ��Ԫ�أ�����Ϊ %d \n", howMany(&t), size(&t));
    NEWLINE;
    
    printf("��ӡ���ջt\n");
    print(&t); 
    NEWLINE;
    
    
    printf("ջ s ��ջ���������ջ��Ԫ��\n");
    pop(&s, e);     printf("\t���Ԫ�أ�%d\n", e);
    pop(&s, e);     printf("\t���Ԫ�أ�%d\n", e);
    pop(&s, e);     printf("\t���Ԫ�أ�%d\n", e);
    pop(&s, e);     printf("\t���Ԫ�أ�%d\n", e);
    pop(&s, e);     printf("\t���Ԫ�أ�%d\n", e);
    printf("��ǰ���� %d ��Ԫ�أ�����Ϊ %d \n", howMany(&s), size(&s));
    NEWLINE; 
    
    printf("��pop����Ԫ�أ����Խ�紦��\n");
    pop(&s, e);     printf("\t���Ԫ�أ�%d\n", e);
    pop(&s, e);     printf("\t���Ԫ�أ�%d\n", e);
    pop(&s, e);     printf("\t���Ԫ�أ�%d\n", e);
    NEWLINE; NEWLINE;
    
    
    printf("ջ t ��ջ���������ջ��Ԫ��\n");
    pop(&t, e);     printf("\t���Ԫ�أ�%d\n", e);
    pop(&t, e);     printf("\t���Ԫ�أ�%d\n", e);
    pop(&t, e);     printf("\t���Ԫ�أ�%d\n", e);
    pop(&t, e);     printf("\t���Ԫ�أ�%d\n", e);
    pop(&t, e);     printf("\t���Ԫ�أ�%d\n", e);
    printf("��ǰ���� %d ��Ԫ�أ�����Ϊ %d \n", howMany(&t), size(&t));
    NEWLINE; 
    
    printf("��pop����Ԫ�أ����Խ�紦��\n");
    pop(&t, e);     printf("\t���Ԫ�أ�%d\n", e);
    pop(&t, e);     printf("\t���Ԫ�أ�%d\n", e);
    pop(&t, e);     printf("\t���Ԫ�أ�%d\n", e);
    NEWLINE;
    
    
    printf("����ջ s\n");
    destroySTACK(&s);
    printf("����ջ t\n");
    destroySTACK(&t);
    
    return 0;
}
