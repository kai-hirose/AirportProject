#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

//Header for the Trie class.
#ifndef TRIE_H
#define TRIE_H
class Trie{
public:
        Trie();

        ~Trie();
        
        static const int ALPHASIZE = 26;
        static const int STATESIZE = 52;
        
        struct tNode
        {
                tNode* array[ALPHASIZE]; 
                int index;
                double lat[STATESIZE];
                double lon[STATESIZE];
                string city[STATESIZE];
                string state[STATESIZE];
        };

        struct returnstruct
        {
                double lat;
                double lon;
                string city;
                string state;
        };

        void buildTrie(string filename);
        returnstruct search(string city, string state);
        void insert(tNode *root, string lat, string lon, string city, string state);
        tNode* genNode();
        string whiteRemover(string name);

private:
        tNode *root;
};
#endif