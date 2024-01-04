#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int parent[MAX];

void makeSet(int n) {
    printf("enter an element");
    scanf("%d/n",&n);
}

int find(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return find(parent[x]);
    }
}

void unionSets(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);

    if (xRoot != yRoot) {
        parent[xRoot] = yRoot;
    }
}

void displayRepresentatives(int n) {
    printf("Set representatives:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d -> Set Representative: %d\n", i, find(i));
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    makeSet(n);

    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Make Set\n");
        printf("2. Union\n");
        printf("3. Find\n");
        printf("4. Display set representatives\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements for the new set: ");
                scanf("%d", &n);
                makeSet(n);
                printf("New set created with %d elements.\n", n);
                break;

            case 2:
                int x, y;
                printf("Enter two elements to be united: ");
                scanf("%d %d", &x, &y);
                unionSets(x, y);
                break;

            case 3:
                int element;
                printf("Enter an element to find its root: ");
                scanf("%d", &element);
                int root = find(element);
                printf("Root of element %d is %d\n", element, root);
                break;

            case 4:
                displayRepresentatives(n);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}

