#include <bits/stdc++.h>
using namespace std;
int n = 5;
void printArr(int *arr)
{
    cout << "arr: ";
    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5}; // mảng tĩnh
    int *arr1 = new int[n];      // mảng động
    delete[] arr1;
    array<int, 5> arr2;

        arr2.fill(2);
    printArr(arr);
    cout << "length: " << sizeof(arr) / sizeof(arr[0]) << endl; // truyền vào hàm sẽ sai
    return 0;
}
