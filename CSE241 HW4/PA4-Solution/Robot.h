#ifndef ROBOT_H
#define ROBOT_H

using namespace std;

namespace PA4{

    class Robot  // Base class
    {
    public:
        Robot();
        Robot(int newStrength, int newHit);

        int getDamage_Robot();// Returns the damage caused by the robot trait
        int gethit();  // returns hit value
        int getStrenght(); // return Strenght value
        
        void Remaining_Hit(int damage);// remaining hit  after taking damage
        void Restart_Hit(); // restart hit value

    private:
    
        int Strength;
        int Hit;
        int Initial_Hit;
    };
    


};

#endif