#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mysort.h"
#include "myrecord.h"

typedef struct {
    float min;
    float max;
    char grade[3];
} GRADE_RANGE;

static GRADE_RANGE grades[] = {
    {90,100,"A+"},{85,90,"A"},{80,85,"A-"},
    {77,80,"B+"},{73,77,"B"},{70,73,"B-"},
    {67,70,"C+"},{63,67,"C"},{60,63,"C-"},
    {57,60,"D+"},{53,57,"D"},{50,53,"D-"},
    {0,50,"F"}
};

GRADE grade(float score){
    int left=0, right=sizeof(grades)/sizeof(grades[0])-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(score>=grades[mid].min && score<=grades[mid].max){
            GRADE g; strcpy(g.letter_grade,grades[mid].grade); return g;
        }
        else if(score<grades[mid].min) right=mid-1;
        else left=mid+1;
    }
    GRADE g; strcpy(g.letter_grade,"F"); return g;
}

int import_data(FILE *fp, RECORD *dataset){
    int count=0;
    while(fscanf(fp,"%[^,],%f\n",dataset[count].name,&dataset[count].score)==2) count++;
    return count;
}

static int cmp_rec(void *x, void *y){
    float a = (*(RECORD**)x)->score;
    float b = (*(RECORD**)y)->score;
    if(a<b) return -1;
    else if(a>b) return 1;
    return 0;
}

STATS process_data(RECORD *dataset,int count){
    STATS s={0,0,0,0};
    if(count<1) return s;
    s.count=count;
    float sum=0;
    for(int i=0;i<count;i++) sum+=dataset[i].score;
    s.mean=sum/count;

    float var=0;
    for(int i=0;i<count;i++) var+=(dataset[i].score-s.mean)*(dataset[i].score-s.mean);
    s.stddev=sqrt(var/count);

    RECORD *ptrs[count];
    for(int i=0;i<count;i++) ptrs[i]=&dataset[i];
    my_sort((void*)ptrs,0,count-1,cmp_rec);

    if(count%2==0) s.median=(ptrs[count/2-1]->score + ptrs[count/2]->score)/2.0;
    else s.median=ptrs[count/2]->score;
    return s;
}

int report_data(FILE *fp, RECORD *dataset, STATS stats){
    if(stats.count<1) return 0;
    fprintf(fp,"stats:value\ncount:%d\nmean:%.1f\nstddev:%.1f\nmedian:%.1f\n\n",stats.count,stats.mean,stats.stddev,stats.median);
    fprintf(fp,"name:score,grade\n");

    RECORD *ptrs[stats.count];
    for(int i=0;i<stats.count;i++) ptrs[i]=&dataset[i];
    my_sort((void*)ptrs,0,stats.count-1,cmp_rec);

    for(int i=stats.count-1;i>=0;i--){
        GRADE g=grade(ptrs[i]->score);
        fprintf(fp,"%s:%.1f,%s\n",ptrs[i]->name,ptrs[i]->score,g.letter_grade);
    }
    return 1;
}
