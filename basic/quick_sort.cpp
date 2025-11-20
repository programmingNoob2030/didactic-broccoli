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
    // 左指针向右边寻找大于等于基准值的元素
    do{i++;} while (pivot > nums[i]);

    // 右指针向左边寻找小于等于基准值的元素
    do{ j--;} while (pivot < nums[j]);

    // 左右指针相遇或交叉,返回分割点并且退出循环
    if (i >= j) return j; // 相遇时返回j，保证[left,j]≤pivot，[j+1,right]≥pivot

    // 若左右指针没有相遇过并且都停止,说明左右指针指向的元素需要交换,否则会陷入死循环
    swap(nums[i], nums[j]);
  }
}
// Lomuto分区法
int partition_lomuto(vector<int> &nums, int left, int right){
  // 核心思想 将数组根据基准值分为三部分
  // 小于等于基准值的值 待排序的值 大于等于基准值的值
  // left i          i+1 j    j+1 right

  int i = left - 1;
  // 选择数组中的最后一个值作为基准值
  int pivot = nums[right];
  for (int j = left; j < right; j++)
  {
    if (nums[j] <= pivot)
    {
      i++;
      // 交换,如果没有遇到比基准值大的值则交换自身
      // 因为 i 总是和 j 相等的,
      // 若遇上了不符合要求的值导致了i j不相等
      // 那么等到再次匹配到符合条件的值时,交换索引i和j的值
      // 使得比基准值小的数位于基准值的左边
      // 比基准值大的数位于基准值的右边
      swap(nums[j], nums[i]);
    }
  }
  // 循环完成之后,在i+1的位置
  // 左边的全部都是小于基准值的元素
  // 右边的全部都是大于基准值的元素
  // 此时我们交换i + 1位置的元素和最右边的元素(基准值)
  // 并且返回基准值所在的位置(分割点)
  swap(nums[i + 1], nums[right]);
  return i + 1;
}

void quick_sort(vector<int> &nums, int left, int right, bool hoare){
  if (left < right){
    int pi;
    if (hoare){
      // 分区，得到分界点
      pi = partition_hoare(nums, left, right);
      // 递归排序左右两部分
      quick_sort(nums, left, pi, true);// 注意：这里包含分界点(hoare分区)
      quick_sort(nums, pi + 1, right, true);
    }else{
      pi = partition_lomuto(nums, left, right);
      quick_sort(nums, left, pi - 1, false); // 这里不包含分界点(lomuto分区)
      quick_sort(nums, pi + 1, right, false);
    }
  }
}
void quick_sort(vector<int> &nums, bool hoare){
    if (!nums.empty()){
      quick_sort(nums, 0, nums.size() - 1, hoare);
    }
}


int main(){

  int n;
  cin >> n;
  // 测试用例
  vector<int> nums(n);
  
  for (int i = 0; i < nums.size(); i++){
    cin >> nums[i];
  }  
  // 快速排序(hoare)
  // quick_sort(nums,true);
  // 快速排序(lomuto)
  quick_sort(nums,false);
  
  // 输出排序结果
  for (int i: nums){
    cout << i << " ";
  }

  return 0;
}