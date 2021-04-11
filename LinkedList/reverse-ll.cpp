#include <iostream>
using namespace std;

class Node
{
public:
    int id;
    string name;
    Node *next;
};

void printList(Node *start)
{
    while (start != nullptr)
    {
        cout << "\n[-] ID : " << start->id << "\tName : " << start->name;
        start = start->next;
    }
}

void insertList(Node *prev, int id, string name)
{
    Node *temp = new Node();
    prev->next = temp;
    temp->id = id;
    temp->name = name;
}

// Iterative
/*
Node *reverseList(Node *head)
{
    Node *mid, *tail;
    mid = nullptr;
    while (head)
    {
        tail = mid;
        mid = head;
        head = head->next;
        mid->next = tail;
    }
    return mid;
}
*/

// Recursive
Node *reverseList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *rest = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}
int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->id = 73;
    head->name = "Sheldon";
    head->next = second;

    second->id = 74;
    second->name = "Leonard";
    second->next = third;

    third->id = 75;
    third->name = "Howard";
    third->next = nullptr;

    insertList(third, 76, "Raj");
    insertList(third->next, 77, "Penny");

    Node *res = reverseList(head);
    printList(res);

    return 0;
}