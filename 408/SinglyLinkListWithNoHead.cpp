// 单链表不带头结点
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList initList(LinkList list)
{
    list = NULL;
    return list;
}

// 插数据（第一个位置）（指定位置）
LinkList insertFirst(LinkList list, int index, int data)
{
    if (index == 1)
    {
        LNode *newNode = (LNode *)malloc(sizeof(LNode));
        if (newNode == NULL)
        {
            return list;
        }
        (*newNode).next = list;
        list = newNode;
        (*newNode).data = data;
        return list;
    }
    return list;
}

// 插数据（指定位置）
int insertList(LinkList list, int index, int data)
{
    LNode *tmp = list;
    int j = 1;
    if (list == NULL)
    {
        return 0;
    }
    if (index < 2)
    {
        return 0;
    }
    while (tmp != NULL && j < index - 1)
    {

        tmp = (*tmp).next;
        j++;
    }

    if (tmp == NULL)
    {
        return 0;
    }

    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL)
    {
        return 0;
    }
    (*newNode).data = data;
    (*newNode).next = (*tmp).next;
    (*tmp).next = newNode;
    return 1;
}

// 插数据（指定结点后）
int insertNextNode(LNode *p, int data)
{
    if (p == NULL)
    {
        return 0;
    }
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL)
    {
        return 0;
    }
    (*newNode).data = data;
    (*newNode).next = (*p).next;
    (*p).next = newNode;
    return 1;
}

// 插数据（指定结点前（不包括第一个结点））【移动数据】
int insertPriorNodeOne(LNode *p, int data)
{
    if (p == NULL)
    {
        return 0;
    }
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL)
    {
        return 0;
    }
    (*newNode).next = (*p).next;
    (*p).next = newNode;
    (*newNode).data = (*p).data;
    (*p).data = data;
    return 1;
}

// 插数据（指定结点前（不包括第一个结点））【循环】
int insertPriorNodeTwo(LinkList list, LNode *p, int data)
{
    //		if(list=NULL || p==NULL){
    //		return 0;
    //	}
    LNode *tmp = list;

    while (tmp != NULL && (*tmp).next != p)
    {
        tmp = (*tmp).next;
    }

    if (tmp == NULL)
    {
        return 0;
    }
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL)
    {
        return 0;
    }
    (*newNode).next = p;
    (*tmp).next = newNode;
    (*newNode).data = data;
    return 1;
}

// 删单链表的第一个位置
LinkList deleteFirst(LinkList list, int index)
{
    if (index == 1)
    {
        LNode *tmp = list;
        list = (*tmp).next;
        //		*data = (*tmp).data;
        free(tmp);
        return list;
    }
}

// 删单链表（除第一个位置）(指定位置)的数据
int deleteList(LinkList list, int index)
{
    if (list == NULL)
    {
        return 0;
    }

    LNode *tmp = list;
    int j = 1;
    if (index < 2)
    {
        return 0;
    }
    while (tmp != NULL && j < index - 1)
    {

        tmp = (*tmp).next;

        j++;
    }
    if (tmp == NULL)
    {
        return 0;
    }
    if ((*tmp).next == NULL)
    {
        return 0;
    }
    LNode *p = (*tmp).next;
    //	int *data=(*p).data;
    (*tmp).next = (*p).next;
    free(p);
    return 1;
}

// 删指定结点（不能删第一个和最后一个）【移动】
int deleteNodeOne(LNode *p)
{
    if (p == NULL)
    {
        return 0;
    }
    LNode *q = (*p).next;
    (*p).next = (*q).next;
    (*p).data = (*q).data;
    free(q);
    return 1;
}

// 删指定结点【循环】
int deleteNodeTwo(LinkList list, LNode *p)
{
    if (list == NULL)
    {
        return 0;
    }

    if (p == NULL)
    {
        return 0;
    }

    LNode *tmp = list;

    while (tmp != NULL && (*tmp).next != p)
    {
        tmp = (*tmp).next;
    }

    if (tmp == NULL)
    {
        return 0;
    }

    (*tmp).next = (*p).next;
    free(p);
    return 1;
}

// 按位查找：返回指定位置的结点
LNode *getElementByIndex(LinkList list, int index)
{
    LNode *tmp = list;
    int j = 1;
    if (index < 0)
    {
        return NULL;
    }
    while (tmp != NULL && j < index)
    {
        tmp = (*tmp).next;
        j++;
    }
    printf("第二个位置：%d,", (*tmp).data);
    return tmp;
}

// 按值查找：返回指定值的结点
LNode *getElementByData(LinkList list, int data)
{
    LNode *tmp = list;

    while (tmp != NULL && (*tmp).data != data)
    {
        tmp = (*tmp).next;
    }
    printf("值为3的位置：%d,", (*tmp).data);
    return tmp;
}

// 求表长
int getLength(LinkList list)
{
    if (list == NULL)
    {
        return 0;
    }
    int length = 1;
    LNode *tmp = list;
    while ((*tmp).next != NULL)
    {
        tmp = (*tmp).next;
        length++;
    }
    return length;
}

// 新建一个链表：头插法--->相当于逆置链表
LinkList constructLinkListOne(LinkList list)
{
    int i = 1;
    for (; i < 5; i++)
    {
        list = insertFirst(list, 1, i + 1);
        printf("%d,", (*list).next->data);
    }
    return list;
}
// 遍历
void bianli(LinkList list)
{
    LNode *tmp = list;
    while (tmp != NULL)
    {
        printf("%d,", (*tmp).data);
        tmp = (*tmp).next;
    }
    printf("\n");
}
// 新建一个链表：尾插法
void constructLinkListTwo(LinkList list)
{
    int i = 1, j = 1;
    LNode *tmp = list;

    for (; i < 5; i++)
    {
        insertList(list, j + 1, i + 1);
        j++;
    }
    bianli(list);
}

// 清空
void clearList(LinkList list)
{
    while (list != NULL)
    {
        LNode *tmp = list;
        list = (*list).next;
        free(list);
    }
}

int main()
{
    int length = 0, i = 0;
    LinkList list = initList(list);
}
