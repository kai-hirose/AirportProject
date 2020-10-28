# AirportProject
A group project for distributed systems course.

# Team Members & Contributions:

	Aidan Bossio: 
		KD-Tree Creation
		5 Nearest Airports Search
		KD-Tree Debug
		Airport File Parsing
	
	Shaun Lee:
		Trie Creation
		Trie Search
		Place File Parsing
		Trie Debugging
	Kai Hirose:
		Data Structuring
		RPC-Related Code
		Establishing RPC Communication
		Makefile
		Portions of the Trie Code
		Fixing General Bugs
		Implemented New Trie Algorithm
		Trie Debugging
		Small Debugging in KD-Tree
		RPC Debugging
	
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
	Trie Search: 
		We changed the tree structure in the design document so the search algorithm will do it from city and then state. It will search the city first which is seattle city and then WA.
	
	Trie Revision: Since we had to account for prefixes, we searched only the city portion. At each node, it will store states and their respective place values if there is a unique place as of that point in the search.
	
# References:

	Reference for KD-Tree insert:
	https://www.geeksforgeeks.org/k-dimensional-tree/
	https://www.geeksforgeeks.org/trie-insert-and-search/
		
		
# Strengths & Weaknesses:

	Strengths: 
		Started early.
		Good planning.
		Good communication.
		Adapted to mistakes.
		
		
	Weaknesses: 
		Huge roadblock with rpcgen, unable to detect error easily.
		Circular dependencies in the makefile but is taken care of in the compiler.
		Misread instructions.
		
		
# Running Instructions:
	
	./PlacesAirports_server filepath
	./ClientPlaces_server host filepath
	./ClientPlaces_client host city state
	
	The airports server program takes a filename or path to the file that contains the airport information.
	The places server program takes a hostname to the airports server and a filename or path to the file that contains the places information.
	The client program will take a hostname to the places server and a cityname and its state.
	


