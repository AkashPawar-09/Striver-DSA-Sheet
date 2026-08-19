# Queue — Basics to Implementation (C++)

## 1. What is a Queue

A queue is a linear data structure following **FIFO** (First In, First Out) — the first element added is the first removed. Think of a line at a ticket counter: people join at the back and get served from the front.

**Core operations (all O(1)):**
- `push(x)` / `enqueue(x)` — insert x at the rear
- `pop()` / `dequeue()` — remove and return front element
- `front()` — return front element without removing
- `back()` — return rear element without removing
- `isEmpty()` — check if queue has no elements
- `size()` — number of elements

## 2. Real World Examples / Use Cases

| Use case | Why queue fits |
|---|---|
| Ticket counter / customer line | First person in line served first |
| CPU / process scheduling (Round Robin) | Processes served in the order they arrived |
| Printer / print job queue | Jobs printed in the order submitted |
| BFS (Breadth-First Search) in graphs/trees | Explores level by level using FIFO order |
| Web server request handling | Requests processed in arrival order |
| IO buffers (keyboard buffer, message queues) | Data consumed in the order it was produced |
| Call center systems | First caller in line gets served first |

## 3. Important Points (imp's)

- **Queue Overflow**: pushing onto a full fixed-size queue (array-based, non-circular).
- **Queue Underflow**: popping from an empty queue — always guard against this.
- **Naive array queue problem**: `front` keeps moving forward on every dequeue, wasting slots at the start of the array even though they're free — solved by a **Circular Queue** (wrap `front`/`rear` using `% capacity`).
- **Array vs Linked List implementation**:
  - Array (circular): fixed/resizable capacity, contiguous memory, cache-friendly, O(1) ops.
  - Linked List: dynamic size, no overflow (until memory runs out), extra pointer overhead per node.
- **C++ STL**: `std::queue<T>` is a container *adapter* — by default built on `std::deque` (can swap underlying container to `list`).
- **Variants**:
  - **Circular Queue** — reuses freed space, avoids the naive-array wastage problem.
  - **Deque (Double-Ended Queue)** — insertion/deletion allowed at both ends.
  - **Priority Queue** — elements dequeued based on priority, not arrival order (usually implemented with a heap).
- **Auxiliary structure pattern**: classic problems like Queue using Stacks, or Circular Tour / Sliding Window Maximum, rely on maintaining a second stack/deque alongside the main queue.
- BFS traversal is the textbook proof of why queue = FIFO matters — it's what guarantees level-by-level exploration.

---

### Queue Functions
 
| Function | What it does | Returns | Time |
|---|---|---|---|
| `push(x)` / `enqueue(x)` | Insert `x` at the rear | void | O(1) |
| `pop()` / `dequeue()` | Remove the front element | void (in STL) | O(1) |
| `front()` | View front element without removing | front element | O(1) |
| `back()` | View rear element without removing | rear element | O(1) |
| `empty()` | Check if queue has zero elements | bool | O(1) |
| `size()` | Number of elements currently in queue | int | O(1) |

---

