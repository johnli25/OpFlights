# CS 225 Data Structures ~ Development Log

**Week of 4/18**
1) Finished function to read and convert data into array form.
2) Finished function to weight of edges.
3) Finished other misc functions (find airport given ID, etc.)
4) Finished filling in the airports' routes vector (with the source and destination Airport)
WEEKLY GOAL: We wanted to be able to read data from OpenFlights correctly and store airport and route data. 
We first needed to write a function to convert the data into array form. Successfully filled in airports' (now Graph) routes vector. Also wrote functions to assign/access weights of edges and other member variables of Graph. 

**Week of 4/25**
1) Finalized the structure for the edge list, adjacency list, and vector table.
2) Created priority queue class and created tests
3) Created foundation for A* search
WEEKLY GOAL: Begin writing priority queue and A* search functions.
We made some minor adjustments to the data structures which will remain consistent for the rest of the project. Includes making vector<Route*>routes a vector of pointers. Succeeded in working on the priority queue and created tests to begin debugging. Created a file for A* search based on pseudocode.

**Week of 5/2**
1) Foundations for Dijkstra
2) Foundations for BFS iterator
WEEKLY GOAL: Begin writing BFS and Dijkstra functions.
Created files for both functions and began working on each based on code from mp_traversals and pseudocode from lecture.
Succeeded in making a base for both functions. Continued work from last week as well: finalized priority queue and made changes to the A* Search function to match Dijkstra.

**Week of 5/9**
1) Finished main function
2) Finished Dijkstra
3) Finished BFS Iterator
4) Finished A*search
WEEKLY GOAL: COMPLETE PROJECT
Successfully completed all functions! Finished Dijkstra and A* functions and wrote tests to debug. Completed the BFS iterator and wrote tests to debug. Completed main function to run simple UI to input airports and choose which method to find airports with. 
