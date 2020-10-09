/*
 *  hw2_18001166
 *	exercise_4.cpp
 *
 *  Author: Nguyen Van Ninh
 */

// functions that simulate the functions of string.h
#include <bits/stdc++.h>
#include<stdio.h> 
#include<conio.h>
#include<string.h>
using namespace std;

// strlen()
int strlen(char* s)
{
    int index = 0;
    while( s[index] != '\0' ){
        index++;
    }
    return index;
}

// strcpy()
void strcpy(char A[], char B[])
{
	int n = 0;
	do
	{
		A[n] = B[n];
		n++;
	}
	while (B[n] != '\0');
}

// strcat()
char *strcat(char *s1, const char *s2)
{
    while(*s1 != '\0'){
        *s1++;
    }
    while(*s2 != '\0'){
        *s1++ = *s2++;
    }
    *s1 = '\0'; 
    return s1;
}
// main
int main4()
{
	char s1[100], s2[100]; 
    string ans;
    
	do{	
		system("cls");
		cout << "\n               SIMULATES THE FUNCTIONS OF STRING.H: STRLEN(), STRCPY(), STRCAT()\n";
		cout << "a. Strlen()\n"
			 << "b. Strcpy()\n"
			 << "c. Strcat()\n";
		char choose;
		cout << "*Enter your choice(type a, b,...): ";
		cin >> choose;
		switch(choose)
		{
			case 'a' :
				cout << "- Enter a string: ";
				cin >> s1; 
				cout << "- The length of the string is: " << strlen(s1);
				break;
			case 'b' : 
				cout << "- Enter a string s1: ";
				cin >> s1;
				cout << "\n- Enter a string s2: ";
				cin >> s2;
				strcpy(s1, s2);
				cout << "- The string after copy: " << s1;
				break;
			case 'c' :
				cout << "- Enter a string s1: ";
				cin >> s1;
				cout << "- Enter a string s2: ";
				cin >> s2;
				strcat(s1, s2);
			    cout << "- The string after concatenation: " << s1;
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
