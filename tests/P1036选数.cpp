// P1036 选数 | AC 2026-03-10
// 关键：组合问题 (Combination), 不同于全排列
//      DFS参数：index=当前遍历起点, sum=当前累计和, cnt=已选个数
// 注意：
//  1-based索引
//  进入下次递归的是循环的索引i + 1(确保每次只向后搜索，不回头)
//  而非index+1(这是一个固定值)没有办法达到组合效果
//  素数判定：i*i <= x 优于 sqrt(x)
// 模板：
//  void dfs(int index, int sum, int cnt) {
//      if (cnt == k) { if(isPrime(sum)) res++; return; }
//      for (int i = index; i <= n; i++) {
//          dfs(i + 1, sum + nums[i], cnt + 1);
//      }
//  }

#include <iostream>
#include <vector>
using namespace std;
int n, k, res;
vector<int> nums(21, 0);
// be careful with the "2"
// mutiply is better than sqrt()
bool isPrime(int x){
  if (x < 2) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (int i = 3; i * i <= x; i += 2){
    if (x % i == 0) return false;
  }
  return true;
}
void dfs(int index,int sum, int cnt){
  // all addition are placed, calculate and compare the result.
  if (cnt == k){
    if (isPrime(sum)) res++;
    return;
  }
  // all the numbers cannot be chosen more than once.
  // so next function starts with its next one.
  for (int i = index; i <= n; i++){
    dfs(i + 1, sum + nums[i], cnt + 1);
  }
}
int main(){
  cin >> n >> k;
  for (int i = 1; i <= n; i++){
    cin >> nums[i];
  }
  dfs(1, 0, 0);
  cout << res << endl;
  return 0;
}