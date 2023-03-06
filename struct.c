#include <stdio.h>

struct people
{
    int age;
    int id;
} a; // a代表什么？

typedef struct cat
{
    int age;
    int id;
} b;

int main()
{
    a.age = 20;
    printf("%d\n", a.age);

    // cat结构体被typedef修饰，表示已经把cat结构体定义为一种类型，这样就可以这样定义一个cat类型的变量b b1,b tom,b robin
    b tom;
    tom.age = 100;
    printf("%d\n", tom.age);
    return 0;
}