# CS225 Project bthuma2-johnwl2-jlin208-kpang3

## Important Files
1. `readFromFile.hpp` and `readFromFile.cpp`
Code to read airports and routes data file into vectors
2. `Graph.h` and `Graph.cpp`
Code to create the graph data structure from vectors
3. `Heap.h` and `Heap.cpp`
Code to create the priority queue used for Dijkstra and A*search
4. `AirportTraversal.h` and `AirportTraversal.cpp`
Code to create the BFS iterator on the graph
5. `Dijkstra.h` and `Dijkstra.cpp`
Code to run Dijkstra's algorithm on the graph
6. `A_search.h` and `A_search.cpp`
Code to run A*search on the graph
7. `main.cpp`
Main code that provides prompts for the user to use the functions
8. `tests/tests.cpp`
Code containing the test files
9. `tests/..`
Folder containing the data files

## Instructions
**Building and using main**
1. `make` to build main.cpp
2. `./finalproj` to run main.cpp
3. Data should be placed in tests folder; download `airports.dat` and `routes.dat` from [OpenFlights Dataset](https://openflights.org/data.html)
4. When prompted for the data, enter `tests/airports.dat.txt` for airport data and `tests/routes.dat.txt` for route data
5. There are no output files; all outputs are shown in the console

**Building and using test**
1. `make test` to build tests/tests.cpp
2. `./test` to run the test

## [Presentation + demo video](https://drive.google.com/file/d/1Z04q6gUYK5Q_2S3jg4roAnz-g6oFIyCM/view?usp=sharing)
