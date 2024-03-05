#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countPairsWithDifference(vector<int>& arr, int key) 
{
    unordered_map<int, int> freqMap;
    int count = 0;

    
    for (int num : arr) 
    {
        freqMap[num]++;
    }

    
    for (int num : arr) 
    {
        int complement1 = num + key;
        int complement2 = num - key;

        
        if (freqMap.find(complement1) != freqMap.end() && complement1 != num) 
        {
            count += freqMap[complement1];
        }

        
        if (freqMap.find(complement2) != freqMap.end() && complement2 != num) 
        {
            count += freqMap[complement2];
        }
    }


    return count / 2;
}

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; ++i) 
        {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        int pairsCount = countPairsWithDifference(arr, key);
        cout << pairsCount << endl;
    }
    
    return 0;
}
