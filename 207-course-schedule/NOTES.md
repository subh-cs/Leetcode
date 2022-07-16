Question was about finding cycle in a directed graph
* declare vis array as 0, which means unprocessed.
* vis is 1, currently node is processing.
* vis is 2, node has been processed and no cycle found.
* During dfs call, if encounter someone with vis 1, return false.(We visited this node before, in the current iteration)
* During dfs call, if vis is 2, we've already processed this node and no cycle found from him. return true.
**Solving using khan's algorithm**
1. take all node's indegree value
2. take all node's whose indegree equal to zero and push them into queue (as they are the leaders of the current graph(starting position of DAG)).
3. take out first node of the queue, process it... decrement one from his adjacent node's indegree array. as we're deleting the parent node....