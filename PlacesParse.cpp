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
                string city;
                string state;
                string lat;
                string lon;
                string temp;
                stringstream ss;
                while (getline(myfile, line))
                {
                        string citywithstate = "";
                        city = "";
                        state = "";
                        ss.str(line);
                        while(ss >> temp)
                        {
                                if(isalpha(temp[1])) citywithstate.append(temp + " "); 
                        }
                        state = citywithstate.substr(0,2);
                        city = citywithstate.substr(9,citywithstate.length());
                        ss.seekg(5);
                        ss >> lat;
                        ss >> lon;
                        cout << "state:" << state + " city:" + city + " lat:" + lat + " lon:" + lon << endl;
                        ss.clear();
                }
        }
        myfile.close();
        return 0;
}