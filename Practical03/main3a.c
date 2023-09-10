#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Stack {
    char data[MAX_SIZE];
    int top;
}Stack;

void initStack(Stack *parenthesis) {
    parenthesis->top = -1;
}

int isFull(Stack *parenthesis) {
    return parenthesis->top == MAX_SIZE - 1;
}

int isEmpty(Stack *parenthesis) {
    return parenthesis->top == -1;
}

void push(Stack *parenthesis, char value) {
    if (isFull(parenthesis)) {
        printf("Stack overflow");
    } else {
        parenthesis->data[++parenthesis->top] = value;
    }
}

int pop(Stack *parenthesis) {
    if (isEmpty(parenthesis)) {
        printf("Parenthesis are not well formed. 😢\n");
        return 0;
    } else {
        int value = parenthesis->data[parenthesis->top--];
        return value;
    }
}

int balacedParenthesis(char *sentence) {
    Stack parenthesis;
    initStack(&parenthesis);
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == '(')
            push(&parenthesis, sentence[i]);
        else if (sentence[i] == ')' && pop(&parenthesis) != '(') {
            return 0;
        }  
    }
    if (isEmpty(&parenthesis)){
        printf("Parenthesis are well formed. 😄\n");
        return 1;
    }
    else {
        printf("Parenthesis are not well formed. 😢\n");
        return 0;
    }
}

int main() {
    char sentence[100];

    printf("Eneter a Sentence : ");
    fgets(sentence, sizeof(sentence), stdin);
    balacedParenthesis(sentence);

    return 0;
}