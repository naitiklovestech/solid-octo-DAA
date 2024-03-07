#include<iostream>
#include<vector>
#include<array>
using namespace std;

int main()
{
    int noOfLines, startingNode, endingNode;

    cout << "Enter the no of nodes that you have :";
    cin >> noOfLines;

    int arr1[noOfLines][noOfLines];
    for(int i=0; i<noOfLines; i++)
    {
        for(int j=0; j<noOfLines; j++)
        {
            cin >> arr1[i][j];
        }
    }

    cout << "Enter the starting node :";
    cin >> startingNode;

    cout << "Enter the destination Node :";
    cin >> endingNode;

    return 0;
}