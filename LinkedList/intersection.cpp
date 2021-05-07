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

void appendList(Node *head, int new_data)
{
    Node *newNode = new Node(new_data);
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = newNode;
    newNode->next = NULL;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int length(Node *head)
{
    int l = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

void intersect(Node *head1, Node *head2, int pos)
{
    Node *temp1 = head1;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int intersection(Node *head1, Node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    Node *ptr1;
    Node *ptr2;

    // ptr1 pointing the longer list
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d--)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main()
{
    Node *head1 = new Node(1);
    Node *head2 = new Node(9);

    head1->next = NULL;
    head2->next = NULL;

    appendList(head1, 2);
    appendList(head1, 3);
    appendList(head1, 4);
    appendList(head1, 5);
    appendList(head1, 6);

    appendList(head2, 10);

    intersect(head1, head2, 4);

    display(head1);
    display(head2);

    cout << intersection(head1, head2) << endl;
}