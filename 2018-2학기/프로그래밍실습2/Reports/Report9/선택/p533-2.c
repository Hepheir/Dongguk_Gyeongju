#include <stdio.h>
#include <string.h>

void mystrcat(char s1[], const char s2[])
{
    int offset, i;
    offset = 0;
    while (s1[offset]) offset++;
    // s1의 널 문자 이후부터는 s2를 대입함
    i = 0;
    while (s2[i]) 
    {
        s1[offset + i] = s2[i];
        i++;
    }
}

int main(void)
{
    char s1[50] = "C ";
    mystrcat(s1, "programming language");
    printf("%s\n", s1);
    return 0;
}