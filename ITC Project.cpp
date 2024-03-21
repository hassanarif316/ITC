#include <iostream>
#include<cmath>
using namespace std;


int main()
{
    int n;
    cout << "Enter Number of Disks : ";
    cin >> n;
    char rod[] = { 'A', 'B', 'C' };

    int arr1[50];
    int arr2[50];
    int arr3[50];

    int top1 = 0;
    int top2 = 0;
    int top3 = 0;

    cout << "Tower of Hanoi for " << n << " disks:"<<endl;

    for (int i = n; i > 0; i--)
    {
        arr1[top1] = i;
        top1++;
    }

    int total = 2;
    for (int i = 1; i < n; i++)
    {
        total =total * 2;
    }
    int totalMoves = total;
    totalMoves--;
    

    for (int i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 0)
        {
            if (top3 == 0 || (top2 != 0 && arr2[top2 - 1] < arr3[top3 - 1]))
            {
                cout << arr2[top2 - 1] << " from " << rod[1] << " to " << rod[2] << endl;
                arr3[top3] = arr2[top2 - 1];
                top2--;
                top3++;
            }
            else if (top2 == 0 || (top3 != 0 && arr3[top3 - 1] < arr2[top2 - 1]))
            {
                cout << arr3[top3 - 1] << " from " << rod[2] << " to " << rod[1] << endl;
                arr2[top2] = arr3[top3 - 1];
                top3--;
                top2++;
            }
        }
        else if (i % 3 == 1)
        {
            if (top3 == 0 || (top1 != 0 && arr1[top1 - 1] < arr3[top3 - 1]))
            {
                cout << arr1[top1 - 1] << " from " << rod[0] << " to " << rod[2] << endl;
                arr3[top3] = arr1[top1 - 1];
                top1--;
                top3++;
            }
            else if(top1 == 0 || (top3 != 0 && arr3[top3 - 1] < arr1[top1 - 1]))
            {
                cout << arr3[top3 - 1] << " from " << rod[2] << " to " << rod[0] << endl;
                arr1[top1] = arr3[top3 - 1];
                top3--;
                top1++;
            }
        }
        else
            if (top2 == 0 || (top1 != 0 && arr1[top1 - 1] < arr2[top2 - 1]))
            {
                cout << arr1[top1 - 1] << " from " << rod[0] << " to " << rod[1] << endl;
                arr2[top2] = arr1[top1 - 1];
                top1--;
                top2++;
            }
            else if (top1 == 0 || (top2 != 0 && arr2[top2 - 1] < arr1[top1 - 1]))
            {
                cout << arr2[top2 - 1] << " from " << rod[1] << " to " << rod[0] << endl;
                arr1[top1] = arr2[top2 - 1];
                top1++;
                top2--;
            }
    }
}
