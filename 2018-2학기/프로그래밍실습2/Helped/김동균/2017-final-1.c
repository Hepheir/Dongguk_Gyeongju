#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ary[7] = { 10,20,30,40,50,60,70 };
void copyarray(int*source, int*dest, int size);

int main(void)
{
   int ary2[7] = { 0 };
   int i = 0;
   copyarray(ary, ary2, 7);
   printf("원본   복사\n");
   while (ary[i] != '\0')
   {
      printf("%d   %d\n", ary[i], ary2[i]);
      i++;
   }
}
void copyarray(int*source, int*dest, int size)
{
   for (int i = 0; i < size;i++)
   {
      dest[i] = source[i];
   }
}