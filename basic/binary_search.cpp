#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> nums, int target){
  int result = -1;
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right){ // 是否只剩下一个元素
    // 为什么需要等于 用于处理找到的情况
    int mid = (left + right) / 2;

    // 大于目标值
    if (nums[mid] > target){
      right = mid - 1;
    }
    // 小于目标值
    else if (nums[mid] < target){
      left = mid + 1;
    }
    // 等于目标值
    else{
      result = mid;
      break;
    }
  }
  return result;
}

int main(){
  vector<int> nums = {1,3,5,7,11,16,19};
  int res = binary_search(nums, 96);
  cout << res << endl;

}