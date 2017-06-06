**The main aim of this repository is to act as a diary that notes small tricks picked up while solving problems in prepartion for ACM-ICPC.**

## 1) TALCA(CC)

[Link](https://www.codechef.com/problems/TALCA)

## Description
Problem Involved an unrooted tree and Q queries of the type LCA(r,u,v) where LCA is the Lowest Common Ancestor for nodes u and v when r is considered as the root

## Concepts-Implemented
1. LCA in O(1) using N*Log(N) precomputation
2. RMQ and LCA reductions
3. Euler Tour Tree

## Extra
LCA(r,u,v) is dependent on LCA(x,u,v), LCA(x,u,r), LCA(x,r,v) where x is a fixed node.
It can be further said that if all three are the same LCA is also the same else LCA is the odd one out from the three of them.

