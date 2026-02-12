#include <stdio.h>
#define MAX 100

int a[MAX], n;


void create();
void display();
void insert();   
void delete();
           
int main()  
{
    int choice;

    while (1)
    {
        printf("\n--- MENU ---");
        printf("\n1. Create Array");
        printf("\n2. Display Array");
        printf("\n3. Insert Element");
        printf("\n4. Delete Element");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: insert();
                    break;
            case 4: delete();
                    break;
            case 5: return 0;
            default: printf("\nInvalid Choice!");
        }
    }
}

void create()
{
    int i;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display()
{
    int i;
    if (n == 0)
    {
        printf("\nArray is empty!");
        return;
    }

    printf("\nArray Elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void insert()
{
    int elem, pos, i;

    if (n == MAX)
    {
        printf("\nArray is full!");
        return;
    }

    printf("\nEnter element to insert: ");
    scanf("%d", &elem);

    printf("Enter position (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1)
    {
        printf("\nInvalid Position!");
        return;
    }

    for (i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = elem;
    n++;

    printf("\nElement inserted successfully!");
}

void delete()
{
    int pos, i;

    if (n == 0)
    {
        printf("\nArray is empty!");
        return;
    }

    printf("\nEnter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
    {
        printf("\nInvalid Position!");
        return;
    }

    for (i = pos - 1; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;
    printf("\nElement deleted successfully!");
   
}
