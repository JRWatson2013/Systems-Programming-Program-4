#include <cstdlib>
#include <iostream>
#include "Node.h"
#include "BST.h"
#include <string>
#include <fstream>
#include <vector>

using namespace ein_jrw_prog4;
using namespace std;

inline vector<string> split(string s, string delim)
{
	int start = 0;
	int end;
	vector<string> splitString;
	// Until find returns nothing (string::npos)
	while((end = s.find(delim,start)) != string::npos)
	{
		// Get the substring up to the delimter
		// end is the position of the delimiting string
		splitString.push_back(s.substr(start,end-start));
		start = end + delim.length();
	}
	// Get the last remaining word
	splitString.push_back(s.substr(start));
	return splitString;
}

inline string strip(string s, const char toRemove)
{
	string stripped = s;
	string::iterator it;
	while(stripped.find(toRemove) != string::npos)
	{
		it = stripped.begin();
		stripped.erase(it+stripped.find(toRemove));
	}
	return stripped;
}

inline string stripSet(string s, const string toRemove)
{
	string stripped = s;
	for(size_t i = 0; i < toRemove.size(); ++i)
	{
		stripped = strip(stripped,toRemove[i]);
	}
	return stripped;
}

inline void toLowerCase(string& s)
{
	for(size_t i = 0; i < s.size(); ++i)
	{
		if(int(s[i]) <= 90 && int(s[i]) >= 65)
			s[i] = int(s[i]) + 32;
	}
}

int main(int argc, char** argv)
{
	Bin_STree j;
	string currentLine;
	ifstream myfile (argv[1]);


	if(myfile.is_open())
	{
		int lineNum = 1;
		while (getline (myfile,currentLine))
		{
			//cout << currentLine << endl;
			string strippedLine = stripSet(currentLine,",./:-;\"\\'[]=`()");
			toLowerCase(strippedLine);
			//cout << strippedLine << endl;
			vector<string> seperatedLine = split(strippedLine," ");
			for(int i = 0; i < seperatedLine.size(); ++i)
			{
				if(!seperatedLine[i].empty())
				{
					j.insert(seperatedLine[i],lineNum);
				}
			}
			lineNum++;
		}
		myfile.close();
	}

	else
		cout << " NO FILE " << endl;
	cout << "________Word___________|_______Count________|_______Lines_______|" << endl;
	j.printTreeInOrder(j.getRootPtr());
	cout << "There were " << j.getNumElements() << " unique words" << endl;
	return 0;
}
