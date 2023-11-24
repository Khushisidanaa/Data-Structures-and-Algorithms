//
//  main.cpp
//  Knapsack
//
//  Created by Khushi Sidana on 18/10/21.
//
#include <iostream>
using namespace std;

//Declaring the structure
typedef struct {
   int value;
   int weight;
   float density;
} Item; //Initialising Item of struct type

//Taking the input from the user
void input(Item items[],int num) {
   
   for(int i = 0; i < num; i++) {
       cout<<endl<<"Enter the value of item "<<i+1<<": ";
      cin >> items[i].value;
       
      cout << "Enter the weight of item "<< i+1<<": ";
      cin >> items[i].weight;
   }
}

//Display the items in a more orderly fashion
void display(Item items[], int num) {
   int i;
   cout << endl<<"Values: ";
   for(i = 0; i < num; i++) {
      cout << items[i].value << "\t";
   }
   cout << endl << "Weight: ";
   for (int i  = 0; i < num; i++) {
      cout << items[i].weight << "\t";
   }
    cout << endl<<endl;
}

//Comparing the items on the basis of density
bool compare(Item i1, Item i2) {
   return (i1.density > i2.density);
}

//Performing fractional knapsack
float knapsack(Item items[], int num, int total_wt)
{
   int i;
   float totalValue = 0, totalWeight = 0;
   for (i = 0; i < num; i++) {
      items[i].density = items[i].value / items[i].weight; // getting density as value/weight
   }
    //Sort the items according to value we are getting by desnity= (value/weight)
   sort(items, items+num, compare);
    
  
   for(i=0; i<num; i++) {
      if(totalWeight + items[i].weight<= total_wt)
      {
         totalValue += items[i].value ;
         totalWeight += items[i].weight;
      } else
      {
         int wt = total_wt-totalWeight;
         totalValue += (wt * items[i].density);
         totalWeight += wt;
         break;
      }
   }
   cout << endl<<"The maximum weight of the bag is " << totalWeight<<endl;
   return totalValue;
}

int main() {
    //Taking user input
    int total_wt;
    int num;
    cout<<"Enter the number of items: ";
    cin>>num;
    
   Item items[num];
   input(items,num);
    
    //Display the data in an ordered fashion
   cout << "The input given is: \n \n";
   display(items,num);
    
   cout<< "Enter the total weight of the Knapsack: ";
   cin >> total_wt;
    
   float max_val = knapsack(items, num, total_wt);
    cout << "Maximum value of the knapsack is "<< max_val<<endl<<endl;;
}
