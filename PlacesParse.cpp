#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class trie {
public:
    trie() {
        string line;
        ifstream myfile("places\\places2k.txt");
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
                //cout << "state:" << state + " city:" + city + " lat:" + lat + " lon:" + lon << endl;
                string properName = state + city;
                tNodePtr* tempPtr = &tree;
                for (int i = 0; i < properName.length(); i++) {
                    //If the ptr is not allocated, it is the end of the branch so we must allocate it.
                    if ((*tempPtr) = nullptr) {
                        (*tempPtr) = new tNode;
                        //Get index of the char (case insensitive) and set it to index
                        (*tempPtr)->array = new tNode[26];
                        for (int i = 0; i < 26; i++) {
                            (*tempPtr)->array[i] = nullptr;
                        }
                        (*tempPtr)->index = ((int)toupper(properName[i])) - 65;
                        //Set lat and lon, move the ptr to the next "letter"
                        (*tempPtr)->lat = std::stod(lat);
                        (*tempPtr)->lon = std::stod(lon);
                        (*tempPtr) = &((*tempPtr)->array[i]);
                    }
                    else {
                        //If the index of the current ptr is not -1, it means there was only one "branch" below it.
                        //Now there will be more than one opion available so we need to set index to -1 to signify it.
                        if ((*tempPtr)->index != -1) {
                            (*tempPtr)->index = -1;
                        }
                        (*tempPtr) = &((*tempPtr)->array[((int)toupper(properName[i])) - 65]);
                    }
                }
                ss.clear();
            }
        }
        myfile.close();
    }

    coordinateCP search(string name) {
        tNodePtr tempPtr = tree;
        coordinateCP returnVal;
        for (int i = 0; i < name.length(); i++) {
            //Invalid letter returns an invalid latitude that the main program checks.
            if (!isalpha(name[i])) {
                returnVal.lat = -999;
                return returnVal;
            }
            //Return the lat and lon stored in the node if index is not -1
            //-1 indicates there is more than one branch beneath.
            if (tempPtr->index != -1) {
                returnVal.lat = tempPtr->lat;
                returnVal.lon = tempPtr->lon;
                return returnVal;
            }

            if (tempPtr->array[((int)toupper(name[i])) - 65] == nullptr) {
                //If there is letters left and the next node is null, return invalid lat.
                if (i < name.length() - 1) {
                    returnVal.lat = -999;
                    return returnVal;
                }
                //If there is no letters left and the next node is null, return the lat and lat stored here.
                returnVal.lat = tempPtr->lat;
                returnVal.lon = tempPtr->lon;
                return returnVal;
            }
            tempPtr->tempPtr->array[((int)toupper(name[i])) - 65];
        }

        //If we havent returned anything somehow, return invalid lat.
        returnVal.lat = -999;
        return returnVal;
    }

private:
    tNodePtr tree = nullptr;
};

int
main(int argc, char* argv[])
{
    trie myTrie;
    coordinateCP test;
    test = myTrie.search("SeAttleWA");
    cout << test.lat << " " << test.lon;
    return 0;
