#include <bits/stdc++.h> 
#define pb push_back
using namespace std; 
typedef  pair<int, int> iPair; 
  
long int component[100];
vector< pair<int, iPair> > edges; 
vector< pair<int, iPair> > TE; 

  
// To add an edge 
void addEdge( long long  int u, long long  int v, long long int wt) 
{ 
    edges.push_back({wt, {u, v}}); 
} 

int main(){
    long long int n, e;
    long long int a,b,c,s,min,u,v; 
    
    cin >> n >> e; 
    //g.assign(n, vector<int>()); 
    for (int i = 0; i < e; i++) { 
        cin >>a>>b>>c; 
        addEdge(a,b,c); 
    }
     sort(edges.begin(), edges.end());
    
    for (int i = 1; i < n+1; i++) { 
        component[i]=i; 
    }
    sort(edges.begin(), edges.end()); 
    a=0;
    while(TE.size()< n-1){
        b=edges[a].second.first;
        c=edges[a].second.second;
        //cout<<component[b]<<"\t"<<component[c]<<"\n";
        if(component[b]!=component[c]){
            TE.push_back({edges[a].first, {b, c}});
            
            cout<<b<<"---"<<c<<"\n";
             for (int k= 1; k < n+1; k++) { 
                if(component[k]==component[b]){
                    component[k]=component[c];
                }
                
            }
        }
        a++;


    }



    return 0;
}