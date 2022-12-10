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
 * integer and the next field set to NULL. If the queue is empty, the new node is both the front and
 * rear of the queue. Otherwise, the new node is added to the rear of the queue
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


int dequeue()
/* This is the dequeue function. It is removing the first element from the queue. */
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

int isEmpty()
{
 return front==NULL;
}

/**
 * BFS(G,s) visits all the vertices of G that are reachable from s
 * 
 * @param G The graph
 * @param start The starting node
 * @param n number of vertices
 */
void BFS(int G[][7],int start,int n)
{
 int i=start,j;

 int visited[7]={0};

 printf("%d ",i);
 visited[i]=1;
 enqueue(i);

 while(!isEmpty())
 {
    i=dequeue();
    for(j=1;j<n;j++)
    {
        if(G[i][j]==1 && visited[j]==0)
    {
    printf("%d ",j);
    visited[j]=1;
    enqueue(j);
    }
    }
 }
}




int main()
{
    //ADJACENCY MATRIX
    int G[7][7]={{0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,1,0,0,1,0,0},
    {0,1,0,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}};

    BFS(G,4,7);

 return 0;
}