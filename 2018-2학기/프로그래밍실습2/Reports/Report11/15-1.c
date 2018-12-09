#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *fname = "basic.txt";
    FILE *f;

    char name[30] = "김동주";
    int point = 100;

    if ( (f = fopen(fname, "w")) == NULL )
    {
        printf("파일이 열리지 않습니다.\n");
        exit(1);
    }

    fprintf(f, "이름이 %s인 학생의 성적은 %d 입니다.\n", name, point);
    fclose(f);

    printf("이름이 %s인 학생의 성적은 %d 입니다.\n", name, point);
    fclose(f);

    puts("프로젝트 폴더에서 파일 basic.txt를 메모장으로 열어 보세요.");

    return 0;
}