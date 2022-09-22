#include <sstream>

class Elevator {

    private:

        const int maxCap;//maximum capacity of the elevator
        int crntCap;//current persons in the elevator
        const int lwrBound;//first floor of the elevator
        const int upprBound;//last floor of the elevator
        int crntFloor;//current floor
        bool doorState;//door state, open if 1/true, closed if 0/false 

    public:

        Elevator();
        Elevator(const int maxCap, const int lwrBound, const int upprBound);

        int getMaxCap() const;
        int getCrntCap() const;
        int getLwrBound() const;
        int getUpprBound() const;
        int getCrntFloor() const;
        bool getDoorState() const;

        void setDoorState(bool doorState);
        int enterElevator(int count);
        int exitElevator(int count);
        bool changeFloor(int floor);
        std::stringstream stringOutput();

};
