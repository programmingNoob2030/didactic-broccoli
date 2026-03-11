// P1706 全排列问题 | AC 2026-03-10
// 关键：将DFS参数x视为递归的“层数”(深度)，而非要填充的值
//      否则顺序会出错，无法保证字典序
// 注意：
//  1-based索引，注意used数组大小和res数组边界
//  dfs(layer+1) 进入下一层，结束后必须重置used[i]和res[layer] (回溯)
// 模板：
//  void dfs(int layer) {
//      if (layer > n) { 打印; return; }
//      for (int i = 1; i <= n; i++) {
//          if (!used[i]) {
//              used[i] = true; res[layer] = i;
//              dfs(layer + 1);
//              used[i] = false; res[layer] = 0; // 回溯
//          }
//      }
//  }
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<bool> used(10, false);
vector<int> res(10, 0);
void dfs(int x){
  if (x > n){
    for (int i = 1; i <= n; i++){
      if (res[i] != 0) printf("%5d",res[i]);
    }
    cout << endl;
  }
  for(int i = 1; i <= n; i++){
    // not visited before
    if (!used[i]){
      // change the used state of the index i of array
      used[i] = true;
      res[x] = i;
      dfs(x + 1);
      used[i] = false;
      res[x] = 0;
    }
  }

}
int main(){
  cin >> n;
  dfs(1);


  return 0;
}