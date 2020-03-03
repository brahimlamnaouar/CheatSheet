#include "Modules/Graph.h"

int     main() {

    Graph<double> G;

    G.addVertex(5);
    G.addVertex(4);
    G.addVertex(2);
    G.addVertex(1);

    cout << G.size() << endl;

    return (0);
}