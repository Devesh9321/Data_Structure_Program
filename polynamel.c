#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coefficient;
    int x;
    int y;
    int z;
    struct node *next;
} *poly[2], *result, *tmp, *new, *ptr;

// Function that are use for the whole program
void displayNodeLL(struct node *head);
struct node *createNodeLL(int coef, int x, int y, int z);
struct node *copyNodeLL(struct node *loc);
struct node *findNodeLL(struct node *head, int x, int y, int z);
void insertAftNodeLL(struct node *head, struct node *locp, struct node *new);
void insertEndNodeLL(struct node *head, struct node *new);
void insertSortNodeLL(struct node *head, struct node *new, int coef, int x, int y, int z);


int main()
{
    int n, coef, x, y, z;
    for (int k = 0; k < 2; k++)
    {
        printf("\n*_*_* Enter the %d of Polynomial *_*_*\n", k + 1);
        printf("Enter the lenght of Polynomial : ");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("%d Term : ", i + 1);
            scanf("%dx^%dy^%dz^%d", &coef, &x, &y, &z);

            new = createNodeLL(coef, x, y, z);

            /* * * *  To Insert the element in Sorted way to Linked list the following code will use. * * *
                // insertSortNodeLL(poly[k],new,coef, x, y, z)
            */
            tmp = findNodeLL(poly[k], x, y, z);
            if (tmp == NULL)
            {
                new->next = poly[k];
                poly[k] = new;
            }
            else
            {
                new->next = tmp->next;
                tmp->next = new;
            }

            /* * * *  To Insert the element at the end the following code will use. * * *
                // insertEndNodeLL(poly[k], new);
                if (poly[k] != NULL){
                    ptr = poly[k];
                    while (ptr->next != NULL){
                        ptr = ptr->next;
                    }
                    ptr->next = new;
                }
                else
                    poly[k] = new;
            */
            // free(new);
            // free(tmp);
        }
    }
    // 4x^1y^2z^3

    printf("\n*_*_*  Your Polynomials  *_*_*\n");
    printf("Polynomial 1st : ");
    displayNodeLL(poly[0]);
    printf("Polynomial 2nd : ");
    displayNodeLL(poly[1]);

    for (int k = 0; k < 2; k++)
    {
        ptr = poly[k];
        while (ptr != NULL)
        {
            new = copyNodeLL(ptr);

            tmp = findNodeLL(result, ptr->x, ptr->y, ptr->z);
            if (tmp == NULL)
            {
                new->next = result;
                result = new;
            }
            else
            {
                new->next = tmp->next;
                tmp->next = new;
            }

            ptr = ptr->next;
        }
    }

    printf("Result ( Addition ) : ");
    displayNodeLL(result);

    return 0;
}

// Creating the new Node
struct node *createNodeLL(int coef, int x, int y, int z)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    // setting values to polynomial
    new->coefficient = coef;
    new->x = x;
    new->y = y;
    new->z = z;
    new->next = NULL;
    return new;
}
// Creating the copy of existing Node
struct node *copyNodeLL(struct node *loc)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    // setting values to polynomial
    new->coefficient = loc->coefficient;
    new->x = loc->x;
    new->y = loc->y;
    new->z = loc->z;
    new->next = NULL;
    return new;
}
// Displaying the Linked list of polynomial
void displayNodeLL(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf(" %dx^%dy^%dz^%d ", ptr->coefficient, ptr->x, ptr->y, ptr->z);
        ptr = ptr->next;
        printf(" + ");
    }
    printf(" C \n");
}
// find the Largest node in linked list and return previous node.
struct node *findNodeLL(struct node *head, int x, int y, int z)
{
    struct node *loc, *locp;
    loc = head;
    locp = NULL;
    while (loc != NULL)
    {
        if (loc->x >= x && loc->y >= y && loc->z >= z)
        {
            // printf("fun :  %dx^%dy^%dz^%d \n", loc->coefficient, loc->x, loc->y, loc->z);
            return locp;
        }

        locp = loc;
        loc = loc->next;
    }

    return locp;
}
// Inserting the node after the location
void insertAftNodeLL(struct node *head, struct node *locp, struct node *new)
{
    if (locp != NULL)
    {
        new->next = locp->next;
        locp->next = new;
    }
    else
    {
        new->next = head;
        head = new;
    }
}
// Inserting the node at the End
void insertEndNodeLL(struct node *head, struct node *new)
{
    if (head != NULL)
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    else
    {
        head = new;
    }
}
// Inserting the node in Sorted Orden in Linked List
void insertSortNodeLL(struct node *head, struct node *new, int coef, int x, int y, int z)
{
    tmp = findNodeLL(head, x, y, z);
    if (tmp == NULL)
    {
        new->next = head;
        head = new;
    }
    else
    {
        new->next = tmp->next;
        tmp->next = new;
    }
}
