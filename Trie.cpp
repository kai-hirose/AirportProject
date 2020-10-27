#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Trie.h"
using namespace std;



string Trie::whiteRemover(string str)
{
    string temp;
    for(int i = 0; i < str.length(); i++)
    {
        if(!isspace(str[i])) temp += str[i];
    }
    return temp;
    
}

Trie::Trie()
{
    root = genNode();
    string line;
    ifstream myfile("places2k.txt");
    if (myfile.is_open())
    {
        string city;
        string state;
        string lat;
        string lon;
        string temp;
        stringstream ss;
        while (getline(myfile, line))
        {
            int count = 0;
            string citywithstate = "";

            ss.str(line);
            while (ss >> temp)
            {
                if (isalpha(temp[1]))
                {
                    //Get the state, codes, and city for now
                    citywithstate.append(temp + " ");
                    count = 0;
                }
                //After the "chunks" of text that make up the state, codes, and city
                //Latitude and longitude are in the 7th and 8th "chunk"
                string latlon = line.substr(143, line.length());
                int index = latlon.rfind('-');
                lat = whiteRemover(latlon.substr(0, 9));
                lon = whiteRemover(latlon.substr(10,latlon.length()));
                // cout << "lat:" + lat + " lon:" + lon << endl;
            }
            //Extract state and city from the text we saved earlier.
            state = citywithstate.substr(0, 2);
            city = citywithstate.substr(9, citywithstate.length());
            // cout << "state:" << state + " city:" + city + " lat:" + lat + " lon:" + lon << endl;
            string stateCitySpaces = city + state;
            string properName;
            for (int i = 0; i < stateCitySpaces.length(); i++)
            {
                if (stateCitySpaces[i] != ' ' && isalpha(stateCitySpaces[i]))
                {
                    //Gets rid of special chars
                    properName += toupper(stateCitySpaces[i]);
                }
            }
            //cout << properName << endl;
            insert(root, properName, lat, lon);
            ss.clear();
        }
    }
    myfile.close();
    cout << "Tree built." << endl;
    if (root == nullptr)
        cout << "fail" << endl;
}

Trie::tNode *Trie::genNode()
{
    tNode *tNodePtr = new tNode;
    tNodePtr->index = -2;
    for (int i = 0; i < 26; i++)
    {
        tNodePtr->array[i] = nullptr;
    }
    return tNodePtr;
}

void Trie::insert(tNode *root, string properName, string lat, string lon)
{
    tNode *temp = root;
    for (int i = 0; i < properName.length(); i++)
    {
        int index = (int)toupper(properName[i]) - (int)'A';
        //If the node'a array is not allocated.
        //  cout << ((int)properName[i]) - 'A' << endl;

        if (isalpha(properName[i]))
        {
            //cout << index << endl;
            temp->index = index;
            //  cout << "lat:" + to_string(temp->lat) + " lon:" + to_string(temp->lon) << endl;
        }
        else
        {
            return;
        }
        if (temp->array[temp->index] == nullptr)
        { 
            temp->array[temp->index] = genNode();
            if (temp->index == -2)
            {
                temp->index = index;
            }
            else if (temp->index >= 0)
            {
                temp->index = -1;
                temp->lat = -1000;
                temp->lon = -1000;
            }
            temp->lat = std::stod(lat);
            temp->lon = std::stod(lon);
        }
        temp = temp->array[index];
    }
}

Trie::coordinate Trie::search(string input)
{
    string name;
    for (int i = 0; i < input.length(); i++)
    {
        if (isalpha(input[i]))
        {
            name += toupper(input[i]);
        }
        else
        {
            cout << "blah blah" << endl;
            coordinate obj;
            obj.lat = -999;
            obj.lon = -999;
            return obj;
        }
    }
    cout << name << endl;

    tNode *temp = root;
    Trie::coordinate returnVal;

    for (int i = 0; i < name.length(); i++)
    {
        int index = toupper(name[i]) - 'A';
        cout << name[i] << endl;
        if (temp == nullptr)
        {
            cout << "failed" << endl;
        }

        //Invalid letter returns an invalid latitude that the main program checks.
        //Return the lat and lon stored in the node if index is not -1
        //-1 indicates there is more than one branch beneath.
        if (i == name.length() - 1 && temp->index == -1){ 
            coordinate obj;
            obj.lat = -1000;
            obj.lon = -1000;
            cout << "lat" + to_string(obj.lat) + " lon" + to_string(obj.lon) << endl;
            return obj;

        }
        if (i == name.length() - 1)
        {
            returnVal.lat = temp->lat;
            returnVal.lon = temp->lon;
            cout << "lat" + to_string(returnVal.lat) + " lon" + to_string(returnVal.lon) << endl;
            return returnVal;
        }
        // temp = &(temp->array[((int)toupper(name[i])) - 'A']);
        temp = temp->array[index];
    }

    //If we havent returned anything somehow, return invalid lat.
    returnVal.lat = -999;
    return returnVal;
}

int main()
{
    Trie obj;
    obj.search("Seattle");
}