#include <stdio.h>
#include <stdlib.h>

#define MAX 3

char cq[MAX];
int front = -1, rear = -1;

void insert(char item);
void deleteElement(void);
void display(void);

int main()
{
    int ch;
    char item;

    while (1)
    {
        printf("\n\n~~ Main Menu ~~");
        printf("\n1. Insertion and Overflow Demo");
        printf("\n2. Deletion and Underflow Demo");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be inserted: ");
            scanf(" %c", &item);
            insert(item);
            break;

        case 2:
            deleteElement();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\nPlease enter a valid choice!");
        }
    }
    return 0;
}

void insert(char item)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\n~~ Circular Queue Overflow ~~");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    cq[rear] = item;
    printf("\nInserted: %c", item);
}

void deleteElement()
{
    char item;

    if (front == -1)
    {
        printf("\n~~ Circular Queue Underflow ~~");
        return;
    }

    item = cq[front];
    printf("\nDeleted element: %c", item);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("\nCircular Queue is Empty");
        return;
    }

    printf("\nCircular Queue contents:\n");
    printf("Front[%d] -> ", front);

    i = front;
    while (i != rear)
    {
        printf("%c ", cq[i]);
        i = (i + 1) % MAX;
    }

    printf("%c ", cq[i]);
    printf("<- Rear[%d]", rear);
}

