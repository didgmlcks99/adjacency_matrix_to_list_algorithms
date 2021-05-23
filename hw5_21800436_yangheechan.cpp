/*

## 강의
slide (ppt) : Knapsack Problem

## blogs and websites

*/

// add below using header
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
// #include <time.h>
#include <vector>
// #include <algorithm>
#include <deque>

using namespace std;

deque<string> nodeGetter(string input, char delimiter);
vector<string> mapGetter(string input, char delimiter);
void print_2d_vector(vector<vector<string> > v);
vector<vector<string> >  transpose(vector<vector<string> > map);

int main(){
    // open data file of the matrix of the map
    ifstream myfile("hw5_data.txt");
    if (myfile.is_open()) { }
    else { 
        cout << "[ERROR] opening file." << endl; 
        cout << "Terminating program." << endl;
        return 0x0;
    }

    // retrive informations about the existing nodes in the map
    string line;
    getline(myfile, line);
    deque<string> nodes = nodeGetter(line, '\t');

    // get directions information for each nodes
    vector<vector<string> > map;
    int count = 0;
    while(getline(myfile, line)){
        map.push_back(mapGetter(line, '\t'));
        count ++;
    }

    // initialize a transposed map and save as a transpoed version of the map 
    vector<vector<string> > transposed_map (map.size(), vector<string>(map[0].size(), "0"));
    transposed_map = transpose(map);

    myfile.close();
    
    return 0;
}

// retrive informations about the existing nodes in the map
deque<string> nodeGetter(string input, char delimiter){
    deque<string> nodes;
    stringstream ss(input);
    string temp;

    while(getline(ss, temp, delimiter)){
        nodes.push_back(temp);
    }

    nodes.pop_front();

    return nodes;
}

// get directions information for each nodes
vector<string> mapGetter(string input, char delimiter){
    vector<string> map;
    stringstream ss(input);
    string temp;

    getline(ss, temp, delimiter);
    while(getline(ss, temp, delimiter)){
        map.push_back(temp);
    }

    return map;
}

// print out a 2D vector
void print_2d_vector(vector<vector<string> > v){
    cout << v.size() << " : " << v[0].size() << endl;
    for(int i=0; i < v.size(); i++){
        for(int j=0; j < v[i].size(); j++){
            cout << v[i][j];
        }cout << endl;
    }
}

// initialize a transposed map and save as a transpoed version of the map 
vector<vector<string> >  transpose(vector<vector<string> > map){
    vector<vector<string> > transposed_map (map.size(), vector<string>(map[0].size(), "0"));

    for(int i=0; i < map.size(); i++){
        for(int j=0; j < map[i].size(); j++){
            transposed_map[i][j] = map[j][i];
        }
    }

    return transposed_map;
}