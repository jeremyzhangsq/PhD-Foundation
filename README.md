# PhD-Foundation

## [Random Sampling: Reservoir Algorithm](PhD-Foundation/reservoir-random-sampling/)

### The original paper is in [link](https://www.cs.umd.edu/~samir/498/vitter.pdf).

### The source code of random sequence generator is in [generator.c](PhD-Foundation/reservoir-random-sampling/generator.c)

### The source code of implemented **algorithm R** is in [algorithm-r.cpp](PhD-Foundation/reservoir-random-sampling/algorithm-r.cpp)

### The note and analysis of algorithm R is in [note.pdf](PhD-Foundation/reservoir-random-sampling/Reservoir_Random_Sampling.pdf)

## [Disjoint Set Data Structure and MST](PhD-Foundation/minimum-spanning-tree/)

### The original material for Disjoint Set Data Structure is in [link](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-design-and-analysis-of-algorithms-spring-2012/lecture-notes/MIT6_046JS12_lec16.pdf)

### The original material for Minimum Spanning Tree is in [link](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-design-and-analysis-of-algorithms-spring-2012/lecture-notes/MIT6_046JS12_lec04.pdf)

### The source codes of implemented **Disjoint Set Data Structure** and **Kruskal's Algorithm** are in [kruskal.cpp](PhD-Foundation/minimum-spanning-tree/kruskal.cpp)

#### Disjoint Set Data Structure is implemented by **linked list** and ** tree**

### The source codes of implemented **Prim's Algorithm** are in [prim.cpp](PhD-Foundation/minimum-spanning-tree/prim.cpp)

### The notes and analysis of disjoint set data structure and Prim's and Kruskal's algorithms are in [note.pdf](PhD-Foundation/minimum-spanning-tree/Minimum_Spanning_Tree.pdf)

## [Frequent Item in Data Streaming](PhD-Foundation/frequent-item-in-stream/)

### The original survey paper is in [link](http://delivery.acm.org/10.1145/1460000/1454225/p1530-cormode.pdf?ip=137.132.216.137&id=1454225&acc=ACTIVE%20SERVICE&key=FF6731C4D3E3CFFF%2EBB5EB8D2067C1662%2E4D4702B0C3E38B35%2E4D4702B0C3E38B35&__acm__=1564969963_b64b1e518a3ff38bb9e3408fcbe4e199)

### In [function.cpp](PhD-Foundation/frequent-item-in-stream/function.cpp), the following algorithms are implemented:

#### 1. Majority Voting Algorithm

#### 2. Count-based Algorithm:

(a). **[Frequent Count Algorithm](PhD-Foundation/frequent-item-in-stream/paper/frequent)** implemented by group linked list `FrequentbyList()` and hash table `FrequentbyMap()`.

(b). **[Loosy Count Algorithm](PhD-Foundation/frequent-item-in-stream/paper/loosy)** implemented in `Loosy()`.

(c). **[Space Saving Count Algorithm](PhD-Foundation/frequent-item-in-stream/paper/spacesaving)** implemented by group linked list `SpaceSavingbyList()` and heap `SpaceSavingbyHeap()`.

#### 3. Quantile-based Algorithm
(a). **[GK Algorithm](PhD-Foundation/frequent-item-in-stream/paper/gk)** implemented in `GK()` and the [note](http://www.mathcs.emory.edu/~cheung/Courses/584-StreamDB/Syllabus/08-Quantile/Greenwald.html#proofprop1) helps a lot.

#### 4. Sketch-based Algorithm
(a). **[Count Sketch Algorithm](PhD-Foundation/frequent-item-in-stream/paper/countsketch)** implemented in `CountSketch()`

(b). **[Count Min Sketch Algorithm](PhD-Foundation/frequent-item-in-stream/paper/countminsketch)** implemented in `CountSketch()`

### Function [prng.cpp](PhD-Foundation/frequent-item-in-stream/prng.cpp) is a probabilistic random number generator, which is refered from the [code bank](https://www.cs.rutgers.edu/~muthu/massdal-code-index.html).




