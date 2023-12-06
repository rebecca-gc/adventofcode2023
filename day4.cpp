//Day4
//g++ -std=c++17 -Wall -pedantic -O3 day4.cpp -o four

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void part1(){
    string input;
    int sum = 0, number = 0, counter = 0;
    bool winning = true, creating = false;

    ifstream MyReadFile("test4.txt");

    while(getline (MyReadFile, input)){
        vector<int> winnings, have;
        for(unsigned i = 8; i < input.size(); i++){
            if(input[i] == '|') winning = false;
            else if(input[i] - '0' >= 0 && input[i] - '0' <= 9){
                creating = true;
                number *= 10;
                number += input[i] - '0';
            }
            else if(creating){
                creating = false;
                if(winning) winnings.push_back(number);
                else have.push_back(number);
                number = 0;
            }
        }
        creating = false;
        if(winning) winnings.push_back(number);
        else have.push_back(number);
        number = 0;
        winning = true;
        for(unsigned i = 0; i < have.size(); i++){
            for(unsigned j = 0; j < winnings.size(); j++){
                if(have[i] == winnings[j]){
                    if(counter) counter *= 2;
                    else counter = 1;
                }
            }
        }
        sum += counter;
        counter = 0;
    }

    cout << sum << endl;
}

// int rec_check(unsigned scard){
//     if(scard == accessible.size()) return 0;
//     int counting = 0;
//     for(unsigned i = 0; i < accessible[scard].size(); i++){
//         counting += 1 + rec_check(accessible[scard][i]);
//     }
//     return counting + rec_check(scard+1);
// }

void part2(){
    string input;
    int sum = 0, number = 0, counter = 0, line = 1;
    bool winning = true, creating = false;
    vector<vector<int>> accessible = {{}};
    vector<pair<int,int>> new_cards = {{0,0}}; //how often, how many

    ifstream MyReadFile("input.txt");

    while(getline (MyReadFile, input)){
        vector<int> winnings, have, a = {};
        for(unsigned i = 8; i < input.size(); i++){
            if(input[i] == '|') winning = false;
            else if(input[i] - '0' >= 0 && input[i] - '0' <= 9){
                creating = true;
                number *= 10;
                number += input[i] - '0';
            }
            else if(creating){
                creating = false;
                if(winning) winnings.push_back(number);
                else have.push_back(number);
                number = 0;
            }
        }
        creating = false;
        have.push_back(number);
        number = 0;
        winning = true;

        for(unsigned i = 0; i < have.size(); i++){
            for(unsigned j = 0; j < winnings.size(); j++){
                if(have[i] == winnings[j]) counter++;
            }
        }

        for(unsigned i = 1; i <= counter; i++) a.push_back(line+i);
        new_cards.push_back({1,counter});
        accessible.push_back(a);
        counter = 0;
        line++;
    }

    for(unsigned i = 1; i < accessible.size(); i++){
        for(unsigned j = 0; j < accessible[i].size(); j++){
            new_cards[accessible[i][j]].first += new_cards[i].first;
        }
    }

    for(unsigned i = 1; i < new_cards.size(); i++) sum += new_cards[i].first;
    cout << sum << endl;
}

int main(){
    part1();
    part2();
}
