#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//****************BLACKBOX START*****************
//START COPYING FROM HERE
class Graph {
  public:
    Graph(int num_nodes) 
      : adj_list(num_nodes), dist(num_nodes, -1) {}

    void add_edge(int start, int end);
    vector<vector<int>> adj_list;
    vector<int> dist;
};

void Graph::add_edge(int start, int end) {
  adj_list[start].push_back(end);
}

vector<int> BFS(Graph& g, int source) {
  vector<bool> visited(g.adj_list.size(), false);
  queue<int> q;
  q.push(source);

  visited[source] = true;
  g.dist[source] = 0;

  while(!q.empty()) {
    int cur_node = q.front();
    q.pop();

    for (int adj_node : g.adj_list[cur_node]) {
      if (!visited[adj_node]) {
        visited[adj_node] = true;
        g.dist[adj_node] = g.dist[cur_node] + 1;
        q.push(adj_node);
      }
    }
  }
  
  return g.dist;
}
//END COPYING HERE
//********************BLACKBOX END******************


int main() {
  // initialize a graph with 5 nodes (0 to 4)
  Graph g(5);

  // DIRECTED GRAPH
  g.add_edge(0, 4);
  g.add_edge(1, 3);

  // UNDIRECTED GRAPH
  g.add_edge(0, 4);
  g.add_edge(4, 0);
  g.add_edge(1, 3);
  g.add_edge(3, 1);

  // BFS starting from node 2
  vector<int> min_dist = BFS(g, 2);

  // Print distances
  for (int i = 0; i < min_dist.size(); i++) {
    cout << "Distance from 2 to " << i << " = " << min_dist[i] << "\n";
  }

  return 0;
}
