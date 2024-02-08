#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findTripletIndices(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = arr[i] + arr[right];
            if (sum == arr[left]) {
                return {i, left, right};
            } else if (sum < arr[left]) {
                right--;
            } else {
                left++;
            }
        }
    }
    return {}; // No triplet found
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

        vector<int> indices = findTripletIndices(arr);

        if (indices.empty()) {
            cout << "No sequence found\n";
        } else {
            cout << indices[0] << " " << indices[1] << " " << indices[2] << endl;
        }
    }
    return 0;
}
