#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int target)
{
    for(int i=0; i<n ; i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int iter, noEle, trgt;


    cout << "Enter the no of times you want to use linear search :";
    cin >> iter;

    while(iter!=0)
    {
        cout << "Enter the no of elements your array has : ";
        cin >> noEle;

        int arr[noEle];

        for(int i =0; i<noEle ; i++)
        {
            cout << "Element " << i+1 << ":";
            cin >> arr[i];
        }

        cout << "Enter the target no :";
        cin >> trgt;

        int index = linearSearch(arr, noEle, trgt);

        if(index == -1)
        {
            cout << "The target element was not found in the given array";
        }
        else
        {
            cout << "The target element was found at index : " << index << endl;
        }

        iter--;
    }
}