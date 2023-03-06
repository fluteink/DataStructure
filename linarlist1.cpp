#include <stdio.h>
void test(int &x)
{
    x = 1024;
    printf("test函数内部 x=%d\n", x);
    printf("%p\n", &x);
}
int main()
{
    int x = 1;
    printf("text调用前 x=%d\n", x);
    printf("%p\n", &x);
    test(x);
    printf("text调用后 x=%d\n", x);
    printf("%p\n", &x);
}