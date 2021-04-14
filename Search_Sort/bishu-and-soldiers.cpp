#include <iostream>
#include <vector>
using namespace std;

void findPower(vector<int> s, int n, int power)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] <= power)
        {
            count++;
            sum += s[i];
        }
    }
    cout << count << " " << sum;
}

// N : no. of soldiers
// Q : no. of rounds
int main()
{
    int N;
    cin >> N;
    vector<int> soldiers;
    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;
        soldiers.push_back(data);
    }
    int Q;
    int bishu_power;
    cin >> Q;
    while (Q--)
    {
        cin >> bishu_power;
        findPower(soldiers, N, bishu_power);
    }
}