#include <stdio.h>
#include <stdlib.h>

typedef struct score
{
    int number;
    char name[40];
    float point1;
    float point2;
    float point3;
    float sum;
} SCORE;

int main()
{
    char f_inputName[] = "in.txt";
    FILE *f_input;

    char f_outputName[] = "out.txt";
    FILE *f_output;

    if ( (f_input = fopen(f_inputName, "r")) == NULL )
    {
        printf("파일이 열리지 않습니다.\n");
        exit(1);
    }

    if ( (f_output = fopen(f_outputName, "w")) == NULL )
    {
        printf("파일이 열리지 않습니다.\n");
        exit(1);
    }

    char line[80];
    SCORE score;

    while (!feof(f_input)) {
        fgets(line, 80, f_input);
        sscanf(line, "%d %s %f %f %f",
            &score.number,
            score.name,
            &score.point1,
            &score.point2,
            &score.point3
        );
        score.sum = score.point1 + score.point2 + score.point3;
        fprintf(f_output, "%4d\t%12s\t%8.2f\t%8.2f\t%8.2f\t 합계: %.2f\n",
            score.number,
            score.name,
            score.point1,
            score.point2,
            score.point3,
            score.sum
        );
        printf("%3d %8s %5.2f %5.2f %5.2f %6.2f\n",
            score.number,
            score.name,
            score.point1,
            score.point2,
            score.point3,
            score.sum
        );
    }
    fclose(f_input);
    fclose(f_output);

    return 0;
}