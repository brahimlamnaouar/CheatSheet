# CP CheatSheet

This cheatsheet contains most of the stuff you'll need to conquer CP competitions

***Made By Brahim Lamnaouar - Team Member Of Plankalkul***

## BASIC DATA STRUCTURES

Here we'll dive into the basics data structures of ***`CPP`***.

***Let's AI this bitch***

### 1. Vector
`vector<type>` is usually used to create a list of items of type `type`

*Exp:* `char **Log` is simply replaced with `vector<string> Log`

*Yeah `string` in **`CPP`** is `char *` in C, pretty dope right?* 

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

### 2. Set
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

### 3. Map

#### Erase from Map
`Map.erase(key): void; //logN`

#### Find in Map
`Map.find(key): Iterator; //logN`

## 105 STL ALGORITHMS

### 1. HEAPS
#### 1.1. Make Heap
`void make_heap(RandIter start, RandIter end);`

takes a vector and makes a heap put of it

#### 1.2. Push Heap
`void push_heap(RandIter start, RandIter end);`

sends the last element to his proper place

#### 1.3. Pop Heap
`void pop_heap(RandIter start, RandIter end);`

it sends the first element (Largest Element of Heap) to the end and calls [Make Heap](#11-make-heap) on the rest

### 2. SORTING
#### 2.1. Sort
`void sort( RandomIt first, RandomIt last, Compare comp ); //NlogN`

*Exp :*
```
// Compares two intervals according to staring times. 
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
}
```

#### 2.2. Partial Sort
`void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last);`

Random-Access iterator pointing to the element in the range [first, last), that is used as the upper boundary for the elements  to be sorted.

#### 2.3. Nth Element
`void nth_element (RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);`

Random-access iterator pointing to the position in the list, which should be sorted. If it points to end, then this function will do nothing.

#### 2.4. Sort Heap
`void sort_heap(RandIter start, RandIter end);`

Repeats [Pop Heap](#13-pop-heap) till sorted

#### 2.5. Inplace Merge
`void inplace_merge(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last, Compare comp);`

*Middle :* the end of the first sorted range and the beginning of the second (begin() + size of first sorted range);

Check out [Merge](#116-merge) which is also interesting

### 3. PARTITIONING
#### 3.1. Partition
`ForwardIt partition( ForwardIt first, ForwardIt last, UnaryPredicate p );`

Partition according to the condition

*Exp :* `partition(vect.begin(), vect.end(), [](int x) {return x%2==0;});`

#### 3.2. Partition point
`ForwardIt partition_point( ForwardIt first, ForwardIt last, UnaryPredicate p );`

Examines the partitioned (as if by [Partition](#31-partition)) range [first, last) and locates the end of the first partition, that is, the first element that does not satisfy p or last if all elements satisfy p.

### 4. PERMUTATIONS
#### 4.1. Rotate
`void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last)`

it moves middle to first

***Types of rotation***

*Left Rotation :* To rotate left, we need to add the vector index. For example, you have to rotate vector left 3 times. The 3th index of vector becomes first element. vec.begin() + 3 will rotate vector 3 times left.

*Right Rotation :* To rotate right, we need to subtract the vector index. For example, you have to rotate vector right 3 times. The 3th last index of vector becomes first element. vec.begin()+vec.size()-3 will rotate vector 3 times right.

#### 4.2. Reverse
`void reverse(BidirectionalIterator first, BidirectionalIterator last)`

Reverse a given collection

#### 4.3. Shuffle
`void shuffle(RandomIt first, RandomIt last, UniformRandomBitGenerator&& g)`

Shuffles all the elements using `g` as a random number generator

*Exp:* `shuffle(s.begin(), s.end(), default_random_engine(seed));`

#### 4.4. Next Permutation
`bool next_permutation (BidirectionalIterator first, BidirectionalIterator last);`

***Return :***

*true :* if the function could rearrange the object as a lexicographically greater permutation.

*false :* the function returns false to indicate that the arrangement is not greater than the previous, but the lowest possible (sorted in ascending order).

#### 4.5. Prev Permutation
`bool prev_permutation (BidirectionalIterator first, BidirectionalIterator last);`

it does what [Next Permutation](#44-next-permutation) does. Only backward.

### 5. THE SECRET ROOM
#### 5.1. STABLE_
`stable_sort`, `stable_partition`

These two function exactly like [Sort](#21-sort) and [Partition](#31-partition) only they hold the order of elements which could be useful when using pairs or intervals

#### 5.2. IS_
`is_partitioned` / `is_sorted` / `is_heap`

Same as [Partition](#31-partition), [Sort](#21-sort) and [Heap](#1-heaps) but it only checks and returns bool 

#### 5.3. IS_X_UNTIL
`is_partitioned_until` / `is_sorted_until` / `is_heap_until`

Returns the iterator that failed the condition or `end()` otherwise.

### 6. NUMERIC ALGORITHMS
#### 6.1. Count
`int count(startingposition, endingposition, value);`

#### 6.2. Accumulate
`T accumulate (InputIterator first, InputIterator last, T init);`

This function returns the sum of all the values lying in a range between [first, last[ with the variable sum.

#### 6.3. Partial Sum
`OutputIterator partial_sum (InputIterator first, InputIterator last, OutputIterator result);`

This function assigns partial sum of the corresponding elements of an array to every position of the second array.It returns the partial sum of all the set of values lying between [first, last) and stores it in another array `result`.

#### 6.4. Reduce
`T reduce(InputIterator first, InputIterator last);`

It's exactly like [Accumulate](#62-accumulate) But it could be used in a parallelized way

`double result = std::reduce(std::execution::par, v.begin(), v.end());`

#### 6.5. Transform Reduce
`T transform_reduce(InputIt1 first1, InputIt1 last1, InputIt2 first2, T init);`

Equivalent to transform_reduce(first1, last1, first2, init, std::plus<>(), std::multiplies<>());, effectively parallelized version of the default std::inner_product

#### 6.6. Inclusive Scan
Same as [Partial Sum](#63-partial-sum) but with the option to execute in parallel

#### 6.7. Exclusive Scan
Same as [Inclusive Scan](#66-inclusive-scan) but with an offset of 1

#### 6.8. Inner Product
`T inner_product( InputIt1 first1, InputIt1 last1, InputIt2 first2, T init );`

It multiplies every two items in the same position and sums everything up

#### 6.9. Sample
`SampleIterator sample( PopulationIterator first, PopulationIterator last,
                       SampleIterator out, Distance n,
                       URBG&& g);`

It takes a number and makes an `n-collection` randomly out of it.

Returns a copy of out after the last sample that was output, that is, end of the sample range.

`std::sample(in.begin(), in.end(), std::back_inserter(out), 5, std::mt19937{std::random_device{}()});`

#### 6.10. Adjacent Difference
`OutputIt adjacent_difference( InputIt first, InputIt last, OutputIt d_first );`

the difference between every two neighbors

### 7. QUERYING A PROPERTY

#### 7.1. All Of
`bool all_of( InputIt first, InputIt last, UnaryPredicate p );`

#### 7.2. Any Of
`bool any_of( InputIt first, InputIt last, UnaryPredicate p );`

#### 7.3. None Of
`bool none_of( InputIt first, InputIt last, UnaryPredicate p );`

#### 7.4. Equal
`bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2);`

Compare item by item

#### 7.5. Is Permutation
`bool is_permutation(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2);`

Check if second collection is a possible permutation of the first one

#### 7.6. Lexicographical Compare
`bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2);`

Compare lexicographically two collections and return *true* if the first one is smaller

#### 7.7. MisMatch 
`std::pair<InputIt1,InputIt2> mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2);`

Returns a pair of elements where the two collections differ, `{end1(), end2()}` Otherwise

### 8. SEARCHING A VALUE
[Find](#81-find) and [Adjacent Find](#82-adjacent-find) are more oriented towards unsorted collection. 
The rest is only used for sorted collections

#### 8.1. Find
`InputIterator find(InputIterator first, InputIterator last, const T& val);`

finds the iterator to the first occurrence

#### 8.2. Adjacent Find
`ForwardIt adjacent_find(ForwardIt first, ForwardIt last, BinaryPredicate p);`

Finds the first iterator to a double occurrence

THe predicate could be something like `std::greater<int>()` to find the greater double occurrence

#### 8.3. Equal Range
`std::pair<ForwardIt,ForwardIt> equal_range(ForwardIt first, ForwardIt last, const T& value);`

Searches a range and returns a range of the value

#### 8.4. Binary Search
`binary_search(Vector.begin(), Vector.end(), value): bool; //logN`

This function is returns `true` if `value` exists between `first` and `last` otherwise `false` 

#### 8.5. Upper Bound
`upper_bound(Vector.begin(), Vector.end(), value): Iterator; // logN && >`

Return the first value strictly greater than `value`  


#### 8.6. Lower Bound
`lower_bound(Vector.begin(), Vector.end(), value): Iterator; // logN && >=`

Return the first value greater than or equal `value`

### 9. SEARCHING RANGES
#### 9.1. Search
`ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                         ForwardIterator2 first2, ForwardIterator2 last2);`

Find first occurrence of sub range and returns an iterator to the first element of the first occurrence of [first2, last2) in [first1, last1), or last1 if no occurrences are found.

#### 9.2. Find End
`ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1,
                         ForwardIterator2 first2, ForwardIterator2 last2);`

Find last occurrence of sub range

#### 9.3. Find First Of
`ForwardIterator1 find_first_of(ForwardIterator1 first1, ForwardIterator1 last1,
                         ForwardIterator2 first2, ForwardIterator2 last2);`

Find first occurrence of any element of sub range

### 10. SEARCHING A RELATIVE VALUE
#### 10.1. Max Element
`ForwardIt max_element(ForwardIt first, ForwardIt last);`

#### 10.2. Min Element
`ForwardIt min_element(ForwardIt first, ForwardIt last);`

#### 10.3. MinMax Element
`std::pair<ForwardIt,ForwardIt> minmax_element(ForwardIt first, ForwardIt last);`

### 11. ALGORITHMS ON SETS
[Set Difference](#111-set-difference), [Set Intersection](#112-set-intersection), [Set Union](#113-set-union) and [Set Symmetric Difference](#114-set-symmetric-difference) return an iterator to `Output.end()`

#### 11.1. Set Difference
`OutputIt set_difference( InputIt1 first1, InputIt1 last1,
                          InputIt2 first2, InputIt2 last2,
                          OutputIt d_first );`
                     
#### 11.2. Set Intersection
`OutputIt set_intersection( InputIt1 first1, InputIt1 last1,
                            InputIt2 first2, InputIt2 last2,
                            OutputIt d_first );`
#### 11.3. Set union
`OutputIt set_union( InputIt1 first1, InputIt1 last1,
                     InputIt2 first2, InputIt2 last2,
                     OutputIt d_first );`

#### 11.4. Set Symmetric Difference
`OutputIt set_symmetric_difference( InputIt1 first1, InputIt1 last1,
                                   InputIt2 first2, InputIt2 last2,
                                   OutputIt d_first );`
                                   
#### 11.5. Includes
`bool includes( InputIt1 first1, InputIt1 last1,
                InputIt2 first2, InputIt2 last2 );`

Returns true if all the elements of the second collection exist in the first one.

#### 11.6. Merge
`OutputIt merge( InputIt1 first1, InputIt1 last1,
                 InputIt2 first2, InputIt2 last2,
                 OutputIt d_first );`
                 
Merges two sorted collections into a big sorted one
            

### 12. MOVERS
#### 12.1. Copy
`OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result)`

it starts copying into result starting from `first` 

#### 12.2. Copy Backward
`OutputIterator copy_backward(InputIterator first, InputIterator last, OutputIterator result)`

it starts copying into result starting from `last` 

#### 12.3. Move
`OutputIterator move(InputIterator first, InputIterator last, OutputIterator result)`

it starts copying into result starting from `first` and deletes every copied item 

#### 12.4. Move Backward
`OutputIterator move_backward(InputIterator first, InputIterator last, OutputIterator result)`

it starts copying into result starting from `last` and deletes every copied item 

#### 12.5. Swap Ranges
`OutputIterator swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2)`

interchange elements between the two collections

### 13. VALUE MODIFIERS
#### 13.1. Fill
`void fill(ForwardIt first, ForwardIt last, const T& value );`

Put the same value everywhere

#### 13.2. Generate
`void generate(ForwardIt first, ForwardIt last, Generator g);`

Uses `g` to generate a random number. `g` doesn't take any parameters

#### 13.3. Iota
`void iota(ForwardIt first, ForwardIt last, const T& value );`

It starts filling with value and add 1....

#### 13.4. Replace
`void replace(ForwardIt first, ForwardIt last, const T& old, const T& new);`

Changes every `old` value to `new`

### 14. STRUCTURE CHANGERS
#### 14.1. Unique
`ForwardIterator unique(ForwardIterator first, ForwardIterator last);`

`ForwardIterator unique(ForwardIterator first, ForwardIterator last, BinaryPredicate Pred);` 

This is a tricky one because it only works on **Vectors** so careful with that. It doesn't remove adjacent duplicates completely but it leaves undefined values at the end and send an iterator to the first one of them which we should delete later on using [Erase](#vector-erase) or [Resize](#vector-resize)

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

#### 14.2. Remove
`ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& val);`

This one is just like [Unique](#141-unique). But it removes the given `val` instead of duplicates.

### 15. _COPY
These algorithms do the same thing as the algorithms without `_copy` only that they put the results in a new collection and leave the original one untouched

[Unique](#141-unique): 

`OutputIterator unique_copy(InputIterator first, InputIterator last, OutputIterator result);`


[Remove](#142-remove):

`ResultIterator remove_copy(ForwardIterator first, ForwardIterator last, ResultIterator result ,const T& ele);`


[Rotate](#41-rotate):

`void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last, OutputIterator result);`


[Reverse](#42-reverse):

`void reverse(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result);`


[Partition](#31-partition): 

`pair<OutputIt1, OutputIt2> partition_copy(InputIt first, InputIt last, 
                                           OutputIt1 d_first_true, OutputIt2 d_first_false,
                                           UnaryPredicate p );`
 
 *Returns :* the size till *d_end_true* and *d_end_false*


[Partial Sort](#22-partial-sort): 

`RandomIt partial_sort_copy(InputIt first, InputIt last, RandomIt d_first, RandomIt d_last);` 

At most `d_last - d_first` elements


[Replace](#134-replace): 

`OutputIterator replace_copy (InputIterator first, InputIterator last,
                              OutputIterator result,
                              const T& old_value, const T& new_value);`
                              
*Returns :* An iterator pointing to the element that follows the last element written in the result sequence.

### 16. _IF
These functions take a predicate instead of value.

***16.1. find_if :*** [Find](#81-find)

***16.2. find_if_not :*** [Find](#81-find)

***16.3. count_if :*** [Count](#61-count)

***16.4. remove_if :*** [Remove](#142-remove)

***16.5. remove_copy_if :*** [Remove](#142-remove)

***16.6. replace_if :*** [Find](#134-replace)

***16.7. replace_copy_if :*** [Replace Copy](#134-replace)

***16.8. copy_if :*** [Copy](#121-copy)


### 17. THE LONELY ISLAND
#### 17.1. Transform
`OutputIterator transform (InputIterator first1, InputIterator last1, OutputIterator result, UnaryOperation op);`

It takes a function and applies it to every element of a collection and then returns the result in another collection

`OutputIterator transform (InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, OutputIterator result,
                             BinaryOperation binary_op);`

Or it could apply a function of two parameters to two collections. You could make [Inner Product](#68-inner-product) using this function. Easy Peasy Lemon Squeezy

#### 17.2. For Each
`OutputIterator for_each (InputIterator first, InputIterator last, Function fn);`

It perform ***SIDE EFFECTS*** so it doesn't matter what `fn` returns

### 18. RAW MEMORY
Think of these bad boys as if you're using ***`MALLOC`*** But in ***`CPP`*** we don't have malloc. We have 

#### 18.1. Uninitialized Fill
`void uninitialized_fill (ForwardIterator first, ForwardIterator last, const T& x);`

#### 18.2. Uninitialized Copy
`ForwardIterator uninitialized_copy ( InputIterator first, InputIterator last, ForwardIterator result );`

#### 18.3. Uninitialized Move
`ForwardIterator uninitialized_move ( InputIterator first, InputIterator last, ForwardIterator result );`

#### 18.4. Destroy
`ForwardIterator destroy ( InputIterator first, InputIterator last );`

#### 18.4. Example
```
// uninitialized_fill example
#include <iostream>
#include <memory>
#include <string>

int main () {
  // get block of uninitialized memory:
  std::pair <std::string*,std::ptrdiff_t>
    result = std::get_temporary_buffer<std::string>(3);

  if (result.second>0) {
    std::uninitialized_fill ( result.first, result.first+result.second, "c++ rocks!" );

    for (int i=0; i<result.second; i++)
      std::cout << result.first[i] << '\n';

    std::return_temporary_buffer(result.first);
  }
  return 0;
}
```

### 19. _N
These functions take a `first iterator` and `size` instead of `first and last iterator`.

***19.1. copy_n :*** [Copy](#121-copy)

***19.2. fill_n :*** [Fill](#131-fill)

***19.3. generate_n :*** [Generate](#132-generate)

***19.4. search_n :*** [Search](#91-search)

***19.5. for_each_n :*** [For Each](#172-for-each)

***19.6. uninitialized_copy_n :*** [Uninitialized Copy](#182-uninitialized-copy)

***19.7. uninitialized_fill_n :*** [Uninitialized Fill](#181-uninitialized-fill)

***19.8. uninitialized_move_n :*** [Uninitialized Move](#183-uninitialized-move)

***19.9. destroy_n :*** [Destroy](#184-destroy)

## EXECUTION POLICY
### 1. Sequenced Policy
`std::execution::sequenced_policy` OR  `std::execution::seq`

The execution policy type used as a unique type to disambiguate parallel algorithm overloading and require that a parallel algorithm's execution may not be parallelized. The invocations of element access functions in parallel algorithms invoked with this policy (usually specified as std::execution::seq) are indeterminately sequenced in the calling thread.

### 2. Policy
### 2. Policy
### 2. Policy