#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

struct Employee
{
    int employee_id;
    char name[20];
    int salary;
};

struct Node
{
    struct Employee em;
    struct Node *next;
};

void insertFirst(struct Node**head,int id,char *name,int salary)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->em.employee_id=id;
    for(int i=0;name[i]!='\0';i++) temp->em.name[i]=name[i];
    temp->em.salary=salary;

    if(*head==NULL) *head=temp;
    else
    {
        temp->next=*head;
        (*head)=temp;
    }
}

void insertLast(struct Node **head,int id ,char *name,int salary)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->em.employee_id=id;
    for(int i=0;name[i]!='\0';i++) temp->em.name[i]=name[i];
    temp->em.salary=salary;

    if(*head==NULL) *head=temp;
    else
    {
        struct Node *p=*head;
        while(p->next) p=p->next;
        p->next=temp;
    }
}

struct Node* deleteFirst(struct Node **head)
{
    if(*head==NULL) return NULL ;
    struct Node *p=*head;
    (*head)=(*head)->next;
    return p;
}

struct Node* deleteLast(struct Node **head)
{
    struct Node *p=*head;
    struct Node *tail=NULL;
    while(p->next)
    {
        tail=p;
        p=p->next;
    }
    tail->next=NULL;
    return p;
}

struct Node* getLast(struct Node *head)
{
    if(head==NULL) return NULL;
    struct Node *p=head;
    while(p->next) p=p->next;
    return p;
}

void insertAfterRefNode(struct Node **head,struct Node *ref,int id ,char *name,int salary)
{
    if(*head==NULL || ref==NULL) return ;
    if(ref==getLast(*head)) {insertLast(head,id ,name,salary);return;}
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->em.employee_id=id;
    for(int i=0;name[i]!='\0';i++) temp->em.name[i]=name[i];
    temp->em.salary=salary;
    struct Node *p=*head;
    while(p!=ref) p=p->next;
    temp->next=p->next;
    p->next=temp;
}

void insertBeforeRefNode(struct Node **head,struct Node *ref,int id ,char *name,int salary)
{
    if(*head==NULL || ref==NULL) return ;
    if(ref==*head) {insertFirst(head,id,name,salary);return;}
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->em.employee_id=id;
    for(int i=0;name[i]!='\0';i++) temp->em.name[i]=name[i];
    temp->em.salary=salary;
    struct Node *p=*head;
    struct Node *tail=NULL;
    while(p!=ref)
    {
        tail=p;
        p=p->next;
    }
    temp->next=p;
    tail->next=temp;
}


struct Node *deleteBeforeRefNode(struct Node **head,struct Node *ref)
{
    if(*head==NULL || ref==NULL || ref==*head) return NULL;
    if(ref==(*head)->next)
    {
        struct Node *p=*head;
        (*head)=(*head)->next;
        return p;
    }
    struct Node *p=*head;
    while(p->next!=ref) p=p->next;
    p->next=ref->next;
}

struct Node *deleteAfterRefNode(struct Node **head,struct Node *ref)
{
    if(*head==NULL || ref==NULL || ref==getLast(*head)) return NULL;
    struct Node *p=*head;
    struct Node *q;
    if((*head)->next) 
    {
        q=(*head)->next;
    }
    while(p!=ref && q && p) 
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    return q;
}



struct Node* partition_id(struct Node*first,struct Node*last)
{
    struct Node *pivot=first;
    struct Node *front=first;
    int id;
    int sal;
    char name[20];
    while(front && front!=last)
    {
        pivot=first;
        

        if(front->em.employee_id<last->em.employee_id)
        {
            

            id=first->em.employee_id;
            first->em.employee_id=front->em.employee_id;
            front->em.employee_id=id;

            sal=first->em.salary;
            first->em.salary=front->em.salary;
            front->em.salary=sal;

            strcpy(name,first->em.name);
            strcpy(first->em.name,front->em.name);
            strcpy(front->em.name,name);

            first=first->next;

        }
        front=front->next;

    }

    id=first->em.employee_id;
    first->em.employee_id=last->em.employee_id;
    last->em.employee_id=id;

    sal=first->em.salary;
    first->em.salary=last->em.salary;
    last->em.salary=sal;

    strcpy(name,first->em.name);
    strcpy(first->em.name,last->em.name);
    strcpy(last->em.name,name);

    return pivot;
}       

void quickSort_id(struct Node*first,struct Node *last)
{
    if(first==last) return ;
    struct Node *pivot=partition_id(first,last);

    if (pivot != NULL && pivot->next != NULL) { 
		quickSort_id(pivot->next, last); 
	} 

	if (pivot != NULL && first != pivot) { 
		quickSort_id(first, pivot); 
	} 
}

struct Node* partition_sal(struct Node*first,struct Node*last)
{
    struct Node *pivot=first;
    struct Node *front=first;
    int id;
    int sal;
    char name[20];
    while(front && front!=last)
    {
        pivot=first;
        

        if(front->em.salary<last->em.salary)
        {
            

            id=first->em.employee_id;
            first->em.employee_id=front->em.employee_id;
            front->em.employee_id=id;

            sal=first->em.salary;
            first->em.salary=front->em.salary;
            front->em.salary=sal;

            strcpy(name,first->em.name);
            strcpy(first->em.name,front->em.name);
            strcpy(front->em.name,name);

            first=first->next;

        }
        front=front->next;

    }

    id=first->em.employee_id;
    first->em.employee_id=last->em.employee_id;
    last->em.employee_id=id;

    sal=first->em.salary;
    first->em.salary=last->em.salary;
    last->em.salary=sal;

    strcpy(name,first->em.name);
    strcpy(first->em.name,last->em.name);
    strcpy(last->em.name,name);

    return pivot;
}       

void quickSort_sal(struct Node*first,struct Node *last)
{
    if(first==last) return ;
    struct Node *pivot=partition_sal(first,last);

    if (pivot != NULL && pivot->next != NULL) { 
		quickSort_sal(pivot->next, last); 
	} 

	if (pivot != NULL && first != pivot) { 
		quickSort_sal(first, pivot); 
	}
}

void displaytheLinkedList(struct Node *head)
{
    struct Node *p=head;
    while(p)
    {
        printf("Employee ID: %d | Name: %s | Salary: %d\n",p->em.employee_id,p->em.name,p->em.salary);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    struct Node *LL1=NULL;

    

    insertFirst(&LL1,789,"Napoleon",9999);
    insertLast(&LL1,390,"OppenHymen",5555);
    insertLast(&LL1,290,"ChadMan",4555);
    insertLast(&LL1,570,"BruhMan",2323);
    insertLast(&LL1,490,"Skibidi",1000);
    insertLast(&LL1,870,"Peter Griffith",1500);
    insertLast(&LL1,800,"MusCat",500);
    insertLast(&LL1,900,"SusBOy",4392);
    insertLast(&LL1,401,"LadyBoy",34);
    insertLast(&LL1,101,"GayBrad",908);

    displaytheLinkedList(LL1);
    printf("Sorted according to Employee ID...\n\n");
    quickSort_id(LL1,getLast(LL1));   //to sort on Employee ID
    displaytheLinkedList(LL1);
    printf("Sorted according to Salary...\n\n");
    quickSort_sal(LL1,getLast(LL1));   //to sort on salary
    displaytheLinkedList(LL1);
    return 0;
}