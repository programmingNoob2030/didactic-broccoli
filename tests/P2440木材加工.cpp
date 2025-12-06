// P2240 木材加工 | AC 2025-12-06
// 关键：二分答案(找出木材长度和段数之间的单调关系--单调减,找出"check"函数)
// 注意：特判k=1的情况，无法切出k段时输出0
// 模板：最大化可行解
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
#include <limits>
#include <algorithm>
using namespace std;
typedef long long ll;
ll f(vector<ll> nums, ll sum){
  ll counter = 0;
  for (int i = 0; i < nums.size(); i++){
    while(nums[i] >= sum){
      nums[i] -= sum;
      counter++;
    }
  }
  return counter;
}
int main(){
  ll max_num = -1;
  ll n, k;
  cin >> n >> k;
  ll l = 0;
  vector<ll> nums(n);
  for (int i = 0; i < n; i++){
    cin >> nums[i];
  }
  for (ll i : nums){
    max_num = max(max_num, i);
  }
  if (k == 1){
    cout << max_num << endl;
    return 0;
  }
  ll left = 1;
  ll right = max_num;
  ll res = numeric_limits<int>::min();
  while(left <= right){
    ll mid = left + (right - left) / 2;
    if(f(nums, mid) >= k){
      res = max(res, mid);
      left = mid + 1;
    }else{
      right = mid - 1;
    }
  }
  res == numeric_limits<int>::min() ? cout << 0 << endl : cout << res << endl;
  return 0;
}
