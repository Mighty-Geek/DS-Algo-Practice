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
// Brute force approach
/*
Node *middleNode(Node *head)
{
    Node *mid = head;
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    int mid_count = count / 2;
    while (mid != NULL && mid_count > 0)
    {
        mid_count--;
        mid = mid->next;
    }
    return mid;
}
*/

Node *middleNode(Node *head)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
    }
    return slow_ptr;
}

int main()
{
    Node *head = new Node();
    Node *first = new Node();

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = nullptr;

    pushList(head, 3);
    pushList(head, 4);
    pushList(head, 5);
    pushList(head, 6);
    pushList(head, 7);

    Node *res = middleNode(head);
    cout << res->data;

    // printList(head);
}
