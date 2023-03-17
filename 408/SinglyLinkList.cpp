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
    if (L == NULL)
    {
        printf("NULL\n");
        printf("\n------------------------------\n");
        return;
    }
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d,", p->data);
        p = p->next;
    }
    printf("\n------------------------------\n");
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
LinkList List_HeadInsert(LinkList &L) // 逆向建立单链表，尾插初始化
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); // 创建头结点
    L->next = NULL;                      // 初始为空链表
    scanf("%d", &x);                     // 输入结点的值
    while (x != 9999)
    {                                       // 输入9999表示结束
        s = (LNode *)malloc(sizeof(LNode)); // 创建新结点
        s->data = x;
        s->next = L->next;
        L->next = s; // 将新结点插入表中，L为头指针
        scanf("%d", &x);
    }
    return L;
}
LinkList Reverse(LinkList &L)
{
    LinkList L2;
    InitList(L2);
    if (Length(L) == 1 && Length(L) == 0)
    {
        L->next = GetElem(L, Length(L));
    }
    else
    {
        int i = Length(L);

        LNode *p = L2;
        while (i > 0)
        {
            p->next = GetElem(L, i);
            p = p->next;
            i--;
        }
        p->next = NULL;
    }
    L = L2;
    return L;
}
// 删除值为x的节点p38_2
bool delete_x(LinkList &L, int x) // p38_2
{
    LNode *p;
    if (L->next == NULL)
    {
        return false;
    }
    else
    {
        p = L;
        while (p->next != NULL) // 直到最后一个节点
        {

            if (p->next->data == x) // 找到x并删除
            {
                LNode *q = p->next;
                p->next = q->next;
                free(q);
            }
            else
            {
                p = p->next;
            }
        }
    }
    return true;
}
// 从尾到头反向输出
void reversePrint(LinkList &L, LinkList &L1) // p38_3忽略头结点
{
    if (L->next == NULL)
    {
        printf("%d\n", L->data);
        return;
    }
    else
    {
        reversePrint(L->next, L1);
        if (L != L1)
        {
            printf("%d\n", L->data);
        }
    }
}
// 删除最小值
void delete_min(LinkList &L) // p38_4删除最小值
{
    if (L->next == NULL)
    {
        return;
    }
    int min = L->next->data;
    LNode *p = L->next, *q = L;
    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    p = L->next;
    while (p->data != min)
    {
        q = q->next;
        p = p->next;
    }
    q->next = p->next;
    free(p);
}
// 原地翻转,头插法
void reverseO1(LinkList &L) // p38_5原地翻转,头插法
{
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
    while (p != NULL)
    {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return;
}
// 插入排序思想
void sort(LinkList &L) // p38_6排序递增有序
{
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while (p != NULL)
    {
        r = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}
// 删除介于mn之间的数
void del_between(LinkList &L, int m, int n) // p38_7
{
    LNode *p = L->next, *pre = L, *temp;
    while (p != NULL && pre != NULL)
    {
        if (p->data < n && p->data > m)
        {
            temp = p;
            pre->next = p->next;
            p = p->next;
            free(temp);
        }
        else
        {
            pre = pre->next;
            p = p->next;
        }
    }
}
LinkList Search_1st_Common(LinkList &L1, LinkList &L2)
{
    int dist;
    int len1 = Length(L1), len2 = Length(L2);
    LinkList longList, shortList;
    if (len1 > len2)
    {
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2;
    }
    else
    {
        longList = L2->next;
        shortList = L1->next;
        dist = len2 - len1;
    }
    while (dist--)
    {
        longList = longList->next;
    }
    while (longList != NULL)
    {
        if (longList == shortList)
        {
            return longList;
        }
        else
        {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}

int main()
{

    srand(time(NULL)); // 设置随机数种子为当前时间
    int k;
    LinkList L;
    InitList(L);
    LinkList L2;
    InitList(L2);
    ElemType e;
    for (size_t i = 1; i <= 10; i++)
    {
        // scanf("%d", &k);
        ListInsert(L, i, rand());
    }
    for (size_t i = 1; i <= 2; i++)
    {
        // scanf("%d", &k);
        ListInsert(L2, i, rand());
    }
    L2->next->next->next = L->next->next;
    // List_TailInsert(L);
    printList(L);
    printList(L2);
    printf("%d\n", Length(L));
    printf("%d\n", Length(L2));
    // sort(L);
    LinkList L3 = Search_1st_Common(L, L2);
    printList(L);
    printList(L2);
    printList(L3);
    return 0;
}