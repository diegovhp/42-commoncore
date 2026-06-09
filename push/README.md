*This project has been created as part of the 42 curriculum by divan-he, nwatelle.*

---

## Description

**Push_swap** is a sorting algorithm project from the 42 curriculum. Given a stack of integers as arguments, the program outputs the shortest possible sequence of operations to sort the stack in ascending order.

The constraint that makes it interesting: you only have two stacks — **A** (input) and **B** (auxiliary) — and a fixed set of operations to work with. No direct swaps of arbitrary indices, no random access. Finding an efficient sequence demands careful algorithm design and, in this implementation, an adaptive strategy that picks the best algorithm based on how disordered the input actually is.

The project is split across two contributors: **nwatelle** handled parsing, stack operations, and benchmarking; **divan-he** designed and implemented the sorting algorithms.

---

## Instructions

### Compilation

Clone the repository and run `make` inside the `push/` directory:

```bash
make
```

This produces the `push_swap` executable at the root of the directory.

### Available Makefile rules

| Rule | Effect |
|---|---|
| `make` / `make all` | Compile all sources into `push_swap` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and `push_swap` |
| `make re` | Full rebuild (`fclean` + `all`) |

### Execution

Pass the integers to sort as command-line arguments:

```bash
./push_swap 3 2 1 0
```

The program prints the sequence of operations to stdout, one per line.

#### Algorithm flags

| Flag | Effect |
|---|---|
| *(none)* | Adaptive selection (default) |
| `--adaptive` | Explicit adaptive mode |
| `--simple` | Force simple algorithm (best for nearly-sorted input) |
| `--medium` | Force medium algorithm |
| `--complex` | Force complex algorithm (best for large random input) |
| `--bench` | Print performance metrics after sorting |

```bash
./push_swap --bench 5 3 8 1 4
./push_swap --complex $(shuf -i 1-500 | tr '\n' ' ')
```

### Checker (bonus)

A checker binary is provided in `bonus/`. Pipe `push_swap` output into it to verify correctness:

```bash
./push_swap 3 2 1 0 | ./bonus/checker 3 2 1 0
```

The checker outputs `OK` if the sequence correctly sorts the input, `KO` otherwise.

---

## Algorithms

### Allowed operations

Both stacks are doubly-linked lists. The allowed operations are:

| Operation | Effect |
|---|---|
| `sa` | Swap the top two elements of A |
| `sb` | Swap the top two elements of B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Move the top of B to the top of A |
| `pb` | Move the top of A to the top of B |
| `ra` | Rotate A: top element goes to the bottom |
| `rb` | Rotate B: top element goes to the bottom |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A: bottom element comes to the top |
| `rrb` | Reverse rotate B: bottom element comes to the top |
| `rrr` | `rra` and `rrb` simultaneously |

### Data structures

The project models each stack as a doubly-linked list so that rotation operations are O(1):

```c
typedef struct s_node {
    int             value;   // original input value
    int             index;   // rank: 0 = smallest, n-1 = largest
    struct s_node   *next;   // towards the bottom
    struct s_node   *prev;   // towards the top
}   t_node;

typedef struct s_stack {
    t_node  *top;
    int     size;
}   t_stack;
```

Before sorting, every value is replaced by its **rank** (index 0 for the smallest element, n-1 for the largest). This normalises the input so algorithms work on a clean range regardless of the actual integers, and prevents overflow issues in cost calculations.

### Disorder metric

Before choosing an algorithm, the program measures how unsorted the input is:

```
disorder = (inversion_pairs * 10000) / total_pairs
```

An **inversion pair** is any pair `(i, j)` where `i < j` but `value[i] > value[j]`. The result is a value between 0 (already sorted) and 10000 (perfectly reversed), scaled to a 0–10000 range. This metric guides the adaptive algorithm selector.

### Base cases

**sort_two** — single comparison, one swap if needed.

**sort_three** — all six orderings of three elements are resolved in at most two operations using a combination of rotations and swaps.

