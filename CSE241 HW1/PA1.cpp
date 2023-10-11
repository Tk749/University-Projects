#include <iostream>
#include <cstdlib>
#include <time.h>

int random(int Number[],int n);// generates random a secret number  (n = number of digits of secret number)
int user(int Number[],int n);//gets secret number information from users  (n = number of digits of secret number)
int digitcontrol(int Number[],int n);//checks digits are valid
int NumberOfDigit(int N[],int n);
int find(int secret[],int user[],int n);//compares user number and secret number and prints first count and second count
// first count  --> The count of digits of the proposed number that match in place of the secret number.
// second count --> The count of digits of the proposed number that match in place of the secret number. 

using namespace std;

int main(){
   
    const int Size = 10;
    int iterations=1;   //keeps track of how many attempts were made
    int Secret_number[Size],User[Size];//holds digits
    char ch[2], mastermind[11];
    int n=0;//number of digits of secret number
    bool f = false;
    int flag;
    int userNumber =0;//user secret number

    srand(static_cast<int>( time(NULL)));

    cin >> mastermind;
    cin >> ch;
    cin >> n;

    if(ch[0] == '-' && ch[1] == 'u'){  // user enters a secret number
        
        userNumber = n;
        n = NumberOfDigit(Secret_number,n);
        
    }

    else if(ch[0] == '-' && ch[1] == 'r') { // generates random secret number

        if( 0>n || n >=9 ){
        
            cout << "E0";
            return 0;
        }
        random(Secret_number,n);
    }
    else{

        cout << "E0";
        return 0;
    }
   
    while(f!=1){// if hidden number found break while loop

        flag = user(User,n);

        if(flag == 0) break;

        if(flag ==1 ){ 

        f = find(Secret_number,User,n);
        ++iterations;
        }

        if(iterations == 100){ // fail  

            cout << "FAÝLED" ;
            return 0;
        }
    }
    
    if(flag == true ) cout << "FOUND " << iterations << endl;
}

int random(int Number[],int n){// generates random a secret number  (n = number of digits of secret number)

    bool alpha;

    for(int i = 0;i<n ;){

        alpha = true;

        Number[i] = rand()%10;

        if(Number[i] == 0 && i == 0) Number[i] = rand()%9+1; // if first number is 0 assigns new number

        for(int j=0 ; j<i;++j){// checks that the same number is entered

            if(Number[i] == Number[j]){

                alpha = false;
                break;
            }
        }

        if(alpha) ++i;
    }

    return 1;
}

int user(int Number[],int n){

    int flag;

    flag = digitcontrol(Number,n);
    if(flag == 2) return 2;
    if(flag == 1) return 0;

    if(Number[0] == 0){//if first digit equal to 0 terminate program 

        cout << "E1";
        return 0;
    }

    for(int i = 0; i<n ; ++i){//checks for repeated digits
        for(int j = 0; j<n;++j){

            if(Number[i] == Number[j] && i != j){
                
                cout << "E1" << endl;
                return 0;}
        }
    }

    return 1;
}

int digitcontrol(int Number[],int n){

    const int size =10;

    char number_char[size] = {10,10,10,10,10,10,10,10,10,10};
    
    cin >> number_char;

    for(int i = 0;  ;++i){ //checks if the number is valid or not valid

        if(!(isdigit(number_char[i]))){
                
            cout << "E2" << endl;
            return 2;
        }

        if((int)(number_char[i+1]) == 0)//en of the string
            break;
    }

    if(number_char[n] != 0){// number lenght
            
        cout << "E1" << endl;
        return 1;
    }

    for(int i = 0; i<n;++i){//turns string into int array

        Number[i] = (int)(number_char[i]) -48;
    }

    return 0;
}

int find(int secret[],int user[],int n){

    int count1 = 0;
    int count2 = 0;

    for(int i = 0;i<n;i++){// compares secret number and user input
        for(int j = 0 ; j <n; ++j){

            if( i == j){

                if(secret[i] == user[j]) {
                    
                    ++count1;
                    break;
                }
            }

            else{

                if(secret[i] == user[j]){
                    
                    ++count2;
                    break;
                }
            }
        }
    }

    cout << count1 << "  " << count2 << endl;

    if(count1 == n) return 1;//if the secret number and the user input are equal terminates the program

    return 0;
}

int NumberOfDigit(int N[],int n){// n --> user input value not number of digit

    int n1;//temp int for n
    int numberofdigit=0;
    n1 = n;

    while(n1!= 0){

        n1 = n1/10;
        ++numberofdigit;
    }

    for(int i = 0; i<numberofdigit ; ++i){

        N[numberofdigit-i-1] = n%10;
        n = n / 10; 
    }
    return numberofdigit;
}
