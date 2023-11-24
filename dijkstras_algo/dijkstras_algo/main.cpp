//
//  main.cpp
//  dijkstras_algo
//
//  Created by Khushi Sidana on 18/10/21.
//

#include <iostream>
using namespace std;

//To find the minumum vertex
int findMinVertex(int* distance, bool*visited, int n){
    int minVertex = -1;
    for (int i=0; i<n; i++)
    {
        //Make sure its not visisted before and the distance is less than the current vertex
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            //assign value of minVertex if condition is satisfied
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int** edges, int n)
{
    int* distance = new int[n];
    bool* visited = new bool[n];
    
    for (int i=0; i<n; i++)
    {
       
        distance[i] = INT_MAX; //Initially all distances are infinity
        visited[i] = false; // Initially mark all visisted as false
    }
    distance[0] = 0; //Distance from node to 0 to node 0 is is 0
    
    for (int i=0; i<n-1; i++)
    {
        int minVertex = findMinVertex(distance, visited, n);
        visited[minVertex] = true;
        for (int j=0; j<n; j++)
        {
            if(edges[minVertex][j] !=0 && !visited[j])
            {
                //Checking if distance through new path is better than the older one
                int dist = distance[minVertex] + edges[minVertex] [j];
                if (dist < distance[j])
                {
                    distance[j] = dist;
                }
            }
        }
    }
    
    //Priniting the distance
    for (int i=0; i<n; i++)
    {
        cout <<"The shortest distance of node"<< i << " from node 0 is  " << distance[i] << endl;
    }
    
    //Deleting the arrays after printing
    delete [] visited;
    delete [] distance;
}

int main()
{
    int num,e_num;
    
    //Taking input from the user
    cout << "Enter the number of vertices: ";
    cin >> num;
    
    cout << "Enter number of edges: ";
    cin >> e_num;
    
    int** Edge = new int *[num];
    for (int i=0; i<num; i++)
    {
        Edge[i] = new int[num];
        for (int j=0; j<num; j++)
        {
            Edge [i][j] = 0;
        }
    }

    //To check if the graph is an undirected graph or a directed graph
    char str;
    cout<<endl<< "Is the graph a undirected graph ? \nEnter 'Y' for yes and 'N' for no:  ";
    cin>>str;
    
    //Incase of undirected graph
    if (str=='Y'|| str=='y')
    {
              
    for (int i=1; i<e_num+1; i++)
    {
        cout<<endl<<"For edge "<<i<<": ";
        int src, dest, wt;
        
        cout << "Enter the source node: ";
        cin >> src;
        
        cout << "Enter the destination node: ";
        cin >> dest;
        
        cout << "Enter the weight of the edge : ";
        cin >> wt;
        
        Edge[src][dest] = wt;
        Edge[dest][src] = wt;
    }
    }
    //Incase of directed graph
        else{
            for (int i=1; i<e_num+1; i++)
            {
                cout<<endl<<"For edge "<<i<<": ";
                int src, dest, wt;
                
                cout << "Enter the source node: ";
                cin >> src;
                
                cout << "Enter the destination node: ";
                cin >> dest;
                
                cout << "Enter the weight of the edge : ";
                cin >> wt;
                
                Edge[src][dest] = wt;
                
            }
          
            
        }
    
    
    cout << endl;
    
    //Performing the dijkstra's algorithm
    dijkstra (Edge, num);
    
    for (int i=0; i<num; i++)
    {
        delete[] Edge[i];
    }
    delete [] Edge;
}
