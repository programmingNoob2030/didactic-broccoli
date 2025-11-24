// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <limits>
// #include <queue>
// #include <map>
// using namespace std;
// // 用于记录被访问的节点，防止重复访问
// vector<string> processed;
// // 用于更新最小花费
// string find_lowest_cost_node(map<string,int>& costs){
//   int lowest_cost = numeric_limits<int>::max();
//   string lowest_cost_node = "";
//   for (auto i : costs){
//     // 节点
//     string node = i.first;
//     // 节点对应的最小花费
//     int cost = i.second;
//     bool is_processed = find(processed.begin(), processed.end(), i.first) != processed.end();
//     if (cost < lowest_cost && !is_processed){
//       // 更新最小花费节点
//       lowest_cost = cost;
//       lowest_cost_node = node;
//     }
//   }
//   return lowest_cost_node;
// }

// int main(){
//   // 要使用dijkstra算法, 需要使用3个散列表
//   // 1、graph: 存储图
//   map<string, map<string, int>> graph;
//   graph["start"] = {{"a", 6}, {"b", 2}};
//   // 注意初始化时最外层需要一个花括号进行包裹
//   graph["a"] = {{"end", 1}};
//   graph["b"] = {{"a", 3}, {"end", 5}};
//   graph["end"] = {};
//   // 2、cost: 存储从起点到每个点的最小花费
//   map<string,int> costs;
//   costs["a"] = 6;
//   costs["b"] = 2;
//   costs["end"] = INT_MAX;
//   // 3、parents: 存储每个点的父节点
//   map<string, string> parents;
//   parents["a"] = "start";
//   parents["b"] = "start";
//   parents["end"] = "";

//   string node = find_lowest_cost_node(costs);
//   while (node != ""){
//     // 处理最小花费节点
//     int cost = costs[node];
//     // 获取当前节点的邻居节点
//     auto neighbors = graph[node];
//     for (auto i : neighbors){
//       // 计算花费
//       int new_cost = cost + i.second;
//       // 如果新的花费值更少的话则修改其对应的costs表和parents表
//       if (new_cost < costs[i.first]){
//         costs[i.first] = new_cost;
//         parents[i.first] = node;
//       }
//     }
//     // 将遍历过的节点放入processed中
//     processed.push_back(node);
//     // 找到下一个最小花费节点
//     node = find_lowest_cost_node(costs);
//   }

//   // 打印输出结果
//   cout << "costs: " << endl;
//   for (auto i : costs){
//     cout << i.first << " " << i.second << endl;
//   }
//   cout << "parents: " << endl;
//   for (auto i : parents){
//     cout << i.first << " " << i.second << endl;
//   }

//   return 0;
// }

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
using namespace std;

// 函数 用于查找开销表中的最小节点
string find_lowest_node(map<string, int> costs, vector<string> processed)
{ // 处理表 用于存储被处理过的节点

  // 定义最小的节点
  string lowest_node = "";
  // 定义最小开销
  int lowest_cost = numeric_limits<int>::max();

  // 遍历所有目前所有没有被处理的节点
  for (auto &node : costs)
  {
    // 从起点到达该节点的开销
    int cost = node.second;
    // 检查该节点是否被处理过
    bool isNodeProcessed = find(processed.begin(), processed.end(), node.first) != processed.end();
    // 如果没有被处理 且 从起点到达该节点的开销比最低开销还要小
    if (!isNodeProcessed && cost < lowest_cost)
    {
      lowest_cost = cost;
      lowest_node = node.first;
    }
  }
  // 返回找到的最小的节点
  return lowest_node;
}

// Dijkstra算法
void dijkstra(map<string, map<string, int>> &graph, map<string, int> &costs, map<string, string> &parents, vector<string> processed)
{
  // 找到一个最小节点
  string node = find_lowest_node(costs, processed);
  // 还能找到节点(还有节点没有被处理,就循环处理直到每一个节点都被处理)
  while (!node.empty())
  {
    // 从起点到最小节点的开销
    int cost = costs[node];
    // 找到该节点的所有邻居节点
    map<string, int> neighbours = graph[node];
    // 遍历该节点的所有邻居节点
    for (auto &neighbour : neighbours)
    {
      // 当前邻居节点
      string n = neighbour.first;
      // 从最小节点到达邻居节点的开销
      int new_cost = cost + neighbour.second;
      // 如果最小节点到达邻居节点的开销 比 原先记录的从起点到该节点的开销 小
      if (new_cost < costs[n])
      {
        // 更新开销表
        costs[n] = new_cost;
        // 更新前驱表
        parents[n] = node;
      }
    }
    // 将处理过后的节点加入到处理表中
    processed.push_back(node);
    // 继续查找下一个邻居节点
    node = find_lowest_node(costs, processed);
  }
}

