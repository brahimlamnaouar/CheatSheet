# CP CheatSheet

This cheatsheet contains most of the stuff you'll need to conquer CP competitions
***Made By Brahim Lamnaouar - Plankalkul***

## STL

Here we'll dive into the STL algorithms.
***Let's AI this bitch***

### Vector
`vector<type>` is usually used to create a list of items of type `type`
*Exp:* `char **Log` is simply replaced with `vector<string> Log`
*Yeah `string` in CPP is `char *` in C, pretty dope right?* 

#### Vector Pre Initialize
`vector<int> v2(size);` initialize without a value
`vector<int> v2(size, value);` initialize with a value

#### Vector Push Back
`vectorname.push_back(value): void; // O(1)`

#### Vector Insert
`vectorname.insert(position, value): void;`

#### Vector Clear
`vectorname.clear()` to remove every element of the vector

#### Vector Erase
`vectorname.erase(position);` to remove only one element
`vectorname.erase(startingposition, endingposition);` to remove a range of elements

#### Vector Resize
`vectorname.resize(int n, int val)` `n` is the new number of elements and `val` is the default value if the new size is bigger

#### Vector Size
`vectorname.size()` returns the size of the vector `vectorname.end() - vectorname.begin()`

#### Example
```
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
```

### Set
`set<type>` is similar to `Vector` only that it's sorted out by default every time you add something new 

#### Set Insert
`Set.insert(value): void; //logN`

#### Set Erase
`Set.erase(value): void; //logN`
`Set.erase(iterator): void; //logN`

#### Set Find
`Set.find(value): Iterator; //logN`
it returns `Set.end()` if not found. 

#### Upper Bound
`Set.upper_bound(value): Iterator; ">" //logN`

#### Lower Bound
`Set.lower_bound(value): Iterator; ">=" //logN`
it returns `Set.end()` if not found. 

```
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
```

### Map

#### Erase from Map
`Map.erase(key): void; //logN`

#### Find in Map
`Map.find(key): Iterator; //logN`

### 1. HEAPS
#### Make Heap
`void make_heap(RandIter start, RandIter end);`
takes a vector and makes a heap put of it

#### Push Heap
`void push_heap(RandIter start, RandIter end);`
sends the last element to his proper place

