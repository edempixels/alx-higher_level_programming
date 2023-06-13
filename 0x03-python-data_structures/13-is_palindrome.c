#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the linked list
 * Return: 0 if not a palindrome, 1 if a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *prev_slow = NULL, *mid_node = NULL;
    listint_t *second_half, *prev_of_slow = NULL;
    int is_palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return (is_palindrome);

    slow = *head;
    fast = *head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    if (fast != NULL)
    {
        mid_node = slow;
        slow = slow->next;
    }

    second_half = slow;
    prev_slow->next = NULL;
    reverse_list(&second_half);
    is_palindrome = compare_lists(*head, second_half);
    reverse_list(&second_half);
    if (mid_node != NULL)
    {
        prev_slow->next = mid_node;
        mid_node->next = second_half;
    }
    else
        prev_slow->next = second_half;

    return (is_palindrome);
}

/**
 * reverse_list - reverses a linked list
 * @head: pointer to the head of the linked list
 */
void reverse_list(listint_t **head)
{
    listint_t *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

/**
 * compare_lists - compares two linked lists
 * @list1: pointer to the head of the first linked list
 * @list2: pointer to the head of the second linked list
 * Return: 0 if not equal, 1 if equal
 */
int compare_lists(listint_t *list1, listint_t *list2)
{
    listint_t *temp1 = list1, *temp2 = list2;

    while (temp1 && temp2)
    {
        if (temp1->n != temp2->n)
            return (0);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 == NULL && temp2 == NULL)
        return (1);

    return (0);
}

