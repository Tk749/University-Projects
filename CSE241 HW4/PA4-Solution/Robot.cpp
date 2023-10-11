#include<iostream>
#include<string> 
#include <cstdlib>
#include"Robot.h"   

using namespace std;

namespace PA4{   // Base class

    Robot::Robot():Strength(10),Hit(10),Initial_Hit(10){

        srand(static_cast<int>(time(NULL)));//for random number
    }

    Robot::Robot(int newStrength, int newHit):Strength(newStrength),Hit(newHit),Initial_Hit(newHit){
        
        srand(static_cast<int>(time(NULL)));//for random number
    }

    int Robot::getDamage_Robot(){ // Returns the damage caused by the robot trait

        int damage;
        
        damage = rand() % Strength + 1;

        return damage;
    }

    void Robot::Restart_Hit(){  // restart hit value

        Hit = Initial_Hit;
    }

    int Robot::gethit(){ // returns hit value

        return Hit;
    }

    int Robot::getStrenght(){ // return strenght value

        return Strength;
    }

    void Robot::Remaining_Hit(int damage){  // remaining hit  after taking damage

        Hit = Hit - damage;
    }
};
