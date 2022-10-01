# Parallel Computing

Postorder, preorder traversals are implemented in parallel using openmp.

## Instructions to Run

For postorder traversal,

```
$ make postorder
```

For preorder traversal,

```
$ make preorder
```

For vertex level,

```
$ make vertex_level
```

## Notes

- The time complexity of taking inputs and printing results is not considered for the total time complexity. The algorithms each take **O(logn)** time.
- The input is currently hard-coded.
- Hashing has been used in a few places for ease of implementation without loss of program correctness.
- Euler tour is generated and printed in each of the traversals. There is no separate command to invoke Euler tour.

## Screenshots

![postorder](https://user-images.githubusercontent.com/58718144/193327702-8d424bae-4fea-4ce4-9702-673c7996d9b5.png)

![preorder](https://user-images.githubusercontent.com/58718144/193327801-c17923bf-09e3-4ae4-bee5-f4dad8981621.png)

![vertex_level](https://user-images.githubusercontent.com/58718144/193327870-d7dd928b-1df3-416a-941f-4452c310141e.png)
