// P1101 单词方阵 | AC 2026-03-13
// 关键：因为是在八个方向中确定一个方向搜索，所以需要锁定搜索方向 (dir)；
//       通过返回 bool 值作为“触发信号”，只有路径匹配成功才回溯标记坐标。
// 注意：
//  1. 必须实现“默认返回”原则（Final Fall-through），防止运行时错误 (RE)；
//  2. 搜索时需检查 index+1，防止越界并确保匹配；
//  3. 与迷宫不同，此处仅在匹配成功时保留 visited 标记。
// 模板：
//
// bool dfs(int x, int y, int dir, int index){
//     // 标记当前位置
//     visited[x][y] = true;
//     // 达到终点
//     if (index == 6) return true;
//
//     int newX = x + dx[dir];
//     int newY = y + dy[dir];
//
//     // 核心：边界检查一定要在最前面 (Fail-Fast)
//     if (newX < 1 || newX > n || newY < 1 || newY > n || g[newX][newY] != target[index + 1]) {
//         visited[x][y] = false; // 回溯：不匹配则撤销
//         return false;
//     }
//
//     // 递归：后续路径通则返回 true，否则回溯
//     if (dfs(newX, newY, dir, index + 1)) return true;
//     else {
//         visited[x][y] = false; // 回溯：撤销标记
//         return false;
//     }
// }
// P1101 单词方阵 | 干净的重构版本
#include <iostream>
#include <vector>
using namespace std;

int n;
char g[105][105];
bool visited[105][105];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
char target[] = "yizhong";

// 递归：尝试沿 dir 方向搜索，仅当路径匹配时才返回 true
bool dfs(int x, int y, int dir, int index){
  // 1. 成功到达终点 (index 6 对应 'g')
  if (index == 6){
    visited[x][y] = true;
    return true;
  }

  // 2. 边界与字符匹配检查 (Fail-Fast)
  int nx = x + dx[dir];
  int ny = y + dy[dir];
  if (nx < 1 || nx > n || ny < 1 || ny > n || g[nx][ny] != target[index + 1]){
    return false;
  }

  // 3. 递归：如果后续路径可行，则标记当前点并向上返回
  if (dfs(nx, ny, dir, index + 1)){
    visited[x][y] = true;
    return true;
  }

  return false; // 最终 Fall-through
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> g[i][j];

  // 遍历每一个可能的起点 'y'
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if (g[i][j] == 'y'){
        for (int k = 0; k < 8; k++){
          // 如果从这个方向找到了，就把起点也标上
          if (dfs(i, j, k, 0))
            visited[i][j] = true;
        }
      }
    }
  }

  // 输出结果
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      cout << (visited[i][j] ? g[i][j] : '*');
    }
    cout << '\n';
  }
  return 0;
}