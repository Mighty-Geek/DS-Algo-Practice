#include <iostream>
#include <stack>
using namespace std;

int mat[10][10];

bool knows(int a, int b) { return mat[a][b]; }
int findCelebrity(int n)
{
    stack<int> s;
    int celebrity;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    int A = s.top();
    s.pop();
    int B = s.top();
    s.pop();

    while (s.size() > 1)
    {
        if (knows(A, B))
        {
            A = s.top();
            s.pop();
        }
        else
        {
            B = s.top();
            s.pop();
        }
    }
    if (s.empty())
        return -1;

    celebrity = s.top();
    s.pop();

    if (knows(celebrity, B))
        celebrity = B;
    if (knows(celebrity, A))
        celebrity = A;

    for (int i = 0; i < n; i++)
    {
        if ((i != celebrity) &&
            (knows(celebrity, i) || !knows(i, celebrity)))
            return -1;
    }
    return celebrity;
}

/* 2-pointer

int findCelebrity(int n)
{
    int a = 0;
    int b = n - 1;

    while (a < b)
    {
        if (knows(a, b))
            a++;
        else
            b--;
    }

    for (int i = 0; i < n; i++)
    {
        if ((i != a) && (knows(a, i) || !knows(i, a)))
            return -1;
    }

    return a;
}
*/
int main()
{
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> mat[i][j];
        }
    }
    int res = findCelebrity(size);
    cout << "[-] Celebrity is : " << res << endl;

    return 0;
}