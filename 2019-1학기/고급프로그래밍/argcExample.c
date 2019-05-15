#include <stdio.h>
#include <stdlib.h>



//  projector_name from_file to_file

int main(int argc, char* argv[])
{
    char *team[4] = { "스위스", "프랑스", "대한민국", "토고"};
    int marks[4] = {4, 3, 3, 1};
    int i;
    char c;
    FILE *fp1, *fp2;

    printf("\n\n");
    printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++) printf("argv[%d]=%s\n", i, argv[i]);

    fp1 = fopen(argv[1], "w");
    // fopen_s(&fp1, argv[1], "w");
    if (fp1 == NULL) {
        printf("Write File Open Error\n");
        exit(1);
    }
    for (i = 0; i < 4; i++) {
        fprintf(fp1, "%s %d\n", team[i], marks[i]);
    }
    fclose(fp1);


    // fopen_s(&fp1, argv[1], "r");
    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        printf("Read File Open Error\n");
        exit(1);
    }
    
    fp2 = fopen(argv[2], "w");
    // fopen_s(&fp2, argv[2], "w");
    if (fp2 == NULL) {
        printf("Write File Open Error\n");
        exit(1);
    }

    while ((c = fgetc(fp1)) != EOF) {
        printf("%c", c);
        fputc(c, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
