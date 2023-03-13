// 不带头结点的单链表操作
#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
typedef int DataType;
typedef int DataType;

typedef struct Node
{
    DataType Data;
    struct Node *next;
} SLNode, *LinkList;

// 初始化
void ListInitiate(SLNode **head)
{
    *head = NULL;
}

// 求当前数据元素个数
int ListLength(SLNode *head)
{
    SLNode *p;
    int size = 0;
    p = head;
    while (p != NULL)
    {
        p = p->next;
        size++;
    }
    return size;
}

// 插入新结点
int ListInsert(SLNode **head, int i, DataType x)
{
    SLNode *p, *q, *m;
    int j;
    if (i == 0) // 若在第0个位置插入
    {
        m = (SLNode *)malloc(sizeof(SLNode));
        m->Data = x;

        m->next = *head;
        *head = m;
        return 1;
    }
    else // 若不在第0个位置插入
    {
        p = *head;
        j = 0;

        while (p->next != NULL && j < i - 1)
        // 最终让指针p指向第i-1个结点
        {
            p = p->next;
            j++;
        }
        if (j != i - 1)
        {
            printf("插入元素位置参数错！");
            return 0;
        }
        q = (SLNode *)malloc(sizeof(SLNode));
        q->Data = x;

        q->next = p->next;
        p->next = q;
        return 1;
    }
}

// 删除新结点
int ListDelete(SLNode **head, int i, DataType *x)
{
    SLNode *p, *q, *m, *s;
    int j;
    if (i == 0) // 若在第0个位置删除
    {
        m = *head;    // 让m指向第0个结点
        *x = m->Data; // 把指针m所指的结点数据域值赋给x

        *head = m->next; // 删除
        free(m);         // 释放m所指结点的内存空间
        return 1;
    }
    else // 若不在第0个位置删除
    {
        p = *head;
        j = 0;

        while (p->next != NULL && p->next->next != NULL && j < i - 1)
        // 循环结束时指针p指向第i-1个结点
        {
            p = p->next;
            j++;
        }

        if (j != i - 1)
        {
            printf("删除元素位置错误！");
            return 0;
        }

        s = p->next;
        *x = s->Data;
        p->next = p->next->next;
        free(s);
        return 1;
    }
}

// 取数据元素
int ListGet(SLNode *head, int i, DataType *x)
{
    SLNode *p;
    int j;

    p = head;
    j = 0;

    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (j != i)
    {
        printf("取数据元素位置错！");
        return 0;
    }

    *x = p->Data;
    return 1;
}

// 撤销单链表
void Destory(SLNode **head)
{
    SLNode *p, *q;
    p = *head;

    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    *head = NULL;
}
// 打印
void printList(SLNode **head)
{
    int x;
    for (int i = 0; i < ListLength(*head); i++) // 显示当前数据元素
    {
        ListGet(*head, i, &x); // 取元素
        printf("%d,", x);      // 显示
    }
    printf("\n--------------------------\n");
}
// 删除值为x的节点
void delete_x(LinkList &L, int x)
{
    SLNode *p;
    if (L == NULL)
    {
        return;
    }
    else
    {
        if (L->Data == x)
        {
            p = L;
            L = L->next;
            free(p);
            delete_x(L, x);
        }
        else
        {
            delete_x(L->next, x);
        }
    }
}
int main()
{
    SLNode *head;
    int i, x;
    ListInitiate(&head);     // 初始化
    for (i = 0; i < 10; i++) // 插入10个数据元素
    {
        scanf("%d", &x);
        ListInsert(&head, i, x);
    }
    printList(&head);
    delete_x(head, 2);
    printList(&head);
    Destory(&head); /// 撤销单链表
    return 0;
}