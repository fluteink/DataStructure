// #include <stdio.h>
// int main()
// {
//     // 问题1：在屏幕上打印一个单引号'，怎么做？
//     // 问题2：在屏幕上打印一个字符串，字符串的内容是一个双引号“，怎么做？
//     printf("%c\n", '\'');
//     printf("%s\n", "\"");
//     return 0;
// }
#include <stdio.h>
int main()
{
    printf("%d\n", strlen("abcdef"));
    // \62被解析成一个转义字符
    printf("%d\n", strlen("c:\test\628\test.c"));
    return 0;
}
