//Day3
//g++ -std=c++17 -Wall -pedantic -O3 day3.cpp -o three

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void part1(){
    string input, field = "";
    int sum = 0;

    ifstream MyReadFile("input.txt");

    for(unsigned i = 0; i < 142; i++) field += '.';
    while(getline (MyReadFile, input)){
        field += '.';                                       // . . . . .
        field += input;                                     // .       .
        field += '.';                                       // . . . . .
    }
    for(unsigned i = 0; i < 142; i++) field += '.';

    unsigned number = 0, len = 0;
    bool creating = false;
    vector<vector<unsigned>> numbers;
    //find numbers
    for(unsigned i = 142; i < field.size() - 142; i++){
        if(field[i] - '0' >= 0 && field[i] - '0' <= 9){
            creating = true;
            number *= 10;
            number += field[i] - '0';
            len++;
        }
        else if(creating){
            creating = false;
            numbers.push_back({number,i-1,len});
            number = len = 0;
        }
    }
    //um number herum Zeichen entdecken
    for(unsigned i = 0; i < numbers.size(); i++){
        unsigned index = numbers[i][1], length = numbers[i][2];
        vector<unsigned> pos_index = {index+1, index+1+142, index+1-142, index-length, index-length+142, index-length-142};
        for(unsigned j = 0; j < length; j++){
            pos_index.push_back(index-j-142); //oben
            pos_index.push_back(index-j+142); //unten
        }
        for(unsigned j = 0; j < pos_index.size(); j++){
            if(field[pos_index[j]] != '.' && (field[pos_index[j]] - '0' < 0 || field[pos_index[j]] - '0' > 9)){
                sum += numbers[i][0];
                break;
            }
        }
    }

    cout << sum << endl;
}

void part2(){
    string input;
    vector<int> hmm;
    int sum = 0;

    ifstream MyReadFile("input.txt");

    for(unsigned i = 0; i < 142; i++) hmm.push_back('.');
    while(getline (MyReadFile, input)){
        hmm.push_back('.');                                                     // . . . . .
        for(unsigned i = 0; i < input.size(); i++) hmm.push_back(input[i]);     // .       .
        hmm.push_back('.');                                                     // . . . . .
    }
    for(unsigned i = 0; i < 142; i++) hmm.push_back('.'); 

    vector<unsigned> gears;
    for(unsigned i = 142; i < hmm.size() - 142; i++) if(hmm[i] == 42) gears.push_back(i);

    unsigned number_ind = 0, number = 0;
    bool creating = false;
    vector<unsigned> numbers;
    for(unsigned i = 142; i < hmm.size() - 142; i++){
        if(hmm[i] >= 48 && hmm[i] <= 57){
            creating = true;
            number *= 10;
            number += hmm[i] - 48;
            hmm[i] = number_ind + 999;
        }
        else if(creating){
            creating = false;
            numbers.push_back(number);
            number = 0;
            number_ind++;
        }
    }
    //um gear herum numbers entdecken
    for(unsigned i = 0; i < gears.size(); i++){
        unsigned index = gears[i];
        int n1 = -1, n2 = -1;
        bool possible = true;
        vector<unsigned> pos_index = {index+1, index+1+142, index+1-142, index-1, index-1+142, index-1-142, index+142, index-142};
        for(unsigned j = 0; j < pos_index.size(); j++){
            if(hmm[pos_index[j]] > 998){
                if(n1 == -1) n1 = hmm[pos_index[j]];
                else if(n1 == hmm[pos_index[j]]);
                else if(n2 == -1) n2 = hmm[pos_index[j]];
                else if(n2 == hmm[pos_index[j]]);
                else possible = false;
            }
        }
        if(n1 == -1 || n2 == -1) possible = false;
        if(possible) sum += (numbers[n1-999]) * (numbers[n2-999]);
    }

    cout << sum << endl;
}

int main(){
    part1();
    part2();
}
