#include <bits/stdc++.h>

// Function to perform counting sort
void countingSort(std::vector<int> &arr)
{
    if (arr.empty())
        return; // Handle empty array

    // Find the maximum element in the array
    int maxVal = *max_element(arr.begin(), arr.end());

    // Create a count array to store the count of each unique value
    std::vector<int> count(maxVal + 1, 0);

    // Store the count of each element
    for (int num : arr)
    {
        count[num]++;
    }

    // Reconstruct the sorted array
    int index = 0;
    for (int i = 0; i <= maxVal; i++)
    {
        while (count[i] > 0)
        {
            arr[index++] = i; // Place the element in the original array
            count[i]--;       // Decrease count
        }
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
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    std::cout << "Original array: ";
    printArray(arr);

    countingSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
