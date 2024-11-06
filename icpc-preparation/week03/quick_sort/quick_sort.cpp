#include <iostream>
#include <vector>

// Function to swap two elements
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Partition function to place the pivot in the correct position
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        { // If current element is smaller than pivot
            i++;
            swap(arr[i], arr[j]); // Swap
        }
    }
    swap(arr[i + 1], arr[high]); // Swap the pivot element with the element at i + 1
    return i + 1;                // Return the partition index
}

// QuickSort function
void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);        // Recursively sort elements before partition
        quickSort(arr, pi + 1, high);       // Recursively sort elements after partition
    }
}

// Function to print the array
void printArray(const std::vector<int> &arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    std::cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
