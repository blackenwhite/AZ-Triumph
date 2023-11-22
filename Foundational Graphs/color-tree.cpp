/*
Description

You have been given a tree with N nodes and N - 1 edges. You want to colour each node, such that no two adjacent nodes (directly connected by an edge) and no two nearly-adjacent nodes (both directly connected to a common node with edges) has the same colour. 
Your task is to find the minimum number of colours required to accomplished this. 


Input Format

The first line of input contains N. Each of the remaining N−1 lines describes an edge in terms of the two nodes it connects.


Output Format

Print the minimum number of colours require.

This problem asks us to colour the vertices of a tree with the minimum number of colours, such that no two nodes of the same colour are adjacent or separated by only two edges. So if some node has d neighbours, then all d neighbours of the node, as well as the node itself, must receive pairwise distinct colours. Hence, if the maximum degree in the tree is D, then we need at least D + 1 colours

This problem asks us to colour the vertices of a tree with the minimum number of colours, such that no two nodes of the same colour are adjacent or separated by only two edges. So if some node has d neighbours, then all d neighbours of the node, as well as the node itself, must receive pairwise distinct colours. Hence, if the maximum degree in the tree is D, then we need at least D + 1 colours.

It turns out that D+1 colours are always sufficient; in fact, we'll show how to construct a valid (D+1)-colouring. Root the tree at an arbitrary vertex, and assign it colour 1. The root has at most D children, so they can be assigned distinct colours in {2,…,D+1}. Now we have at most D child subtrees, with the root of each subtree coloured. Every node which has not been coloured has distance 3 or more from any node in a different subtree, so we can colour the subtrees independently.

Pick a child c of the root, and suppose that it has colour i≠1. There are at most D−1 children of c, so they can be assigned distinct colours in {2,…,i−1,i+1,…,D+1}. Once again, the at most D−1 subtrees can now be coloured independently.

This process continues until the tree is completely coloured. In general, any non-root node u has at most D−1 children, which can be assigned distinct colours in {1,…,D+1} which avoid the colour of u, and the colour of u's parent. This ensures that the colouring condition is satisfied: among any two adjacent nodes, one is a child of the other, and the child is assigned a different colour from the parent. For any two nodes separated by at most two edges, there are two cases. If the nodes are siblings, then they are assigned distinct colours simultaneously. Otherwise, one node is the grand-child of the other, and so avoids the colour of its grandparent.

Thus, the final algorithm is quite simple: compute the degree of every node, find the maximum, and add one.
*/

#include <iostream>
using namespace std;

int N,a,b;
int d[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1;i<N;i++)
    {
        cin >> a >> b;
        d[a-1]++, d[b-1]++;
    }
    int D = 0;
    for(int i=0;i<N;i++)
        if(d[i] > D)
            D = d[i];
    cout << D+1 << '\n';
}
