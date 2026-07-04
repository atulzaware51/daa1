#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array on the basis of pivot element
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // We usually pick the last element as the pivot
    int i = (low - 1);     // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap current element with the element at index i
        }
    }
    // Place the pivot element in its correct sorted position
    swap(arr[i + 1], arr[high]);
    return (i + 1); // Return the partitioning index
}

// The main function that implements QuickSort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now at its final sorted place
        int pi = partition(arr, low, high);

        // Recursively sort elements before the partition and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 80, 30, 90, 40, 50, 70};
    int n = arr.size();
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    // Call the quick sort function
    quickSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
