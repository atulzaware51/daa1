#include <iostream>
using namespace std;

int maximum(int arr[], int low, int high) {
    // Base case 1: Only one element
    if (low == high) { 
        return arr[low]; 
    }
    // Base case 2: Two elements (prevents infinite recursion loops in some cases)
    if (high == low + 1) {
        if (arr[low] > arr[high]) return arr[low];
        else return arr[high];
    }

    int mid = low + (high - low) / 2;
    
    int LM = maximum(arr, low, mid);
    int RM = maximum(arr, mid + 1, high);

    if (LM > RM) return LM;
    else return RM;
}

int minimum(int arr[], int low, int high) {
    // Base case 1: Only one element
    if (low == high) { 
        return arr[low]; 
    }
    // Base case 2: Two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) return arr[low];
        else return arr[high];
    }

    int mid = low + (high - low) / 2;
    
    int LM = minimum(arr, low, mid);
    int RM = minimum(arr, mid + 1, high);

    if (LM < RM) return LM;
    else return RM;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]); // Fixed array size calculation
    
    // Added missing semicolons
    cout << "maxele: " << maximum(arr, 0, n - 1) << endl; 
    cout << "minele: " << minimum(arr, 0, n - 1) << endl; 
    
    return 0;
} // Added missing closing brace for main
