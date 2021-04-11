#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
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

void printList(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << head->data;
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *addOneUtil(Node *head)
{
    Node *res = head;
    Node *temp, *prev = NULL;

    int carry = 1, sum;

    while (head != NULL)
    {
        sum = carry + head->data;

        carry = (sum >= 10) ? 1 : 0;

        sum = sum % 10;

        head->data = sum;
        temp = head;
        head = head->next;
    }
    if (carry > 0)
        temp->next = new Node(carry);

    return res;
}

Node *addOne(Node *head)
{
    head = reverse(head);
    head = addOneUtil(head);
    return reverse(head);

    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->next = third;
    third->next = NULL;

    appendList(head, 4);
    appendList(head, 5);
    appendList(head, 9);

    Node *res = addOne(head);
    printList(res);
}