#include <stdio.h>
#include <unistd.h>

int main() {
    char str[100];
    printf("Enter string with length up to 99\n");
    fgets(str, 100, stdin);
    printf("Hello world, %s\n", str);
    return 0;
}
