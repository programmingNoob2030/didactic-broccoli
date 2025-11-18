#include <iostream>
#include <vector>
using namespace std;

// hoare版本
int partition_hoare(vector<int> &nums, int left, int right){
  // 定义基准值 请注意这里的基准值既是分组的依据,也是需要排序的元素之一,
  // 等待分组过程完毕之后其处于正确的位置,无需再对其进行额外的操作
  int pivot = nums[left];
  // 定义左右指针
  int i = left - 1;
  int j = right + 1;
  // 进行夹逼操作
  while (1){
    // 左指针向右边寻找小于等于基准值的元素
    do{i++;} while (pivot > nums[i]);

    // 右指针向左边寻找大于等于基准值的元素
    do{ j--;} while (pivot < nums[j]);

    // 左右指针相遇或交叉,返回分割点并且退出循环
    if (i >= j) return j; // 相遇时返回j，保证[left,j]≤pivot，[j+1,right]≥pivot

    // 若左右指针没有相遇过并且都停止,说明左右指针指向的元素需要交换,否则会陷入死循环
    swap(nums[i], nums[j]);
  }
}

void quick_sort(vector<int> &nums, int left, int right){
  // 递归条件
  if (left < right){
    int pivot = partition_hoare(nums, left, right);
    // 递归操作,进行分治
    quick_sort(nums, left, pivot);
    quick_sort(nums, pivot + 1, right);
  }
  // 当left >= right时,说明已经排序完毕,无需再进行递归操作
}

void quick_sort(vector<int>& nums){
  if (!nums.empty()){
    quick_sort(nums, 0, nums.size() - 1);
  }  
}




int main(){
  // 测试用例
  vector<int> nums(5);
  
  for (int i = 0; i < nums.size(); i++){
    cin >> nums[i];
  }  
  // 快速排序(hoare)
  quick_sort(nums);
  
  // 输出排序结果
  for (int i: nums){
    cout << i << " ";
  }

  return 0;
}