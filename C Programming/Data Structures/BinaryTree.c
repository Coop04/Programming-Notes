#include <stdio.h>
#include <stdlib.h>

struct NodeType
{
    int data;
    struct NodeType *left;
    struct NodeType *right;
};

typedef struct NodeType NODE;

NODE *root;

NODE *insert(NODE *p, int k)
{
    NODE *new;
    if (p == NULL)
    {
        new = (NODE *)malloc(sizeof(NODE));
        new->data = k;
        new->left = new->right = NULL;
        return new;
    }
    else
    {
        if (k < p->data)
            p->left = insert(p->left, k);
        else
            p->right = insert(p->right, k);
    }
    return p;
}

NODE *minvalue(NODE *p)
{
    NODE *current;
    current = p;
    while (current->left != NULL)
        current = current->left;
    return current;
}

NODE *successor(NODE *key)
{
    if (key->right != NULL)
        return minvalue(key->right);
}

NODE *search(NODE *root, int k)
{
    if (root->data == k)
        return (root);
    else if (k > root->data)
        return search(root->right, k);
    else
        return search(root->left, k);
    return 0;
}

void inorder(NODE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void preorder(NODE *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

NODE *delete (NODE *root, int k)
{
    NODE *succparent, *temp, *succ;
    if (root->data == k)
    {
        printf("\n Item deleted");
        if (root->left == NULL && root->right == NULL)
        {
            printf("\n both child nodes were empty");
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return (temp);
        }
        else
        {
            succparent = root;
            succ = root->right;
            while (succ->left != NULL)
            {
                succparent = succ;
                succ = succ->left;
            }
            if (succparent != root)
            {
                succparent->left = succ->right;
            }
            else
            {
                succparent->right = succ->right;
            }
            root->data = succ->data;
            free(succ);
            return root;
        }
    }
    else if (root->data < k)
    {
        root->right = delete (root->right, k);
        return root;
    }
    else
    {
        root->left = delete (root->left, k);
        return root;
    }
}

int main()
{
    int item, choice;
    NODE *temp;
    root = NULL;
    while (1)
    {
        printf("\n enter 1. insert, 2. inorder, 3. minvalue, 4. successor, 5 delete 6. exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n enter item");
            scanf("%d", &item);
            root = insert(root, item);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            temp = minvalue(root);
            printf("\n min value %d", temp->data);
            break;
        case 4:
            temp = successor(root);
            printf("\n successor value %d", temp->data);
            break;
        case 5:
            if (root == NULL)
            {
                printf("\n Tree Empty");
            }
            else
            {
                printf("\n enter the item to be deleted");
                scanf("%d", &item);
                temp = delete (root, item);
                printf("\n Item deleted %d", temp->data);
                inorder(root);
                preorder(root);
                postorder(root);
            }
            break;
        case 6:
            exit(0);
        default:
            printf("\n invalid choice");
        }
    }

    return 0;
}