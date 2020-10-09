/*
 *  hw2_18001166
 *	exercise_2.cpp
 *
 *  Author: Nguyen Van Ninh
 */

#include <bits/stdc++.h>
#include <time.h>
using namespace std;

// sum off odd negative integers
int average(int arr[], int n)
{	
	float sum = 0, count = 0;
	for(int i = 0; i < n; i ++)
	{
		if(arr[i] < 0 && abs(arr[i]) % 2 != 0 )
		{	
			sum = sum + arr[i];
			count ++;
		}
	}
	cout << "- Sum of odd negative integers = " << sum/count;
}

// remove the duplicate elements from the array
int remove(int arr[], int n)
{
	for(int i = 0; i < n; i ++)
	{
		for(int j = i + 1; j < n; )
		{
			if(arr[i] == arr[j])
			{
				for(int k = j; k < n - 1; k ++)
				{
					arr[k] = arr[k + 1];
				}
				-- n;
			}
			else 
				++ j;
		}
	}
	cout << "- Array after remove duplicate elements: ";
	for(int i = 0; i < n; i ++)
	{
		cout << arr[i] << " ";
	}
}

// find min, max
int findminmax(int arr[], int n)
{	
	int min, max;
	min = max = arr[0];
	for(int i = 0; i < n; i ++)
	{
		if(arr[i] <= min)
		{
			min = arr[i];
		}
		if(arr[i] >= max) 
		{
			max = arr[i];
		}
	}
	
	cout << "- Min = " << min;
	cout << "\n- Max = " << max;
}

// simple sort
int sort(int arr[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;        
            }
        }
    }
    
    cout << "- Array after sort:\n";
    cout << "+ ascending: ";
	for(int i = 0; i < n; i ++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n+ decreasing: ";
	for(int i = n; i > 0 ; i --)
	{
		cout << arr[i] << " ";
	}
}
// main
int main2()
{
	cout << "Enter N: ";
	int n; cin >> n;
	int arr[n];
	srand(time(0));
	if(n < 10)
	{
		for(int i = 0; i < n; i ++)
		{
			cout << "arr[" << i << "] = ";
			cin >> arr[i];
		}
	}
	else
	{
		for(int i = 0; i < n; i ++)
		{
			arr[i] = (rand() % 201) - 100;
		}
	} 
	
	string ans;
	do{	
		system("cls");
		cout << "\n                      MANIPULATING A ONE-DIMENSIONAL ARRAY\n";
		cout << "a. Output array\n"
			 << "b. Sum of odd negative integers\n"
			 << "c. Remove the duplicate elements from the array\n"
			 << "d. Find min, max of array\n"
			 << "e. Simple sort\n";
		char choose;
		int count = 0;
		cout << "*Enter your choice(type a, b,...): ";
		cin >> choose;
		switch(choose)
		{
			case 'a' :
				cout << "- Your array: \n";
				for(int i = 0; i < n; i ++)
				{
					cout << setw(6) << arr[i];
					count ++;
					if(count % 10 == 0)
					{
						cout << endl;
					}
				}
				break;
			case 'b' :
				average(arr, n);
				break;	
			case 'c' :
				remove(arr, n);
				break;
			case 'd' :
				findminmax(arr, n);
				break;
			case 'e' :
				sort(arr, n);
				break;
			default :
				cout << "Let's do something!";
				break;
		}
		cout << "\n\nDo you want to continue (type y or n)? ";
		cin >> ans;
	} while(ans == "Y" || ans == "y");
}
