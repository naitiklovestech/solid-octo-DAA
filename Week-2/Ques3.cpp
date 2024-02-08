#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countPairsWithDifference(vector<int>& arr, int key) {
    unordered_map<int, int> freqMap;
    int count = 0;

    // Create a frequency map of elements in the array
    for (int num : arr) {
        freqMap[num]++;
    }

    // Count pairs with difference equal to key
    for (int num : arr) {
        int complement1 = num + key;
        int complement2 = num - key;

        // If complement1 exists in the map and is not the same as num, increment count
        if (freqMap.find(complement1) != freqMap.end() && complement1 != num) {
            count += freqMap[complement1];
        }

        // If complement2 exists in the map and is not the same as num, increment count
        if (freqMap.find(complement2) != freqMap.end() && complement2 != num) {
            count += freqMap[complement2];
        }
    }

    // Each pair is counted twice, so divide by 2 to get the actual count
    return count / 2;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int key;
        cin >> key;

        int pairsCount = countPairsWithDifference(arr, key);
        cout << pairsCount << endl;
    }
    return 0;
}
