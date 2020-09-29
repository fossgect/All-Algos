
// A simple representation of graph using STL 
#include<bits/stdc++.h> 
using namespace std; 
  
// A utility function to add an edge in an 
// undirected graph. 

  
// Driver code 
int main() 
{ 
    int x,y,i,n; 
    vector< vector <int> > adj; 
    vector<int>::iterator m; 
    cout<<"Enter the no.of edges\n";
    cin>>n;
    adj.resize(n);
    for(i=0;i<n;i++)
    {   
        cin>>x>>y;
        adj[x].push_back(y); 
        adj[y].push_back(x);
    }
    for (int v = 0; v < n; v++) 
    { 
        
        cout << "\n Adjacency list of vertex "
             << v << "\n head "; 
        for (m = adj[v].begin(); m < adj[v].end(); m++) 
           cout << "-> " << *m; 
        printf("\n"); 
    } 

    
  //  printGraph(adj, n); 
    return 0; 
} 