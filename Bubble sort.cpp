#include <iostream>

using namespace std;



/* Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the list to be sorted, 

compares each pair of adjacent items and swaps them if they are in the wrong order. */

int* bubbleSort(int arr[], int n);



int main()

{

    // sample array

    const int size = 7;

    int arr[] = {9, 5, 12, 4, 8, 42, 3};



    // sort the array

    arr[size] = *bubbleSort(arr, size);

    

    for (int i = 0; i < size; i++)

    {

        cout << arr[i] << " ";

    }



    return 0;

}



int* bubbleSort(int *arr, int n) 

{

    bool swapped = true;

    int j = 0;

    int tmp;

    while(swapped) 

    {

        swapped = false;

        j++;

        for (int i = 0; i < n - j; i++) 

        {

            if (arr[i] > arr[i + 1]) 

            {

                tmp = arr[i];

                arr[i] = arr[i + 1];

                arr[i + 1] = tmp;

                swapped = true;

            }

        }

    }

    return arr;

}

