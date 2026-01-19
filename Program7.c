#include <stdio.h>
#include <stdlib.h>

struct node
{
    char usn[25], name[25], branch[25];
    int sem;
    long int phone;
    struct node *link;
};

typedef struct node *NODE;

NODE start = NULL;
int count = 0;

NODE create()
{
    NODE snode = (NODE)malloc(sizeof(struct node));
    if (snode == NULL)
    {
        printf("\nMemory not available");
        exit(1);
    }

    printf("\nEnter USN Name Branch Sem Phone: ");
    scanf("%s %s %s %d %ld",
          snode->usn,
          snode->name,
          snode->branch,
          &snode->sem,
          &snode->phone);

    snode->link = NULL;
    count++;
    return snode;
}

NODE insertfront()
{
    NODE temp = create();
    temp->link = start;
    return temp;
}

NODE deletefront()
{
    NODE temp;
    if (start == NULL)
    {
        printf("\nLinked List is empty");
        return NULL;
    }

    temp = start;
    start = start->link;
    printf("\nDeleted student USN: %s", temp->usn);
    free(temp);
    count--;
    return start;
}

NODE insertend()
{
    NODE temp = create(), cur;

    if (start == NULL)
        return temp;

    cur = start;
    while (cur->link != NULL)
        cur = cur->link;

    cur->link = temp;
    return start;
}

NODE deleteend()
{
    NODE cur, prev;

    if (start == NULL)
    {
        printf("\nLinked List is empty");
        return NULL;
    }

    if (start->link == NULL)
    {
        printf("\nDeleted student USN: %s", start->usn);
        free(start);
        count--;
        return NULL;
    }

    prev = NULL;
    cur = start;

    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }

    printf("\nDeleted student USN: %s", cur->usn);
    prev->link = NULL;
    free(cur);
    count--;
    return start;
}

void display()
{
    NODE cur;
    int num = 1;

    if (start == NULL)
    {
        printf("\nSLL is empty");
        return;
    }

    printf("\nSLL Contents:");
    cur = start;

    while (cur != NULL)
    {
        printf("\n%d USN:%s Name:%s Branch:%s Sem:%d Phone:%ld",
               num, cur->usn, cur->name, cur->branch,
               cur->sem, cur->phone);
        cur = cur->link;
        num++;
    }

    printf("\nTotal nodes = %d", count);
}

void stackdemo()
{
    int ch;

    while (1)
    {
        printf("\n\nStack Demo");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            start = insertfront();
            break;
        case 2:
            start = deletefront();
            break;
        case 3:
            display();
            break;
        case 4:
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
        printf("\n1.Create SLL");
        printf("\n2.Display Status");
        printf("\n3.Insert at End");
        printf("\n4.Delete at End");
        printf("\n5.Stack Demo");
        printf("\n6.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter number of students: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                start = insertfront();
            break;

        case 2:
            display();
            break;

        case 3:
            start = insertend();
            break;

        case 4:
            start = deleteend();
            break;

        case 5:
            stackdemo();
            break;

        case 6:
            exit(0);

        default:
            printf("\nInvalid choice");
        }
    }
}

