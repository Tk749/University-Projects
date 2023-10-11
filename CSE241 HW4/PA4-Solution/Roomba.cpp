#include <iostream>
#include <string>

#include "Roomba.h"

using namespace std;

namespace PA4{

    Roomba::Roomba():Strength(10){}

    Roomba::Roomba(int newStrength, int newHit)
    :Robot(newStrength,newHit),Strength(newStrength){}

    int Roomba::getDamage(){

        return getDamage_Robot() + getDamage_Robot();
    }

    string Roomba::get_type(){

        return "Roomba";
    }

    void Matches(Roomba& x, Roomba& y){//fighting simulation

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
    

    void Matches(Roomba& x, Robocop& y){//fighting simulation

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
    

    void Matches(Roomba& x, Optimusprime& y){//fighting simulation

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
    

    void Matches(Roomba& x, Bulldozer& y){//fighting simulation

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
