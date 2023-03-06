// #include <stdio.h>
// int main()
// {
//     int num = 10;
//     &num; // 取出num的地址
//     int *p;
//     p = &num;
//     // 注：这里num的4个字节，每个字节都有地址，取出的是第一个字节的地址（较小的地址）
//     printf("%p\n", &num); // 打印地址，%p是以地址的形式打印
//     // printf("%d", *p);
//     return 0;
// }
// #include <stdio.h>
// int main()
// {
//     char ch = 'w';
//     char *pc = &ch;
//     *pc = 'q';
//     printf("%c\n", ch);
//     return 0;
// }
#include <stdio.h>
// 指针变量的大小取决于地址的大小
// 32位平台下地址是32个bit位（即4个字节）
// 64位平台下地址是64个bit位（即8个字节）
int main()
{
    printf("%d\n", sizeof(char *));
    printf("%d\n", sizeof(short *));
    printf("%d\n", sizeof(int *));
    printf("%d\n", sizeof(double *));
    return 0;
}
