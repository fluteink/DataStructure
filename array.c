#include <stdio.h>
int main()
{
    int arr[10] = {1, 2, 3, 4, 5};
    printf("%p\n", arr);
    printf("%p\n", &arr);
    printf("%p\n", &arr[0]);
    printf("%d\n", *arr);
    // 输出结果
    return 0;
}