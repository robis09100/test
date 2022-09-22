#include <iostream>
#include <string>

using namespace std;

void visualizer(int crntFloor, int frstFloor, int lstFloor) {

  int tmp;
  
  for (int i = frstFloor; i <= lstFloor; i++) {
      tmp = to_string(i).length();
      if (i == crntFloor) {
        for (int j = 0; j < tmp; j++) {
          cout << "\033[1;31m_\033[0m";
        }
      } else {
        for (int j = 0; j < tmp; j++) {
          cout<<" ";
        }
      }
      cout<<" ";
      
  }

  cout<<endl;
  
  for (int i = frstFloor; i <= lstFloor; i++) {
    if (i == crntFloor) {
      cout << "\033[1;31m"<<i<<"\033[0m ";
    } else {
      cout<<i<<" ";
    }
  }

  cout<<endl;
}
