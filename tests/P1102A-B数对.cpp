// P1102 A-B数对 | 调试中 2024-12-04
// 我的思路：将 A-B=C 变形为 A = B + C
//          遍历每个元素作为B，在数组中二分查找值等于(B+C)的A
// 当前调试：统计逻辑的边界条件处理
// 明日目标：确保重复元素被正确计数，尝试双指针优化
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll counter = 0;
int binary_search(vector<ll> &nums, ll target){
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right){
    int mid = left + (right - left) / 2; // 防止溢出
    // 找到了直接返回找到了一个
    if (nums[mid] == target){
      // 看看前面和后面还有没有没有找到的
      counter++;
      return mid;
    }
    else if (nums[mid] > target){
      right = mid - 1; // 中间值大于目标值,继续往左边查
    }
    else if (nums[mid] < target){
      left = mid + 1; // 中间值小于目标值,继续往右边查
    }
  }
  return -1;
}
int main(){
  // 计数器
  ll n, c;
  cin >> n >> c;
  vector<ll> nums(n);
  for (int i = 0; i < n; i++){
    cin >> nums[i];
  }
  // 保证nums是有序的
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n; i++){
    // 题目要求为 C = A - B --> A = B + C
    // 定义target(A)
    ll target = nums[i] + c;
    // 二分查找
    int index = binary_search(nums, target);
    if (index != -1){
      int left = index;
      int right = index;
      while (1){
        if (left < 0 || nums[left] != nums[index])
          break;
        if (right > n - 1 || nums[right] != nums[index])
          break;
        if (nums[left] == nums[index]){
          left--;
          counter++;
        }
        if (nums[right] == nums[index]){
          right++;
          counter++;
        }
      }
    }
  }
  cout << counter << endl;
  return 0;
}