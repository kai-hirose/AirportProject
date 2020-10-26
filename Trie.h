#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class Trie
{
public:
        struct tNode {
                tNode* array;
                int index;
                double lat;
                double lon;
        };

        struct coordinate {
                double lat;
                double lon;
        };

        Trie();
        coordinate search(string);

private:
        tNode* root;
};
#endif