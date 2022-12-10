#include <stdio.h>
#include <stdlib.h>

/**
 * A Queue is a structure that contains an integer size, an integer front, an integer rear, and a
 * pointer to an integer.
 * @property {int} size - The size of the queue.
 * @property {int} front - The index of the front element of the queue.
 * @property {int} rear - The index of the last element in the queue.
 * @property {int} Q - This is the array that will hold the elements of the queue.
 */
struct Queue
{
 int size;
 int front;
 int rear;
 int *Q;
};


/**
 * The function creates a queue of size size and initializes the front and rear to -1.
 * 
 * @param q pointer to the queue
 * @param size The size of the queue.
 */

void create(struct Queue *q,int size)
{
 q->size=size;
 q->front=q->rear=-1;
 q->Q=(int *)malloc(q->size*sizeof(int));
}


/**
 * The function enqueue() takes a pointer to a queue and an integer as arguments and adds the integer
 * to the queue
 * 
 * @param q pointer to the queue
 * @param x The value to be inserted into the queue
 */
void enqueue(struct Queue *q,int x)
{
 if(q->rear==q->size-1)
 printf("Queue is Full");
 else
 {
 q->rear++;
 q->
 Q[q->rear]=x;
 }
}


/**
 * If the queue is not empty, then increment the front pointer and return the element at the front
 * pointer
 * 
 * @param q pointer to the queue
 * 
 * @return The value of the front of the queue.
 */
int dequeue(struct Queue *q)
{
 int x=-1;

 if(q->front==q->rear)
 printf("Queue is Empty\n");
 else
 {
 q->front++;
 x=q->Q[q->front];
 }
 return x;
}


/**
 * The function Display() displays the elements of the queue
 * 
 * @param q The queue
 */
void Display(struct Queue q)
{
 int i;

 for(i=q.front+1;i<=q.rear;i++)
 {
 printf("%d ",q.Q[i]);
 printf("\n");
 }
}



int main()
{
 struct Queue q;
 create(&q,5);

 enqueue(&q,10);
 enqueue(&q,20);
 enqueue(&q,30);
 Display(q);

 printf("%d ",dequeue(&q));
 return 0;
}