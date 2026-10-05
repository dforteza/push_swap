*This project was created as part of the 42 curriculum by difortez, bedo-car*

# push_swap
Milestone 1, October 2026

## Description

This project presents a hybrid sorting engine combining specialized integer-sorting algorithms, specifically designed for a constrained dual-stack environment and optimized as to minimize the total of basic operations needed and its overall computational complexity.

In this sense, it's worth noting that the challenge set forth by the subject imposes two strict hardware-like constraints:
1. **Dual-stack environment** enforcing sequential boundary access over conventional random-access architectures. 
2. **Strict permutation cost model** as the function shall not be evaluated on its time complexity, but exclusively in the total count of emitted instructions.

Conforming to the following operations:
1. *Swap* `sa` / `sb` / `ss`: swaps the first two elements at the top of stack `A`, stack `B`, or both simultaneously.
2. *Push*  `pa` / `pb`: takes the top element from one stack and pushes it onto the other.
3. *Rotate* `ra` / `rb` / `rr`: shifts all elements of a stack up by 1 so that the first element becomes the last.
4. *Reverse Rotate* `rra` / `rrb` / `rrr`: shifts all elements of a stack down by 1 so that the last element becomes the first.

That is why, although at first glance it may look like a simple sorting challenge, **push_swap** embodies a discrete optimization and compiler-like instruction generation problem. Resulting in an algorithmic engine that operates on an abstract two-stack machine with severe physical constraints. To be evaluated on its capacity to calculate, emit and optimize the shortest possible sequence of machine-like atomic instructions developed to sort the data.

## Architecture
The project responds to five interrelated layers that correspond to the process of treating and sorting the dataset according to the above-mentioned set of instructions. 

**1. Command Line Interface (CLI) & Input Validation**

Responsible for parsing the input so that the project supports both single-string multi-argument commands and space-separated lists, attests command-line flags, intercepts integer overflows and detects possible duplicates. 

**2. Data abstraction**

Normalizes the arbitrary numeric values submitted via command line into an index $[0, n - 1]$ that neutralizes negative numbers and establishes a uniform pattern for interval matching algorithms. And, moreover, measures the disorder of the dataset in line with its inversion ratio. That is, by accounting (pair by pair) for the existence of inversions regarding the expected ascending order of the indexes and calculating its pertinence to the set (the total of pairs).

**3. Steering**

Pursues the best method to organize the indexed dataset based on its size and level of disorder, enabling a sorting algorithm chosen to perform better under each specific set of conditions.

**4. Algorithmic Engines**

* `small_sort`: hard-coded trivial cases. Sorts up to five elements evaluating the permutation topology of the set and aiming to isolate the maximum index in the bottom of the stack (`sort_three`), isolating the minimum indexes when needed (`sort_four`, `sort_five`).
* `selection_sort`: repeatedly selects the minimum index of the unordered stack to compose an assistant stack of descending order, so as to return its elements in ascending order to the original one. 
* `chunk_sort`: repeatedly traverses the stack splitting the elements into dynamic segments of the index whose size nearly correspond to their total's square root. In this sense, if an element fits within the current range, it is grouped on the assistant stack. Otherwise it is rotated and stays on the original stack. Once all segments have been moved, the maximum index will be reiteratively reinserted in the original stack. 
* `quicksort`: partitions the stack using an already allocated set of pivots, chosen to improve the algorithm's performance and recursively organize the surrounding values until reaching the sorted base case.
* `insertion_sort`: taking the small ratio of disorder, repeatedly isolates inverted elements from the original stack in order to re-insert them taking the maximum index of the assistant stack. 

**5. Basic Operations**

Emulate the fundamental operations behind the previously mentioned algorithms, ensuring the memory is seamlessly managed and the structures that enable the project's workings and return values are properly handled.

### Workload disclosure

*difortez* was in charge of command line interface, input validation, data abstraction and steering, while *bedo-car* carried out the basic operations. Both of us contributed to the development of the sorting algorithms. *difortez* implemented `selection_sort`, `chunk_sort` and `quick_sort`, while *bedo-car* implemented `small_sort` and `insertion_sort`.

