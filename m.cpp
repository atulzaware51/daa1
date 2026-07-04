#include <iostream>
#include <vector>
using namespace std;

// Changed return type from int to void, added missing parameter types
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int i = low;
    int j = mid + 1; // Fixed typo

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) { // Changed < to <= for stability
            temp.push_back(arr[i]); // Push the VALUE, not the index 'i'
            i++;
        } else {
            temp.push_back(arr[j]); // Push the VALUE, not the index 'j'
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= high) { // Fixed logical error: should be j <= high, not j <= mid
        temp.push_back(arr[j]);
        j++;
    }

    // Fixed missing parentheses on size()
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[low + idx] = temp[idx]; // Added missing semicolon
    }
}

// Removed spacing in name, removed trailing semicolon, added param types
void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2; // Missing semicolon fixed

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    vector<int> arr = {7,0, 5,8, 1,9};
    int n = arr.size(); // Correct size calculation for vectors

    mergeSort(arr, 0, n - 1);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
