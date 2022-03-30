#define _CRT_SECURE_NO_WORNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
typedef struct Worker{
    unsigned long ID;     //"ID" is only positive number representing the id of the worker
    char* Name;    //"Name" represent the name of the worker
    unsigned long Salary;   //"Salary" is only a positive number representing the salery of the worker
    int start;
    union Year{
       char hebrew[7];
       unsigned long global;
    }year;                   //"year" used as a field in worker structure
    }Worker;          //"Worker" is a structure of worker's data

typedef struct WorkerList {
Worker* data;
struct WorkerList* next;
} WorkerList;            //"WorkerList" is a list of workers data

Worker* CreateWorker(unsigned long id, char* name, unsigned long sel, char year1[7], unsigned long year2, int start);
void PrintWorker(Worker* wr, int start);
WorkerList* addWorker(WorkerList *head, Worker * w);
int index_r(WorkerList* head, unsigned long id);
int index_l(WorkerList* head, unsigned long id);
void update_worker(WorkerList *head, float percent);
WorkerList* reverse(WorkerList *head);
void freeWorkers(WorkerList *head);
void print_e(void);

unsigned long id = 0, salary = 0, g_year = 0;
    char h_year[6];
    char* full_name;
    int start;

int main()
{
    WorkerList* List_w = (struct WorkerList*)malloc(sizeof(struct WorkerList));
    Worker* worker1 = (struct Worker*)malloc(sizeof(struct Worker));
    Worker* worker2 = (struct Worker*)malloc(sizeof(struct Worker));
    Worker* worker3 = (struct Worker*)malloc(sizeof(struct Worker));
    if (!worker1 || !worker2 || !worker3){ printf("allocation failed!\n"); exit(1);}
    print_e();
    worker1 = CreateWorker(id, full_name, salary, h_year, g_year, start);
    free(full_name);
    print_e();
    worker2 = CreateWorker(id, full_name, salary, h_year, g_year, start);
    free(full_name);
    print_e();
    worker3 = CreateWorker(id, full_name, salary, h_year, g_year, start);
    free(full_name);

    addWorker(List_w, worker1);
    addWorker(List_w, worker2);
    addWorker(List_w, worker3);

    PrintWorker(List_w->data, 1);
    PrintWorker(List_w->next->data, 0);
    PrintWorker(List_w->next->next->data, 0);
    reverse(List_w);

    return 0;
}
Worker* CreateWorker(unsigned long id, char* name, unsigned long sal, char year1[7], unsigned long year2, int start)
{
    fseek(stdin, 0, SEEK_END);
    Worker* Wr = (Worker*)malloc(sizeof(Worker)); //memory allocation for "Wr" - which is pointer for worker structure
    if (!Wr) {
        printf("allocation failed!\n");
        exit(1);
    } //checking for seuccses in allocation
    Wr->ID = id; //setting value of the ID in "Wr"
    Wr->Salary = sal;  //setting value of the salary in "Wr"
    Wr->Name = (char*)malloc((int)strlen(name)); //memory allocation for "Wr" is Name - which is a string
    if(!Wr->Name){
        printf("full of memory!\n");
    exit(1);
    } //checking for seuccses in allocation
    strcpy(Wr->Name,name);
    if (start) //checking if the year "Wr" started to work is in the hebrew or gregorin calendery
    strcpy(Wr->year.hebrew, year1);
    else
        Wr->year.global = year2;
    return Wr;
}
void PrintWorker(Worker* wr,int start)
{
    printf("Worker's Name: %sֿֿ\n", wr->Name);
    printf("Worker's ID: %lu\n", wr->ID);
    printf("Worker's Salery: %lu\n", wr->Salary);
if (start)
    printf("Worker's starting year:%s\n", wr->year.hebrew);
else
    printf("Worker's starting year: %lu\n", wr->year.global);
}
WorkerList *addWorker(WorkerList *head, Worker *w)
{
    WorkerList *temp1 = (struct WorkerList*)malloc(sizeof(struct WorkerList));
    WorkerList *temp2 = (struct WorkerList*)malloc(sizeof(struct WorkerList));
    if (!temp1 || !temp2) { printf("allocation failed!\n"); exit(1);}
    
    if (head == NULL){ temp1->data = w; temp1->next = NULL; return temp1;}
    temp1 = temp2 = head;
    if (temp1->next != NULL) {
        while (temp1) {
     if ((temp1->data->Salary > w->Salary) || (temp1->next->data->Salary < w->Salary)) {
         temp2->next = temp1->next;
         temp1->next = temp2;
         temp2->data = w;
     }
            temp1 = temp1->next;
        }}
    else if (temp1->data->Salary > w->Salary)
    {
        temp1->data = w;
        head->next = temp1;
    }
else {
    temp1->next = head;
    temp1->data = w;
}
    return head;
}
int index_r(WorkerList* head, unsigned long id)
{
    static int k = 1;
    if (head->data->ID == id){
        return k;
    }
    k++;
    index_r(head->next, id);
    return -1;
}
int index_l(WorkerList* head, unsigned long id)
{
    int k = 1;
    WorkerList* temp;
    temp = head;
    if (!head) {
        return -1;
    }
    while (temp) {
        if (temp->data->ID == id) {
            break; }
        temp = temp->next;
        k++;
    }
    return k;
}
WorkerList* deleteWorstWorker(WorkerList *head)
{
 static WorkerList *temp1 = NULL, *temp2 = NULL;
    if (!temp2){
        temp1 = head;
    temp2 = head;}
    if(!head){
        printf("List is empty!\n");
        return temp1;
    }
        if(!head->next) {
            if (head->data->Salary < temp2->data->Salary){
                free(head->data->Name);
                free(head->data);
            head = NULL;
            }
            else
                free(temp2->data->Name);
            free(temp2->data);
            temp2 = NULL;
                return temp1;
        }
    if (head->data->Salary < temp2->data->Salary)
    temp2 = head;
    return deleteWorstWorker(head->next);
}
void update_worker(WorkerList *head, float percent)
{
    WorkerList* temp = head;
    while (temp) {
        temp->data->Salary = (unsigned long)(temp->data->Salary * (1+ percent));
        temp->next = temp;
    }
    return;
}
WorkerList* reverse(WorkerList *head)
{
    if (!head->next)
        return head;
    
   return reverse(head->next)->next = head;
}
void freeWorkers(WorkerList *head)
{
    WorkerList *temp = (struct WorkerList*)malloc(sizeof(WorkerList));
    if (!temp) { printf("allocation faild!\n"); exit(1); }
    temp = head;
    while (head)
    {
        temp = head->next;
        free(temp->data->Name);
        free(temp->data);
        head = head->next;
    }
    free(temp);
    return;
}
void print_e(void)
{
    full_name = (char*)malloc(sizeof(SIZE));
    printf("Please enter your ID: ");
    scanf("%lu", &id);
    printf("Please enter full name: ");
    fseek(stdin, 0, SEEK_END);
    fgets(full_name, SIZE, stdin);
    *(full_name + (int)strlen(full_name) -1) = '\0';
    printf("Please enter your salary:  ");
    scanf("%lu", &salary);
    printf("Please enter 1 if you used to write years in hebrew calndery or 0 if you used to write years in gregorian calendry: ");
    scanf("%d",&start);
    printf("Please enter the year you have started to work:  \n");
    fseek(stdin, 0, SEEK_END);
    if (start)
        scanf("%s",h_year);
    else
        scanf("%lu",&g_year);
    }
