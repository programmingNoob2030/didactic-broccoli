#include <iostream>
#include <vector>
using namespace std;

// void bubble_sort(vector<int> &nums){
//   for (int i = 0; i < nums.size(); i++){
//     for (int j = i + 1; j < nums.size(); j++){
//       if (nums[i] > nums[j]){
//         int temp = nums[j];
//         nums[j] = nums[i];
//         nums[i] = temp;
//       }
//     }
//   }
//   for (int i : nums){
//     cout << i << " ";
//   }

// }

// 用于查找最小值的索引
int find_min(vector<int> nums){
  int mini = nums[0]; // 默认第一个元素为最小值
  int mini_index = 0; // 默认第一个元素的索引为最小值的索引
  for (int i = 1; i < nums.size(); i++){
    // 如果当前元素小于最小值, 则更新最小值和最小值的索引
    if (nums[i] < mini){
      mini = nums[i];
      mini_index = i;
    }
  }
  return mini_index;
}
void selection_sort(vector<int> nums){
  // 用于存储排序后的元素
    vector<int> sorted;
  // cpp中每次循环都会重新计算nums的长度
  // 并且因为每次都会删除一个元素, 所以需要提前计算长度
    int length = nums.size();
    for (int i = 0; i < length; i++){
      // 获取最小值的索引
      int mini_index = find_min(nums);
      // 将获取到的最小值添加到排序后的数组最后面
      sorted.push_back(nums[mini_index]);
      // 从数组中弹出当前最小值, 防止其被重复选择
      nums.erase(nums.begin() + mini_index); 
    }

    for (int i = 0; i < sorted.size(); i++){
      cout << sorted[i] << " ";
    }
}
int main(){

  vector<int> nums = {1,5,4,6,1};
  selection_sort(nums);
  // bubble_sort(nums);


}