// 代码1
// #include <stdio.h>
// void test()
// {
//     int i = 0;
//     i++;
//     printf("%d ", i);
// }
// int main()
// {
//     int i = 0;
//     for (i = 0; i < 10; i++)
//     {
//         test();
//     }
//     return 0;
// }
// 代码2
#include <stdio.h>
void test()
{
    // static修饰局部变量
    static int i = 0;
    i++;
    printf("%d ", i);
}
int main()
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        test();
    }
    return 0;
}