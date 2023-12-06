//Day6
//g++ -std=c++17 -Wall -pedantic -O3 day6.cpp -o six

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "aoc.h"

using namespace std;

void part1(){
    string input;
    int sum = 1, ways = 0;
    vector<long long> time = {56, 71, 79, 99}, distance = {334, 1135, 1350, 2430};

    for(unsigned i = 0; i < time.size(); i++){
        for(unsigned j = 0; j < time[i]; j++){
            if((time[i] - j) * j > distance[i]) ways++;
        }
        sum *= ways;
        ways = 0;
    }

    cout << sum << endl;
}

void part2(){
    string input;
    int ways = 0;
    long long time = 56717999, distance = 334113513502430;

    for(unsigned i = 0; i < time; i++){
        if((time - i) * i > distance) ways++;
    }

    cout << ways << endl;  
}

int main(){
    part1();
    part2();
}
