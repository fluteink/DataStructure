#include <cstdlib>
#include <ctime>
#include <stdio.h>
/**定义模块**/
typedef int ElemType;

typedef struct RDNode
{
    ElemType data;
    struct RDNode *prior, *next;
} RDNode, *RDLinklist;

bool InitList(RDLinklist &L);

bool Empty(RDLinklist L);

// 判断是否为尾结点
bool isTail(RDLinklist L, RDNode *p);

bool InsertNextNode(RDNode *p, RDNode *s);
/**定义模块**/

/**实现模块**/
bool InitList(RDLinklist &L)
{
    L = (RDNode *)malloc(sizeof(RDNode));
    if (L == NULL)
        return false;
    // 循环链表的尾结点指向头结点
    // 初始化时空链表的头结点也是尾结点
    L->prior = L;
    L->next = L;
    return true;
}

bool Empty(RDLinklist L)
{
    return (L->next == L);
}

bool isTail(RDLinklist L, RDNode *p)
{
    return (p->next == L);
}

bool InsertNextNode(RDNode *p, RDNode *s)
{
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    s->prior = p;
    return true;
}
bool printlist(RDLinklist L)
{
    RDNode *p = L;
    if (L == NULL)
    {
        printf("L==NULL\n");
    }
    else
    {
        while (!isTail(L, p))
        {
            printf("%d,", p->next->data);
            p = p->next;
        }
        printf("\n---------------------\n");
    }
    return true;
}
bool isSymphony(RDLinklist &L)
{
    RDNode *p = L, *tail = L->prior;
    p = L->next;
    while (p->next != tail && p->next != tail->prior)
    {
        if (p->data == tail->data)
        {
            p = p->next;
            tail = tail->prior;
        }
        else
        {
            break;
        }
    }
    if (p->next->data == tail->prior->data)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**实现模块**/
// h2加到h1之后
RDLinklist Link(RDLinklist &h1, RDLinklist &h2) // p39-18
{
    RDNode *p, *q;
    p = h1;
    while (p->next != h1)
    {
        p = p->next;
    }
    q = h2;
    while (q->next != h2)
    {
        q = q->next;
    }
    p->next = h2->next;
    q->next = h1;
    return h1;
}
// 依次删除最小的
void Del_All(RDLinklist &L) // p39-19
{
    RDNode *p, *pre, *minp, *minpre;
    while (L->next != L)
    {
        p = L->next;
        pre = L;
        minp = p;
        minpre = pre;
        while (p != L)
        {
            if (p->data < minp->data)
            {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        printf("%d,", minp->data);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
    printf("\nfinish!");
}
int main()
{
    srand(time(NULL)); // 设置随机数种子为当前时间
    RDLinklist L, R;
    InitList(L);
    InitList(R);
    int k;
    RDNode *p = L;
    for (size_t i = 0; i < 10; i++)
    {
        // scanf("%d", &k);
        k = rand() % 20;
        RDNode *node = (RDNode *)malloc(sizeof(RDNode));
        node->data = k;
        InsertNextNode(p, node);
        p = p->next;
    }
    RDNode *q = R;
    for (size_t i = 0; i < 10; i++)
    {
        // scanf("%d", &k);
        k = rand() % 20;
        RDNode *node = (RDNode *)malloc(sizeof(RDNode));
        node->data = k;
        InsertNextNode(q, node);
        q = q->next;
    }
    printlist(L);
    printlist(R);

    L = Link(L, R);
    printlist(L);

    return 0;
}
