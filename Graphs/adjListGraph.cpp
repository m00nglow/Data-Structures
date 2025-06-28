#include <list>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
}

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}