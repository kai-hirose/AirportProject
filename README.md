# AirportProject
A group project for distributed systems course.

# Team Members & Contributions:

	Aidan Bossio: 
		KD-Tree Creation
		5 Nearest Airports Search
		KD-Tree Debug
		airport file parsing
	
	Shaun Lee:
		Trie Creation
		Trie Search
		place file parsing
		
	Kai Hirose:
		Data Structuring
		RPC-Related Code
		Establishing RPC Communication
		Makefile
		Portions of the Trie Code
		Fixing General Bugs
	
# Data Structures:
	
	KD-Tree: 
		Used to store airport information. The airport contains the code, city name, state, latitude, and longitude.
		
	Trie: 
		Used to store the places information. The place contains the city name, state, latitude, and longitude.
	
# Algorithms:
	
	KD-Tree Efficient Nearest Neighbor Seach: 
		Modified to find the five closest airports from a given coordinate which contains the latitude and longitude.
		
	Trie Search:
		Used to find the latitude and longitude coordinates from the name of a place given by the user.
		
# Improvements:
	Trie Search: we change the tree structure in the design document. So, the search algorithm will do it from city and then state. It will search the city first which is seattle city and then WA.
# References:

	Reference for KD-Tree insert:
	https://www.geeksforgeeks.org/k-dimensional-tree/
	https://www.geeksforgeeks.org/trie-insert-and-search/
		
		
# Strengths & Weaknesses:

	Strengths: Started early, good planning, good communication
		
		
	Weaknesses: roadblock with rpcgen, Unable to detect error easily, Circular dependencies in the makefile but is taken care of in the compiler, 
		
		
# Running Instructions:
	
	./PlacesAirports_server filepath
	./ClientPlaces_server host filepath
	./ClientPlaces_client host city state
	
	The airports server program takes a filename or path to the file that contains the airport information.
	The places server program takes a hostname to the airports server and a filename or path to the file that contains the places information.
	The client program will take a hostname to the places server and a cityname and its state.
	


