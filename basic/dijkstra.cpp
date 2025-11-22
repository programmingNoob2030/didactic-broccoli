#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <map>
using namespace std;
// 用于记录被访问的节点，防止重复访问
vector<string> processed;
// 用于更新最小花费
string find_lowest_cost_node(map<string,int>& costs){
  int lowest_cost = numeric_limits<int>::max();
  string lowest_cost_node = "";
  for (auto i : costs){
    // 节点
    string node = i.first;
    // 节点对应的最小花费
    int cost = i.second;
    bool is_processed = find(processed.begin(), processed.end(), i.first) != processed.end();
    if (cost < lowest_cost && !is_processed){
      // 更新最小花费节点
      lowest_cost = cost;
      lowest_cost_node = node;
    }
  }
  return lowest_cost_node;
}

int main(){
  // 要使用dijkstra算法, 需要使用3个散列表
  // 1、graph: 存储图
  map<string, map<string, int>> graph;
  graph["start"] = {{"a", 6}, {"b", 2}};
  // 注意初始化时最外层需要一个花括号进行包裹
  graph["a"] = {{"end", 1}};
  graph["b"] = {{"a", 3}, {"end", 5}};
  graph["end"] = {};
  // 2、cost: 存储从起点到每个点的最小花费
  map<string,int> costs;
  costs["a"] = 6;
  costs["b"] = 2;
  costs["end"] = INT_MAX;
  // 3、parents: 存储每个点的父节点
  map<string, string> parents;
  parents["a"] = "start";
  parents["b"] = "start";
  parents["end"] = "";

  string node = find_lowest_cost_node(costs);
  while (node != ""){
    // 处理最小花费节点
    int cost = costs[node];
    // 获取当前节点的邻居节点
    auto neighbors = graph[node];
    for (auto i : neighbors){
      // 计算花费
      int new_cost = cost + i.second;
      // 如果新的花费值更少的话则修改其对应的costs表和parents表
      if (new_cost < costs[i.first]){
        costs[i.first] = new_cost;
        parents[i.first] = node;
      }
    }
    // 将遍历过的节点放入processed中
    processed.push_back(node);
    // 找到下一个最小花费节点
    node = find_lowest_cost_node(costs);
  }

  // 打印输出结果
  cout << "costs: " << endl;
  for (auto i : costs){
    cout << i.first << " " << i.second << endl;
  }
  cout << "parents: " << endl;
  for (auto i : parents){
    cout << i.first << " " << i.second << endl;
  }

  return 0;
}