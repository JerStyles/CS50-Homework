#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        n->number = atoi(argv[i]);
        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }
        else
        {
            for (node *temp = list; temp != NULL; temp = temp->next)
            {
                if (temp->next == NULL)
                {
                    temp->next = n;
                    break;
                }
            }
        }

    }

    node *ptr = list;

    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    // Free memory
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}
