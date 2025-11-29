#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
  // /*背包*/
  // // 商品数组
  // vector<pair<int, int>> items = {
  //     {1500, 1},
  //     {3000, 4},
  //     {2000, 3}};
  // int goods = items.size();
  // int capacity = 4;
  // // dp数组 表示容量为j时选择前i个商品的总价值
  // vector<vector<int>> dp(goods + 1, vector<int>(capacity + 1, 0));

  // for (int i = 1; i <= goods; i++){
  //   // 商品的价值
  //   int value = items[i - 1].first;
  //   // 商品的重量
  //   int weight = items[i - 1].second;

  //   for (int j = 1; j <= capacity; j++){
  //     // 第i个商品可以被选择,计算自己的价值和剩下的价值是否超过之前记录的最大值
  //     if (weight <= j){
  //       // 注意这里的应该为i - 1因为是在已经选择的物品中去选择
  //       dp[i][j] = max(dp[i - 1][j - weight] + value, dp[i - 1][j]);
  //     }
  //     // 第i个商品不能被选择,继承前面选出的最大值
  //     else{
  //       dp[i][j] = dp[i - 1][j];
  //     }
  //   }
  // }
  // cout << "最大价值为:" << dp[goods][capacity] << endl;

  
  return 0;
}