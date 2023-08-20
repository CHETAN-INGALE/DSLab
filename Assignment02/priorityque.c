#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element elements[MAX_SIZE];
    int size;
} PriorityQueue;

void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(PriorityQueue *pq, int idx) {
    printf("idx = %d\n",idx);
    int left = 2 * idx + 1;
    printf("left = %d\n",left);
    int right = 2 * idx + 2;
    printf("right = %d\n",right);
    int largest = idx;
    printf("largest = %d\n",largest);

    if (left < pq->size && pq->elements[left].priority > pq->elements[largest].priority) {
        largest = left;
    }

    if (right < pq->size && pq->elements[right].priority > pq->elements[largest].priority) {
        largest = right;
    }

    if (largest != idx) {
        swap(&pq->elements[idx], &pq->elements[largest]);
        max_heapify(pq, largest);
    }
}

void insert(PriorityQueue *pq, int data, int priority) {
    if (pq->size == MAX_SIZE) {
        printf("Priority Queue is full.\n");
        return;
    }

    Element newElement = {data, priority};
    int idx = pq->size;
    pq->elements[idx] = newElement;

    while (idx > 0 && pq->elements[(idx - 1) / 2].priority < pq->elements[idx].priority) {
        swap(&pq->elements[(idx - 1) / 2], &pq->elements[idx]);
        idx = (idx - 1) / 2;
    }

    pq->size++;
}

Element extract_max(PriorityQueue *pq) {
    if (pq->size == 0) {
        Element empty = {-1, -1};
        printf("Priority Queue is empty.\n");
        return empty;
    }

    Element max_element = pq->elements[0];
    pq->elements[0] = pq->elements[pq->size - 1];
    pq->size--;

    //max_heapify(pq, 0);

    return max_element;
}

void display(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
    }
    else {
        printf("Priority Queue: ");
        for (int i = 0; i < pq->size; i++) {
            printf("(%d, %d) ", pq->elements[i].data, pq->elements[i].priority);
        }
        printf("\n");
    }
}

int main() {
    PriorityQueue pq = {{0}, 0};  // Initialize an empty priority queue

    int choice, data, priority;

    do {
        printf("\nOptions:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                insert(&pq, data, priority);
                break;
            case 2: {
                Element max_element = extract_max(&pq);
                printf("max_element.data = %d\n",max_element.data);
                if (max_element.data != -1) {
                    printf("Dequeued Element: (%d, %d)\n", max_element.data, max_element.priority);
                }
                break;
            }
            case 3:
                display(&pq);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
