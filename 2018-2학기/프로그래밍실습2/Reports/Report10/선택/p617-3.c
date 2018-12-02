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
        { "       ��", "���ѹ�", 17613000, { 2014, 7, 30 } },
        { "     ���ϵ�", "�ֵ���", 12983000, { 2014, 12, 17 } },
        { "     �λ���", "����ȣ", 11566862, { 2016, 7, 01 } },
        { "   ��������", "���¿�", 14257000, { 2014, 12, 17 } },
        { "�ý� ������", "����", 12186205, { 2017, 8, 15 } }
    };

    printf("     ����   \t���� \t������  \t������\n");
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