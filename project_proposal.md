#Final Project Proposal (kpang3, jlin208, johnwl2, bthuma2)

## **Leading Question:** 
Given two cities, the goal is to find the shortest route between them. Shortest will be defined as the lowest distance required to travel between the two cities. 

## **Dataset Acquisition and Processing:** 
We will be accessing the OpenFlights database for airports.dat, countries.dat, and routes.dat to find the shortest route from one city to another. The data is in *.dat format, and we will cite this reference from StackOverFlow to load the data into an array. For our graph structure, we will use the airport ID provided from the airports.dat file as the nodes. An edge will exist between two nodes if there exists a route between two airports provided by routes.dat. We will assign the weights for each edge to be the euclidean distance between two airports that it connects (using latitude and longitude data provided by airport.dat). There are potential errors in the provided data so we will ignore any data that doesn’t contain all of the necessary information.

## **Graph Algorithms:** 
Our graph traversal will be a BFS using an iterator. The input to the iterator constructor will be the starting airport ID node and every time we call operator++ on it, it should go to a new airport ID node until there are no nodes left to traverse.

One algorithm will be Dijikstra’s Algorithm, which will take a starting airport ID node and a destination airport ID node. It should output the shortest path with the lowest distance required to travel from the starting airport to the destination airport.

The final algorithm will A* Search, which will take a starting airport ID node and a destination airport ID node. A* Search requires a heuristic, which will be the euclidean distance between the current airport and the destination airport without taking into consideration the routes. This will approximate the distance between the airports. It should output the shortest path with the lowest distance required to travel from the starting airport to the destination airport.

## **Timeline:**
April 8 - work on proposal and contract together

April 9 - submit project proposal and team contract

April 15 - set up initial repository and Makefile and finish reading in data into array format and write simple tests to verify correctness

April 19 - convert array format into graph format and pass simple tests

April 25 - write BFS iterator and verify with tests

May 1 - write Dijikstra's and verify with tests

May 5 - write A* search and verify with tests

May 7 - finish report

May 9 - sync to record final presentation

May 11 - finish editing presentation and submit
