// P2678 跳石头 | AC 2025-12-07/08
// 关键：二分猜最短距离，贪心检查是否可行
//      贪心检查：从当前位置看石头，太近就搬走，够远就跳过去
// 注意：
//  要检查最后到终点的距离(第一块石头直接放进循环中处理即可--因为其上一块石头距离固定为0)
//  这里移除的石头数目和最短距离最大值为正比关系, 所以可以使用二分答案来解答
//  因为是正比关系且是求最大值, 所以当找到答案之后应该继续往右边找, 直到找到最右边的答案
// 模板：最大化可行解(和P2440木材加工类似)
// while(l<=r){
//     mid = l + (r-l)/2;
//     if(check(mid)){   // 可行
//         ans = mid;     // 记录答案
//         l = mid + 1;   // 尝试更大值
//     }else{
//         r = mid - 1;   // 尝试更小值
//     }
// }
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll l, n, m;
ll f(vector<ll> s, ll target){
  ll counter = 0;
  ll last_dist = 0;
  for (int i = 0; i < s.size(); i++){
    // 当前石头满足条件 跳过去
    if (s[i] - last_dist >= target){
      last_dist = s[i];
    }
    // 当前石头不满足条件 丢掉
    else{
      counter++;
    }
  }
  // 特判 最后一个石头
  if (l - last_dist < target){
    counter++;
  }
  return counter;
}
int main(){
  cin >> l >> n >> m;
  ll res = -1;
  vector<ll> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  // 因为M >= N 所以当N为0时,没有任何石头,直接输出L即可
  if (n == 0){
    cout << l << endl;
    return 0;
  }
  ll left = 0;
  ll right = l;
  while (left <= right){
    ll mid = left + (right - left) / 2;
    if (f(s, mid) <= m){
      res = mid;
      left = mid + 1;
    }
    else{
      right = mid - 1;
    }
  }
  if (res == -1)
    cout << 0 << endl;
  else
    cout << res << endl;
  return 0;
}