#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class Trie{
public:
        static const int SIZE = 26;
        struct tNode
        {
                tNode *array[SIZE];
                int index;
                double lat;
                double lon;
        };

        struct coordinate
        {
                double lat;
                double lon;
        };

        Trie();
        coordinate search(string);
        void insert(tNode *root, string properName, string lat, string lon);
        tNode* genNode(void);

private:
        tNode *root;
};

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
                //if (count == 7)
                //    lat = temp;
                //if (count == 8)
                //    lon = temp;
                //count++;
                
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
                     properName += tolower(stateCitySpaces[i]);
                 }
             }
             //cout << properName << endl;
             insert(root,properName,lat,lon);
            ss.clear();
        }
    }
        myfile.close();
    cout << "Tree built." << endl;
    if (root == nullptr)
        cout << "fail" << endl;
}

Trie::tNode* Trie::genNode()
{
    tNode* tNodePtr = new tNode;
    for(int i = 0; i < 26; i++){
        tNodePtr->array[i] = nullptr;
    }
    return tNodePtr;
}

void Trie::insert(tNode* root,string properName,string lat, string lon){ 
             tNode* temp = root;
             for (int i = 0; i < properName.length(); i++)
             {
                 int index = tolower(properName[i]) - 'a';
                 //If the node'a array is not allocated.
                 //  cout << ((int)properName[i]) - 'a' << endl;

                 if (isalpha(properName[i]))
                 { 
                     //cout << index << endl;
                     temp->index = index;
                    //  cout << "lat:" + to_string(temp->lat) + " lon:" + to_string(temp->lon) << endl;
                 }
                 else{
                     return;
                 }
                 if (temp->array[temp->index] == nullptr)
                 {
                     temp->array[temp->index] = genNode();
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
            name += tolower(input[i]);
        }
    }
    cout << name << endl;

    tNode *temp = root;
    Trie::coordinate returnVal;
    
    for (int i = 0; i < name.length(); i++)
    {
        int index = tolower(name[i]) - 'a';
        cout << name[i] << endl;
        if (root == nullptr)
        {
            cout << "failed" << endl;
        }

        //Invalid letter returns an invalid latitude that the main program checks. 
        //Return the lat and lon stored in the node if index is not -1
        //-1 indicates there is more than one branch beneath.
        if (i == name.length()-1)
        {
            returnVal.lat = temp->lat;
            returnVal.lon = temp->lon;
            cout << "lat" + to_string(returnVal.lat) + " lon" + to_string(returnVal.lon) << endl;
            return returnVal;
        }
        // temp = &(temp->array[((int)tolower(name[i])) - 'a']);
        temp = temp->array[index]; 
    }

    //If we havent returned anything somehow, return invalid lat.
    returnVal.lat = -999;
    return returnVal;
}

int main()
{
    Trie obj;
    obj.search("Seattle City");
}