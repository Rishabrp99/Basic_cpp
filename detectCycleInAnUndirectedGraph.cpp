
  // Graph - Detect Cycle in Undirected graph
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;

class Graph
{
    int V;  
    list<int> *adj; 
    bool isCyclicUtill(int v,bool *visited,int parent);
public :
    Graph(int V); 
    void addEdge(int v,int w);
    bool isCyclic();
};
Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V]; 
}
void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);  
    adj[w].push_back(v); 
}
bool Graph::isCyclicUtill(int v,bool visited[],int parent)
{
    visited[v]=true;

    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
        {
            if(isCyclicUtill(*i,visited,v))
                  return true;
        }
        else if(*i!=parent)
            return true;
    }
    return false;
}
bool Graph::isCyclic()
{
   bool *visited=new bool[V];  
   for(int i=0;i<V;i++)
       visited[i]=false;

   for(int i=0;i<V;i++) 
       if(!visited[i])
          if(isCyclicUtill(i,visited,-1))
                 return true;

    return false;
}
int main()
{
    Graph g(4); 
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);    
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    if(g.isCyclic())
        cout<<" Graph contains cycle\n";
    else
        cout<<" Graph doesn't contain cycle\n";

    Graph g1(5);
    g1.addEdge(1,0);
    g1.addEdge(0,2);
    g1.addEdge(2,1);
    g1.addEdge(0,3);
    g1.addEdge(3,4);
    g1.isCyclic()?cout<<" Graph contain cycle\n":cout<<" Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0,1);
    g2.addEdge(1,2);
    g2.isCyclic()?cout<<" Graph contain cycle\n":cout<<" Graph doesn't contain cycle\n";

    return 0;
}
