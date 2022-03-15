//
//  main.c
//  Exercises-C-Avanced
//
//  Created by Ron Arugeti on 15/03/2022.
//
#include <string.h>
#include <stdio.h>
typedef struct year{
    char heberw[6];
    int global;
}year;

typedef struct Worker{
    int ID;
    char* name;
    int selary;
    year* started;
}Worker;

typedef struct WorkerList {
Worker* data;
struct WorkerList* next;
} WorkerList;

int main() {
    printf("How are you!\n");
    return 0;
}

