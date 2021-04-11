#include <iostream>
using namespace std;

// using recursion
int main()
{
    static int i = 1;
    if (i <= 100)
    {
        cout << i++ << " ";
        main();
    }
    return 0;
}

// using goto

/*
int main()
{
    static int i = 0;
increase:
    i++;
    if (i <= 100)
    {
        cout << i << " ";
        goto increase;
    }
    return 0;
}

// using exception handling & goto :

int main()
{
    int x = 1;

    try
    {
    label:
        if (x <= 100)
        {
            cout << x++ << " ";
            goto label;
        }
        else
        {
            throw(x);
        }
    }

    catch (int i)
    {
        cout << "Exception caught :" << x;
    }
    return 0;
}
*/
