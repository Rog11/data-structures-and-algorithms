#define MAX_QUEUE_SIZE 100

struct Queue {
  int front;
  int rear;
  int data[MAX_QUEUE_SIZE];
};

void enqueue(struct Queue *queue, int value) 
{
  if ((queue->rear + 1) % MAX_QUEUE_SIZE != queue->front) 
  {
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->data[queue->rear] = value;
  }
  else 
  {
    printf("Error: queue overflow\n");
  }
}

int dequeue(struct Queue *queue) 
{
  if (queue->front != queue->rear) 
  {
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return queue->data[queue->front];
  } 
  else
  {
    printf("Error: queue underflow\n");
    return -1;
  }
}

int peek(struct Queue *queue)
{
  if (queue->front != queue->rear)
  {
    return queue->data[(queue->front + 1) % MAX_QUEUE_SIZE];
  }
  else
  {
    printf("Error: queue is empty\n");
    return -1;
  }
}

int main()
{
  struct Queue queue;
  queue.front = 0;
  queue.rear = 0;
  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);
  printf("%d\n", dequeue(&queue));  // prints 10
  printf("%d\n", peek(&queue));  // prints 20
  return 0;
}



#include <stdio.h>
#include <stdlib.h>

struct queue {
  int data; 
  struct queue *next;
}; 

struct queue *front = NULL; 
struct queue *rear = NULL;

void enqueue (int item)
{
  struct queue *new_node = (struct queue*)malloc(sizeof(struct queue));
  new_node->data = item; 
  new_node->next = NULL;

  if (front == NULL && rear == NULL)
  {
    front = rear = new_node; 
    return; 
  }
  rear->next = new_node; 
  rear = new_node;
}

void dequeue()
{
  struct queue *temp = front; 
  if (front = NULL)
  {
    printf("Queue is empty\n");
    return; 
  }
  if (front == rear)
  {
    front = rear = NULL;
  }
  else 
  {
    front = front->next; 
  }
  free(temp);
}

int peek()
{
  if (front == NULL)
  {
    printf("Queue is empty\n");
    return -1; 
  }
  return front->data; 
}

int is_empty()
{
  return front == NULL;
}

int main()
{
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40); 

  printf("Fron element is %d\n", peek());

  dequeue();
  dequeue();

  printf("Front element is %d\n", peek());

  return 0;
}