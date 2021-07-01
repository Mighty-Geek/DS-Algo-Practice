// cycle detection and returning first node of cycle using Hashset

#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void printList(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << head->data;
}

void pushList(Node *head, int new_data)
{
    Node *temp = new Node();
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = temp;
    temp->data = new_data;
    temp->next = NULL;
}

Node *has_cycle(Node *head)
{
    unordered_set<Node *> visited;
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (visited.find(ptr) != visited.end())
            return ptr;
        else
            visited.insert(ptr);
        ptr = ptr->next;
    }
    return NULL;
}
int main()
{
    Node *head = new Node();
    Node *first = new Node();
    Node *second = new Node();

    head->data = 50;
    head->next = first;

    first->data = 20;
    first->next = second;

    second->data = 15;
    second->next = NULL;

    pushList(head, 4);
    pushList(head, 10);
    head->next->next->next->next->next = head->next->next;

    Node *res = has_cycle(head);
    if (res != NULL)
        cout << res->data << endl;
    else
        cout << "Cycle not found!" << endl;
    return 0;
}