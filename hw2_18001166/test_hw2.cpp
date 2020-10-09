/*
 *	hw2_18001166
 *  test_hw2.cpp
 *
 *  Author: Nguyen Van Ninh
 */
 
#include <bits/stdc++.h>
#include "erastosthenes.cpp";
#include "exercise_2.cpp";
#include "exercise_3.cpp";
#include "exercise_4.cpp";
#include "exercise_5.cpp";
#include "exercise_6.cpp";
#include "exercise_7.cpp";


int main() 
{
	string ans; 
	do{	
		system("cls");
		cout << "Hw1_18001166\nYou are running the file: test_hw2.cpp\nAuthor: Nguyen Van Ninh\n\n";
		cout << "1. excercise_1: eratosthenes screening algorithm\n"
			 << "2. excercise_2: manipulating a one-dimensional array\n"
			 << "3. excercise_3: manipulating with matrices\n"
			 << "4. excercise_4: simulates the functions of string.h: strlen(), strcpy(), strcat()\n"
			 << "5. excercise_5: compress and decompress strings\n"
			 << "6. excercise_6: manipulate with polynomials using struct\n"
			 << "7. excercise_7: compare the execution time of the sorting method \n";
		int choose;
		cout << "- Enter your choice(type 1, 2,...): ";
		cin >> choose;
		switch(choose)
		{
			case 1 :
				main1();
				break;
			case 2 :
				main2();
				break;	
			case 3 :
				main3();
				break;
			case 4 :
				main4();
				break;
			case 5 :
				main5();
				break;
			case 6 :
				main6();
				break;
			case 7 :
				main7();
				break;
			default :
				cout << "Let's do something!";
				break;
		}
		cout << "\nDO YOU WANT TO CONTINUE CHECKING OTHER EXERCISE(TYPE Y OR N)?";
		cin >> ans;
		cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
	} while(ans == "Y" || ans == "y");
}
	
// end homework 2

