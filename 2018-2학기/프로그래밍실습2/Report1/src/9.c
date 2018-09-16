#include <stdio.h>

int main()
{
   char isLier;

   int Innesim = 9;

   printf("당신은 거짓말을 한 적이 있습니까? (Y/N) : ");
   scanf("%c", &isLier);

   while(1)
   {
       if (isLier == 'Y' || isLier == 'y')
       {
           printf("알고 있었어요.\n");
           break;
       }

       if (Innesim < 0)
       {
           printf("거짓말 치지마요.\n");
           break;
       }

       printf("진짜로 당신은 거짓말을 한 적이 없나요? (Y/N): ");
       scanf(" %c", &isLier);

       // 부정형으로 질문하였으니 한국 문법에 맞게 대답을 역전 시켜준다.
       isLier = (isLier == 'Y' || isLier == 'y') ? 'N' : 'Y';

       Innesim--;
   }

   return 0;
}