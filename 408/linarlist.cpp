#include <stdio.h>
#define Maxsize 10
typedef struct
{
    int data[Maxsize];
    int length;
} SqlList;
void InitList(SqlList &L)
{
    // for (int i = 0; i < Maxsize; i++)
    // {
    //     L.data[i] = 0;
    // }
    L.length = 0;
}
void printListAll(SqlList &L)
{
    printf("sizeof(L)=%d\n", sizeof(L));
    for (int i = 0; i < Maxsize; i++)
    {
        printf("data[%d]=%d\n", i, L.data[i]);
        printf("&L.data[%d]=%p\n", i, &L.data[i]);
    }
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
int test()
{
    SqlList L;
    InitList(L);
    // printListAll(L);
    printList(L);
    return 0;
}