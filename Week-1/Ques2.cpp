#include <iostream>
#include <vector>
#include <algorithm>

bool binarySearch(const std::vector<int>& arr, int key, int& comparisons) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;

        if (arr[mid] == key) {
            return true; // Element found
        } else if (arr[mid] < key) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return false; // Element not found
}

int main() {
    std::vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16};
    int key = 10;
    int comparisons = 0;

    if (binarySearch(arr, key, comparisons)) {
        std::cout << "Element found!" << std::endl;
    } else {
        std::cout << "Element not found!" << std::endl;
    }

    std::cout << "Total comparisons: " << comparisons << std::endl;

    return 0;
}
