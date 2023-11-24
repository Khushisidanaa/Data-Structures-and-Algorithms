//
//  main.cpp
//  insertionsort
//
//  Created by Khushi Sidana on 18/10/21.
//

// C++ program for insertion sort
#include<iostream>
using namespace std;

// Function to sort an array using insertion sort
void insertionSort(int array[], int num)
{
    int i, pointer, j;
    for (i = 1; i < num; i++)
    {
        pointer = array[i];
        j = i - 1;
        
        //The elements greater than the key are moved one position ahead
        while (j >= 0 && array[j] > pointer)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = pointer;
    }
}

// A utility function to print an array of size n
void Output_array(int arr[], int num)
{
    cout<<"The array after performing insertion sort: "<<endl;
    int i;
    for (i = 0; i < num; i++)
        cout << arr[i] << " ";
    cout << endl<<endl;
}

/* Driver code */
int main()
{
    int num,i;
    
    cout<<"Enter the number of elements: ";
    cin>>num;
    int arr[num] ;
    
   
    for (i = 0; i < num; i++)
    {
       cout<<"Enter the element"<<i+1<<": ";
        cin >> arr[i] ;
    }
    cout << endl;
    
    cout<<"The given array is ";
    for (i = 0; i < num; i++)
        cout << arr[i] <<" ";
    cout<<endl<<endl;
    
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    Output_array(arr, n);

    return 0;
}

// This is code is contributed by rathbhupendra


