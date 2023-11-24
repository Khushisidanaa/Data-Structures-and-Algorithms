//
//  main.cpp
//  Floydwarshall
//
//  Created by Khushi Sidana on 20/10/21.
//

#include <iostream>
using namespace std;

#define INF 9999   // setting infinity as 9999

//Function to print the output matrix after Floyd Warshall Algorithm
void printOutput(int **adj ,int num)
{
   
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (adj[i][j] == INF)
                cout << "INF"
                    << "     ";
            else
                cout << adj[i][j] << "     ";
        }
        cout <<endl;
    }
    cout<<endl;
}


//Function to implement the Floyd Warshall Algorithm
void floydWarshall(int **adj, int num)
{
    int  i, j, k;

    for (k = 0; k < num; k++) //k represnts the number of iterations which is the node which is visited
    {
        for (i = 0; i < num; i++) // i is the column number
        {
            for (j = 0; j < num; j++)  // j is the row number
            {
                if (adj[i][j] > (adj[i][k] + adj[k][j])
                    && (adj[k][j] != INF
                        && adj[i][k] != INF))
                    adj[i][j] = adj[i][k] + adj[k][j];  // assigning the value of the shortest path
            }
        }
    }
    
    int *print[num];
    
    for( int k=0; k<num; k++)
    {
        print[k]=adj[k];
    }
    
    cout << endl<<"The output matrix after performing Floyd Warshall Algorithm is: "<<endl<<endl;
    printOutput(print, num);    // calling the printOutput function
}


// Driver code
int main()
{

//Taking user input
int num;
cout<<"Enter the number of vertices: ";
cin>>num;
cout<<endl;
    
    int adj[num][num];
    
    cout<<"";
    
    cout<<"Enter the values for the Adjacency matrix"<<endl;
    for (int i = 0; i < num; i++)
    {
        cout<<endl<<"Enter values for row "<<(i+1)<<": "<<endl;
        for (int j = 0; j < num; j++)
        {
            cout<<"Enter the ["<<i<<"]["<<j<<"]"<< " element: ";
            cin>>adj[i][j];
        }
    }
    
    int *array[num];
    for( int k=0; k<num; k++)
    {
        array[k]=adj[k];
    }

    cout<<endl<<"The input matrix is "<<endl;
    printOutput(array, num);          //function call to print the input array
    floydWarshall(array, num);        //function call to implement the algo
    
    return 0;
}




