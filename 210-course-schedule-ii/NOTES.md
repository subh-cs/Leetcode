The idea is similar to course schedule problem.
1. first create the adj list
2. check for cycle, if present return an empty array
3. if cycle is not present, congo! we've have a DAG.
4. Now, to find ordering, apply topological sorting
** Hurrah!**