string print_shortest_path(map<string, string> &parents)
{
  string path = "end";
  string before = parents["end"];
  while (!before.empty())
  {
    path += "<-" + before;
    if (before != "start")
      before = parents[before];
    else
      return path;
  }
  return path;
}

int main()
{
  // 图A
  map<string, map<string, int>> graphA;
  graphA["start"] = {{"a", 5}, {"b", 2}};
  graphA["a"] = {{"d", 4}, {"c", 2}};
  graphA["b"] = {{"a", 8}, {"c", 7}};
  graphA["c"] = {{"end", 1}};
  graphA["d"] = {{"c", 6}, {"end", 3}};
  graphA["end"] = {};
  // 图A开销表
  map<string, int> costsA;
  costsA["a"] = 5;
  costsA["b"] = 2;
  costsA["c"] = numeric_limits<int>::max();
  costsA["d"] = numeric_limits<int>::max();
  costsA["end"] = numeric_limits<int>::max();
  // 图A前驱表
  map<string, string> parentsA;
  parentsA["a"] = "start";
  parentsA["b"] = "start";
  parentsA["c"] = "";
  parentsA["d"] = "";
  parentsA["end"] = "";

  // 图B
  map<string, map<string, int>> graphB;
  graphB["start"] = {{"a", 10}};
  graphB["a"] = {{"c", 20}};
  graphB["b"] = {{"a", 1}};
  graphB["c"] = {{"b", 1}, {"end", 30}};
  graphB["end"] = {};
  // 图B开销表
  map<string, int> costsB;
  costsB["a"] = 10;
  costsB["b"] = numeric_limits<int>::max();
  costsB["c"] = numeric_limits<int>::max();
  costsB["end"] = numeric_limits<int>::max();

  // 图B前驱表
  map<string, string> parentsB;
  parentsB["a"] = "start";
  parentsB["b"] = "";
  parentsB["c"] = "";
  parentsB["end"] = "";

  // 图C
  map<string, map<string, int>> graphC;
  graphC["start"] = {{"a", 2}, {"b", 2}};
  graphC["a"] = {{"b", 2}};
  graphC["b"] = {{"c", 2}, {"end", 2}};
  graphC["c"] = {{"a", -1}, {"end", 2}};
  graphC["end"] = {};
  // 图C开销表
  map<string, int> costsC;
  costsC["a"] = 2;
  costsC["b"] = 2;
  costsC["c"] = numeric_limits<int>::max();
  costsC["end"] = numeric_limits<int>::max();
  // 图C前驱表
  map<string, string> parentsC;
  parentsC["a"] = "start";
  parentsC["b"] = "start";
  parentsC["c"] = "";
  parentsC["end"] = "";

  vector<string> processed;
  dijkstra(graphA, costsA, parentsA, processed);
  dijkstra(graphB, costsB, parentsB, processed);
  dijkstra(graphC, costsC, parentsC, processed);
  // 最短路径A
  string pathA = print_shortest_path(parentsA);
  cout << "最短路径A" << endl;
  cout << pathA << endl;
  cout << "最小权重和" << endl;
  cout << costsA["end"] << endl;
  // 最短路径B
  string pathB = print_shortest_path(parentsB);
  cout << "最短路径B" << endl;
  cout << pathB << endl;
  cout << "最小权重和" << endl;
  cout << costsB["end"] << endl;
  // 最短路径C(这个案例中存在负权边但仍然能够得到正确答案)
  string pathC = print_shortest_path(parentsC);
  cout << "最短路径C" << endl;
  cout << pathC << endl;
  cout << "最小权重和" << endl;
  cout << costsC["end"] << endl;

  return 0;
}