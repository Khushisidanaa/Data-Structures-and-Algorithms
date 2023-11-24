#include<iostream>
using namespace std;


class Edge{
public:
    int source;
    int dest;
    int weight;
};


bool compare(Edge E1, Edge E2){
    return E1.weight< E2.weight;
}


int findparent(int v, int *parent)
{
    if (parent[v]== v)
    {
        return v;
    }
    return findparent(parent[v], parent);
}


void kruskals(Edge *input, int num, int e_num)
{
    //Sort edges in ascending order based on weights
    sort(input, input+e_num, compare );
    

    Edge *output= new Edge[num-1];
    int *parent= new int[num];
    
    for(int i=0; i<num; i++){
        parent[i]=i;
    }
    
    int count=0;
    int k=0;
    
    while(count!= num-1){
        
        Edge current_edge = input[k];
        
        int parent_source = findparent(current_edge.source, parent);
        int dest_parent= findparent(current_edge.dest, parent );
        
        //To make sure a cycle doesnt exist
        if (parent_source != dest_parent){
            output[count] = current_edge;
            count++;
            parent[parent_source]=dest_parent;
        }
        k++;
    }
    
    cout<<endl<<"The output after performing Kruskal's Algorithm is : "<< endl;
    
   
    for(int i=0;i<num-1;i++){
        if(output[i].source<output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
    }
    
  
      
   
    
    
}
int main(){
    
   
    int n,e_num,src,dest,wt;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>e_num;
    
    Edge *input = new Edge[e_num];
    
    for(int i=1; i< e_num+1; i++){
        
        cout<<endl<<"For edge "<<i<<":"<<endl;
        cout<<"Enter the source node, destination node and weight of edge ";
        cin>>src>>dest>>wt;
       
        
        input[i].source=src;
        input[i].dest=dest;
        input[i].weight=wt;
        
    }
    

    
    //Implement Kruskal's algorithm on the given input
     kruskals(input, n , e_num);
    
    
}
