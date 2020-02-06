#include "library.h"

bool    f(int x, int y) {
    return x > y;
}

/**
 * Vectors
 */
void    vectorDemo() {
    vector<int> A = {5, 7, 2, 1, 6};

    cout << A[4] << endl;

    sort(A.begin(), A.end());
    // 1, 2, 5 ,6 ,7

    bool present = binary_search(A.begin(), A.end(), 5); //true
    present = binary_search(A.begin(), A.end(), 4); //false

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    // 1, 2, 5, 6, 7, 100, 100, 100, 100, 123
    auto it1 = lower_bound(A.begin(), A.end(), 100); // >=
    auto it2 = upper_bound(A.begin(), A.end(), 100); // >

    print_vector_int(it1, it2);

    cout << it2 - it1 << endl;

    sort(A.begin(), A.end(), f);

    for (auto &x: A) {
        cout << ++x << " ";
    }
    cout << endl;
}

/**
 * Sets
 */
void    setDemo() {
    set<int> S;
    S.insert(5);
    S.insert(7);
    S.insert(8);
    S.insert(-1);

    for (auto x : S) {
        cout << x << " ";
    }
    cout << endl;

    auto it8 = S.find(8);
    if (it8 == S.end()) {
        cout << 8 << " was Not Found" << endl;
    } else {
        cout << 8 << " was found" << endl;
    }

    S.erase(8);


    it8 = S.find(8);
    if (it8 == S.end()) {
        cout << 8 << " was Not Found" << endl;
    } else {
        cout << 8 << " was found" << endl;
    }
}

/**
 * Map
 */
void    mapDemo() {
    map<int, int> M;
    M[1] = 1;
    M[2] = 3;
    M[3] = 3;
    M[4] = 7;

    for (int i = 1; i < 5; ++i) {
        cout << M[i];
    }
    cout << endl;

    map<char, int> cnt;
    string hello = "Brahim Lamnaouar";

    for (char c : hello) {
        cnt[c]++;
    }

    for (char c : hello) {
        cout << c << ": " << cnt[c] << endl;
    }

}

void    powerOfStl(char **argv) {
    set< pair<int, int> > S;
    S.insert({5, 9});
    S.insert({10, 30});
    S.insert({31, 399});
    S.insert({400, 430});

    int point = atoi(argv[1]);

    auto it = S.upper_bound({point, 100000});

    if (it == S.begin()) {
        cout << "Way too small" << endl;
        exit(1);
    }
    it--;
    pair<int, int> current = *it;
    if (current.first <= point && point <= current.second) {
        cout << point << " is in the interval [" << current.first << ", " << current.second << "]" << endl;
    } else {
        cout << "Not Found" << endl;
    }
}

int     main(int argc, char **argv) {

    if (argc <= 1) {
        cout << "No arguments given" << endl;
        exit(1);
    }
    powerOfStl(argv);

    return 0;
}