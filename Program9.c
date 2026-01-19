#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *lchild;
    struct BST *rchild;
};

typedef struct BST *NODE;

NODE create()
{
    NODE temp = (NODE)malloc(sizeof(struct BST));
    if (temp == NULL)
    {
        printf("\nMemory allocation failed");
        exit(1);
    }
    printf("Enter value: ");
    scanf("%d", &temp->data);
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

void insert(NODE root, NODE newnode)
{
    if (newnode->data < root->data)
    {
        if (root->lchild == NULL)
            root->lchild = newnode;
        else
            insert(root->lchild, newnode);
    }
    else if (newnode->data > root->data)
    {
        if (root->rchild == NULL)
            root->rchild = newnode;
        else
            insert(root->rchild, newnode);
    }
}

void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

void search(NODE root)
{
    int key;
    NODE cur = root;

    if (root == NULL)
    {
        printf("\nBST is empty");
        return;
    }

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    while (cur != NULL)
    {
        if (cur->data == key)
        {
            printf("\nKey element %d found in BST", key);
            return;
        }
        else if (key < cur->data)
            cur = cur->lchild;
        else
            cur = cur->rchild;
    }

    printf("\nKey element %d not found in BST", key);
}

int main()
{
    int ch, n, i;
    NODE root = NULL, newnode;

    while (1)
    {
        printf("\n\n~~~~ BST MENU ~~~~");
        printf("\n1.Create BST");
        printf("\n2.Traverse BST");
        printf("\n3.Search");
        printf("\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter number of elements: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                newnode = create();
                if (root == NULL)
                    root = newnode;
                else
                    insert(root, newnode);
            }
            break;

        case 2:
            if (root == NULL)
            {
                printf("\nBST is empty");
                break;
            }
            printf("\nPreorder: ");
            preorder(root);
            printf("\nInorder: ");
            inorder(root);
            printf("\nPostorder: ");
            postorder(root);
            break;

        case 3:
            search(root);
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice");
        }
    }
}
