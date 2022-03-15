//
//  main.c
//  Exercises-C-Avanced
//
//  Created by Ron Arugeti on 15/03/2022.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Year{
    char hebrew[7];
    unsigned long global;
}Year;

typedef struct Worker{
    unsigned long ID;
    char* Name;
    unsigned long Selary;
    Year started;
}Worker;

typedef struct WorkerList {
Worker* data;
struct WorkerList* next;
} WorkerList;
Worker* CreateWorker(unsigned long id, char* name, unsigned long sel, char year1[7], unsigned long year2, int start);

int main() {
    printf("How are you!\n");
    return 0;
}Worker* CreateWorker(unsigned long id, char* name, unsigned long sel, char year1[7], unsigned long year2, int start){
    Worker* Wr = NULL;
    Wr->ID = id;
    Wr->Selary = sel;
    Wr->Name = (char*)malloc((int)strlen(name) +1);
    strcpy(Wr->Name,name);
    if (start)
        strcpy(Wr->started.hebrew, year1);
    else
        Wr->started.global = year2;
    return Wr;
}
