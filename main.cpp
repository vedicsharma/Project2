#include <iostream>
#include "PageGraph.h"
using namespace std;




PageGraph addToGraph(string Input, PageGraph p){
    string space = " ";
    bool success = true;
    string commandString = Input;
    string remainingString = "";

    for(int i = 0; i < Input.size(); i++) {
        string letter = Input.substr(i,1);
        if (space == letter){
            commandString = Input.substr(0,i);
            remainingString = Input.substr(i+1, Input.size()-(i));
            break;
        }
    }
    p.insertEdge(commandString, remainingString);
    return p;

}



int main() {

    int numLines;
    int powerValue;
    PageGraph p;
    std::cin >> numLines >> powerValue;
    string clearfield = "";
    getline(cin, clearfield);

    for (int i=0; i<numLines;i++){
        string nextInput = "";
        getline(cin, nextInput);
        p = addToGraph(nextInput, p);
    }
    vector<float> v;
    //v = p.createVector();
    //p.display(v);
    //v = p.multiply(v);
    //p.display(v);

    p.printGraph();
    return 0;
    // NEED TO PASS graph P BY REFERNCE TO SAVE TIME!!!!
}