**sort_five** — push the two smallest elements to B, sort the remaining three in A with `sort_three`, then push both back.

### sort_simple — O(n²)

Triggered when disorder < 2000.

1. Push everything except three elements from A to B.
2. Sort the three remaining elements in A with `sort_three`.
3. Pull elements back from B one by one: for each top element of B, rotate A to its target position, then push.
4. Rotate A so the minimum ends up on top.

This is fast for nearly-sorted inputs because few elements need to be moved in step 3, but it degrades quickly as disorder grows because the pull phase does no cost optimisation — it only ever looks at the top of B.

### sort_medium — O(n√n)

Triggered when disorder is between 2000 and 4999.

1. **Push phase with chunking:** Divide elements into chunks of size ⌊√n⌋ by rank. Push elements belonging to the current chunk to B. When a chunk is full, move to the next. Elements within each chunk arrive in B in roughly ascending order.
2. Sort remaining three in A.
3. **Cost-optimised pull:** For every element in B, compute the cheapest way to bring it to the top of B *and* rotate A to its target insertion position simultaneously. The best candidate (lowest total rotation cost) is pulled first. Combined `rr`/`rrr` moves are used whenever both stacks need to rotate in the same direction.
4. Rotate A so the minimum is on top.

The chunk push gives B a useful structure that the cost-aware pull can exploit. The pull still only looks at elements individually though — no lookahead beyond choosing the single best element at each step.

### sort_complex — O(n log n) in practice

Triggered when disorder ≥ 5000, or when forced with `--complex`. The default chunk sizes are tuned for the 42 benchmark targets:

| Input size | Chunk size |
|---|---|
| ≤ 100 | 43 |
| > 100 | 215 |

1. **Push phase:** Same chunk-based strategy as `sort_medium`, but with fixed chunk sizes chosen to minimise total operations for typical random inputs at 100 and 500 elements.
2. Sort remaining three in A.
3. **Greedy pull (`pull_greedy`):** Scan *every* position in B, not just the top. For each element, calculate the rotation cost needed to bring it to the top of B combined with the rotation cost to bring A to the correct insertion point. Pick the globally cheapest element, apply the optimal combination of `rr`/`rrr`/individual rotations, then push. Repeat until B is empty.
4. Rotate A so the minimum is on top.

The greedy full-scan in step 3 is what separates `sort_complex` from `sort_medium`. Rather than committing to whatever happens to sit at the top of B, it evaluates all candidates and picks the one that minimises total moves. The `calc_rot` helper considers four rotation strategies for every candidate and returns the minimum:

| Strategy | When beneficial |
|---|---|
| Both stacks rotate forward (`rr`) | Target positions both need downward rotation |
| Both stacks reverse rotate (`rrr`) | Target positions both need upward rotation |
| A forward, B backward | Positions require opposite directions |
| A backward, B forward | Positions require opposite directions |

### sort_adaptive — dynamic selection

The default mode. After computing the disorder score, it selects:

| Disorder range | Algorithm |
|---|---|
| 0 – 1999 | `sort_simple` |
| 2000 – 4999 | `sort_medium` |
| 5000 – 10000 | `sort_complex` |

This avoids paying the overhead of a full greedy scan on inputs that are already close to sorted, while still handling large random inputs efficiently.

---

## Resources

### References

- *Introduction to Algorithms* (CLRS) — sorting theory and complexity analysis
- *The Algorithm Design Manual* (Skiena) — greedy strategies and heuristic design
- Wikipedia — [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm), [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))
- `man` pages — standard C library reference

### AI usage

Claude was used during this project for:

- **Generating this README** — content was defined by the authors; Claude handled formatting and prose.
- **Explaining theoretical concepts** — clarifying how doubly-linked lists and stacks work at a memory level, inversion-pair counting as a disorder measure, and the mathematical basis of the disorder metric.
- **Generating random test inputs** — producing varied integer lists of different sizes and disorder levels to stress-test the algorithms during development.

Overall, AI assistance was focused on theory clarification and documentation; the algorithm design, implementation, and debugging were done by the authors.
