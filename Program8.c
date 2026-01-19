#include <stdio.h>
#include <stdlib.h>

struct node
{
    char ssn[25], name[25], dept[10], designation[25];
    int sal;
    long int phone;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE first = NULL;
int count = 0;

NODE create()
{
    NODE enode = (NODE)malloc(sizeof(struct node));
    if (enode == NULL)
    {
        printf("\nMemory allocation failed");
        exit(1);
    }

    printf("\nEnter SSN Name Dept Designation Salary Phone: ");
    scanf("%s %s %s %s %d %ld",
          enode->ssn,
          enode->name,
          enode->dept,
          enode->designation,
          &enode->sal,
          &enode->phone);

    enode->llink = NULL;
    enode->rlink = NULL;
    count++;
    return enode;
}

NODE insertfront()
{
    NODE temp = create();
    if (first == NULL)
        return temp;

    temp->rlink = first;
    first->llink = temp;
    return temp;
}

NODE insertend()
{
    NODE temp = create(), cur;
    if (first == NULL)
        return temp;

    cur = first;
    while (cur->rlink != NULL)
        cur = cur->rlink;

    cur->rlink = temp;
    temp->llink = cur;
    return first;
}

NODE deletefront()
{
    NODE temp;
    if (first == NULL)
    {
        printf("\nDLL is empty");
        return NULL;
    }

    temp = first;
    if (first->rlink == NULL)
    {
        printf("\nDeleted employee SSN: %s", temp->ssn);
        free(temp);
        count--;
        return NULL;
    }

    first = first->rlink;
    first->llink = NULL;
    printf("\nDeleted employee SSN: %s", temp->ssn);
    free(temp);
    count--;
    return first;
}

NODE deleteend()
{
    NODE cur;
    if (first == NULL)
    {
        printf("\nDLL is empty");
        return NULL;
    }

    if (first->rlink == NULL)
    {
        printf("\nDeleted employee SSN: %s", first->ssn);
        free(first);
        count--;
        return NULL;
    }

    cur = first;
    while (cur->rlink != NULL)
        cur = cur->rlink;

    printf("\nDeleted employee SSN: %s", cur->ssn);
    cur->llink->rlink = NULL;
    free(cur);
    count--;
    return first;
}

void display()
{
    NODE cur;
    int i = 1;

    if (first == NULL)
    {
        printf("\nDLL is empty");
        return;
    }

    cur = first;
    printf("\nDLL Contents:");
    while (cur != NULL)
    {
        printf("\n%d SSN:%s Name:%s Dept:%s Designation:%s Salary:%d Phone:%ld",
               i, cur->ssn, cur->name, cur->dept,
               cur->designation, cur->sal, cur->phone);
        cur = cur->rlink;
        i++;
    }
    printf("\nTotal nodes = %d", count);
}

void deqdemo()
{
    int ch;
    while (1)
    {
        printf("\n\nDouble Ended Queue Demo");
        printf("\n1.Insert Front");
        printf("\n2.Delete Front");
        printf("\n3.Insert Rear");
        printf("\n4.Delete Rear");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            first = insertfront();
            break;
        case 2:
            first = deletefront();
            break;
        case 3:
            first = insertend();
            break;
        case 4:
            first = deleteend();
            break;
        case 5:
            display();
            break;
        case 6:
            return;
        default:
            printf("\nInvalid choice");
        }
    }
}

int main()
{
    int ch, i, n;

    while (1)
    {
        printf("\n\nMenu");
        printf("\n1.Create DLL");
        printf("\n2.Display Status");
        printf("\n3.Insert at End");
        printf("\n4.Delete at End");
        printf("\n5.Insert at Front");
        printf("\n6.Delete at Front");
        printf("\n7.Double Ended Queue Demo");
        printf("\n8.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter number of employees: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                first = insertend();
            break;
        case 2:
            display();
            break;
        case 3:
            first = insertend();
            break;
        case 4:
            first = deleteend();
            break;
        case 5:
            first = insertfront();
            break;
        case 6:
            first = deletefront();
            break;
        case 7:
            deqdemo();
            break;
        case 8:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
}

