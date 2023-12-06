//Day1
//g++ -std=c++17 -Wall -pedantic -O3 day1.cpp -o one

#include <iostream>
#include <fstream>
#include <string>

#include "aufgabe1.h"

using namespace std;

void Horspool::setPattern(const std::string& pat){
    pattern = pat;
    lookUpTable = {};
    for(int i = pattern.size() - 2; i >= 0; i--){
        if(!checkIf(lookUpTable, pattern[i]).first){
            pair<char, int> neu; neu.first = pattern[i]; neu.second = pattern.size() - 1 - i;
            lookUpTable.push_back(neu);
            if(pattern[i] == '?') break;
        }
    }
};

pair<bool, int> Horspool::checkIf(vector<pair<char, int> > table, char search) const{
    for(unsigned i = 0; i < table.size(); i++){
        if(table[i].first == search){
            pair<bool, int> p; p.first = true; p.second = table[i].second;
            return p;
        }
    }
    pair<bool, int> p; p.first = false; p.second = pattern.size();
    return p;
};

const std::string& Horspool::getPattern() const{
    return pattern;
};

uint32_t Horspool::getShift_(const char last_char) const{
    return checkIf(lookUpTable, last_char).second;
};

std::vector<size_t> Horspool::getHits(const std::string& text) const{
    vector<size_t> hits;
    //exception catch: text or pattern empty
    if(!text.size() || !pattern.size()) return hits;

    const int lastCharIndex = pattern.size() - 1;
    const char lastChar = pattern[lastCharIndex];
    long long unsigned indexCounter = lastCharIndex;

    while(indexCounter <= text.size()-1){
        //alignment matched on lastChar, Wildcard included
        if(text[indexCounter] == lastChar || lastChar == '?' || text[indexCounter] == '?'){
            long long unsigned count = 1;
            //counts every match of current alignment
            for(long long unsigned i = 1; i < pattern.size(); i++){
                if(text[indexCounter - i] != pattern[lastCharIndex - i]){
                    if(pattern[lastCharIndex - i] != '?' && text[indexCounter - i] != '?'){
                        break;
                    }
                }
                count++;
            }
            if(count == pattern.size()){
                hits.push_back(indexCounter - pattern.size() + 1);
            }
        }
        //Shift:
        //char not in lookUpTable, so safe shift distance = '?' shift distance
        alignCheck_(indexCounter-lastCharIndex);
        if(!checkIf(lookUpTable, text[indexCounter]).first) indexCounter += getShift_('?');
        else indexCounter += getShift_(text[indexCounter]);
    }
    return hits;
};

void part1(){
    string input;
    int current = 0, sum = 0, line = 1;
    bool found = false;

    ifstream MyReadFile("test1.txt");

    while(getline (MyReadFile, input)){
        for(unsigned i = 0; i < input.size(); i++){
            int lol = int(input[i]) - 48;
            if(lol > 0 && lol < 10){
                current += lol;
                break;
            }
        }
        for(unsigned i = input.size() - 1; i > 0; i--){
            int lol = int(input[i]) - 48;
            if(lol > 0 && lol < 10){
                found = true;
                current *= 10;
                current += lol;
                break;
            }
        }
        int lol = int(input[0]) - 48;
        if(lol > 0 && lol < 10 && !found) current *= 11;
        sum += current;
        cout << line++ << " " << current << endl;
        current = 0;
        found = false;
    }
    cout << sum << endl;
}

void part2(){
    string input;
    int current = 0, sum = 0, line = 1;
    vector<string> digits = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    
    Horspool h;

    ifstream MyReadFile("input1.txt");

    while(getline (MyReadFile, input)){
        vector<unsigned> pos_index;
        vector<int> what;
        
        for(unsigned i = 1; i < digits.size(); i++){
            h.setPattern(digits[i]);
            auto hits = h.getHits(input);
            for(unsigned j = 0; j < hits.size(); j++){
                pos_index.push_back(hits[j]);
                if(i < 10) what.push_back(i);
                else what.push_back(i-9);
            }
        }

        unsigned min_index = pos_index[0], max_index = pos_index[0], first = 0, last = 0;
        for(unsigned i = 1; i < pos_index.size(); i++){
            if(min_index > pos_index[i]){
                min_index = pos_index[i];
                first = i;
            }
            if(max_index < pos_index[i]){
                max_index = pos_index[i];
                last = i;
            }
        }
        int min = what[first], max = what[last];
        current = min*10 + max;
        sum += current;
        cout << line++ << " " << current << endl;
        current = 0;
    }
    cout << sum << endl;
}

int main(){
    part1();
    part2();
}
