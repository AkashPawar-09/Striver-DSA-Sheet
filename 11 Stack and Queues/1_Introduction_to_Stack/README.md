# Stack — Basics to Implementation (C++)

## 1. What is a Stack

A stack is a linear data structure following **LIFO** (Last In, First Out) — the last element added is the first removed. Think of a stack of plates: you add/remove from the top only.

**Core operations (all O(1)):**
- `push(x)` — insert x on top
- `pop()` — remove and return top element
- `top()` / `peek()` — return top element without removing
- `isEmpty()` — check if stack has no elements
- `size()` — number of elements

## 2. Real World Examples / Use Cases

| Use case | Why stack fits |
|---|---|
| Browser back button | Each visited page pushed; back = pop |
| Undo/Redo in editors | Each action pushed; undo = pop |
| Function call stack (recursion) | Each call pushed with its local state; return = pop |
| Expression evaluation (infix→postfix, postfix eval) | Operators/operands need LIFO ordering |
| Balanced brackets / syntax parsing (compilers) | Matching nested structures needs LIFO |
| DFS / backtracking (maze solving, N-Queens) | Explore path, push state; backtrack = pop |
| Ctrl+Z style command history | Same as undo/redo |

## 3. Important Points (imp's)

- **Stack Overflow**: pushing onto a full fixed-size stack (array-based).
- **Stack Underflow**: popping from an empty stack — always guard against this.
- **Array vs Linked List implementation**:
  - Array: fixed/resizable capacity, contiguous memory, cache-friendly, O(1) ops but may need resizing.
  - Linked List: dynamic size, no overflow (until memory runs out), extra pointer overhead per node.
- **C++ STL**: `std::stack<T>` is a container *adapter* — by default built on `std::deque` (can swap underlying container to `vector` or `list`).
- Recursion **implicitly** uses the system call stack — deep recursion can cause a real stack overflow.
- **Auxiliary stack pattern**: many problems (Min Stack, Sort a Stack, Queue using Stacks) solve themselves by keeping a second stack alongside the main one.
- Reversing a string/array is a classic O(n) stack use.

---

### Stack Functions
 
| Function | What it does | Returns | Time |
|---|---|---|---|
| `push(x)` | Insert `x` on top | void | O(1) |
| `pop()` | Remove the top element | void (in STL) | O(1) |
| `top()` | View top element without removing | top element | O(1) |
| `empty()` | Check if stack has zero elements | bool | O(1) |
| `size()` | Number of elements currently in stack | int | O(1) |

---


