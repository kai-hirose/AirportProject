#include "KDTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <math.h>

KDTree::KDTree(std::string filename) 
{
	root = NULL;
	buildAirportTree(filename);
}

KDTree::~KDTree() {
	deleteTree(root);
}

KDTree::returnPA KDTree::fiveNearestAP(KDTree::coordinatePA point)
{
	returnPA list;
	for (int i = 0; i < 5; i++)
		list.array[i].dist = 50000;
	return fiveNearestAPRec(root, point, 0, list);
}

double KDTree::deg2rad(double deg) {
	return (deg * pi / 180);
}
double KDTree::rad2deg(double rad) {
	return (rad * 180 / pi);
}

double KDTree::distance(double lat1, double lon1, double lat2, double lon2)
{
	double theta, dist;
		theta = lon1 - lon2;
		dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
		dist = acos(dist);
		dist = rad2deg(dist);
		dist = dist * 60 * 1.1515; //Returning distance in Miles
		return (dist);
}

void KDTree::buildAirportTree(std::string filename)
{
	const char *cstr = filename.c_str();
	FILE* inFile = fopen(cstr, "r");
	if (inFile == NULL)
		exit(EXIT_FAILURE);
	
	KDTree::airportPA ap;
	char line[255];
	fgets(line, 255, inFile); // Get rid of first line in file
	while (inFile) {
		if (fgets(line, 255, inFile) != NULL) {
			std::stringstream buffer;
			buffer << line;
			buffer >> ap.code;
			ap.code = ap.code.substr(1,3);
			buffer >> ap.lat;
			buffer >> ap.lon;
			buffer >> ap.name;
			if (!buffer.eof()) {
				std::string temp;
				buffer >> temp;
				ap.name = ap.name + " " + temp;
			}
			int index = ap.name.rfind(',');
			ap.state = ap.name.substr(index+1, ap.name.length());
			ap.name = ap.name.substr(0, index);
			//cout << "city:" + city + " state:" + state << endl; 
			insertKD(root, ap, 0);
		} else {
			break;
		}
	}
	fclose(inFile);
}

void KDTree::insertKD(KDTree::kDNode *&r, KDTree::airportPA newAp, unsigned depth)
{
	if (r == NULL) {
		r = new kDNode;
		r->ap.code = newAp.code;
		r->ap.name = newAp.name;
		r->ap.state = newAp.state;
		r->ap.lat = newAp.lat;
		r->ap.lon = newAp.lon;
		r->left = NULL;
		r->right = NULL;
	} else {	
		if (depth % 2 == 0) {
			if (newAp.lat < r->ap.lat)
				insertKD(r->left, newAp, depth+1);
			else 
				insertKD(r->right, newAp, depth+1);
		} else if (depth % 2 == 1) {
			if (newAp.lon < r->ap.lon)
				insertKD(r->left, newAp, depth+1);
			else 
				insertKD(r->right, newAp, depth+1);
		}
	}
}

