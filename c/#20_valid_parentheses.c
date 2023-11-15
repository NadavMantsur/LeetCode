#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char* array;
    char* top;
    int capacity;
} Stack;

// Function to initialize a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == stack->array;
}

// Function to push an element onto the stack
void push(Stack* stack, char value) {
    *(stack->top++) = value;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return *(--stack->top);
    }
    return '\0';  // Return a null character for an empty stack
}

/*using pointers*/
bool isValid(char* s) {
    Stack* stack = createStack(strlen(s));

    while ('\0' != *s) {
        if (*s == '(' || *s == '{' || *s == '[') {
            push(stack, *s);
        } 
        else {
            if ((*s == '}' && top(stack) != '{') ||
                (*s == '}' && top(stack) != '{') ||
                (*s == '}' && top(stack) != '{')) {
                free(stack);
                return false;
            }
            else{
                stack.pop();
            }
        }

        ++s;
    }

    free(stack->array);
    free(stack);
    return isEmpty(stack);
}

/******************************************************************************/
/*using indexes*/
bool isValid(char* s) {
    int length = strlen(s);
    Stack* stack = createStack(length);

    for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(stack, s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (isEmpty(stack) || s[i] != pop(stack)) {
                free(stack->array);
                free(stack);
                return false;
            }
        }
    }

    bool result = isEmpty(stack);
    free(stack->array);
    free(stack);
    return result;
}