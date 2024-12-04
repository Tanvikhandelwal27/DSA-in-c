// Question 1: Implement the Merge Sort Algorithm (10 Marks)
// Problem:
// Implement the Merge Sort algorithm to sort an array of integers. Your solution should:
// Accept an array of integers as input.
// Sort the array in ascending order using the Merge Sort algorithm.
// Return the sorted array.
// Instructions:
// Implement merge sort using the divide and conquer approach.
// Provide a helper function for merging two sorted sub-arrays.
// Your implementation should be recursive and should use the merge step to combine sorted subarrays.
// Ensure that you handle both small arrays and large arrays efficiently.
// Time complexity should be O(n log n), and space complexity should be O(n).
// Additional Tasks:
// After implementing the algorithm, sort an array with at least 10 integers and display the sorted result.
// Time complexity analysis: Explain the time complexity of the merge sort algorithm and how it achieves the optimal performance.
 
// UPLOAD THE GITHUB LINK FOR THE SOLUTION.

#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;    
    
    int* leftArray = (int*)malloc(n1 * sizeof(int));
    int* rightArray = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
    
    free(leftArray);
    free(rightArray);
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    
   
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
   
    int* arr = (int*)malloc(n * sizeof(int));
    
    
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    displayArray(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    displayArray(arr, n);
    
    free(arr);
    return 0;
}