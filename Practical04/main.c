#include <stdio.h>

int queue[10], front = 0, rear = -1;

int isFull() {
    if(rear == 9)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if(rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full: Cannot enqueue element %d\n", value);
    } else {
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty: Cannot dequeue element.\n");
        return -1;
    } else {
        for (int i = 0; i <= rear; i++) {
            queue[i] = queue[i+1];
        }
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\nStack Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}