#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

class PageGraph
{
private:
    map<int, vector<pair<int, int>>> graph;
    map<string, int> mapper;
    map<int, string> reversemapper;
    vector<int> outranks;

public:
    inline void insertEdge(string from, string to);
    inline void printGraph();
    inline vector<float> multiply(vector<float> values);
    inline void display(vector<float> values);
    inline vector<float> createVector();
    inline void initialize(int x);

};

inline void PageGraph::insertEdge(string from, string to) {
    if (mapper.find(from) == mapper.end()) {
        //cout << "done"<< endl;
        mapper[from] = mapper.size();
        reversemapper[reversemapper.size()] = from;
    }

    if (mapper.find(to) == mapper.end()) {
        //cout << "done"<< endl;
        mapper[to] = mapper.size();
        reversemapper[reversemapper.size()] = to;
    }

    int fromMap = mapper.find(from)->second;
    int toMap = mapper.find(to)->second;

    graph[fromMap].push_back(make_pair(toMap, 1));

    outranks[toMap] = outranks[toMap] + 1;

}


inline void PageGraph::printGraph() {

    for(int i = 0; i< graph.size(); i++){
        string name = reversemapper[i];
        cout << "Site#: " << i << ":"<<name;
        for(int a = 0; a<graph[i].size(); a++){

            cout << " " << graph[i][a].first<< "||";
        }
        cout << endl;
    }
}

inline vector<float> PageGraph::multiply(vector<float> values) {
    for(int i = 0; i< graph.size(); i++){
        float newRowVal = 0;
        for(int a = 0; a<graph[i].size(); a++){
            float temp = outranks[graph[i][a].first];
            //cout << temp<< " makes ";
            float val = 1/temp;
            //cout << val;
            newRowVal = newRowVal + (values[i]*val);
        }
        cout<< endl;
        values[i] = newRowVal;
    }
    return values;
}

void PageGraph::display(vector<float> values) {
    for(int i = 0; i<values.size(); i++){
        cout << values[i] << endl;
    }
}

vector<float> PageGraph::createVector() {
    int lines = graph.size();
    //cout <<"lines:"<<lines<<endl;
    vector<float> output;
    for(int i = 0; i<lines; i++){
        float temp = 1.0/lines;
        //cout <<"temp:"<< temp << endl;
        output.push_back(temp);
    }
    return output;
}

void PageGraph::initialize(int x) {
    for (int i = 0; i<x;i++){
        outranks.push_back(0);
    }
}

