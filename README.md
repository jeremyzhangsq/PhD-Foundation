# PhD-Foundation

## [Random Sampling: Reservoir Algorithm](PhD-Foundation/reservoir-random-sampling/)

- The original paper is in [link](https://www.cs.umd.edu/~samir/498/vitter.pdf).

- The source code of random sequence generator is in [generator.c](PhD-Foundation/reservoir-random-sampling/generator.c)

- The source code of implemented **algorithm R** is in [algorithm-r.cpp](PhD-Foundation/reservoir-random-sampling/algorithm-r.cpp)

- The note and analysis of algorithm R is in [note.pdf](PhD-Foundation/reservoir-random-sampling/Reservoir_Random_Sampling.pdf)


## [Disjoint Set Data Structure and MST](PhD-Foundation/minimum-spanning-tree/)

- The original material for Disjoint Set Data Structure is in [link](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-design-and-analysis-of-algorithms-spring-2012/lecture-notes/MIT6_046JS12_lec16.pdf)

- The original material for Minimum Spanning Tree is in [link](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-design-and-analysis-of-algorithms-spring-2012/lecture-notes/MIT6_046JS12_lec04.pdf)

- The source codes of implemented **Disjoint Set Data Structure** and **Kruskal's Algorithm** are in [kruskal.cpp](PhD-Foundation/minimum-spanning-tree/kruskal.cpp) and Disjoint Set Data Structure is implemented by **linked list** and **tree**.

- The source codes of implemented **Prim's Algorithm** are in [prim.cpp](PhD-Foundation/minimum-spanning-tree/prim.cpp)

- The notes and analysis of disjoint set data structure and Prim's and Kruskal's algorithms are in [note.pdf](PhD-Foundation/minimum-spanning-tree/Minimum_Spanning_Tree.pdf)


## [Frequent Item in Data Streaming](PhD-Foundation/frequent-item-in-stream/)

- The original survey paper is in [link](https://dl.acm.org/citation.cfm?id=1454225)

- In [function.cpp](PhD-Foundation/frequent-item-in-stream/function.cpp), the following algorithms are implemented:

	1. Majority Voting Algorithm
	2. Count-based Algorithm:

		- **[Frequent Count Algorithm](https://github.com/jeremyzhangsq/PhD-Foundation/blob/master/PhD-Foundation/frequent-item-in-stream/paper/frequent.pdf)** implemented by group linked list `FrequentbyList()` and hash table `FrequentbyMap()`.

		- **[Loosy Count Algorithm](https://github.com/jeremyzhangsq/PhD-Foundation/blob/master/PhD-Foundation/frequent-item-in-stream/paper/loosy.pdf)** implemented in `Loosy()`.

		- **[Space Saving Count Algorithm](https://github.com/jeremyzhangsq/PhD-Foundation/blob/master/PhD-Foundation/frequent-item-in-stream/paper/spacesaving.pdf)** implemented by group linked list `SpaceSavingbyList()` and heap `SpaceSavingbyHeap()`.

	3. Quantile-based Algorithm
		- **[GK Algorithm](https://github.com/jeremyzhangsq/PhD-Foundation/blob/master/PhD-Foundation/frequent-item-in-stream/paper/gk.pdf)** implemented in `GK()` and the [note](http://www.mathcs.emory.edu/~cheung/Courses/584-StreamDB/Syllabus/08-Quantile/Greenwald.html#proofprop1) helps a lot.

	4. Sketch-based Algorithm
		- **[Count Sketch Algorithm](https://github.com/jeremyzhangsq/PhD-Foundation/blob/master/PhD-Foundation/frequent-item-in-stream/paper/countsketch.pdf)** implemented in `CountSketch()`

		- **[Count Min Sketch Algorithm](https://github.com/jeremyzhangsq/PhD-Foundation/blob/master/PhD-Foundation/frequent-item-in-stream/paper/countminsketch.pdf)** implemented in `CountSketch()`

- Function [prng.cpp](PhD-Foundation/frequent-item-in-stream/prng.cpp) is a probabilistic random number generator, which is refered from the [code bank](https://www.cs.rutgers.edu/~muthu/massdal-code-index.html).





