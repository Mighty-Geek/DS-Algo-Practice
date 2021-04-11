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

bool has_cycle(Node *head)
{
    unordered_set<Node *> visited;
    while (head != NULL)
    {
        if (visited.find(head) != visited.end())
            return true;

        visited.insert(head);
        head = head->next;
    }
    return false;
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

    bool res = has_cycle(head);

    if (res)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    return 0;
}