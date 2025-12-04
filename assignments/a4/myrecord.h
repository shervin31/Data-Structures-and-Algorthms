#ifndef MYRECORD_H
#define MYRECORD_H
#include <stdio.h>


#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    float score;
} RECORD;

typedef struct {
    int count;
    float mean;
    float stddev;
    float median;
} STATS;

typedef struct {
    char letter_grade[3];
} GRADE;

GRADE grade(float score);
int import_data(FILE *fp, RECORD *dataset);
STATS process_data(RECORD *dataset, int count);
int report_data(FILE *fp, RECORD *dataset, STATS stats);

#endif
