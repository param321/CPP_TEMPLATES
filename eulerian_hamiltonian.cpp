//Eulerian - all edges once

//undirected graph
The existence of Eulerian paths and circuits depends on the degrees of the nodes.
First, an undirected graph has an Eulerian path exactly when all the edges
belong to the same connected component and
• the degree of each node is even or
• the degree of exactly two nodes is odd, and the degree of all other nodes is
even.
In the first case, each Eulerian path is also an Eulerian circuit. In the second
case, the odd-degree nodes are the starting and ending nodes of an Eulerian path
which is not an Eulerian circuit.

//directed
In a directed graph, we focus on indegrees and outdegrees of the nodes. A
directed graph contains an Eulerian path exactly when all the edges belong to
the same connected component and
• in each node, the indegree equals the outdegree, or
• in one node, the indegree is one larger than the outdegree, in another node,
the outdegree is one larger than the indegree, and in all other nodes, the
indegree equals the outdegree.
In the first case, each Eulerian path is also an Eulerian circuit, and in the
second case, the graph contains an Eulerian path that begins at the node whose
outdegree is larger and ends at the node whose indegree is larger.

//Hierholzer’s algorithm to find eulerian path
Solution to(un-directed) : https://cses.fi/problemset/task/1691
(directed) : https://cses.fi/problemset/task/1693



//Hamiltonian - all vertices once

• Dirac’s theorem: If the degree of each node is at least n /2, the graph
contains a Hamiltonian path.
• Ore’s theorem: If the sum of degrees of each non-adjacent pair of nodes is
at least n , the graph contains a Hamiltonian path.
