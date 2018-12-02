#include <stdio.h>

typedef struct date
{
    int year;
    int month;
    int day;
} DATE;

typedef struct movie
{
    char title[50];
    char director[30];
    long watches;
    DATE release;
} MOVIE;

int main(void)
{
    MOVIE movieList[5] = {
        { "       명량", "김한민", 17613000, { 2014, 7, 30 } },
        { "     도둑들", "최동훈", 12983000, { 2014, 12, 17 } },
        { "     부산행", "연상호", 11566862, { 2016, 7, 01 } },
        { "   국제시장", "류승완", 14257000, { 2014, 12, 17 } },
        { "택시 운전사", "장훈", 12186205, { 2017, 8, 15 } }
    };

    printf("     제목   \t감독 \t관객수  \t개봉일\n");
    printf("===============================================\n");

    MOVIE movie;
    for (int i = 0; i < 5; i++)
    {
        movie = movieList[i];
        printf("[%s]\t%3s\t%d\t%4d.%2d.%2d\n",
            movie.title,
            movie.director,
            movie.watches,
                movie.release.year,
                movie.release.month,
                movie.release.day
        );
    }
    
    return 0;
}