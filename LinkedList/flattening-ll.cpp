#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;
    Node(int x)
    {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

void pushList(Node **head, int new_data)
{
    Node *newNode = new Node(new_data);
    newNode->next = NULL;
    newNode->bottom = *head;
    *head = newNode;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->bottom;
    }
}

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *res;
    if (a->data < b->data)
    {
        res = a;
        res->bottom = merge(a->bottom, b);
    }
    else
    {
        res = b;
        res->bottom = merge(a, b->bottom);
    }
    res->next = NULL;
    return res;
}

Node *flatten(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    return merge(head, flatten(head->next));
}

int main()
{
    Node *head = NULL;
    pushList(&head, 30);
    pushList(&head, 8);
    pushList(&head, 7);
    pushList(&head, 5);

    pushList(&(head->next), 20);
    pushList(&(head->next), 10);

    pushList(&(head->next->next), 50);
    pushList(&(head->next->next), 22);
    pushList(&(head->next->next), 18);

    pushList(&(head->next->next->next), 45);
    pushList(&(head->next->next->next), 40);
    pushList(&(head->next->next->next), 35);
    pushList(&(head->next->next->next), 28);

    head = flatten(head);

    printList(head);

    return 0;
}