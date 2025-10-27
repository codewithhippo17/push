# Push_swap

A simple **stack-sorting algorithm** that decides whether a number is pushed from one stack to another using a configurable *magic number* (threshold).

---
## Overview

This repository contains an implementation of an algorithm that sort a list by moving nodes between tow stacks based on a **single deciding value** the *magic number*.  

### How it works:

- Start with a **source stack** `A` containing integers.  
- Have a **target stack** `B` that receives some of those integers.  
- Use a **magic number** as a configurable threshold to decide which values get pushed to `B`.


**Default decision rule:**

- Push value `x` from `A` to `B` if `x <= MAGIC_NUMBER`  
- Otherwise, push `x` to an auxiliary stack `C`

> You can modify the comparison operator (`<=, <, >=, >, %`) or replace it with any predicate to change the behavior. The *magic number* is the single parameter controlling the logic.

---
