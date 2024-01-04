#include <stdio.h>

#define MAX_SIZE 3
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int element) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("\nQueue is full. Cannot enqueue element %d", element);
    } else {
        if (front == -1 && rear == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = element;
    }
}

int dequeue() {
    int dequeuedElement = -1; 

    if (front == -1 && rear == -1) {
        printf("\nQueue is empty. Cannot dequeue.");
    } else {
        dequeuedElement = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("\nThe dequeued element is %d", dequeuedElement);
    }
    return dequeuedElement;
}

void display() {
    int i = front;

    if (front == -1 && rear == -1) {
        printf("\nQueue is empty.");
    } else {
        printf("\nElements in the queue are: ");
        while (i != rear) {
            printf("%d, ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d", queue[rear]);
    }
}

int main() {
    int choice = 1, x;

    while (choice < 4 && choice != 0) {
        printf("\n********** MAIN MENU **********");
        printf("\n-----------------------------");
        printf("\nPress 1: Insert an element");
        printf("\nPress 2: Delete an element");
        printf("\nPress 3: Display the elements");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("\nInvalid choice. Please enter a valid option (1-3).");
                break;
        }
    }
    return 0;
}

