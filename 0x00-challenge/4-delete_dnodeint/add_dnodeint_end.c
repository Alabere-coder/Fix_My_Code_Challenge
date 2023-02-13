#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a new node to the end of a doubly linked list
 * @head: A pointer to the head of the doubly linked list
 * @n: The data to store in the new node
 *
 * Return: A pointer to the newly added node, or `NULL` if failed to allocate memory
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new;
    dlistint_t *last;

    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
    {
        return NULL;
    }

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        new->prev = NULL;
        return new;
    }

    last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new;
    new->prev = last;

    return new;
}