## Sorting Algorithms & Complexity
Given the problem's restrictions, conventional sorting algorithms are rendered useless. Random-access memory models are verboten and no arbitrary indexing is allowed, all movements directly implicate the evaluation criteria and the dual-stack environment entangles possibly destructive reinsertions. That is why **push_swap** requires adapting classical algorithms into chunking, coordinate compression, and sliding-window heuristics that cluster data and minimize rotational distance. And this section addresses the structural decisions behind the previous architecture, making sure to highlight the overall complexity they ascribe to the project and justify their precedence over the available alternatives. Considering the engine integrates a flexible strategy selector and a built-in diagnostic profiler (`--bench`) that measures execution metrics without interfering with pipeline validation. 

`--simple`: **Selection Sort**

Selection sort stands out among other algorithms of $O(n^2)$ complexity given its reduced operation cost, in reference to its memory write complexity and its close relationship with the nature of this assignment. In this sense, although algorithms such as Insertion Sort and Bubble Sort share its asymptotic time complexity and may perform better regarding its number of comparisons, Selection Sort better satisfies the assessment criteria. 

Even so, we acknowledge the adaptability of Insertion Sort mechanisms hand in hand with its adequacy to partially ordered datasets. That is why it is the preferred method to handle a small level of disorder in our adaptive strategy.

`--medium`: **Chunk Sort**

Chunk Sort is prominent when it comes to restrictive contexts due to its adaptability and simplicity. Outshining algorithms like Shell Sort, on account of its premise of arbitrary memory access, and Bucket Sort, considering the intricate structures needed to implement its underlying mechanism and their resulting memory load, whilst evidencing the works of its complexity. 

Moreover, Chunk Sort opens space for optimizations like the bi-directional decision window implemented through `move_to_top` in order to reduce the constant factor of unidirectional searches. Hand in hand with its grouping mechanism, that disregards the need to loop over the assistant stack searching for the element to be displaced, making it preferable to an optimized version of our simple algorithm.

`--complex`: **Quicksort**

Quicksort stands out among other algorithms of $O(n \log n)$ complexity due to its *Divide and Conquer* nature and adaptability towards the project's restrictions. Overcoming comparison-based approaches like Merge Sort or Heap Sort on account of the temporary structures and subsequent memory required, entailing extra rotations or random insertion movements verboten by the subject. As well as non-comparison based approaches like Radix Sort, our initial choice, taking the rigidity of its operations against the shortcut brought about by Quicksort's pivots.

Furthermore, it is worth noting that the present implementation enhances the algorithm's advantages on a dual-stack environment by treating both stacks as two-sided buffers thanks to a dual-pivot recursive model that processes each block and leaves it sorted in ascending order on top of stack `a` once it reaches a trivial base case. In this sense, instead of seeking random access, it divides the problem into $O(\log_3 n)$ recursion layers where each item is streamed directly to its proper zone and permanently locked into place, minimizing the amount of operations needed. 

`--adaptive`: **Insertion Sort and the handling of trivial cases**

This project's adaptive strategy aims to adapt the above-mentioned algorithms to features that may condition the performance of a dataset. Most noticeably its size and level of disorder. That is why it separately handles cases of up to five elements and adopts an optimized Insertion Sort algorithm to nearly ordered cases. 

Applying, on the one hand, basic logics into hard-coding trivial sorting schemes. Reaching an $O(1)$ complexity of maximum 10 operations. And, on the other hand, an elementary adaptation of Python's Tim Sort reasoning. As to uncover the previously ordered elements of the stack and efficiently reinsert those isolated in the assistant one. Its cost is $O(n \cdot k)$, where $k$ is the number of elements isolated in the assistant stack, which stays small given the low level of disorder.

### Adaptive thresholds

The default strategy measures the disorder $d$ of the input (inverted pairs divided by the $n(n-1)/2$ possible pairs) and chooses:

* $d < 0.2$ → **Insertion Sort**. With few inversions, most elements already form an ascending run, so only the few that break it are moved to `b` and reinserted.
* $d \geq 0.2$ → **Quicksort**.

The subject sets $0.2$ and $0.5$ as the limits between low, medium and high disorder, and asks for at most $O(n\sqrt{n})$ in the medium band. Those limits are upper bounds, and since $O(n \log n) \subseteq O(n\sqrt{n})$, Quicksort meets the medium requirement as well as the high one. We measured both engines across the $0.2$–$0.5$ band and Quicksort used fewer operations in every case. Therefore we actively chose to maintain Quicksort as the preferred sorting algorithm in both the $0.2$–$0.5$ and $\geq 0.5$ bands.

