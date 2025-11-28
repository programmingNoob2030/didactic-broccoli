#include <iostream>
#include <limits>
#include <vector>
#include <string>
using namespace std;
struct Lesson{
  string name;
  double start;
  double end;
};

int main(){

  // 想要尽可能多地在这个教室上课
  // 1、我们首先选择结束时间最早的课程
  // 2、然后选择离这个结束时间最近的课程
  // 3、重复上述步骤，直到没有课程可以选为止
  vector<Lesson> lessons;
  lessons.push_back(Lesson{"美术",9,10});
  lessons.push_back(Lesson{"英语", 9.30, 10.30});
  lessons.push_back(Lesson{"数学", 10, 11});
  lessons.push_back(Lesson{"计算机", 10.30, 11.30});
  lessons.push_back(Lesson{"音乐", 11, 12});

  double min_end = numeric_limits<double>::max();
  string clazz_name = "";
  // 找出最早结束的课程
  for (auto lesson : lessons){
    if (lesson.end < min_end){
      min_end = lesson.end;
      clazz_name = lesson.name;
    }
  }
  cout << "选择:" << clazz_name << endl;
  double min_diff = numeric_limits<double>::max();

  for (auto lesson : lessons){
    if (lesson.name != clazz_name){
      double diff = lesson.start - min_end;
      if(diff < 0) continue;
      else if (min_diff > diff){
        min_diff = diff;
        min_end = lesson.end;
        clazz_name = lesson.name;
      }
      cout << "选择:" << clazz_name << endl;
      min_diff = numeric_limits<double>::max();

    }
  }
  

  return 0;
}