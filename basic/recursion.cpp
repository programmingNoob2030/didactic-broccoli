#include <iostream>

using namespace std;

void countdown(int n){
  if (n < 0) return; // 基线条件
  countdown(n - 1);
  cout << n << endl; // 递归条件
}
int factorial(int n){
  if (n == 0) return 1; // 基线条件
  return n * factorial(n - 1); // 递归条件
}
int main(){
  int n;
  cout << "请输入一个数字: ";
  cin >> n;
  countdown(n);
}