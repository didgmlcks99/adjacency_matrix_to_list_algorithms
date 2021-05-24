/*

## 강의

## blogs and websites
https://www.geeksforgeeks.org/program-to-find-transpose-of-a-matrix/
https://www.tutorialspoint.com/Passing-two-dimensional-array-to-a-Cplusplus-function

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <deque>

using namespace std;

vector<string> nodeGetter(string input, char delimiter);
void mapGetter(int *map, string input, char delimiter);
void print_2d_vector(int **v);
void transpose(int **map, int **transposed_map);
void adjacency_list(int **map, vector<string> nodes);

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
    vector<string> nodes = nodeGetter(line, '\t');

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

    cout << "Matrix of original map." << endl;
    print_2d_vector(map);

    cout << "Adjancy list of original map." << endl;
    adjacency_list(map, nodes);

    cout << "Matrix of transposed map." << endl;
    print_2d_vector(transposed_map);

    cout << "Adjancy list of transposed map." << endl;
    adjacency_list(transposed_map, nodes);

    myfile.close();
    
    return 0;
}

// retrive informations about the existing nodes in the map
vector<string> nodeGetter(string input, char delimiter){
    vector<string> nodes;
    stringstream ss(input);
    string temp;

    getline(ss, temp, delimiter);
    while(getline(ss, temp, delimiter)){
        nodes.push_back(temp);
    }

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
    cout << sizeof(v) << " x " << sizeof(v[0]) << endl;
    for(int i=0; i < sizeof(v); i++){
        for(int j=0; j < sizeof(v[i]); j++){
            cout << v[i][j];
        }cout << endl;
    }cout << endl;
}

// initialize a transposed map and save as a transpoed version of the map 
void transpose(int **map, int **transposed_map){
    for(int i=0; i < sizeof(map); i++){
        for(int j=0; j < sizeof(map[i]); j++){
            transposed_map[i][j] = map[j][i];
        }
    }
}

void adjacency_list(int **map, vector<string> nodes){
    for(int i=0; i < nodes.size(); i++){
        cout << nodes[i][0];
        for(int j=0; j < sizeof(map[i]); j++){
            if(map[i][j] == 1){
                cout << " --> " << nodes[j];
            }
        }cout << endl;
    }cout << endl;
}