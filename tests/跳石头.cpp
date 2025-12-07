// P2678 跳石头 | 未AC 2025-12-07
// 关键：二分猜最短距离，贪心检查是否可行
// 注意：
//  贪心检查：从当前位置看石头，太近就搬走，够远就跳过去
//  要检查最后到终点的距离
//  二分边界 left=1, right=L
// 目前的问题:
// 贪心策略不够好, 不满足题目的要求, 导致二分答案时出现错误
// 准备明天再大改一下
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll l, n, m;
ll f(vector<ll> s, ll target){
  ll counter = 0;
  ll r = 0;
  for (int i = 0; i < s.size(); i++){
    if (i == 0) {
      if (s[i] >= target) {
        counter++;
      }
    }
    else if (i == s.size() - 1){
      if (l - s[i] < target){
        counter++;
      }
    }
    else{
      if (s[i] - s[r] < target){
        while(s[i] - s[r] < target && r < s.size()){
          r++;
          counter++;
        }
      }
    }
  }
}
int main(){
  cin >> l >> n >> m;
  vector<ll> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  cout << f(s, 4) << endl;
  return 0;
}