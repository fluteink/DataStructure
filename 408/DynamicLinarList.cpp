#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;
#define InitSize 10
typedef struct
{
    int *data;
    int Maxsize;
    int length;
} SqlList;
int P17_01Del_min(SqlList &L)
{
    int min, pos = 0;
    if (L.length == 0)
    {
        printf("线性表为空，长度为0！");
        return 0;
    }
    min = L.data[0];
    for (size_t i = 1; i < L.length; i++)
    {
        if (L.data[i] < min)
        {
            min = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return min;
}
void InitList(SqlList &L)
{
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.Maxsize = InitSize;
}
void IncreaseSize(SqlList &L, int len)
{
    int *p = L.data;
    // printf("sizeof(p)=%d\n", sizeof(p));
    L.data = (int *)malloc((L.Maxsize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.Maxsize += len;
    free(p);
}
void printList(SqlList &L)
{
    printf("L.length=%d\n", L.length);
    for (int i = 0; i < L.length; i++)
    {
        printf("data[%d]=%d\n", i, L.data[i]);
        // printf("&L.data[%d]=%p\n", i, &L.data[i]);
    }
}
void printSizeofList(SqlList &L)
{
    printf("sizeof(L)=%d\n", sizeof(L));
    printf("sizeof(L.data)=%d\n", sizeof(L.data));
    printf("sizeof(*(L.data))=%d\n", sizeof(*(L.data)));
}
void add(SqlList &L, int n)
{
    if (L.length == L.Maxsize)
    {
        IncreaseSize(L, L.Maxsize);
    }
    L.data[L.length] = n;
    L.length++;
}
bool P17_02ReverseList(SqlList &L)
{
    if (L.length == 0)
    {
        printf("表长度为0！");
        return false;
    }

    int temp = L.data[0];
    for (size_t i = 0; i < L.length / 2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
    return true;
}
void P17_03Del_x(SqlList &L, int x)
{
    int j = 0;
    for (size_t i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[j] = L.data[i];
            j++;
        }
    }
    L.length = j;
}
int main()
{
    SqlList L;
    InitList(L);
    for (size_t i = 8; i >= 1; i--)
    {
        add(L, rand() % 6);
    }
    printList(L);
    P17_03Del_x(L, 4);
    printf("---------------------\n");
    printList(L);
}
