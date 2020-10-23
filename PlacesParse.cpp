#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
        string line;
        int count = 0;
        ifstream myfile("places\\places2k.txt");
        if (myfile.is_open())
        {
                stringstream ss;
                string city;
                string lat;
                string lon;
                string temp;
                while (getline(myfile, line))
                {
                        ss.str(line);
                        string temp;
                        while(ss >> temp)
                        {
                                // if(isalpha(temp[1])){
                                //         city.append(temp + " ");
                                // }
                                
                                cout << temp << endl;
                        }
                }
        }
        myfile.close();
        return 0;
}