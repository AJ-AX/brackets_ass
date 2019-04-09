// C-implementation of stack 
#include "stack.h" 
  
// function to create a stack of given capacity. 
Stack* createStack(unsigned capacity){
	Stack* stack = (Stack*) malloc(sizeof(Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
	StackNode* head;	
    return stack; 
}

// Stack is full when top index is equal to capacity-1
int isFull(Stack* stack){
	//TODO
	if(stack->top == stack->capacity-1){
		return 1;
	}
	else{
		return 0;
	}
}

// Stack is empty when top is equal to -1 (or head of the list is NULL)
int isEmpty(Stack* stack){
	//TODO
	if(stack->head == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void add_stacknode(StackNode **head, Bracket data){
	StackNode *N = malloc(sizeof(StackNode));
	N->data = data;
	N->next = (*head);
	(*head) = N;
}

// Function to add an item to stack.  
void push(Stack* stack, Bracket item){
	if (isFull(stack)) 
        return;
	else{
		add_stacknode(&(stack->head), item);
		return;
	}
    //TODO
}


// Function to remove an item from stack and return it. 
Bracket pop(Stack* stack){
	Bracket top = stack->head->data;
	StackNode *f = stack->head;
	stack->head = f->next;
	return top;
}