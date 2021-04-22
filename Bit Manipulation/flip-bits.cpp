#include <iostream>
using namespace std;

int countBitsFlip(int a, int b)
{

    // Your logic here
    int num = a ^ b;
    unsigned int c = 0;

    while (num > 0)
    {
        c += num & 1;
        num >>= 1;
    }
    return c;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << countBitsFlip(a, b);
    return 0;
}