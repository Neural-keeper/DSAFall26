#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// helper
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // size of left sub vector
    int n2 = right - mid; // size of right sub vector
    vector<int> L(n1); // temporary left vector
    vector<int> R(n2); // temporary right vector
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i]; // copy left part into temp L vector
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j]; // copy left part into temp L vector
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void printVector(vector<int>& arr) {
    cout << "{ ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    } 
    cout << "}" << endl;
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return; // exit if 1 or 0
    }
    int mid = left + (right - left)/2; 
    mergeSort(arr, left, mid); // recursive sort left half
    mergeSort(arr, mid + 1, right); // recursive sort right half
    merge(arr, left, mid, right);
    printVector(arr);
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // pivot is last element
    int i = (low - 1); // index of smaller element
    for (int j = low; j <= high; j++) { // looping through the elements within the partition given
        if (arr[j] < pivot) { // if element is smaller than pivot
            i++; // increment the index
            swap(arr[i], arr[j]); // swap elements 
        }
    }
    swap(arr[i + 1], arr[high]); // place the pivot in the correct position
    return (i + 1); // return the pivot index
}

// for this particular implementation, using last element as the pivot
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) { 
        // checking if bounds are valid
        int pi = partition(arr, low, high); // get the partition index
        quickSort(arr, low, pi - 1); // sort left partition
        quickSort(arr, pi + 1, high); // sort right partition
    }
}

// insertion sort
void insertionSort(vector<int>& arr) {
    int n = arr.size(); // Get size of array
    for (int i = 1; i < n; i++) { // Loop from second element
        int key = arr[i]; // Store current element
        int j = i - 1; // Previous index
        while (j >= 0 && arr[j] > key) { // Shift elements greater than key
            arr[j + 1] = arr[j]; // Shift right
            j = j - 1; // Move left
        }
        arr[j + 1] = key; // Insert key into correct position
    }
}

// selection sort
void selectionSort(vector<int>& arr) {
    int n = arr.size(); // Get size of array
    for (int i = 0; i < n - 1; i++) { // Loop through array
        int minIndex = i; // Assume current index is minimum
        for (int j = i + 1; j < n; j++) { // Find minimum in remaining array
            if (arr[j] < arr[minIndex]) { // Update minimum index if smaller found
                minIndex = j; // Store new minimum index
            }
        }
        if (minIndex != i) { // If minimum changed
            swap(arr[i], arr[minIndex]); // Swap elements
        }
    }
}

// heapify helper
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index
    if (left < n && arr[left] > arr[largest]) // If left child is larger than root
        largest = left; // Update largest index
    if (right < n && arr[right] > arr[largest]) // If right child is larger than largest so far
        largest = right; // Update largest index
    if (largest != i) { // If largest is not root
        swap(arr[i], arr[largest]); // Swap root with largest element
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

// heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size(); // Get size of array
    for (int i = n / 2 - 1; i >= 0; i--) // Build max heap
        heapify(arr, n, i); // Heapify subtree
    for (int i = n - 1; i > 0; i--) { // Extract elements from heap one by one
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0); // Call max heapify on reduced heap
    }
}

int main() {
    vector<int> arr1 = {85, 24, 63, 45, 17, 9, 31, 41, 98, 1};
    printVector(arr1);
    mergeSort(arr1, 0, arr1.size() - 1);
    printVector(arr1);

    vector<int> arr2 = {78, 21, 14, 97, 87, 62, 74, 85, 76, 45, 84, 22};
    printVector(arr2);
    quickSort(arr2, 0, arr2.size() - 1);
    printVector(arr2);

    return 0;
}

/*
 * =========================================================================
 * ALGORITHM PROPERTIES & COMPLEXITIES REFERENCE TABLE
 * =========================================================================
 * Algorithm       | Best Case   | Average Case | Worst Case | Stable? | In-Place?
 * -------------------------------------------------------------------------
 * Merge Sort      | O(n log n)  | O(n log n)   | O(n log n) | Yes     | No (O(n) space)
 * Quick Sort      | O(n log n)  | O(n log n)   | O(n^2)     | No      | Yes (O(log n) stack)
 * Insertion Sort  | O(n)        | O(n^2)       | O(n^2)     | Yes     | Yes
 * Selection Sort  | O(n^2)      | O(n^2)       | O(n^2)     | No      | Yes
 * Heap Sort       | O(n log n)  | O(n log n)   | O(n log n) | No      | Yes
 * =========================================================================
 */