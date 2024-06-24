/*This is the code for algorithim of merge sort.
Merge sort involves divide and conquer principle to sort large data sets accordingly. */



#include <iostream>
using namespace std;

/*
 * merge function Merges two sorted subarrays of the given array.
 * @parameter arr The input array.
 * @parameter l The starting index of the left subarray.
 * @parameter mid The middle index that separates the left and right subarrays.
 * @parameter r The ending index of the right subarray.
 */
void merge(int arr[], int l, int mid, int r)
{
    // n1 and n2 variable calculates the sizes of the left and right sub-arrays
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // Create temporary arrays to hold the left and right subarrays
    int a[n1];
    int b[n2];

    // Copying the elements in left subarray to 'a'
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    // Copy the elements of the right subarray to 'b'
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    // Merge the two subarrays back into the original array
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    // Add any remaining elements from the left subarray
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }

    // Add any remaining elements from the right subarray
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

/**
 * @brief Recursively sorts the given array using the Merge Sort algorithm.
 * 
 * @param arr The input array to be sorted.
 * @param l The starting index of the array.
 * @param r The ending index of the array.
 */
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Calculate the middle index
        int mid = (l + r) / 2;

        // Recursively sort the left and right halves of the array
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);

        // Merge the sorted left and right halves
        merge(arr, l, mid, r);
    }
}

int main()
{
    cout << "Enter 4 elements of a four element array" << endl;

    // Create a 4-element array
    int arr[4];

    // Get the input elements from the user
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }

    // Sort the array using Merge Sort
    mergesort(arr, 0, 3);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
