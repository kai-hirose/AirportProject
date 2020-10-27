#ifndef TRIE_H
#define TRIE_H

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
        string whiteRemover(string);
private:
        tNode *root;
};
#endif