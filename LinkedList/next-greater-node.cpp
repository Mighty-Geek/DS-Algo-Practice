#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void append(Node *head, int new_data)
{
    Node *temp = new Node(new_data);
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = temp;
    temp->next = NULL;
}

void printList(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << head->data;
}

int main()
{
    Node *head = new Node(1);
    head->next = NULL;

    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    append(head, 6);

    printList(head);
    return 0;
}