#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void printList(Node *head)
{
    while (head->next != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << head->data;
}

void pushList(Node *head, int new_data)
{
    Node *temp = new Node();
    while (head->next != nullptr)
    {
        head = head->next;
    }
    head->next = temp;
    temp->data = new_data;
    temp->next = nullptr;
}

Node *deleteDuplicates(Node *head)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        if (temp->data < (temp->next)->data)
        {
            temp = temp->next;
        }
        else
        {
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            delete (temp2);
        }
    }
    return head;
}

int main()
{
    Node *head = new Node();
    Node *first = new Node();

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = nullptr;

    pushList(head, 2);
    pushList(head, 3);
    pushList(head, 3);
    pushList(head, 3);
    pushList(head, 4);

    Node *res = deleteDuplicates(head);
    printList(res);

    // printList(head);
}