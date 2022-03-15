//
//  main.c
//  Exercises-C-Avanced
//
//  Created by Ron Arugeti 
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
void PrintWorker(Worker* wr, int start);
WorkerList * addWorker(WorkerList *head, Worker * w);

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
}void PrintWorker(Worker* wr, int start){
    printf("Worker's Name: %s", wr->Name);
    printf("Worker's ID: %lu", wr->ID);
    printf("Worker's Salery: %lu", wr->Selary);
if (start)
    printf("Worker's starting year: %s", wr->started.hebrew);
else
    printf("Worker's starting year: %lu", wr->started.global);
}WorkerList * addWorker(WorkerList *head, Worker * w){
   static WorkerList *temp1, *temp2, *temp3;
    do {
        temp3 = head;
    } while (!temp2);
    if(head->data->Selary > w->Selary){
        temp1->data = w;
        temp1->next = head;
        temp2->next = temp1;
        return temp3;
    }
    temp2 = head;
    return addWorker(head->next, w);
}
