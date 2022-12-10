#include <stdio.h>
#include <stdlib.h>

/* Creating a structure called Node with two members, data and next. It is also creating two pointers
to Node, front and rear, and initializing them to NULL. */
struct Node
{
 int data;
 struct Node *next;
 
}*front=NULL,*rear=NULL;


/**
 * The function takes an integer as an argument and creates a new node with the data field set to the
 * integer. It then adds the new node to the end of the queue
 * 
 * @param x The value to be inserted into the queue.
 */
void enqueue(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
    printf("Queue is FUll\n");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
            {
            rear->next=t;
            rear=t;
            }
    }
 
}

/**
 * If the queue is empty, print a message and return -1. Otherwise, remove the first element from the
 * queue, return its value, and free the memory used by the removed element
 * 
 * @return The value of the node that is being dequeued.
 */
int dequeue()
{
 int x=-1;
 struct Node* t;
 
 if(front==NULL)
    printf("Queue is Empty\n");
 else
    {
    x=front->data;
    t=front;
    front=front->next;
    free(t);
    }
 return x;
}


/**
 * It prints the data of each node in the queue, starting from the front node, until it reaches the end
 * of the queue
 */
void Display()
{
 struct Node *p=front;
 while(p)
 {
    printf("%d ",p->data);
    p=p->next;
 }
 printf("\n");
}

int main()
{
 enqueue(10);
 enqueue(20);
 enqueue(30);
 enqueue(40);
 enqueue(50);
 
 Display();
 
 printf("%d ",dequeue());
 
 return 0;
}