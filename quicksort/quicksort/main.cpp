//
//  main.cpp
//  quicksort
//
//  Created by Khushi Sidana on 18/10/21.
//

#include <iostream>
using namespace std;

//Function for swapping
void swap( int *a, int *b)
{
    int t = *a;
    *a= *b;
    *b = t;
}

int partition( int array[], int low , int high)
{
    
    //Assign the last element of the array to pivot
    int pivot= array[high];
    int i =(low-1);
    
    //Swap all the elements of array smaller than pivot to the left of the array
    for(int k=low; k<=high; k++)
    {
        // if current element is smaller than pivot
        if (array[k]<pivot)
        {
            //increment the 'i' index of elements smaller than pivot
            i++;
            swap(&array[i], &array[k]);
        }
    }
    
    //position pivot after all elements smaller than pivot
    swap( &array[i+1], &array[high]);
     return (i+1);
    
}

//Function for sorting elements in the array
void quickSort(int array[], int low, int high )
{
    if(low<high)
    {
        //Sort the elements to position pivot in the correct place
        int piv= partition( array, low, high);
        
        quickSort(array, low, piv-1);  // Sort elements before pivot
        quickSort(array, piv+1, high); // Sort elements after pivot
    }
    
}

//Function to print the output array
void output_array(int array[], int num)
{
    int i;
    for( i=0; i<num; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int num,i;
    
    //Taking inputs from the user
    cout<<"Enter the number of elements: ";
    cin>>num;
    int arr[num] ;
    
   
    for (i = 0; i < num; i++)
    {
       cout<<"Enter the element"<<i+1<<": ";
        cin >> arr[i] ;
    }
    cout << endl;
    
    //Displaying the input array
    cout<<"The given array is ";
    for (i = 0; i < num; i++)
        cout << arr[i] <<" ";
    cout<<endl<<endl;
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, num-1);
    
    cout<<"The sorted array after performing Quick Sort: "<<endl;
    output_array(arr, num);
    
    cout<<endl;
    
    return 0;

}
