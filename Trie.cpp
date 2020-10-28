#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Trie.h"


Trie::Trie(){
    //Just make the object and do nothing until we get a filename and call BuildTrie.
    root = nullptr;
}

string Trie::whiteRemover(string str)
{
    string temp;
    for(int i = 0; i < str.length(); i++)
    {
        if(!isspace(str[i])) temp += str[i];
    }
    return temp;
    
}

void Trie::buildTrie(string filename)
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
                }

                //Manually get the lat and lon using column numbers because of their formatting.
                string latlon = line.substr(143, line.length());
                lat = whiteRemover(latlon.substr(0, 9));
                lon = whiteRemover(latlon.substr(10,latlon.length()));
            }

            //Extract state and city from the text we saved earlier.
            state = citywithstate.substr(0, 2);
            city = citywithstate.substr(9, citywithstate.length());
            string properCity;
            string properState;

            //Formate the characters
            for (int i = 0; i < city.length(); i++)
            {
                if (city[i] != ' ' && isalpha(city[i]))
                {
                    //Gets rid of special chars
                    properCity += toupper(city[i]);
                }
            }
            for (int i = 0; i < state.length(); i++)
            {
                if (state[i] != ' ' && isalpha(state[i]))
                {
                    //Gets rid of special chars
                    properState += toupper(state[i]);
                }
            }

            //Insert into trie after they are formatted.
            insert(root, lat, lon, properCity, properState);
            ss.clear();
        }
    }
    myfile.close();
}

Trie::tNode *Trie::genNode()
{
    tNode *tNodePtr = new tNode;
    //-2 index indicates nothing is stored there yet.
    tNodePtr->index = -2;
    for (int i = 0; i < 26; i++)
    {
        tNodePtr->array[i] = nullptr;
    }
    return tNodePtr;
}

void Trie::insert(tNode *root, string lat, string lon, string city, string state)
{
    tNode *temp = root;
    for (int i = 0; i < city.length(); i++)
    {
        int nextLetter = (int)toupper(city[i]) - (int)'A';

        //If next node is null, make one.
        if (temp->array[nextLetter] == nullptr)
        {
            temp->array[nextLetter] = genNode();
            temp->array[nextLetter]->index = 1;
            temp->array[nextLetter]->lat[0] = std::stod(lat);
            temp->array[nextLetter]->lon[0] = std::stod(lon);
            temp->array[nextLetter]->city[0] = city;
            temp->array[nextLetter]->state[0] = state; 
        }
        else
        {
            //-1 Means the state does not exist, -2 means there is but is cancelled out, 0 or higher identifies the index to cancel out.
            int exists = -1;
            for(int i=0;i<temp->array[nextLetter]->index;i++){
                if(temp->array[nextLetter]->state[i] == state){
                    exists = i;
                }else if(temp->array[nextLetter]->state[i]==state+"X"){
                    exists = -2;
                }
            }

            //Store values if an entry for that state is not stored there.
            if(exists == -1){
                temp->array[nextLetter]->state[temp->array[nextLetter]->index]=state;
                temp->array[nextLetter]->city[temp->array[nextLetter]->index]=city;
                temp->array[nextLetter]->lat[temp->array[nextLetter]->index]=std::stod(lat);
                temp->array[nextLetter]->lon[temp->array[nextLetter]->index]=std::stod(lon);
                temp->array[nextLetter]->index+=1;
            }else if (exists >=0 ){
                //Signify that more than one entry exists for that query in the state by putting an "X" after the state.
                temp->array[nextLetter]->state[exists]=state+"X";
            }
        }
        temp = temp->array[nextLetter];
    }
}

Trie::~Trie(){ 
}

Trie::returnstruct Trie::search(string city, string state)
{
    tNode *temp = root;
    Trie::returnstruct returnVal;
    string properState = "";
    string properCity = "";

    //Query is empty.
    if(city.length()<1){
        returnVal.city = "Refine";
        returnVal.state = "Refine";
        returnVal.lat = -1000;
        returnVal.lon = -1000;
        return returnVal;
    }

    //Get formatted names
    for (int i = 0; i < state.length(); i++)
    {
        if (isalpha(state[i]) && !isspace(state[i]))
        {
            properState += toupper(state[i]);
        }
    }
    for (int i = 0; i < city.length(); i++)
    {
        if (isalpha(city[i]) && !isspace(city[i]))
        {
            properCity += toupper(city[i]);
        }
    }

    //Traverse trie with the formatted city and state.
    for (int i = 0; i < properCity.length(); i++)
    {
        int index = properCity[i] - 'A';
        if (temp->array[index] == nullptr)
        {
            returnVal.lat = -999;
            returnVal.lon = -999;
            returnVal.city = "Nonexistent";
            returnVal.state = "Nonexistent";
            return returnVal;
        }

        //Return the values if unique state is found, otherwise return refine error code.
        if (i == properCity.length() - 1)
        {
            for(int i=0;i<index;i++){
                if(temp->array[index]->state[i]==properState){
                    returnVal.city = temp->array[index]->city[i];
                    returnVal.state = properState;
                    returnVal.lat = temp->array[index]->lat[i];
                    returnVal.lon = temp->array[index]->lon[i];
                    return returnVal;
                }else if (temp->array[index]->state[i]==properState+"X"){
                    returnVal.city = "Refine";
                    returnVal.state = "Refine";
                    returnVal.lat = -1000;
                    returnVal.lon = -1000;
                    return returnVal;
                }
            }
        }
        temp = temp->array[index];
    }

    //If we havent returned anything somehow, return invalid lat.
    returnVal.lat = -999;
    returnVal.lon = -999;
    returnVal.city = "Nonexistent";
    returnVal.state = "Nonexistent";
    return returnVal;
}