// wb는 binary모드로 write
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct personscore
{
    int number;
    char name[40];
    int mid;
    int final;
    int quiz;
};
typedef struct personscore pscore;

int main()
{
    char fname[] = "score.bin";
    FILE *f;

    // if (fopen_s(&f, fname, "wb") != 0)
    if ( (f = fopen(fname, "wb")) == NULL )
    {
        printf("파일이 열리지 않습니다.\n");
        exit(1);
    };
    
    char line[80];
    int cnt = 0;
    pscore score;
    printf("이름과 성적(중간, 기말, 퀴즈)을 입력하세요.\n");

    fgets(line, 80, stdin);
    while (!feof(stdin))
    {
        // sscanf_s(line, "%s %d %d %d", score.name, 40,
        //     &score.mid, &score.final, &score.quiz);
        sscanf(line, "%s %d %d %d", score.name,
            &score.mid, &score.final, &score.quiz);
        score.number = ++cnt;
        fwrite(&score, sizeof(pscore), 1, f);
        fgets(line, 80, stdin);
    }
    fclose(f);

    return 0;
}