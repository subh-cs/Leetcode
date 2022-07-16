Question was about finding cycle in a directed graph
* declare vis array as 0, which means unprocessed.
* vis is 1, currently node is processing.
* vis is 2, node has been processed and no cycle found.
* During dfs call, if encounter someone with vis 1, return false.(We visited this node before, in the current iteration)
* During dfs call, if vis is 2, we've already processed this node and no cycle found from him. return true.