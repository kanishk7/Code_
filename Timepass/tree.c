#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "treedef.h"

#define YO printf("yo.\n");







Node initLL(Node head, Dataset start);
Node populateLL(Node head, Dataset data);
void printLL(Node head);
void setDataset(Dataset* set, int n, char *s);













int main()
{
    Dataset sample1, sample2;
    int i; char t;
    srand(time(NULL));
    setDataset(&sample1,125,"Some.");

    //Linked list
    Node head,temp;
    head = initLL(head,sample1);

    //True
    BTnode a;
    return 0;
}

Node initLL(Node head, Dataset start)
{
    head = (struct node*)malloc(sizeof(struct node));
    head->data = start;
    head->next = NULL;

    return head;
}

//Returns the last node.
Node populateLL(Node head, Dataset data)
{

    while(head->next != NULL)
        head = head->next;
    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->next = NULL;
    head->next->data = data;

    return head->next;
}

void printLL(Node head)
{
    while(head->next != NULL)
    {
        printf("%d -> ", head->data.n);
        head = head->next;
    }
    printf("EOL");
    return;
}

void setDataset(Dataset* set, int n, char *s)
{
    set->n=n;
    strcpy(set->s,s);
    return;
}
