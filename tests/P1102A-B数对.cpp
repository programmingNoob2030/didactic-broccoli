// P1102 A-B数对 | AC 2025-12-04/05
// 关键：将 A-B=C 变形为 A = B + C
//          遍历每个元素作为B，在数组中二分查找值等于(B+C)的A
//          存在重复的满足条件的值,排序后计算出最后出现位置和最早
//          出现位置做差求得总共出现次数
// 注意：如何优化时间复杂度
// 模板：
//   lower_bound
//   while(l<=r){
//       if(a[mid]==x) ans=mid, r=mid-1;
//       else if(a[mid]>x) r=mid-1;
//       else l=mid+1;
//   }
//   upper_bound
//   while(l<=r){
//       if(a[mid]==x) ans=mid, l=mid+1;
//       else if(a[mid]>x) r=mid-1;
//       else l=mid+1;
//   }
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll lower_bound(vector<ll>& nums, ll target){
  ll left = 0;
  ll right = nums.size() - 1;
  ll index = 1;
  while(left <= right){
    ll mid = left + (right - left) / 2;
    if (target == nums[mid]){
      index = mid;
      right = mid - 1;
    }
    else if(target < nums[mid]){
      right = mid -1;
    }
    else if(target > nums[mid]){
      left = mid + 1;
    }
  }
  return index;
}
ll upper_bound(vector<ll>& nums, ll target){
  ll left = 0;
  ll right = nums.size() - 1;
  ll index = -1;
  while (left <= right){
    ll mid = left + (right - left) / 2;
    if (target == nums[mid]){
      index = mid;
      left = mid + 1;
    }
    else if (target < nums[mid]){
      right = mid - 1;
    }
    else if (target > nums[mid]){
      left = mid + 1;
    }
  }
  return index;
}
int main(){
  ll n, c;
  cin >> n >> c;
  vector<ll> nums(n);
  for (int i = 0; i < n; i++){
    cin >> nums[i];
  }
  // 保证nums是有序的
  sort(nums.begin(), nums.end());
  // 计数器
  ll counter = 0;
  for (int i = 0; i < n; i++){
    // 题目要求为 C = A - B --> A = B + C
    // 定义target(A)
    ll target = nums[i] + c;

    // 使用lower_bound和upper_bound,分别计算出在排序数组中,重复出现数字的最小边界和最大边界
    ll max_bound = upper_bound(nums, target);
    ll min_bound = lower_bound(nums, target);
    // 只要满足要求的值存在lower_bound和upper_bound一定能够找到
    // 并且能够正常计数,如果不存在,则不能正常计数

    if (max_bound != -1 && min_bound != -1){
      ll repeated_times = max_bound - min_bound + 1;
      counter += repeated_times;
    }
  }
  cout << counter << endl;
  return 0;
}