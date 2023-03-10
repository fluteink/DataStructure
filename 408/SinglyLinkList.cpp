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
LNode *GetElem(LinkList &L, int i) // 找到第i个节点并返回
{
    if (i < 0)
    {
        return NULL;
    }
    LNode *p;
    p = L;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
LNode *LocateElem(LinkList &L, ElemType i) // 按值查找
{
    LNode *p = L->next;
    while (p != NULL && p->data != i)
    {
        p = p->next;
    }
    return p;
}
int Length(LinkList &L) // 求表长
{
    LNode *p = L;
    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}
void printList(LinkList &L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("------------------------------\n");
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
bool InsertNextNode(LNode *p, ElemType e) // 在p后面插入一个节点
{
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
bool ListInsert(LinkList &L, int i, ElemType e) // 在第i个位置插入元素e
{
    if (i < 1)
    {
        return false;
    }
    LNode *p = GetElem(L, i - 1);
    return InsertNextNode(p, e);
}
bool InsertPriorNode(LNode *p, ElemType e) // 节点前插
{
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        /* code */
        return false;
    }

    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i < 1)
    {
        return false;
    }
    LNode *p = GetElem(L, i - 1);
    if (p == NULL || p->next == NULL)
    {
        /* code */
        return false;
    }
    LNode *q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}
bool DeleteNode(LNode *p) // 只能用来删除不是最后一个节点的节点

{
    if (p == NULL)
    {
        return false;
    }
    LNode *q = p->next;

    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}
LinkList List_TailInsert(LinkList &L) // 后插定义
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}
int main()
{

    srand(time(NULL)); // 设置随机数种子为当前时间

    LinkList L;
    InitList(L);
    ElemType e;
    // for (size_t i = 1; i <= 0; i++)
    // {
    //     ListInsert(L, i, rand());
    // }
    List_TailInsert(L);
    printList(L);
    printf("%d\n", Length(L));
    return 0;
}