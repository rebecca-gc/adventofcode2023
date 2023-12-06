//Day2
//g++ -std=c++17 -Wall -pedantic -O3 day2.cpp -o two

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void part1(){
    string input;
    int idCounter = 0, current = 1, red = 12, green = 13, blue = 14, rc = 0, gc = 0, bc = 0, rmax = 0, gmax = 0, bmax = 0;
    bool game = true;

    ifstream MyReadFile("input.txt");

    while(getline (MyReadFile, input)){
        for(unsigned i = 0; i < input.size(); i++){
            if(input[i] == 'd'){
                if(input[i-6] == ' ') rc += (input[i-5] - '0')*10 + (input[i-4] - '0');
                else rc += input[i-4] - '0';
            }
            else if(input[i] == 'g'){
                if(input[i-4] == ' ') gc += (input[i-3] - '0')*10 + (input[i-2] - '0');
                else gc += input[i-2] - '0';
            }
            else if(input[i] == 'b'){
                if(input[i-4] == ' ') bc += (input[i-3] - '0')*10 + (input[i-2] - '0');
                else bc += input[i-2] - '0';
            }
            else if(input[i] == ';'){
                if(rc > rmax) rmax = rc;
                if(gc > gmax) gmax = gc;
                if(bc > bmax) bmax = bc;
                if(rmax > red || gmax > green || bmax > blue){
                    game = false;
                    break;
                }
                rc = bc = gc = 0;
            }
        }
        if(game && rc <= red && gc <= green && bc <= blue) idCounter += current;
        current++;
        rc = bc = gc = rmax = gmax = bmax = 0;
        game = true;
    }
    cout << idCounter << endl;
}

void part2(){
    string input;
    int rc = 0, bc = 0, gc = 0, rmax = 0, gmax = 0, bmax = 0, power = 0;

    ifstream MyReadFile("input.txt");

    while(getline (MyReadFile, input)){
        for(unsigned i = 0; i < input.size(); i++){
            if(input[i] == 'd'){
                if(input[i-6] == ' ') rc += (input[i-5] - '0')*10 + (input[i-4] - '0');
                else rc += input[i-4] - '0';
            }
            else if(input[i] == 'g'){
                if(input[i-4] == ' ') gc += (input[i-3] - '0')*10 + (input[i-2] - '0');
                else gc += input[i-2] - '0';
            }
            else if(input[i] == 'b'){
                if(input[i-4] == ' ') bc += (input[i-3] - '0')*10 + (input[i-2] - '0');
                else bc += input[i-2] - '0';
            }
            else if(input[i] == ';'){
                if(rc > rmax) rmax = rc;
                if(gc > gmax) gmax = gc;
                if(bc > bmax) bmax = bc;
                rc = bc = gc = 0;
            }
        }
        if(rc > rmax) rmax = rc;
        if(gc > gmax) gmax = gc;
        if(bc > bmax) bmax = bc;
        power += rmax * gmax * bmax;
        rc = bc = gc = rmax = gmax = bmax = 0;
    }
    cout << power << endl;
}

int main(){
    part1();
    part2();
}
