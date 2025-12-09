// P1182 数组分段SectionII | AC 2025-12-09
// 关键：二分猜最短距离，贪心检查是否可行
//      贪心检查：检测某元素能否放入到某段中,如果不可以就将这个元素作为新段的第一个元素
// 注意：
//  二分的left和right不是随便设置的:需要根据理论的最小值和最大值来设置(否则会出现漏解或错解[最开始left设置为0,WA了])
//  这里需要分的段数和最大值是成反比的,所以可以使用二分答案来解答
// 模板：最小化可行解
// while(l<=r){
//     mid = l + (r-l)/2;
//     if(check(mid)){   // 可行
//         ans = mid;     // 记录答案
//         r = mid - 1;   // 尝试更小值
//     }else{
//         l = mid + 1;   // 尝试更大值
//     }
// }
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m;
ll f(const vector<ll> &nums, ll m){
  ll cnt = 0; // 计数器
  ll sum = 0; // 每段和
  for (int i = 0; i < n; i++){
    if (sum + nums[i] <= m){
      sum += nums[i];
    }
    else{
      sum = nums[i]; // 重置sum为当前元素,代表一段分组已经完成
      cnt++;
    }
    if (i == n - 1) cnt++; // 特殊处理最后一段
  }
  return cnt;
}
int main(){
  cin >> n >> m;
  vector<ll> nums(n);
  ll max_n = -1;
  for (int i = 0; i < n; i++){
    cin >> nums[i];
    if(max_n < nums[i]) max_n = nums[i];
  }
  if (n == m){
    cout << max_n << endl;
    return 0;
  }
  ll left = max_n;
  ll right = 1e9;
  ll res = -1;
  while(left <= right){
    ll mid = left + (right - left) / 2;
    if (f(nums, mid) <= m){
      right = mid - 1;
      res = mid;
    }else{
      left = mid + 1;
    }
  }
  cout << res << endl;
  return 0;
}