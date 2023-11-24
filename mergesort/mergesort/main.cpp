//
//  main.cpp
//  mergesort
//
//  Created by Khushi Sidana on 18/10/21.
//


#include<iostream>
using namespace std;

//function to swap the elements
void swapping(int &a, int &b)
{
   int temp;
   temp = a;
   a = b;
   b = temp;
}

//function to display the array
void display(int *array, int num) {
   for(int i = 0; i<num; i++)
      cout << array[i] << " ";
   cout << endl;
}

void merge(int *array, int left, int mid, int right) {
   int i, j, k, new_left, new_right;
    
   //Finding the size of left and right sub-arrays
   new_left = mid-left+1;
   new_right = right-mid;
    int left_arr[new_left];
    int right_arr[new_right];
    
   
    //Filling the left sub-array
   for(i = 0; i<new_left; i++)
      left_arr[i] = array[left+i];
    
    //Filling the right sub-array
   for(j = 0; j<new_right; j++)
      right_arr[j] = array[mid+1+j];
    
   i = 0; j = 0; k = left;
    
   //merge the temp arrays to get the real array
    
   while(i < new_left && j<new_right) {
      if(left_arr[i] <= right_arr[j]) {
         array[k] = left_arr[i];
         i++;
      }else{
         array[k] = right_arr[j];
         j++;
      }
      k++;
   }
   while(i<new_left) {       //in case of extra element in left array
      array[k] = left_arr[i];
      i++; k++;
   }
   while(j<new_right) {     //incase of extra element in right array
      array[k] = right_arr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int left, int right)
{
   if(left  < right)
   {
       //Find the middle point of array
      int mid = left+(right-left)/2;
      // Sort first and second arrays
       
      mergeSort(array, left, mid); //Sort first array that is the array to the left of the mid point
      mergeSort(array, mid+1, right); //Sort second array that is the array to the right of the mid point
      merge(array, left, mid, right); // Merge the arrays
   }
}
int main() {
    
    int num,i;
    //Taking user input of the elements

    
    //Taking inputs from the user
    cout<<"Enter the number of elements: ";
    cin>>num;
    int arr[num] ;
    
    for (int i = 0; i < num; i++)
    {
       cout<<"Enter the element "<<i+1<<": ";
        cin >> arr[i] ;
    }
    cout << endl;
    
    //Displaying the input array
    
  //Printing the array before  sorting
   cout << "The Array before Sorting: ";
   display(arr, num);
    cout<<endl;
    
    //Performing merge sort
   mergeSort(arr, 0, num-1);     //(n-1) indiactes the last index
    
    //Display the array after sorting
   cout << "Array after Sorting: ";
   display(arr, num);
    cout<<endl;
}