void KDTree::inList(KDTree::returnPA &list, KDTree::coordinatePA pointA, KDTree::airportPA pointB)
{	
	int sortPoint = 0;
	// Looks if the list is filled yet
	double newDist = distance(pointA.lat, pointA.lon, pointB.lat, pointB.lon);
	if (list.array[4].dist==50000) {
		for (int i = 0; i < 5; i++) {
			if (list.array[i].dist==50000) {
				list.array[i].code = pointB.code;
				list.array[i].name = pointB.name;
				list.array[i].state = pointB.state;
				list.array[i].lat = pointB.lat;
				list.array[i].lon = pointB.lon;
				list.array[i].dist = newDist;
				sortPoint = i;
				break;
			}
		}
	} else {
		// Replaces largest distance in the list with new value
		if (newDist < list.array[4].dist) {
			list.array[4].code = pointB.code;
			list.array[4].name = pointB.name;
			list.array[4].state = pointB.state;
			list.array[4].lat = pointB.lat;
			list.array[4].lon = pointB.lon;
			list.array[4].dist = newDist;
			sortPoint = 4;
		}
	}
	KDTree::airportPA temp;
	// Sorts list from least to greatest
	for (int i = 0; i < sortPoint+1; i++) {
		if (list.array[sortPoint].dist < list.array[i].dist) {
			for (int j = i; j < sortPoint; j++) {
				temp.code = list.array[j].code;
				temp.name = list.array[j].name;
				temp.state = list.array[j].state;
				temp.lat = list.array[j].lat;
				temp.lon = list.array[j].lon;
				temp.dist = list.array[j].dist;
				list.array[j].code = list.array[sortPoint].code;
				list.array[j].name = list.array[sortPoint].name;
				list.array[j].state = list.array[sortPoint].state;
				list.array[j].lat = list.array[sortPoint].lat;
				list.array[j].lon = list.array[sortPoint].lon;
				list.array[j].dist = list.array[sortPoint].dist;
				list.array[sortPoint].code = temp.code;
				list.array[sortPoint].name = temp.name;
				list.array[sortPoint].state = temp.state;
				list.array[sortPoint].lat = temp.lat;
				list.array[sortPoint].lon = temp.lon;
				list.array[sortPoint].dist = temp.dist;
			}
			break;
		}
	}
}

KDTree::returnPA KDTree::fiveNearestAPRec(KDTree::kDNode *r, KDTree::coordinatePA point, unsigned depth, KDTree::returnPA &list)
{
	if (r != NULL) {
		if (depth % 2 == 0) {
			if (point.lat < r->ap.lat) {
				fiveNearestAPRec(r->left, point, depth+1, list);
				inList(list, point, r->ap);
				// Checks if there could be a closer node on opposite tree branch 
				if (distance(point.lat, point.lon, r->ap.lat, point.lon) < list.array[4].dist)
					list = fiveNearestAPRec(r->right, point, depth+1, list);
			} else {
				fiveNearestAPRec(r->right, point, depth+1, list);
				inList(list, point, r->ap);
				if (distance(point.lat, point.lon, r->ap.lat, point.lon) < list.array[4].dist)
					list = fiveNearestAPRec(r->left, point, depth+1, list);
			}
		} else {
			if (point.lon < r->ap.lon) {
				fiveNearestAPRec(r->left, point, depth+1, list);
				inList(list, point, r->ap);
				if (distance(point.lat, point.lon, point.lat,  r->ap.lon) < list.array[4].dist)
					fiveNearestAPRec(r->right, point, depth+1, list);						
			} else {
				fiveNearestAPRec(r->right, point, depth+1, list);
				inList(list, point, r->ap);
				if (distance(point.lat, point.lon, point.lat,  r->ap.lon) < list.array[4].dist)
					fiveNearestAPRec(r->left, point, depth+1, list);				
			}
		}
	}
	return list;
}

void KDTree::printAirport(airportPA ap)
{
	std::cout << ap.code << " " << ap.name << " " << ap.state << " " << ap.lat << " " << ap.lon << " " << ap.dist << std::endl;
}

void KDTree::printTree() {
	printTree(root);
}

void KDTree::printTree(kDNode *r)
{
	if (r != NULL) {
		printAirport(r->ap);
		printTree(r->left);
		printTree(r->right);
	}
}

void KDTree::printResult(returnPA list)
{
	for (int i = 0; i < 5; i++) {
		std::cout << list.array[i].code << " " << list.array[i].name << " " << list.array[i].state << " " << list.array[i].lat << " " << list.array[i].lon << " " << list.array[i].dist << std::endl;
	}
}

void KDTree::deleteTree(kDNode *&r)
{
	if (r != NULL) {
		deleteTree(r->left);
		deleteTree(r->right);
		delete r;
		r = NULL;
	}
}
