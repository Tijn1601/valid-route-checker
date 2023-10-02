/**
* @author Valentijn van Overveld
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Graph.h"

using namespace std;

/** Sorts the values and names using bubble sort and prints them out
* @param names the vector containing the names of the drivers
* @param vals the total weights of the paths of each driver
*/
void sortAndPrint(vector<string> names, vector<int> vals){
    //sorting the values using bubble sort
    for(unsigned long i = 0; i < names.size(); i++){
        for(unsigned long j = i; j < names.size(); j++){
            if(vals[i] > vals[j] || (vals[i] == vals[j] && names[i] > names[j])){
                swap(vals[i], vals[j]);
                swap(names[i], names[j]);
            }
        }
    }

    //printing out all the values
    for(unsigned long i = 0; i < names.size(); i++){
        if(vals[i] == 0){
            cout << names[i] << "\t" << vals[i] << "\tinvalid" << endl;
        } else {
            cout << names[i] << "\t" << vals[i] << "\tvalid" << endl;
        }
    }
}

/** Traverses through a vector to find the index of the give string
* @param names the vector of names to be searched
* @param name the name to be searched for
* @return the index of the name, or -1 if not found;
*/
int findIndex(vector<string> names, string name){
    for(unsigned long i = 0; i < names.size(); i++){
        if(names[i] == name)
            return static_cast<int>(i);
    }
    return -1;
}

/** Find the total weight of the driver's paths
* @param g the graph containing vertices and edges
* @param names the names of all the planets visited
* @return the weight of all the driver's paths or 0 if route is invalid
*/
int getTotalWeight(Graph* g, vector<string> names, string path){
    vector<int> vect;
    string temp;
    int total = 0;
    stringstream input(path);

    //taking all the planets and adding their indexes into a vector
    while(input >> temp){
        int idx = findIndex(names, temp);
        if(idx == -1)
            return 0;
        vect.push_back(idx);
    }

    //adding the total weight of all paths to the graph
    for(unsigned long i = 0; i < vect.size() - 1; i++){
        if(g->matrix[vect[i]][vect[i + 1]] != 0 && g->matrix[vect[i]][vect[i + 1]] != -1){
            total += g->matrix[vect[i]][vect[i + 1]];
        } else {
            //if the path is not valid
            return 0;
        }
    }
    return total;
}

/** Takes a line and adds the edges to the graph
* @param v1 the vertex the other vertices are connected to
* @param line the other vertices that v1 is connected to
* @param g the graph the edges are added to
* @param names the list of planet names
*/
void addToGraph(int v1, string line, Graph *g, vector<string> names){
    string temp;
    string v2;
    int weight;
    stringstream input(line);
    while(input >> temp){
        //getting rid of the commas
        for(unsigned long i = 0; i < temp.length(); i++){
            if(temp[i] == ',')
                temp[i] = ' ';
        }
        stringstream points(temp);
        points >> v2 >> weight;
        //inserts the edge based on the index of the vertices
        int idx = findIndex(names, v2);
        if(idx != -1)
            g->insertEdge(v1, idx, weight);
    }
}

/** Executes the program
* @return the status of the program once ran
*/
int main()
{
    string data, routes;
    cin >> data >> routes;
    ifstream input1(data);
    vector<string> vert;
    vector<string> lines;
    Graph* g = nullptr;

    //taking input from the graph file
    if(input1.good()){
        string temp;
        string line;
        while(input1 >> temp){
            vert.push_back(temp);
            getline(input1, line);
            lines.push_back(line);
        }

        //creating the graph and adding its vertices and edges
        g = new Graph(static_cast<int>(vert.size()));
        for(unsigned long i = 0; i < vert.size(); i++){
            g->insertVertex();
        }
        for(unsigned long i = 0; i < vert.size(); i++){
            addToGraph(static_cast<int>(i), lines[i], g, vert);
        }
    }
    input1.close();

    vector<string> names;
    vector<string> paths;
    vector<int> total;
    ifstream input2(routes);

    //taking input from the paths file
    if(input2.good()){
        string tempLine;
        string temp;
        while(getline(input2, tempLine)){
            stringstream ss(tempLine);
            ss >> temp;
            names.push_back(temp);
            getline(ss, tempLine);
            paths.push_back(tempLine);
        }
        //getting the total weight of the drivers paths
        for(unsigned long i = 0; i < names.size(); i++){
            total.push_back(getTotalWeight(g, vert, paths[i]));
        }
        sortAndPrint(names, total);
    }
    input2.close();
    return 0;
}
