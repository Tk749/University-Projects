#include <iostream>
#include <string> 

#include "Bulldozer.h"   

using namespace std;

namespace PA4{

    Bulldozer::Bulldozer():Strength(10){}
    
    Bulldozer::Bulldozer(int newStrength, int newHit)
    :Robot(newStrength,newHit),Strength(newStrength){}

    int Bulldozer::getDamage(){  // returns total damage of bulldozer

        return getDamage_Robot();
    }

    string Bulldozer::get_type(){

        return "Bulldozer";
    }

    void Matches(Bulldozer& x, Roomba& y){//fighting simulation

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

    void Matches(Bulldozer& x, Robocop& y){//fighting simulation

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

    void Matches(Bulldozer& x, Optimusprime& y){//fighting simulation

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

    void Matches(Bulldozer& x, Bulldozer& y){//fighting simulation

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