Chunk Sort remains available through `--medium`.

### Complexity bounds

Time is measured as the number of emitted operations, as the subject requires. Space is the extra memory used besides the input.

* `small_sort` (2–5 numbers): time $O(1)$, at most 10 operations for 5 numbers (checked on all 120 permutations); space $O(1)$.
* Insertion Sort (adaptive, $d < 0.2$): time $O(n \cdot k)$, with $k$ the number of elements moved to `b`; space $O(1)$.
* `--simple`, Selection Sort: time at most $n^2/4 + 2n$ → $O(n^2)$; space $O(1)$.
* `--medium`, Chunk Sort: time at most $2n\sqrt{n}$ ($\sqrt{n}$ blocks of at most $n$ moves to `b`, then $n$ elements brought back with at most $\sqrt{n}$ rotations each) → $O(n\sqrt{n})$; space $O(1)$.
* `--complex`, Quicksort: time at most $3n \log_3 n$ (each of the $\log_3 n$ recursion levels moves every element once, with at most 3 operations) → $O(n \log n)$; space $O(\log n)$ for the recursion.
* In every strategy, both stacks together always hold the same $n$ nodes, because elements are moved between them and never copied, so the stacks use $O(n)$ memory.

### Benchmark
The `--bench` flag enables an execution audit report delivered strictly via `stderr`. This channel separation ensures compatibility with external tools and highlights the required analytical metrics, while the benchmark presents itself as a tool embedded in the code to record performance data about the sorting process. That is why it is meant to assist the evaluation of the algorithmic complexity of the project, evidencing its diagnostics according to:

1. *Disorder index*, where `0.00` represents an already sorted sequence and `100.00` indicates a completely unordered, inversely ordered one. 
2. *Chosen strategy* identifies the executed strategy alongside its theoretical complexity class.
3. *Total operation count* as the aggregate sum of all stack manipulation operations.
4. *Operations breakdown*, that is, the explicit mark for each individual primitive stack operation.

## Instructions

This project uses a standard `Makefile` configured with the mandatory 42 compilation flags (`-Wall -Wextra -Werror`). In this sense:
* `make` compiles the project's binary.
* `make clean` erases previously created object files.
* `make fclean` erases not only object files, but also the compiled binary. 
* `make re` erases previously created files and compiles all source files once again.

And you can run the program passing a list of integers either as separate arguments or inside a quoted string, optionally indicating which strategy to run or the benchmark flag. No arguments or the benchmark flag alone shall lead to a silent exit. While any non-integer value, integer overflow or duplicate value shall trigger the error exit. 

```bash
make
./push_swap 3 2 5 1 4                  # adaptive strategy (default)
./push_swap "3 2 5 1 4"                # same input as a single string
./push_swap --complex 3 2 5 1 4        # force a strategy: --simple, --medium, --complex, --adaptive
./push_swap --bench 3 2 5 1 4          # operations on stdout, report on stderr
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker_linux $ARG   # prints OK if the stack ends sorted
```

## Resources
Traditional, digital and collaborative resources were employed in order to ensure the quality of this work and the background knowledge its implementation demands. Most notably:

* Charte Ojeda, F. (2022). *Introducción a la programación*. Madrid: Anaya.

* Geeks for Geeks (2026). *Sorting Algorithms*. Available at: https://www.geeksforgeeks.org/dsa/sorting-algorithms/. 

* MIT OpenCourseWare (2011). *Introduction to algorithms*, 6.006 Fall 2011. Available at: https://www.youtube.com/playlist?list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb.

* MIT OpenCourseWare (2010). *Mathematics for computer science*, 6.042J. Available at: https://www.youtube.com/playlist?list=PLB7540DEDD482705B.

* Polya, G. (1990). *How to solve it*. Princeton: Princeton University Press.

### Disclosure on the use of AI

AI was used as a tutor to understand the underlying concepts and as an assistant to evaluate candidate sorting algorithms and choose the ones best suited to the subject's requirements. It also helped debug and refactor parts of the code, all of which we reviewed and can explain.
