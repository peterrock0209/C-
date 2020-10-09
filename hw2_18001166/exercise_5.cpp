/*
 *  hw2_18001166
 *	exercise_5.cpp
 *
 *  Author: Nguyen Van Ninh
 */

// program run length
//#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <iostream> 
#include <sstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void encoding(string str)
{	
	string newstr;
	int n = str.length();
	for (int i = 0; i < n; i++) {
		int count = 1;
		while (i < n - 1 && str[i] == str[i + 1]) {
			count++;
			i++;
		}
		if(count == 1){
			newstr += str[i];
		}
		else {
			string result;          
		    ostringstream convert;   
		    convert << count;      
		    result = convert.str();
			newstr = newstr + result + str[i];
		}
	}
	cout << newstr;
	int m = newstr.length();
	cout << " [" <<  (static_cast<float>(m) / static_cast<float>(n))*100 << "%]";
}

void decoding(string str)
{
	string newstr;
	int i = 0, ticket;
	while(i < str.length())
	{
		if(str[i] < '0' || str[i] > '9')
			ticket = 1;
		else{
			ticket = int(str[i]) - 48; // ASCII table
			i ++;
			while(str[i] >= '0' && str[i] <= '9')
			{
				int nin = int(str[i]) - 48;
				ticket = ticket*10 + nin;
				i ++;
			}
		}
		for(int j = 0; j < ticket; j++)
		{
			newstr += str[i];
		}
		i ++;
	}
    cout << newstr;
}

int main5()
{	
	string str, ans;
	do{	
		system("cls");
		cout << "\n                      COMPRESS AND DECOMPRESS STRINGS\n";
		cout << "a. String compression\n"
			 << "b. Unzip the string\n";
		char choose;
		cout << "*Enter your choice(type a, b,...): ";
		cin >> choose;
		switch(choose)
		{
			case 'a' :
				cout << "- Enter the string to compress: ";
				cin >> str;
				cout << "- String after compression: ";
				encoding(str);
				break;
			case 'b' : 
				cout << "- Enter the string to unzip: ";
				cin >> str;
				cout << "- String after unzip: ";
				decoding(str);
				break;
			default :
				cout << "Let's do something!";
				break;
		}
		cout << "\n\nDo you want to continue (type y or n)? ";
		cin >> ans;
	} while(ans == "Y" || ans == "y");
	return 0;
}

