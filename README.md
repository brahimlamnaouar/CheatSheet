# CP CheatSheet

This cheatsheet contains most of the stuff you'll need to conquer CP competitions

***Made By Brahim Lamnaouar***

## STL

Here we'll dive into the STL algorithms.

***Let's AI this bitch***

### Vector
`vector<type>` is usually used to create a list of items of type `type`

*Exp:* `char **Log` is simply replaced with `vector<string> Log`

*Yeah `string` in CPP is `char *` in C, pretty dope right?* 

#### Add to Vector
`Vector.push_back(value): void; // O(1)`

#### Insert in Vector
`Vector.insert(position, value): void;`

#### Example
```diff
/**
* Vectors
*/
void    vectorDemo() {
   + vector<int> A = {5, 7, 2, 1, 6};

   cout << A[4] << endl;

   + sort(A.begin(), A.end());
   // 1, 2, 5 ,6 ,7

   + bool present = binary_search(A.begin(), A.end(), 5); //true
   present = binary_search(A.begin(), A.end(), 4); //false

   A.push_back(100);
   A.push_back(100);
   A.push_back(100);
   A.push_back(100);
   A.push_back(123);
   // 1, 2, 5, 6, 7, 100, 100, 100, 100, 123
   + auto it1 = lower_bound(A.begin(), A.end(), 100); // >=
   + auto it2 = upper_bound(A.begin(), A.end(), 100); // >

   print_vector_int(it1, it2);

   cout << it2 - it1 << endl;

   + sort(A.begin(), A.end(), f);

   for (auto &x: A) {
       cout << ++x << " ";
   }
   cout << endl;
}
```

### Set

`set<type>` is similar to `Vector` only that it's sorted out by default every time you add something new 

#### Insert into Set
`Set.insert(value): void; //logN`

#### Erase from Set
`Set.erase(value): void; //logN`

#### Find
`Set.find(value): Iterator; //logN`

it returns `Set.end()` if not found. 

#### Upper Bound
`Set.upper_bound(value): Iterator; ">" //logN`

#### Lower Bound
`Set.lower_bound(value): Iterator; ">=" //logN`

it returns `Set.end()` if not found. 

```diff
/**
 * Sets
 */
void    setDemo() {
    + set<int> S;
    # S.insert(5);
    # S.insert(7);
    # S.insert(8);
    # S.insert(-1);

    for (auto x : S) {
        cout << x << " ";
    }
    cout << endl;

    + auto it8 = S.find(8);
    ! if (it8 == S.end()) {
    !    cout << 8 << " was Not Found" << endl;
    ! } else {
    !    cout << 8 << " was found" << endl;
    ! }

    + S.erase(8);


    it8 = S.find(8);
    if (it8 == S.end()) {
        cout << 8 << " was Not Found" << endl;
    } else {
        cout << 8 << " was found" << endl;
    }
}
```

### Map

#### Erase from Map
`Map.erase(key): void; //logN`

#### Find in Map
`Map.find(key): Iterator; //logN`

### Algorithms

#### Sort Vector
`sort(Vector.begin(), Vector.end(), comp): void; //NlogN`

`comp: bool comp(int x, int y)` is the function that defines the order *(asc or desc)* By default it's *Asc*

#### Binary Search
`binary_search(Vector.begin(), Vector.end(), value): bool; //logN`

This function is returns `true` if `value` exists between `first` and `last` otherwise `false` 

#### Upper Bound
`upper_bound(Vector.begin(), Vector.end(), value): Iterator; // logN && >`

Return the first value strictly greater than `value`  


#### Lower Bound
`lower_bound(Vector.begin(), Vector.end(), value): Iterator; // logN && >=`

Return the first value greater than or equal `value`

### Numeric Algorithms
#### Count
`count(begin, end, value): int;`


### Structure Changes
#### Erase
`myvector.erase(myvector.begin()+5);` to remove only one element

`myvector.erase(myvector.begin(),myvector.begin()+3);` to remove a range of elements

#### Unique

#### Remove

