#define MAX_STACK_SIZE 100

struct Stack {
  int top;
  int data[MAX_STACK_SIZE];
};

void push(struct Stack *stack, int value)
{
  if (stack->top < MAX_STACK_SIZE - 1) {
    stack->top++;
    stack->data[stack->top] = value;
  } else {
    printf("Error: stack overflow\n");
  }
}

int pop(struct Stack *stack) {
  if (stack->top >= 0) {
    int value = stack->data[stack->top];
    stack->top--;
    return value;
  } else {
    printf("Error: stack underflow\n");
    return -1;
  }
}

int peek(struct Stack *stack) {
  if (stack->top >= 0) {
    return stack->data[stack->top];
  } else {
    printf("Error: stack is empty\n");
    return -1;
  }
}

int main() {
  struct Stack stack;
  stack.top = -1;
  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);
  printf("%d\n", pop(&stack));  // prints 30
  printf("%d\n", peek(&stack));  // prints 20
  return 0;
}


