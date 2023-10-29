#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 

struct stack {
    int items[MAX_SIZE];
    int top;
};

void initialize_stack(struct stack *s)
{
    s->top = -1;
}

int is_empty(struct stack *s)
{
    return s->top == -1;
}

int is_full(struct stack *s)
{
    return s->top == MAX_SIZE -1; 
}

void push(struct stack *s, int item)
{
    if (is_full(s))
    {
        printf("stack overflow.\n");
        return; 
    }
    s->top++;
    s->items[s->top] = item;
}

int pop(struct stack *s)
{
    if (is_empty(s))
    {
        printf("stack underflow.\n");
        return -1; 
    }
    int item = s->items[s->top];
    s->top--; 
    return item; 
}

int peek(struct stack *s)
{
    if (is_empty(s))
    {
        printf("Stack is empty\n");
        return -1; 
    }
    return s->items[s->top]; 
}

int main() 
{
    struct stack s; 
    initialize_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element is %d\n", peek(&s));

    pop(&s); 
    pop(&s);

    printf("Top element is: %d\n", peek(&s));

    return 0; 
}
