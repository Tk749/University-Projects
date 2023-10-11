#include <iostream>
#include <string> 

#include "Humanic.h"
#include "Optimusprime.h"


using namespace std;

namespace PA4{


    Optimusprime::Optimusprime():Strength(10){}

    Optimusprime::Optimusprime(int newStrength, int newHit)
    :Humanic(newStrength,newHit),Strength(newStrength){}

    int Optimusprime::getDamage(){

        int chance = rand() % 15;

        if(chance == 0 || chance == 1 || chance == 2){

            return 2 * getDamage_Robot() +getDamage_Humanic();
        }
        else{

            return  getDamage_Robot() +getDamage_Humanic();
        }
    }

    string Optimusprime::get_type(){

        return "Optimusprime";
    }

    void Matches(Optimusprime& x, Roomba& y){//fighting simulation

        int n = 0;

        while(1){
            y.Remaining_Hit(x.getDamage());

            if(y.gethit() <= 0 ){
                
                x.Restart_Hit();
                y.Restart_Hit();

                cout << "---" << x.get_type() << "(" << x.getStrenght() << "," << x.gethit() << ")" <<" WİN---" << endl << endl;
                break;
            }

            x.Remaining_Hit(y.getDamage());

            if(x.gethit() <= 0 ){
                
            y.Restart_Hit();
            x.Restart_Hit();

            cout << "---" << y.get_type() << "(" << y.getStrenght() << "," << y.gethit() << ")" <<" WİN---" << endl ;
            break;
            }

            
            cout << "*****   Tour  " << ++n << "   *****" << endl;       //for every tour
            cout <<x.get_type() <<" Hit = " << x.gethit() << endl;       //for every tour
            cout <<y.get_type() <<" Hit = " << y.gethit() << endl <<endl;//for every tour
            

        }
    }

    void Matches(Optimusprime& x, Robocop& y){//fighting simulation

        int n = 0;

        while(1){
            y.Remaining_Hit(x.getDamage());

            if(y.gethit() <= 0 ){
                
                x.Restart_Hit();
                y.Restart_Hit();

                cout << "---" << x.get_type() << "(" << x.getStrenght() << "," << x.gethit() << ")" <<" WİN---" << endl << endl;
                break;
            }

            x.Remaining_Hit(y.getDamage());

            if(x.gethit() <= 0 ){
                
            y.Restart_Hit();
            x.Restart_Hit();

            cout << "---" << y.get_type() << "(" << y.getStrenght() << "," << y.gethit() << ")" <<" WİN---" << endl ;
            break;
            }

            
            cout << "*****   Tour  " << ++n << "   *****" << endl;       //for every tour
            cout <<x.get_type() <<" Hit = " << x.gethit() << endl;       //for every tour
            cout <<y.get_type() <<" Hit = " << y.gethit() << endl <<endl;//for every tour
            

        }
    }

    void Matches(Optimusprime& x, Optimusprime& y){//fighting simulation

        int n = 0;

        while(1){
            y.Remaining_Hit(x.getDamage());

            if(y.gethit() <= 0 ){
                
                x.Restart_Hit();
                y.Restart_Hit();

                cout << "---" << x.get_type() << "(" << x.getStrenght() << "," << x.gethit() << ")" <<" WİN---" << endl << endl;
                break;
            }

            x.Remaining_Hit(y.getDamage());

            if(x.gethit() <= 0 ){
                
            y.Restart_Hit();
            x.Restart_Hit();

            cout << "---" << y.get_type() << "(" << y.getStrenght() << "," << y.gethit() << ")" <<" WİN---" << endl ;
            break;
            }

            
            cout << "*****   Tour  " << ++n << "   *****" << endl;       //for every tour
            cout <<x.get_type() <<" Hit = " << x.gethit() << endl;       //for every tour
            cout <<y.get_type() <<" Hit = " << y.gethit() << endl <<endl;//for every tour
            

        }
    }

    void Matches(Optimusprime& x, Bulldozer& y){//fighting simulation

        int n = 0;

        while(1){
            y.Remaining_Hit(x.getDamage());

            if(y.gethit() <= 0 ){
                
                x.Restart_Hit();
                y.Restart_Hit();

                cout << "---" << x.get_type() << "(" << x.getStrenght() << "," << x.gethit() << ")" <<" WİN---" << endl << endl;
                break;
            }

            x.Remaining_Hit(y.getDamage());

            if(x.gethit() <= 0 ){
                
            y.Restart_Hit();
            x.Restart_Hit();

            cout << "---" << y.get_type() << "(" << y.getStrenght() << "," << y.gethit() << ")" <<" WİN---" << endl ;
            break;
            }

            
            cout << "*****   Tour  " << ++n << "   *****" << endl;       //for every tour
            cout <<x.get_type() <<" Hit = " << x.gethit() << endl;       //for every tour
            cout <<y.get_type() <<" Hit = " << y.gethit() << endl <<endl;//for every tour
            

        }
    }

};