#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cmath>

// 带头结点的单链表
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
void printList(LinkList &L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) // 内存不足，分配失败
    {
        return false;
    }
    L->next = NULL; // 头结点之后暂时还没有节点
    return true;
}
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
    {
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
int main()
{
    LinkList L;
    InitList(L);
    for (size_t i = 1; i <= 5; i++)
    {
        ListInsert(L, i, i);
    }
    printList(L);
    return 0;
}