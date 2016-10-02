/*
 *  DFS algorithm for graphs
 * */

#include<iostream>
#include<list>
using namespace std;
class Graph
{
  int V; //no of vertices
  list<int> *vertex; //list to store edges
public:
  Graph(int v)
  {
    //Lets initialize the graph here
    V=v;
    vertex= new list<int>[v];
  }
  void addEdge(int x, int y)
  {
    //Push the edge into records
    vertex[x].push_back(y);
  }
  void seekTheEdges(int v, bool visit[])
  {
    cout << v << " ";
    //We are visiting a new vertex so make it true
    visit[v]=true;
    //Now dfs on all the edges connected to it
    list<int>::iterator i;
    for(i=vertex[v].begin(); i!=vertex[v].end(); i++)
      if(!visit[*i])
        seekTheEdges(*i,visit);
  }
  void dfs()
  {
    int i;
    //This array keeps a track of vertices we have visited
    bool *visit = new bool[V];
    //Currently no vertices are visited, so false-ify
    for(i=0; i<V; i++)
      visit[i]=false;
    for(i=0; i<V; i++)
      if(!visit[i])
        seekTheEdges(i,visit);
  }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "The dfs output is: ";
    g.dfs();
}

