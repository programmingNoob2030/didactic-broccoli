// P2249 查找 | AC 2025-12-03
// 关键：找第一次出现 => 找到后right=mid-1继续左搜
// 注意：1-based索引，数组已有序别排序
// 模板：
//   while(l<=r){
//       if(a[mid]==x) ans=mid, r=mid-1;
//       else if(a[mid]>x) r=mid-1;
//       else l=mid+1;
//   }
//   return ans==-1 ? -1 : ans+1;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
int binary_search(vector<int> &a, int target){
  int ans = -1;
  int left = 0;
  int right = a.size() - 1;
  while (left <= right){
    int mid = left + (right - left) / 2; // 防止溢出
    if (a[mid] == target){
      // 因为是找第一次出现的,所以不论后面怎么找到的
      // 都需要继续往左边搜索
      ans = mid; // 记录一个找到的目标值的位置
      right = mid - 1; // 继续往左边搜索
    }else if (a[mid] > target){
      right = mid - 1; // 如果目标值小于中间值，则在左半部分继续查找
    }else if (a[mid] < target){
      left = mid + 1; // 如果目标值大于中间值，则在右半部分继续查找
    }
  }
  // 搜索完毕之后根据情况返回值
  if (ans == -1){
    return -1;
  }
  // 如果找到了那么就返回其位置(因为题目要求从0开始找,所以返回值需要+1)
  return ans + 1;
}
int main(){
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }
  // 首先确保数组a有序(题目已经说明了a是有序的数组)
  // sort(a.begin(),a.end());
  // 依此查找每一个目标
  for (int i = 0; i < m; i++){
    int index = binary_search(a, b[i]);
    cout << index << " "; // 输出找到的结果
    // 注意题目是从1开始计数的，所以输出时需要+1
  }
  return 0;
}