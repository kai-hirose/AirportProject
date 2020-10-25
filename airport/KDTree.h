#ifndef KDTREE_H
#define KDTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <math.h>

class KDTree 
{
	
	#define pi 3.14159265358979323846
	
	public:
	
		struct airportPA {
			std::string code;
			std::string name;
			std::string state;
			double lat;
			double lon;
			double dist;
		};

		struct returnPA {
			int error;
			airportPA array[5];
		};

		struct kDNode {
			airportPA ap;
			struct kDNode *left, *right;	
		};

		struct coordinatePA {
			double lat;
			double lon;
		};
	
		KDTree(std::string filename);
		
		~KDTree();
		
		// Searches for 5 nearest airports to the provided coordinate
		returnPA fiveNearestAP(coordinatePA point);

		// Distance Calulation Functions
		double deg2rad(double deg);
		double rad2deg(double rad);
		double distance(double lat1, double lon1, double lat2, double lon2);
		void printResult(returnPA list);
		void printTree();
	
	private:
	
		kDNode *root;
		
		// Builds a kd-tree using the information from the airport-locations.txt file
		void buildAirportTree(std::string filename);
		void insertKD(kDNode *&r, airportPA newAirport, unsigned depth);

		returnPA fiveNearestAPRec(kDNode *r, coordinatePA point, unsigned depth, returnPA &list);
		
		void inList(returnPA &list, coordinatePA pointA, airportPA pointB);
		
		void deleteTree(kDNode *&r);
		
		void printTree(kDNode *r);
		
		void printAirport(airportPA ap);
};

#endif