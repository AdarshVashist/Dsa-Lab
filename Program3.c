#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push();
void pop();
void display();
void palindrome();

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n--- STACK MENU ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Check Palindrome");
        printf("\n4. Display Stack");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: palindrome(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice");
        }
    }
}

void push()
{
    int x;
    if (top == MAX - 1)
    {
        printf("Stack Overflow");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &x);

    stack[++top] = x;
    printf("Element pushed");
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
        return;
    }

    printf("Popped element: %d", stack[top--]);
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty");
        return;
    }

    printf("Stack elements:\n");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

void palindrome()
{
    char str[50], rev[50];
    int i, len = 0, j = 0;
    top = -1;

    printf("Enter string: ");
    scanf("%s", str);

    while (str[len] != '\0')
        len++;

    for (i = 0; i < len; i++)
        stack[++top] = str[i];

    for (i = 0; i < len; i++)
        rev[i] = stack[top--];

    rev[len] = '\0';

    for (i = 0; i < len; i++)
    {
        if (str[i] != rev[i])
        {
            printf("Not a Palindrome");
            return;
        }
    }

    printf("Palindrome");
}
