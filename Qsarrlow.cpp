#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array using the first element as the pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // Picking the first element as the pivot
    int i = low;          // Index to keep track of smaller elements

    // Start checking from the element right after the pivot
    for (int j = low + 1; j <= high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap current element with the element at index i
        }
    }
    // Place the pivot element in its correct sorted position
    swap(arr[low], arr[i]);
    return i; // Return the partitioning index
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
    // Moved 70 to the front so it acts as our first pivot
    vector<int> arr = {70, 80, 30, 90, 40, 50, 10}; 
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
