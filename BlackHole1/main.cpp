/*
Data of blackholes are stored in a text file. Each line of the file starts with the ID of a blackhole
(string without whitespace), which is followed by measurements. A measurement consists of a date
(YYYY.MM.DD format, string), the weight (in billion tonns, int) and the distance from the Earth
(in thousand light year, int). In one line, data is separated by tabs or whitespace.
We can assume that data of one blackhole can be found in only one line of the file.
The dates in one line are in ascending order. The weight of one blackhole increases by time.

Give a blackhole (ID) the last weight of which is the highest from those which were measured anytime to be
closer than 2700 thousand light years from the Earth.
*/

#include<bits/stdc++.h>
#include"InFile.h"
using namespace std;

int main()
{
    string filename;
    cout<<"Enter the Filename ";
    cin>>filename;

    try
    {
        int max = 0;
        string Id  ;
        InFile t(filename);

        if(t.end())
        {
            cout << "No Such Element";
        }
        else
        {
        for ( t.first() ; !t.end(); t.next())
        {
            if (t.current().lastweight > max)
            {
                max = t.current().lastweight;
                Id = t.current().ID;
            }

        }
        cout << max << "  "<< Id;
        }

    }
    catch( InFile::ERROR  e)
    {
         cout << "File Error ";
    }


}
