//Day5
//g++ -std=c++17 -Wall -pedantic -O3 day5.cpp -o five

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "aoc.h"

using namespace std;

void part1(){
    string input;
    long long number = 0, counter = 0, min_loc;
    bool creating;
    vector<long long> seeds, current_map;
    vector<vector<long long>> mappings;

    ifstream MyReadFile("input.txt");

    while(getline (MyReadFile, input)){
        for(unsigned i = 0; i < input.size(); i++){
            if(input[i] == ':'){
                if(counter > 1) mappings.push_back(current_map);
                else seeds = current_map;
                counter++;
                current_map = {};
            }
            else if(isDigit(input[i])){
                creating = true;
                number *= 10;
                number += cti(input[i]);
                if(i+1 == input.size()){
                    creating = false;
                    current_map.push_back(number);
                    number = 0;
                }
            }
            else if(creating){
                creating = false;
                current_map.push_back(number);
                number = 0;
            }
        }
    }
    mappings.push_back(current_map);

    //destination range start, source range start, the range length.
    int distance;
    for(unsigned i = 0; i < seeds.size(); i++){
        number = seeds[i];
        for(unsigned j = 0; j < mappings.size(); j++){
            for(unsigned k = 1; k < mappings[j].size(); k += 3){
                if(number >= mappings[j][k] && number < mappings[j][k] + mappings[j][k+1]){
                    distance = mappings[j][k] - number;
                    number = mappings[j][k-1] - distance;
                    break;
                }
            }
        }
        if(!i) min_loc = number;
        else min_loc = min(min_loc, number);
    }

    cout << min_loc << endl;
}

void part2(){
    string input;
    long long number = 0, counter = 0, min_loc;
    bool creating;
    vector<long long> seeds, current_map;
    vector<vector<long long>> mappings;

    ifstream MyReadFile("input.txt");

    while(getline (MyReadFile, input)){
        for(unsigned i = 0; i < input.size(); i++){
            if(input[i] == ':'){
                if(counter > 1) mappings.push_back(current_map);
                else seeds = current_map;
                counter++;
                current_map = {};
            }
            else if(isDigit(input[i])){
                creating = true;
                number *= 10;
                number += cti(input[i]);
                if(i+1 == input.size()){
                    creating = false;
                    current_map.push_back(number);
                    number = 0;
                }
            }
            else if(creating){
                creating = false;
                current_map.push_back(number);
                number = 0;
            }
        }
    }
    mappings.push_back(current_map);

    //destination range start, source range start, the range length.
    int distance;
    for(unsigned i = 0; i < seeds.size(); i += 2){
        for(unsigned l = 0; l < seeds[i+1]; l++){
            number = seeds[i] + l;
            for(unsigned j = 0; j < mappings.size(); j++){
                for(unsigned k = 1; k < mappings[j].size(); k += 3){
                    if(number >= mappings[j][k] && number < mappings[j][k] + mappings[j][k+1]){
                        distance = mappings[j][k] - number;
                        number = mappings[j][k-1] - distance;
                        break;
                    }
                }
            }
            if(!i) min_loc = number;
            else min_loc = min(min_loc, number);
        }
    }

    cout << min_loc << endl;
}

int main(){
    part1();
    //part2();
}
