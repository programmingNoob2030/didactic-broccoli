#include <iostream>
#include <map>
using namespace std;
bool find_name(map<string,int> phone_book,string name){
  if (phone_book.find(name) == phone_book.end()){
     cout << "没有找到这个联系人" << endl;
     return false;
  }else return true;
}

int main(){
  map<string,int> phone_book;
  // key
  string name;
  // value
  int number;
  while(1){
    int choice;
    cout << "请输入指令:\n 1)增加 2)查询 3)删除 4)所有联系人 5)退出" << endl;
    cin >> choice;
    if (choice == 1){
      cout << "请输入联系人姓名和电话号码" << endl;
      cin >> name >> number;
      // 因为散列表由散列函数(计算索引)和数组(存储)组成
      // 所以可以通过索引的方式直接赋值,如果不存在会自动创建
      phone_book[name] = number;
      cout << "添加成功" << endl;
    }else if( choice == 2){
      cout << "请输入要查询的联系人姓名" << endl;
      cin >> name;
      // find函数返回的是一个迭代器,如果没有找到返回end()
      bool print = find_name(phone_book,name);
      print == true? cout << name << "的电话号码为:" << phone_book[name] << endl : cout;
    }else if (choice == 3){
      cout << "请输入要删除的联系人姓名" << endl;
      cin >> name;
      phone_book.erase(name);
      bool print = find_name(phone_book, name);
      print == true? cout << "删除成功" << endl : cout;
    }else if(choice == 4){
      if (phone_book.empty()){
        cout << "没有联系人" << endl;
      }else{
        string block = "  "; 
        cout << "联系人" << block << "电话号码" << endl;
        for (auto item :phone_book){
          cout << item.first << block << item.second << endl;
        }
      }
    }else if (choice == 5){
      cout << "退出程序" << endl;
      break;
    }
    cout << endl;
  }

  return 0;
}