/*
 *  hw2_18001166
 *	exercise_3.cpp
 *
 *  Author: Nguyen Van Ninh
 */

#include <bits/stdc++.h>
#include <time.h>
using namespace std;
const int LENGTH = 100;


void makeMatrix(int arr[][LENGTH], int n)
{	
	srand(time(0));
	int i, j;
	if (n <= 3) 
	{
		for(i = 0; i < n; i ++){
			for(j = 0; j < n; j ++)
			{
				cout << " arr[" << i << "][" << j << "] = ";
				cin >> arr[i][j];
			}
		}
	}
	else 
	{
		for(i = 0; i < n; i ++){
			for(j = 0; j < n; j ++)
			{
				arr[i][j] = (rand() % 201) - 100;
			}
		}
	}
}
// print out matrix
void printMatrix(int arr[][LENGTH], int n)
{
	for(int i = 0; i < n; ++i)
  	{
		for(int j = 0; j < n; ++j)
	        cout << setw(5) << arr[i][j];
	        cout << "\n";
    }
}

// transpose matrix
void transposeMatrix(int arr[][LENGTH], int transpose[][LENGTH], int n) 
{
	int i, j;
	for(i = 0; i < n; i ++)
		for(j = 0;j < n; j++)
		{
			transpose[i][j] = arr[j][i];
		}
		
	cout << "- Transpose matrix \n";
	for(int i = 0; i < n; ++i)
  	{
		for(int j = 0; j < n; ++j)
	        cout << setw(5) << transpose[i][j];
	        cout << "\n";
    }
	
}
// print secondary diagonal 
void printSecondaryDiagonal(int matrix[][LENGTH], int n)
{
	for(int sum = 0; sum < 2*n; sum++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i + j + 1 == sum)
				{
					cout << setw(5) << matrix[i][j];
				}
			}
		}
		cout << "\n";
	}
}

void sumColumnValue(int arr[][LENGTH], int n) 
{ 
  	int sumCol[n] = {0, 0};
    // finding the column sum 
    for (int i = 0; i < n; ++i) 
	{ 
        for (int j = 0; j < n; ++j) 
		{ 
              sumCol[i] += arr[j][i]; 
        } 
    }
    
    for (int i = 0; i < n - 1; ++i) 
	{ 
        for (int j = i + 1; j < n; ++j) 
		{ 
			if(sumCol[i] > sumCol[j])
			{
			    for(int k = 0; k < n; k++)
				{
				int temp = arr[k][j];
				arr[k][j] = arr[k][i];
				arr[k][i] = temp;
				}
			}
        } 
    }
	cout << "- Matrix after sort by sum of column value\n"; 
	printMatrix(arr, n);
} 

// find the saddle points
bool saddlePoints(int arr[][LENGTH], int n ){
	for (int i = 0; i < n; i++) 
    { 
        int min_row = arr[i][0], index = 0; // column index
        for (int j = 1; j < n; j++) 
        { 
            if (min_row > arr[i][j]) 
            { 
                min_row = arr[i][j]; 
                index = j; 
            } 
        } 
  
        int k; 
        for (k = 0; k < n; k++) 
            if (min_row < arr[k][index]) 
                break; 
  
        if (k == n) 
        { 
           cout << "Value of saddle point " << min_row; 
           return true; 
        } 
    } 
    // if saddle point not found 
    return false;
}
	
// main
int main3()
{	
	int n;
	int a[LENGTH][LENGTH], b[LENGTH][LENGTH];
	string ans;
	do{	
		system("cls");
		cout << "\n                      MANIPULATING WITH MATRICES\n";
		cout << "a. Make & print matrix\n"
			 << "b. Transpose matrix\n"
			 << "c. Sort matrix by sum of column value\n"
			 << "d. Export all diagonal lines parallel to the secondary diagonal\n" 
			 << "e. Find the saddle points of the matrix\n";
		char choose;
		cout << "*Enter your choice(type a, b,...): ";
		cin >> choose;
		switch(choose)
		{
			case 'a' :
				cout << "Enter n: ";
				cin >> n;
				makeMatrix(a, n);
				cout << "- Matrix \n";
				printMatrix(a, n);
				break;
			case 'b' :
				cout << "- Original matrix \n";
				printMatrix(a, n);
				transposeMatrix(a, b, n);
				break;
			case 'c' :
				cout << "- Original matrix \n";
				printMatrix(a, n);
				sumColumnValue(a, n);
				break;
			case 'd' :
				cout << "- Original matrix \n";
				printMatrix(a, n);
				cout << "- All diagonal lines parallel to the secondary diagonal\n";
				printSecondaryDiagonal(a, n);
				break;
			case 'e' :
				cout << "- Original matrix \n";
				printMatrix(a, n);
				if (saddlePoints(a, n) == false) 
       			cout << "- No Saddle Point ^^";
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
