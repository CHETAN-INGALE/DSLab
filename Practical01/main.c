#include <stdio.h>

void storeElements(int arr[], int n) {
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int searchElement(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void sortArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseArray(int arr[], int n) {
    int temp, start = 0, end = n - 1;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice, target, index;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    storeElements(arr, n);

    while (1) {
        printf("\nOperations:\n");
        printf("1. Search an element\n");
        printf("2. Sort the array\n");
        printf("3. Reverse the array\n");
        printf("4. Exit\n");

        printf("Enter your choice (1/2/3/4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &target);
                index = searchElement(arr, n, target);
                if (index != -1) {
                    printf("Element found at index %d\n", index + 1);
                } else {
                    printf("Element not found in the array.\n");
                }
                break;

            case 2:
                sortArray(arr, n);
                printf("Array sorted successfully.\n");
                break;

            case 3:
                reverseArray(arr, n);
                printf("Array reversed successfully.\n");
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a valid option (1/2/3/4).\n");
        }
    }

    return 0;
}