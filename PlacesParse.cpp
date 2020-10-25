#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class trie {
public:
    trie() {
        tree = new tNode;
        tree->array = nullptr;
        string line;
        ifstream myfile("places/places2k.txt");
        if (myfile.is_open()) {
            string city;
            string state;
            string lat;
            string lon;
            string temp;
            stringstream ss;
            while (getline(myfile, line)) {
                int count = 0;
                string citywithstate = "";

                ss.str(line);
                while (ss >> temp) {
                    if (isalpha(temp[1])) {
                        //Get the state, codes, and city for now
                        citywithstate.append(temp + " ");
                        count = 0;
                    }
                    //After the "chunks" of text that make up the state, codes, and city
                    //Latitude and longitude are in the 7th and 8th "chunk"
                    if (count == 7) lat = temp;
                    if (count == 8) lon = temp;
                    count++;
                }
                //Extract state and city from the text we saved earlier.
                state = citywithstate.substr(0, 2);
                city = citywithstate.substr(9, citywithstate.length());
                cout << "state:" << state + " city:" + city + " lat:" + lat + " lon:" + lon << endl;
                string stateCitySpaces = city + state;
                string properName;
                for (int i = 0; i < stateCitySpaces.length(); i++) {
                    if (stateCitySpaces[i] != ' ' && isalpha(stateCitySpaces[i])) {
                        //Gets rid of special chars
                        properName += toupper(stateCitySpaces[i]);
                    }
                }
                tNodePtr temp = tree;
                for (int i = 0; i < properName.length(); i++) {
                    //If the node'a array is not allocated.
                    if (temp->array = nullptr) {
                        cout << ((int)properName[i]) - 65 << endl;
                        temp->index = ((int)properName[i]) - 65;
                        temp->lat = std::stod(lat);
                        temp->lon = std::stod(lon);
                        temp->array = new tNode[26];
                        for (int i = 0; i < 26; i++) {
                            temp->array[i].array = nullptr;
                        }
                        temp = &(temp->array[temp->index]);
                    }
                    else {
                        //If the index of the current ptr is not -1, it means there was only one "branch" below it.
                        //Now there will be more than one opion available so we need to set index to -1 to signify it.
                        if (temp->index != -1) {
                            temp->index = -1;
                        }
                        temp = &(temp->array[((int)properName[i]) - 65]);
                    }
                }
                ss.clear();
            }
            myfile.close();
        }
        cout << "Tree built." << endl;
        if (tree == nullptr)
            cout << "fail" << endl;
    }

    coordinateCP search(string name) {
        tNodePtr temp = tree;
        coordinateCP returnVal;
        for (int i = 0; i < name.length(); i++) {
            cout << name[i] << endl;
            if (tree == nullptr) {
                cout << "failed" << endl;
            }
            //Invalid letter returns an invalid latitude that the main program checks.
            if (!isalpha(name[i])) {
                returnVal.lat = -999;
                return returnVal;
            }

            if (temp->array = nullptr) {
                //If there is letters left and the next node is null, return invalid lat.
                if (i < name.length() - 1) {
                    returnVal.lat = -999;
                    return returnVal;
                }
                //If there is no letters left and the next node is null, return the lat and lat stored here.
                returnVal.lat = temp->lat;
                returnVal.lon = temp->lon;
                return returnVal;
            }

            //Return the lat and lon stored in the node if index is not -1
            //-1 indicates there is more than one branch beneath.
            if (temp->index != -1) {
                returnVal.lat = temp->lat;
                returnVal.lon = temp->lon;
                return returnVal;
            }
            temp = &(temp->array[((int)toupper(name[i])) - 65]);
        }

        //If we havent returned anything somehow, return invalid lat.
        returnVal.lat = -999;
        return returnVal;
    }

private:
    tNodePtr tree;
};