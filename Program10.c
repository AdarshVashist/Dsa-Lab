#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
    int height;
};

int height(struct node *n)
{
    return n ? n->height : 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

struct node* newNode(int key)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int getBF(struct node *n)
{
    return n ? height(n->left) - height(n->right) : 0;
}

struct node* rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node* leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct node* insert(struct node* node, int key)
{
    if (!node)
        return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int bf = getBF(node);

    if (bf > 1 && key < node->left->data)
        return rightRotate(node);

    if (bf < -1 && key > node->right->data)
        return leftRotate(node);

    if (bf > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (bf < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct node* minValueNode(struct node* node)
{
    struct node* cur = node;
    while (cur->left)
        cur = cur->left;
    return cur;
}

struct node* deleteNode(struct node* root, int key)
{
    if (!root)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left || !root->right)
        {
            struct node *temp = root->left ? root->left : root->right;
            if (!temp)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            struct node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int bf = getBF(root);

    if (bf > 1 && getBF(root->left) >= 0)
        return rightRotate(root);

    if (bf > 1 && getBF(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && getBF(root->right) <= 0)
        return leftRotate(root);

    if (bf < -1 && getBF(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct node* root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d(BF=%d) ", root->data, getBF(root));
        inorder(root->right);
    }
}

void preorder(struct node* root)
{
    if (root)
    {
        printf("%d(BF=%d) ", root->data, getBF(root));
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node* root = NULL;
    int choice, x;
    int data[] = {10,15,9,12,13,79,45,36,22};
    int n = 9, i;

    while (1)
    {
        printf("\n\n1.Create\n2.Insert\n3.Delete\n4.Print\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                root = NULL;
                for (i = 0; i < n; i++)
                    root = insert(root, data[i]);
                printf("AVL Tree Created");
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;

            case 4:
                printf("Preorder:\n");
                preorder(root);
                printf("\nInorder:\n");
                inorder(root);
                break;

            case 5:
                return 0;
        }
    }
}

