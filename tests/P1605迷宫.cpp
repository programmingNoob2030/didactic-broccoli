// P1605 迷宫 | AC 2026-03-11
// 关键：需要使用一个数组来记录访问过的坐标，否则会出现无限访问的情况
//      每个点访问了四个方向之后需要恢复其可访问性，否则不能遍历全部的可能性    
// 注意：
//  当2D数组可以被展开为1D数组，在某些极端情况下可以提升效率，
//  但操作起来需要数学计算并且易错，一般不用
//  达到终点之后必须马上恢复终点的可访问性，否则影响其他分支结果
//  边界检查一定要在最前面，否则出现可能出现越界问题导致出现运行错误
// 模板：
//
// void dfs(int sx, int sy, int fx, int fy){
//    // 标记当前位置为已访问
//    visited[sx][sy] = 1;
//    // 达到终点：计数并回溯
//    if (sx == fx && sy == fy) {
//        visited[sx][sy] = 0;
//        counter++;
//        return;
//    }
//    for (int i = 0; i < 4; i++){
//        int newX = sx + dx[i];
//        int newY = sy + dy[i];
//        // 核心：边界检查一定要在最前面 (Fail-Fast)
//        if (newX < 1 || newX > n || newY < 1 || newY > m) continue;
//        if (visited[newX][newY] || obstacles[newX][newY]) continue;
//
//        dfs(newX, newY, fx, fy);
//    }
//    // 回溯：重置状态，允许其他路径再次经过该点
//    visited[sx][sy] = 0;
// }
#include <iostream>
#include <vector>
#include <map>
    using namespace std;

int n, m, t;
int counter;
// 4 directions
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<int>> visited(6,vector<int>(6));
vector<vector<int>> obstacles(6,vector<int>(6));
bool meetObstacles(int x, int y){
  return obstacles[x][y] == 1;
}
void dfs(int sx, int sy, int fx, int fy){

  // mark the pos visited
  visited[sx][sy] = 1;
  // arrive at the end
  if (sx == fx && sy == fy) {
    visited[sx][sy] = 0;
    counter++;
    return;
  }
  // go to 4 directions
  for (int i = 0; i < 4; i++){
    int newX = sx + dx[i];
    int newY = sy + dy[i];
    // if out of map
    if (newX < 1 || newY < 1 || newX > n || newY > m) continue;
    // if pos visited
    if (visited[newX][newY]) continue;
    // if meet the obstacles
    if (meetObstacles(newX, newY)) continue;
    dfs(newX, newY, fx, fy);
    // mark the pos not visited;
  }
  visited[sx][sy] = 0;
}
int main(){
  cin >> n >> m >> t;
  int x,y,sx,sy,fx,fy;
  cin >> sx >> sy >> fx >> fy;
  for (int i = 1; i <= t; i++){
    cin >> x >> y;
    obstacles[x][y] = 1;
  }
  dfs(sx, sy, fx, fy);
  cout << counter << endl;
  return 0;
}