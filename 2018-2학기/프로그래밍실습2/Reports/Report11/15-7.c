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
void printhead();

int main()
{
    char fname[] = "score.bin";
    FILE *f;

    if ( (f = fopen(fname, "rb")) == NULL )
    {
        printf("파일이 열리지 않습니다.\n");
        exit(1);
    }
    printhead();

    pscore score;
    fread(&score, sizeof(score), 1, f);
    while ( !feof(f) )
    {
        fprintf(stdout, "%6s%18s%8d%8d%8d\n",
            score.number,
            score.name,
            score.mid,
            score.final,
            score.quiz
        );
        fread(&score, sizeof(pscore), 1, f);
    }
    printf("%s\n", "  ------------------------------------------------");
    fclose(f);

    return 0;
}

void printhead()
{
    printf("%s\n", "  ------------------------------------------------");
    printf("%8s%15s%10d%8d%8d\n", "번호", "이름", "중간", "기말", "퀴즈");
    printf("%s\n", "  ------------------------------------------------");
}