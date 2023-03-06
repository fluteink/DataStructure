#include <stdio.h>
// 举例
enum Sex
{
    MALE,
    FEMALE,
    SECRET
};
// 括号中的MALE,FEMALE,SECRET是枚举常量
int main()
{
    // 字面常量演示
    3.14; // 字面常量
    1000; // 字面常量

    // const 修饰的常变量
    const float pai = 3.14f; // 这里的pai是const修饰的常变量
    // pai = 5.14;              // 是不能直接修改的！

    // #define的标识符常量 演示
#define MAX 100
    printf("max = %d\n", MAX);

    // 枚举常量演示
    printf("%d\n", MALE);
    printf("%d\n", FEMALE);
    printf("%d\n", SECRET);
    // 注：枚举常量的默认是从0开始，依次向下递增1的
    return 0;
}
