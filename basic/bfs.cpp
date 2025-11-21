#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
bool isSeller(string name){
  return name.back() == 'm';
}
// bfs逻辑
void bfs(map<string,vector<string>> rel){
  // 创建一个数组用于存放已经访问过的节点
  vector<string> visited;
  // 创建一个队列用于存储等待访问的节点
  queue<string> node;
  node.push("you");
  while (!node.empty()){
    bool isVisited = find(visited.begin(),visited.end(),node.front()) != visited.end();
    if (!isVisited){
      // 获得队首节点
      string name = node.front();
      // 弹出队首节点,为下次循环做准备
      node.pop();
      // 判断当前节点是否为目标节点
      if (isSeller(name)){ // 如果是就输出并结束
        cout << name << " is a mango seller" << endl;
        return;
      }
      else{ // 如果不是就将当前节点的子节点(邻居)全部加入队列
        for (auto i : rel[name]){
          node.push(i);
        }
      }
    }
  }
  // 全部节点都查找完成还没有找到的情况
  cout << "no mango seller" << endl;
}
int main(){
  // 构建一个关系图
  map<string,vector<string>> rel;
  rel["you"] = {"bob","alice","claire"};
  rel["bob"] = {"anuj","peggy"};
  rel["alice"] = {"peggy"};
  rel["claire"] = {"thom","jonny"};
  
  bfs(rel);
  
  
  
  return 0;

}