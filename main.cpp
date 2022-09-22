/**
 * @author Roberts Pičukans
 * @brief A_picukans_03_MD
 * @date 9/21/2022
 */

#include <unistd.h>
#include <iostream>
#include "elevator.hpp"
#include "visualizer.hpp"

using namespace std;

int main() {
  
  Elevator elevator;

  char inputChar;
  int inputInt;
  elevator.setDoorState(false);
  
  while (true) {
    visualizer(elevator.getCrntFloor(), elevator.getLwrBound(), elevator.getUpprBound());
    cout<<endl;
    cout<<elevator.stringOutput().str();
    cout<<endl;
    
    cout<<"press <a> to add persons to elevator"<<endl;
    cout<<"press <r> to remove persons from elevator"<<endl;
    cout<<"press <c> to change floor"<<endl;
    cout<<"press <d> to set door state"<<endl;
    cout<<"press <x> to exit"<<endl;
    cin>>inputChar;
    
    if (inputChar == 'x') {break;}
    
    switch(inputChar) {
      
      case 'a':
        system("clear");
        cout<<"number of persons to enter the elevator => ";
        cin>>inputInt;
        cout<<elevator.enterElevator(inputInt)<<" persons entered the elevator"<<endl;
        if (elevator.getDoorState() == 0) {
          cout<<"\033[1;31mBruh, is the door stuck?\033[0m"<<endl;
          cout.flush();
          usleep(4000000);
        }
        cout.flush();
        usleep(4000000);
        system("clear");
        break;
      
      case 'r':
        system("clear");
        if (elevator.getCrntCap() == 0) {
          cout<<"*crickets*"<<endl;
        }
        cout<<"number of persons to leave the elevator => ";
        cin>>inputInt;
        cout<<elevator.exitElevator(inputInt)<<" persons left the elevator"<<endl;
        cout.flush();
        usleep(4000000);
        system("clear");
        break;
      
      case 'c':
        system("clear");
        cout<<"change floor to => ";
        cin>>inputInt;
        if (elevator.changeFloor(inputInt)) {
          cout<<"\u001b[32mFloor changed to "<<elevator.getCrntFloor()<<"\033[0m";
        } else {
          cout<<"\033[1;31mOOPsie! Invalid input\033[0m"<<endl;
          if (inputInt > elevator.getUpprBound()) {
            cout<<"\u001b[35m*crashing through the roof*\033[0m";
            cout<<"\u001b[35mThat was some Willy Wonka action!\033[0m";
            cout.flush();
            usleep(6000000);
            system("clear");
          }
        }
        cout.flush();
        usleep(4000000);
        system("clear");
        break;
      
      case 'd':
        system("clear");
        cout<<"set door state opened(1) closed(0) => ";
        cin>>inputInt;
        elevator.setDoorState(inputInt);
        break;
    }
  }
}
