//Some usefull functions for aoc
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int cti(char c){
    return c - '0';
}

bool isDigit(char c){
    return c - '0' >= 0 && c - '0' <= 9;
}

template <typename E>
void printVec(vector<E>& vec){
    cout << "{ ";
    for(unsigned i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    cout << "}  :)\n";
}

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int min(int a, int b){
    if(a < b) return a;
    else return b;
}

int vecSum(vector<int>& vec){
    int sum = 0;
    for(unsigned i = 0; i < vec.size(); i++) sum += vec[i];
    return sum;
}
