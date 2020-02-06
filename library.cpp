#include "library.h"

void hello() {
    cout << "Hello, World!" << endl;
}

void print_vector_int(vector<int>::iterator begin, vector<int>::iterator end) {
    for (auto i = begin; i < end; ++i) {
        cout << *i << " ";
    }
    cout << endl;
}