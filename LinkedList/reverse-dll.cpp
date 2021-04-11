#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void pushList(Node *head, int new_data)
{
    Node *newNode = new Node();
    Node *last = head;
    newNode->data = new_data;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
    return;
}

void printListFwd(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << head->data;
}

Node *reverseDll(Node *head)
{
    Node *temp = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->prev = second;
    third->next = NULL;

    pushList(head, 4);
    pushList(head, 5);
    pushList(head, 6);

    cout << "\nBefore : \n";
    printListFwd(head);
    Node *revLink = reverseDll(head);
    cout << "\n\nAfter : \n";
    printListFwd(revLink);
    return 0;
}
