#include <stdio.h>

#define max 5

int front = -1, rear = -1;
int q[max];

void enqueue() {
    int val;
    printf("Enter value :");
    scanf("%d", &val);

    if ((rear + 1) % max == front)
        printf("Queue is full.");
    else if (rear == -1) {
        rear = front = 0;
        q[rear] = val;
        printf("Inserted successfully.");
    }
    else {
        rear = (rear + 1) % max;
        q[rear] = val;
        printf("Inserted successfully.");
    }
}

int dequeue() {
    int val;

    if (front == -1) {
        printf("Queue is empty.");
        return -1;
    }
    else if (front == rear) {
        int val = q[front];
        front = rear = -1;
        printf("Deleted value : %d", val);
        return val;
    }
    else {
        val = q[front];
        front = (front + 1) % max;
        printf("Deleted value : %d", val);
        return val;
    }
}

void display() {
    int i;

    if (front == -1)
        printf("Queue is empty.");
    else {
        printf("Queue is :");
        for (i = front; i != rear; i = (i + 1) % max) {
            printf("%d, ", q[i]);
        }
        printf("%d", q[i]);
    }
}

int main() {
    int choice;
    do {
        printf("\n\nCircular Queue Operations\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
        printf("Exiting...\n");
            break;
        }

    }
    while (choice != 4);

    return 0;
}