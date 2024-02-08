#include <iostream>
#include <vector>
using namespace std;

int binarySearchFirst(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1; // Continue searching in the left half for the first occurrence
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int binarySearchLast(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            low = mid + 1; // Continue searching in the right half for the last occurrence
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

void searchKey(vector<int>& arr, int key) {
    int first = binarySearchFirst(arr, key);
    if (first == -1) {
        cout << "Key not present\n";
        return;
    }
    int last = binarySearchLast(arr, key);
    int count = last - first + 1;
    cout << key << " " << count << endl;
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
        searchKey(arr, key);
    }
    return 0;
}
