#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coff;
    int power;
    struct Node *next;
} Node;

int power(int base, int exponent)
{
    if (exponent == 0)
        return 1;

    int result = base;
    for (; exponent > 1; exponent--)
    {
        result = result * base;
    }

    return result;
};

void CreateNode(Node **head, int coff, int power)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("*********Linked List is full*********\n");
        return;
    }

    newNode->coff = coff;
    newNode->power = power;

    newNode->next = *head;
    (*head) = newNode;
}

int GetSum(Node *first_eq_head, Node *second_eq_head, int x)
{
    int sum1 = 0, sum2 = 0, tempSum;
    Node *temp = first_eq_head;

    while (temp)
    {
        tempSum = power(x, temp->power);
        tempSum *= temp->coff;
        sum1 += tempSum;
        temp = temp->next;
    }

    temp = second_eq_head;
    while (temp)
    {
        tempSum = power(x, temp->power);
        tempSum *= temp->coff;
        sum2 += tempSum;
        temp = temp->next;
    }
    free(temp);
    return sum1 + sum2;
};

int main()
{
    Node *first_equation_head = NULL;
    Node *second_equation_head = NULL;
    int n, coff, power, x;
    printf("***Enter the terms of first equation****\n");
    printf("Number of terms: ");
    scanf("%d", &n);

    // take the inputs for the first equation
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the coffecient for %d term: ", i + 1);
        scanf("%d", &coff);
        printf("\nEnter the power of the %d term: ", i + 1);
        scanf("%d", &power);
        CreateNode(&first_equation_head, coff, power);
    }

    printf("***Enter the terms of second equation****\n");
    printf("Number of terms: ");
    scanf("%d", &n);

    // take the inputs for the second equation

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the coffecient for %d term: ", i + 1);
        scanf("%d", &coff);
        printf("\nEnter the power of the %d term: ", i + 1);
        scanf("%d", &power);
        CreateNode(&second_equation_head, coff, power);
    }

    printf("******Enter the value of X******\n->");
    scanf("%d", &x);
    int sum = GetSum(first_equation_head, second_equation_head, x);

    printf("Sum:%d", sum);

    free(first_equation_head);
    free(second_equation_head);
    return 0;
}