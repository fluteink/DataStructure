// 代码1
// add.c
// int g_val = 2018;
// // test.c
// int main()
// {
//     printf("%d\n", g_val);
//     return 0;
// }
// 代码2
// add.c
static int g_val = 2018;
// test.c
int test()
{
    printf("%d\n", g_val);
    return 0;
}