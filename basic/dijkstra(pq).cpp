#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <climits>
using namespace std;
int inf = INT_MAX;
struct Node{
  string name;
  int cost;

  // 重载大于运算符,用于优先队列的比较(greater)
  bool operator>(const Node &other) const {
    return cost > other.cost;
  }
};

void dijkstra(map<string, map<string, int>> &g, priority_queue<Node, vector<Node>, greater<Node>> &pq, map<string, int> &costs){

  while (!pq.empty()){
    // 使用pq自动获取最小开销的节点,无需手写函数并且效率更高
    Node min_node = pq.top();
    pq.pop();

    // 获取最小节点的所有信息
    string node_name = min_node.name;
    int node_cost = min_node.cost;
    map<string, int> neighbours = g[node_name];
    
    // 遍历所有的邻居节点,和三表法一样
    for (auto &i : neighbours){
      // 获取邻居的名字和到达邻居节点的开销
      string neighbour_name = i.first;
      int neighbour_cost = i.second;
      // 计算从最小节点到达邻居节点的开销
      int new_cost = node_cost + neighbour_cost;
      // 如果到达邻居节点的开销小于已知的最小开销,则更新最小开销
      if (new_cost < costs[neighbour_name]){
        costs[neighbour_name] = new_cost;
        // 进队的时机:只有当到达这个节点的最小开销改变时才让节点进队
        pq.push(Node{neighbour_name, costs[neighbour_name]});
      }
    }
  }
}
int main(){
  priority_queue<Node, vector<Node>, greater<Node>> pq;
  map<string, map<string, int>> g;
  g["start"] = {{"a", 3}, {"b", 5}};
  g["a"] = {{"c", 5}, {"d", 9}};
  g["b"] = {{"c", 2}, {"e", 7}, {"d", 6}};
  g["c"] = {{"e", 6}};
  g["d"] = {{"e", 2}};
  g["e"] = {};

  map<string, int> costs;
  costs["a"] = 3;
  costs["b"] = 5;
  costs["c"] = inf;
  costs["d"] = inf;
  costs["e"] = inf;

  pq.push(Node{"a", 3});
  pq.push(Node{"b", 5});

  dijkstra(g, pq, costs);

  cout << "到达a点的最短路径" << endl;
  cout << costs["a"] << endl;

  cout << "到达b点的最短路径" << endl;
  cout << costs["b"] << endl;

  cout << "到达c点的最短路径" << endl;
  cout << costs["c"] << endl;

  cout << "到达d点的最短路径" << endl;
  cout << costs["d"] << endl;

  cout << "到达e点的最短路径" << endl;
  cout << costs["e"] << endl;

  return 0;
}