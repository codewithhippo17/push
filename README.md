# Push_swap

A simple **stack-sorting algorithm** that moves numbers between stacks using a configurable *magic number* as a threshold.

---

## Overview

This repository implements an algorithm to **sort a list of integers** by moving nodes between two stacks based on a **single deciding value** the *magic number*.  

### How it works:

- Start with a **source stack** `A` containing integers.  
- The **target stack** `B` receives the integers in an efficient order.  
- A **magic number** determines which values are pushed to `B`.  
  - Small numbers are pushed towards the middle of `B`.  
  - Larger numbers are temporarily deferred and returned later, maintaining a partially ordered stack.  

The following diagram illustrates the process:  

<img width="505" height="320" alt="stack sorting illustration" src="https://github.com/user-attachments/assets/9ed8db1d-b9ed-4e6d-8754-9fed63c76189" />

**Default decision rule:**

- Push value `x` from `A` to `B` if `x <= MAGIC_NUMBER`  
- Otherwise, push `x` to an auxiliary stack `C`

> You can modify the comparison operator (`<=, <, >=, >, %`) or use a custom predicate to change the behavior. The *magic number* is the single parameter controlling the logic.

---

### Key Points

- The algorithm distributes small numbers towards the center of `B` and larger numbers farther away, facilitating an efficient sorting sequence.  
- The *magic number* can be adjusted to tune the sorting behavior.  
- Auxiliary stacks (`C`) can be used to temporarily store numbers that don’t meet the condition.  

---

This makes the algorithm **flexible, simple to understand, and easy to adapt** for different sorting strategies.

