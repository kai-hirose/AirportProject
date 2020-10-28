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
                    count = 0;
                }
                //After the "chunks" of text that make up the state, codes, and city
                //Latitude and longitude are in the 7th and 8th "chunk"
                string latlon = line.substr(143, line.length());
                int index = latlon.rfind('-');
                lat = whiteRemover(latlon.substr(0, 9));
                lon = whiteRemover(latlon.substr(10,latlon.length()));
            }
            //Extract state and city from the text we saved earlier.
            state = citywithstate.substr(0, 2);
            city = citywithstate.substr(9, citywithstate.length());
            string properCity;
            string properState;
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
            insert(root, lat, lon, properCity, properState);
            ss.clear();
        }
    }
    myfile.close();
}

Trie::tNode *Trie::genNode()
{
    tNode *tNodePtr = new tNode;
    tNodePtr->index = -2;
    /* iffy
    tNodePtr->lat[0] = lat;
    tNodePtr->lon[0] = lon;
    tNodePtr->city[0] = city;
    tNodePtr->state[0] = state;
    */
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
            
            if(exists == -1){
                temp->array[nextLetter]->state[temp->index]=state;
                temp->array[nextLetter]->city[temp->index]=city;
                temp->array[nextLetter]->lat[temp->index]=std::stod(lat);
                temp->array[nextLetter]->lon[temp->index]=std::stod(lon);
                temp->array[nextLetter]->index+=1;
            }else if (exists >=0 ){
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
        cout<<"Query empty"<<endl;
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
        { /**change coordinatessss**/
            returnVal.lat = -999;
            returnVal.lon = -999;
            returnVal.city = "Nonexistent";
            returnVal.state = "Nonexistent";
            return returnVal;
        }

        //Invalid letter returns an invalid latitude that the main program checks.
        //Return the lat and lon stored in the node if index is not -1
        //-1 indicates there is more than one branch beneath.
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

int main(){
    Trie myTrie;
    myTrie.buildTrie("places2k.txt");
    Trie::returnstruct test = myTrie.search("seattlec", "");
    cout<<test.city<<test.state<<test.lat<<test.lon<<endl;
    return 0;
}