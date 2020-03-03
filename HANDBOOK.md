# The CP Handbook
let's AI this bitch

## Introduction

### Code Template
```
#include <bits/stdc++.h>
using namespace std;
int main() {
    // solution comes here
}
```
to compile a code use: `g++ -std=c++11 -O2 -Wall test.cpp -o test`

### Input and Output

#### Cin Cout
Always use `"\n"` instead of `endl` because it's faster

#### Syncing
Sometimes `cin` and `cout` face a syncing problem which you could solve with adding this to the beginning of your main:

```
ios::sync_with_stdio(0);
cin.tie(0);
```

#### Scanf and Printf
```c++
int a, b;
scanf("%d %d", &a, &b);
```
```c++
int a = 123, b = 456;
printf("%d %d\n", a, b);
```

#### Scan a string with whitespaces
```c++
string s;
getline(cin, s);
```

#### Scan an unknown amount of data
```c++
while (cin >> x) {
    // code
}
```

#### Scan and Write to a file
use the following lines to set where to read from as well as write to. Then use the regular `cin` and `cout`
```c++
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

### Working With Numbers

#### Integers
```c++
int         x = 123456789;              //This goes to 2^32
long long   x = 123456789123456789LL;   //This goes to 2^64
__int128_t  x = 15454561                //This goes to 2^128
```

The `LL` suffix signifies that we're working with a `long long` number.

Never use `int` with `long long`
```c++
int a = 123456789;
long long b = a*a;
cout << b << "\n"; // -1757895751 Oh-Ouuuh
```
#### Modular Arithmetic

```
(a+ b) mod m = (a mod m+ b mod m) mod m
(a− b) mod m = (a mod m− b mod m) mod m
(a· b) mod m = (a mod m· b mod m) mod m
```

The mod of negative numbers is also a negative number and a quick fix to that is 
```c++
x = x%m;
if (x < 0) x += m;
```

#### Floating point numbers

```c++
double //64bits
long double //80 bits and more accurate
```

in some contests the precision is required. For example to write 9 numbers after the point try using `printf`

```c++
printf("%.9f\n", x);
```

Sometimes the floating point number gets weird. the next example should give you `1` but it gets weird because of a rounding error
```c++
double x = 0.3*3+0.1;
printf("%.20f\n", x); // 0.99999999999999988898
```
to avoid this try using a comparison with `ε = 10−9`
```c++
if (abs(a-b) < 1e-9) {
    // a and b are equal
}
```

### Shortening code

#### The names

```c++
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
```
#### Macros
```c++
#define F first
#define S second
#define PB push_back
#define MP make_pair
```
#### Reps
```c++
#define REP(i,a,b) for (int i = a; i <= b; i++)
```

### Mathematics
#### Sum Formulas
```
Sum(1, n)(k) = n*(n+1)/2
Sum(1, n)(k^2) = n*(n+1)*(2*n+1)/6
```
#### Arithmetic progression
An arithmetic progression is a sequence of numbers where the difference
between any two consecutive numbers is constant. For example: 
***3,7,11,15***

```
a+ ...n times... +b = n(b+a)/2; // n is the length of the arithmetic progression 
```

#### Geometric progression
A geometric progression is a sequence of numbers where the ratio between any two consecutive numbers is constant.

For example: ***3,6,12,24*** is a geometric progression with constant 2

```
a + ak + ak^2 +···+ b = (bk-a)/(k-1); // n is the length of the arithmetic progression 
```

#### Set Theory
A set always has `2^|S|` subsets including the empty set

#### Fibonacci
```
F(n) = ((1 + sqrt(5))^n - (1 - sqrt(5))^n)/srqt(5)*2^n
```


## Graphs
### Graph representation
#### Adjacency list representation
***Non Weithed:***
```c++
vector<int> adj[N];
adj[1].push_back(2);
adj[2].push_back(3);
adj[2].push_back(4);
adj[3].push_back(4);
adj[4].push_back(1);
```
If the graph is undirected, it can be stored in a similar way, but each edge is
added in both directions.

***Weighted:***
```c++
vector<pair<int,int>> adj[N];
adj[1].push_back({2,5});
adj[2].push_back({3,7});
adj[2].push_back({4,6});
adj[3].push_back({4,5});
adj[4].push_back({1,2});
```
***Moving:***
```c++
for (auto u : adj[s]) {
    // process node u
}
```
This for finds the nodes you can move to from the node `s`
#### Adjacency matrix representation
```c++
int adj[N][N];
```
where each value adj[a][b] indicates whether the graph contains an edge from
node a to node b. If the edge is included in the graph, then adj[a][b] = 1 or weight, and
otherwise adj[a][b] = 0.
#### Edge list representation
***Non Weighted:***
```c++
vector<pair<int,int>> edges;
edges.push_back({1,2});
edges.push_back({2,3});
edges.push_back({2,4});
edges.push_back({3,4});
edges.push_back({4,1});
```
***Non Weighted:***
```c++
vector<tuple<int,int,int>> edges;
edges.push_back({1,2,5});
edges.push_back({2,3,7});
edges.push_back({2,4,6});
edges.push_back({3,4,5});
edges.push_back({4,1,2});
```

### Shortest Path
#### Bellman-Ford
```c++
for (int i = 1; i <= n; i++) distance[i] = INF;
distance[x] = 0;
for (int i = 1; i <= n-1; i++) {
    for (auto e : edges) {
        int a, b, w;
        tie(a, b, w) = e;
        distance[b] = min(distance[b], distance[a]+w);
    }
}
```

**Bellman-Ford** runs for `n-1` rounds and shortens the paths to every node. 

It could be used to detect negative cycles(The mean bitches that make the algorithm useless). How? Easy just run it for another round(`n`) and if shortens anything then there's a negative cycle bitch suck on that.

You could stop the algorithm the moment a round doesn't reduce anything.
```c++
for (int i = 1; i <= n; i++) distance[i] = INF;
distance[x] = 0;
for (int i = 1; i <= n-1; i++) {
    int p = 1;
    for (auto e : edges) {
        int a, b, w;
        tie(a, b, w) = e;
        if (distance[b] > distance[a]+w) {
            p = 0;
            distance[b] = distance[a]+w;
        }
    }
    if (p) break;
}
```
#### SPFA algorithm
This algorithm is a fast version of [Bellman-Ford](#bellman-ford). It considers a queue initialized by a starting node. We take the first node `a`. if there's an edge `{a, b}` such that it reduces a distance then `b` is added to the `queue`. And so on and so forth till the queue is empty.

#### Dijkstra
```c++
for (int i = 1; i <= n; i++) distance[i] = INF;
distance[x] = 0;
q.push({0,x});
while (!q.empty()) {
    int a = q.top().second; q.pop();
    if (processed[a]) continue;
    processed[a] = true;
    for (auto u : adj[a]) {
        int b = u.first, w = u.second;
        if (distance[a]+w < distance[b]) {
            distance[b] = distance[a]+w;
            q.push({-distance[b],b});
        }
    }
}
```

the `-distance[b]` in the queue prioritizes the minimum. This queue takes the maximum value first and we want the minimum.