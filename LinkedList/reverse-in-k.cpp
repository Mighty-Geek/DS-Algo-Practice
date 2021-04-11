#include <bits/stdc++.h>
using namespace std;

// Input : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11
// k = 3
// Output : 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 9 -> 8 -> 7 -> 10 -> 11

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

Node *reverseKGroup(Node *head, int k)
{
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
    appendList(head, 6);

    int k;
    cout << "Enter size of groups(k) : ";
    cin >> k;
    Node *res = reverseKGroup(head, k);

    printList(res);
}