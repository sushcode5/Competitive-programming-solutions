/* 
            Name - Rindhe Sushil Samadhan
            IIT Guwahati
            
*/

/*  

     "Kruskals.cpp" was solved using "Union find Algorithm"
     This problem is solved using "Union by rank and path compression" which has better time complexity.
     
*/


//Solved using union by rank and path compression.
//Time complexity -> ElogE +ElogV

#include <bits/stdc++.h>
using namespace std;
struct Edges{
    int source;
    int destination;
    int weight;
};
struct subset{
    int parent;
    int rank;
};
bool sortInput(Edges E1,Edges E2){
    
        return E1.weight <E2.weight;
}
int find(int i,struct subset Subsets[])
{
    if (Subsets[i].parent != i){
        Subsets[i].parent = find(Subsets[i].parent, Subsets);
    }
 
    return Subsets[i].parent;
}
void Union( struct subset*Subsets,int xroot,int yroot){
    if(Subsets[xroot].rank<Subsets[yroot].rank){
        Subsets[xroot].parent=yroot;
    }
    else if(Subsets[xroot].rank>Subsets[yroot].rank){
        Subsets[yroot].parent=xroot;
    }
    else{
        Subsets[yroot].parent = xroot;
        Subsets[xroot].rank++;
    }
}
vector<Edges> Kruskals(Edges* input,int V,int E){
    //Sort input array based on weights
     sort(input,input+E,sortInput);
    
    vector<Edges>output;
    subset* Subsets = new subset[V];
    for(int i=0;i<V;i++){
        Subsets[i].parent = i;
        Subsets[i].rank = 0;
    }
   
    int count = 0;
    int i=0;
    while(count<V-1){
        //Find parent for v1 and v2
        int parentV1 = find(input[i].source, Subsets);
        int parentV2 = find(input[i].destination, Subsets);
        if(parentV1!=parentV2){
            Union(Subsets,parentV1,parentV2);
            output.push_back(input[i]);
            count++;
        }
        i++;
    }
    delete[]Subsets;
    return output;
}

int main() {
    int V,E;
    cin>>V>>E;
    Edges* input=new Edges[E];
    //take the input
    for(int i=0;i<E;i++){
        
        int vertex1,vertex2, edgeWeight;
        cin>>vertex1>>vertex2>>edgeWeight;
        
        input[i].source=vertex1;
        input[i].destination=vertex2;
        input[i].weight= edgeWeight;
    } 
    // call for function
    vector<Edges>output= Kruskals(input,V,E);
    
    //Print the output
    for(int i=0;i<output.size();i++){
        if(output[i].source<output[i].destination)
            cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
        else
             cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
            
    }
    delete[]input;
    return 0;
}
