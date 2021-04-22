#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
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
        cout << head->data << "-> ";
        head = head->next;
    }
    cout << head->data;
}

void deleteNode(Node *head, int val)
{
    while (head->data != val)
    {
        head = head->next;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

void reverseList(Node **headref)
{
    Node *current = *headref;
    Node *prev = NULL;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headref = prev;
}
void deleteLesserNodes(Node *head)
{
    Node *curr = head;
    Node *maxNode = head;
    Node *temp;

    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data < maxNode->data)
        {
            temp = curr->next;
            curr->next = temp->next;
            delete (temp);
        }
        else
        {
            curr = curr->next;
            maxNode = curr;
        }
    }
}

void deleteLesser(Node **headref)
{
    reverseList(headref);
    deleteLesserNodes(*headref);
    reverseList(headref);
}

int main()
{
    Node *head = new Node(12);
    head->next = NULL;

    append(head, 15);
    append(head, 10);
    append(head, 11);
    append(head, 5);
    append(head, 6);
    append(head, 2);
    append(head, 3);

    deleteLesser(&head);
    printList(head);
    return 0;
}