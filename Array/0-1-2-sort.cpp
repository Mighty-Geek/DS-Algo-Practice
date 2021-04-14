#include <iostream>
using namespace std;

// void sort012(int a[], int n)
// {
//     int zero_count = 0, one_count = 0, two_count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] == 0)
//             zero_count++;
//         else if (a[i] == 1)
//             one_count++;
//         else
//             two_count++;
//     }
//     for (int i = 0; i < zero_count; i++)
//     {
//         cout << "0 ";
//     }
//     for (int i = 0; i < one_count; i++)
//     {
//         cout << "1 ";
//     }
//     for (int i = 0; i < two_count; i++)
//     {
//         cout << "2 ";
//     }
// }

void sort012(int a[], int n)
{
    int l = 0;
    int h = n - 1;
    int mid = 0;

    while (mid <= h)
    {
        switch (a[mid])
        {
        case 0:
            swap(a[l++], a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid], a[h--]);
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort012(arr, n);
    return 0;
}
