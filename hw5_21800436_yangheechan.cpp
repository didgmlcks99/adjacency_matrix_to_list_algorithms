/*

## 강의

## blogs and websites
https://www.geeksforgeeks.org/program-to-find-transpose-of-a-matrix/

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
void mapGetter(int *map, string input, char delimiter);
void print_2d_vector(int **v);
void transpose(int **map, int **transposed_map);

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
    int **map;
    map = new int *[nodes.size()];
    for(int i=0; i<nodes.size(); i++){
        map[i] = new int[nodes.size()];
    }

    int count = 0;
    while(getline(myfile, line)){
        mapGetter(map[count], line, '\t');
        count ++;
    }

    // initialize a transposed map and save as a transpoed version of the map 
    int **transposed_map;
    transposed_map = new int *[nodes.size()];
    for(int i=0; i<nodes.size(); i++){
        transposed_map[i] = new int[nodes.size()];
    }
    transpose(map, transposed_map);

    print_2d_vector(map);
    cout << endl;
    print_2d_vector(transposed_map);

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
void mapGetter(int *map, string input, char delimiter){
    stringstream ss(input);
    string temp;
    
    int count = 0;
    getline(ss, temp, delimiter);
    while(getline(ss, temp, delimiter)){
        map[count] = stoi(temp);
        count++;
    }
}

// print out a 2D vector
void print_2d_vector(int **v){
    cout << sizeof(v) << " : " << sizeof(v[0]) << endl;
    for(int i=0; i < sizeof(v); i++){
        for(int j=0; j < sizeof(v[i]); j++){
            cout << v[i][j];
        }cout << endl;
    }
}

// initialize a transposed map and save as a transpoed version of the map 
void transpose(int **map, int **transposed_map){
    for(int i=0; i < sizeof(map); i++){
        for(int j=0; j < sizeof(map[i]); j++){
            transposed_map[i][j] = map[j][i];
        }
    }
}