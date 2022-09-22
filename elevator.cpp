#include "elevator.hpp"
#include <sstream>

using namespace std;

//@brief default constructor
Elevator::Elevator()
    : maxCap(8), lwrBound(1), upprBound(10), crntCap(0), crntFloor(1),
      doorState(false) {}
//@brief initialization constructor
Elevator::Elevator(const int maxCap, const int lwrBound, const int upprBound)
    : maxCap(maxCap), lwrBound(lwrBound), upprBound(upprBound), crntCap(0),
      crntFloor(1), doorState(false) {}

//@ brief returns total person capacity
int Elevator::getMaxCap() const { return maxCap; }
//@ brief returns number of persons current in the elevator
int Elevator::getCrntCap() const { return crntCap; }
//@ brief returns lowest floor of the elevator
int Elevator::getLwrBound() const { return lwrBound; }
//@ brief returns highest floor of the elevator
int Elevator::getUpprBound() const { return upprBound; }
//@ brief returns current floor of the elevator
int Elevator::getCrntFloor() const { return crntFloor; }
//@ brief returns 0 if the door is closed, 1 if the door is open
bool Elevator::getDoorState() const { return doorState; }

//@ brief sets door to open (1/true) or closed (0/false)
void Elevator::setDoorState(bool doorState) { this->doorState = doorState; }
//@ brief adds persons to crntCap (current persons in the elevator) and returns
//how many persons have succesfully entered
int Elevator::enterElevator(int count) {
  int entered;
  if (doorState == true) {
    if (crntCap + count > maxCap) {
      entered = maxCap - crntCap;
      crntCap = maxCap;
      return entered;
    } else {
      crntCap += count;
      return count;
    }
  }
  return 0;
}
//@ brief removes persons from crntCap (current persons in the elevator) and
//returns how many persons have succesfully exited
int Elevator::exitElevator(int count) {
  int exited;
  if (doorState == true) {
    if (crntCap - count <= 0) {
      exited = crntCap;
      crntCap = 0;
      return exited;
    } else {
      crntCap -= count;
      return count;
    }
  }
  return 0;
}
//@brief changes floor of the elevator, returns true if succesfull, false if
//failed
bool Elevator::changeFloor(int floor) {
  doorState = false;
  if (floor >= lwrBound && floor <= upprBound) {
    crntFloor = floor;
    return true;
  } else
    return false;
}

//@brief returns stringstream object of the information about Elevator object
stringstream Elevator::stringOutput() {
  stringstream ss;
  ss << "Persons in elevator: " << crntCap << '\n';
  ss << "Floor: " << crntFloor << '\n';
  ss << "Door: " << doorState << '\n';
  ss << "Capacity: " << maxCap << '\n';
  return ss;
};