#### Pop Heap
`void pop_heap(RandIter start, RandIter end);`
it sends the first element (Largest Element of Heap) to the end and calls [Make Heap](#make-heap) on the rest

### 2. SORTING
#### Sort
`void sort( RandomIt first, RandomIt last, Compare comp ); //NlogN`
*Exp :*
```
// Compares two intervals according to staring times. 
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
}
```

#### Partial Sort
`void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last);`
Random-Access iterator pointing to the element in the range [first, last), that is used as the upper boundary for the elements  to be sorted.

#### Nth Element
`void nth_element (RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);`
Random-access iterator pointing to the position in the list, which should be sorted. If it points to end, then this function will do nothing.

#### Sort Heap
`void sort_heap(RandIter start, RandIter end);`
Repeats [Pop Heap](#pop-heap) till sorted

#### Inplace Merge
`void inplace_merge(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last, Compare comp);`
*Middle :* the end of the first sorted range and the beginning of the second (begin() + size of first sorted range);

### 3. PARTITIONING
#### Partition
`ForwardIt partition( ForwardIt first, ForwardIt last, UnaryPredicate p );`
Partition according to the condition
*Exp :* `partition(vect.begin(), vect.end(), [](int x) {return x%2==0;});`

#### Is Partitioned
`bool is_partitioned( ForwardIt first, ForwardIt last, UnaryPredicate p );`
Same as [Partition](#partition) but it only checks and returns bool 

#### Partition point
`ForwardIt partition_point( ForwardIt first, ForwardIt last, UnaryPredicate p );`
Examines the partitioned (as if by [Partition](#partition)) range [first, last) and locates the end of the first partition, that is, the first element that does not satisfy p or last if all elements satisfy p.

### 4. PERMUTATIONS
#### Rotate
`void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last)`
it moves middle to first
***Types of rotation***
*Left Rotation :* To rotate left, we need to add the vector index. For example, you have to rotate vector left 3 times. The 3th index of vector becomes first element. vec.begin() + 3 will rotate vector 3 times left.
*Right Rotation :* To rotate right, we need to subtract the vector index. For example, you have to rotate vector right 3 times. The 3th last index of vector becomes first element. vec.begin()+vec.size()-3 will rotate vector 3 times right.

#### Reverse
`void reverse(BidirectionalIterator first, BidirectionalIterator last)`
Reverse a given collection

#### Shuffle
`void shuffle(RandomIt first, RandomIt last, UniformRandomBitGenerator&& g)`
Shuffles all the elements using `g` as a random number generator
*Exp:* `shuffle(s.begin(), s.end(), default_random_engine(seed));`

#### Next Permutation
`bool next_permutation (BidirectionalIterator first, BidirectionalIterator last);`
***Return :***
*true :* if the function could rearrange the object as a lexicographically greater permutation.
*false :* the function returns false to indicate that the arrangement is not greater than the previous, but the lowest possible (sorted in ascending order).

#### Prev Permutation
`bool prev_permutation (BidirectionalIterator first, BidirectionalIterator last);`
it does what [Next Permutation](#next-permutation) does. Only backward.

### 6. NUMERIC ALGORITHMS
#### Count
`int count(startingposition, endingposition, value);`

### 8. SEARCHING A VALUE
[Find](#find) and [Adjacent Find](#adjacent-find) are more oriented towards unsorted collection.
The rest is only used for sorted collections

#### Find
`InputIterator find(InputIterator first, InputIterator last, const T& val);`
finds the iterator to the first occurrence

#### Adjacent Find
`ForwardIt adjacent_find(ForwardIt first, ForwardIt last, BinaryPredicate p);`
Finds the first iterator to a double occurrence
THe predicate could be something like `std::greater<int>()` to find the greater double occurrence

#### Equal Range
`std::pair<ForwardIt,ForwardIt> equal_range(ForwardIt first, ForwardIt last, const T& value);`
Searches a range and returns a range of the value

#### Binary Search
`binary_search(Vector.begin(), Vector.end(), value): bool; //logN`
This function is returns `true` if `value` exists between `first` and `last` otherwise `false` 

#### Upper Bound
`upper_bound(Vector.begin(), Vector.end(), value): Iterator; // logN && >`
Return the first value strictly greater than `value`  


#### Lower Bound
`lower_bound(Vector.begin(), Vector.end(), value): Iterator; // logN && >=`
Return the first value greater than or equal `value`

### 12. MOVERS
#### Copy
`OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result)`
it starts copying into result starting from `first` 

#### Copy Backward
`OutputIterator copy_backward(InputIterator first, InputIterator last, OutputIterator result)`
it starts copying into result starting from `last` 

#### Move
`OutputIterator move(InputIterator first, InputIterator last, OutputIterator result)`
it starts copying into result starting from `first` and deletes every copied item 

#### Move Backward
`OutputIterator move_backward(InputIterator first, InputIterator last, OutputIterator result)`
it starts copying into result starting from `last` and deletes every copied item 

#### Swap Ranges
`OutputIterator swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2)`
interchange elements between the two collections

### 13. VALUE MODIFIERS
#### Fill
`void fill(ForwardIt first, ForwardIt last, const T& value );`
Put the same value everywhere

#### Generate
`void generate(ForwardIt first, ForwardIt last, Generator g);`
Uses `g` to generate a random number. `g` doesn't take any parameters

#### Iota
`void iota(ForwardIt first, ForwardIt last, const T& value );`
It starts filling with value and add 1....

#### Replace
`void replace(ForwardIt first, ForwardIt last, const T& old, const T& new);`
Changes every `old` value to `new`

### 14. STRUCTURE CHANGERS
#### Unique
`ForwardIterator unique(ForwardIterator first, ForwardIterator last);`
`ForwardIterator unique(ForwardIterator first, ForwardIterator last, BinaryPredicate Pred);` 
This is a tricky one because it only works on **Vectors** so careful with that. It doesn't remove adjacent duplicates completely but it leaves undefined values at the end and send an iterator to the first one of them which we should delete later on using [Erase](#erase) or [Resize](#resize)

*Exp: Pred*
```
bool Pred(char a, char b) 
{ 
    // Checking if both the arguments are same and equal 
    // to 'G' then only they are considered same 
    // and duplicates are removed 
    if (a == b && a == 'G') { 
        return 1; 
    } else { 
        return 0; 
    } 
}
```

#### Remove
`ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& val);`
This one is just like [Unique](#unique). But it removes the given `val` instead of duplicates.

### 15. _COPY
These algorithms do the same thing as the algorithms without `_copy` only that they put the results in a new collection and leave the original one untouched

[Unique](#unique): 
`OutputIterator unique_copy(InputIterator first, InputIterator last, OutputIterator result);`

[Remove](#remove):
`ResultIterator remove_copy(ForwardIterator first, ForwardIterator last, ResultIterator result ,const T& ele);`

[Rotate](#rotate):
`void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last, OutputIterator result);`

[Reverse](#reverse):
`void reverse(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result);`

[Partition](#partition): 
`pair<OutputIt1, OutputIt2> partition_copy(InputIt first, InputIt last, 
                                           OutputIt1 d_first_true, OutputIt2 d_first_false,
                                           UnaryPredicate p );`
 *Returns :* the size till *d_end_true* and *d_end_false*

[Partial Sort](#partial-sort): 
`RandomIt partial_sort_copy(InputIt first, InputIt last, RandomIt d_first, RandomIt d_last);` At most `d_last - d_first` elements

[Replace](#replace): 
`OutputIterator replace_copy (InputIterator first, InputIterator last,
                              OutputIterator result,
                              const T& old_value, const T& new_value);`
*Returns :* An iterator pointing to the element that follows the last element written in the result sequence.

### _IF
#### Remove_If
Same as [Remove](#remove). But with a predicate 
`ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);`
A predicate would be something like this:
```
bool IsOdd(int i) 
{ 
    return ((i % 2) == 1); 
}
```
