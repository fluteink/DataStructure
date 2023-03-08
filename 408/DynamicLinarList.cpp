#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
#define InitSize 100
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
bool P17_04Del_s_t(SqlList &L, int s, int t)
{
    if (L.length == 0 || s >= t)
    {
        return false;
    }

    int i = 0, j = 0;
    for (; i < L.length && L.data[i] < s; i++)
        ;
    for (i = j; j < L.length && L.data[j] <= t; j++)
        ;
    for (; j < L.length; i++, j++)
    {
        L.data[i] = L.data[j];
    }
    L.length = i;
    return true;
}
bool P17_05Del_s_t(SqlList &L, int s, int t)
{
    if (L.length == 0 || s >= t)
    {
        return false;
    }
    int j = 0;
    for (size_t i = 0; i < L.length; i++)
    {
        if (!(L.data[i] >= s && L.data[i] <= t))
        {
            L.data[j] = L.data[i];
            j++;
        }
    }
    L.length = j;
    return true;
}
void P17_06Del_same(SqlList &L)
{
    if (L.length == 0)
    {
        return;
    }
    int i, j;
    for (i = 0, j = 1; j < L.length; j++)
    {
        if (L.data[i] != L.data[j])
        {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i + 1;
}
void P17_07Merge(SqlList &L1, SqlList &L2, SqlList &L3)
{
    if (L1.length + L2.length > L3.Maxsize)
    {
        return;
    }
    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length)
    {
        if (L1.data[i] <= L2.data[j])
        {
            L3.data[k++] = L1.data[i++];
        }
        else
        {
            L3.data[k++] = L2.data[j++];
        }
    }
    while (i < L1.length)
    {
        L3.data[k++] = L1.data[i++];
    }
    while (j < L1.length)
    {
        L3.data[k++] = L2.data[j++];
    }
    L3.length = k;
}
bool P17_08Reverse(int A[], int left, int right, int arraysize)
{
    if (left >= right || right > arraysize)
    {
        return false;
    }
    int mid = (left + right) / 2;
    for (size_t i = 0; i < mid - left; i++)
    {
        int temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
    return true;
}
void P17_08Exchange(int A[], int m, int n, int arraysize)
{
    P17_08Reverse(A, 0, m + n - 1, arraysize);
    P17_08Reverse(A, 0, n - 1, arraysize);
    P17_08Reverse(A, n, m + n - 1, arraysize);
}
void P17_09SearchExchangeInert(int A[], int x, int n)
{
    int low = 0, high = n - 1, mid;
    while (low <= high) // 二分查找
    {
        mid = (low + high) / 2;
        if (A[mid] == x)
        {
            break;
        }
        else if (A[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (A[mid] == x && mid != n - 1) // 找到了，但是不是最后一个交换位置（因为最后一个不用和后面那个交换位置）
    {
        int t = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = t;
    }
    if (low > high) // 没有找到，插入
    {
        int i;
        for (i = n - 1; i > high; i--)
        {
            A[i + 1] = A[i];
        }
        A[i + 1] = x;
    }
}
void P17_10Reverse(int A[], int from, int to)
{
    int i, temp;
    for (i = 0; i < (to - from + 1) / 2; i++)
    {
        temp = A[from + i];
        A[from + i] = A[to - i];
        A[to - i] = temp;
    }
}
void P17_10Move_left(int A[], int p, int n)
{
    P17_10Reverse(A, 0, p - 1);
    P17_10Reverse(A, p, n - 1);
    P17_10Reverse(A, 0, n - 1);
    // int B[n];
    // int j = p, i;
    // if (p <= 0 || p >= n)
    //     return;
    // for (i = 0; p < n; p++, i++)
    // {
    //     B[i] = A[p];
    // }
    // for (size_t k = 0; k < j; k++, i++)
    // {
    //     B[i] = A[k];
    // }
    // for (size_t i = 0; i < n; i++)
    // {
    //     A[i] = B[i];
    // }
    // 时间复杂度O(n),空间复杂度O(n)
}
int main()
{
    srand(time(NULL)); // 设置随机数种子为当前时间
    SqlList L;
    InitList(L);
    int A[20];
    for (size_t i = 20; i >= 1; i--)
    {
        A[i] = rand() % 100;
        // int input = 0;
        // scanf("%d", &input);
        // add(L, input);
        // add(L, rand() % 10);
    }
    // sort(A, A + 20);
    for (size_t i = 0; i < 20; i++)
    {
        printf("%d\n", A[i]);
    }
    int input = 0;
    scanf("%d", &input);
    P17_10Move_left(A, input, 20);
    printf("---------------------\n");

    // printList(L3);
    for (size_t i = 0; i < 20; i++)
    {
        printf("%d\n ", A[i]);
    }
}
