/*
 *  hw2_18001166
 *	erastosthenes.cpp
 *
 *  Author: Nguyen Van Ninh
 */

#include <bits/stdc++.h>
using namespace std;

int eras(int n)
{
	bool arr[n +  1];
	memset(arr, true, sizeof(arr));

	for (int i = 2; i <= n; i ++)
	{
		if(arr[i] == true)
		{
			for (int j = 2*i; j <= n; j += i)
			{	
				arr[j] = false;
			}
		}
	}
//
//	for (int i = 2; i*i <= n; i ++) 
//    {	
//	    if (arr[i] == true) 
//	        { 
//	        for (int j = i*i; j <= n; j += i) 
//                arr[j] = false; 
//        } 
//    }
		
	int count = 0;
	for (int i = 2; i <= n; i ++)
	{
		if(arr[i] == true)
		{
			cout << setw(6) << i;
			count ++;
			if(count % 10 == 0)
			{
				cout << endl;
			}
		}
	}
}

int main1()
{	
	cout << "\n                      ERATOSTHENES SCREENING ALGORITHM\n";
	cout << "Enter n: ";
	int n;
	cin >> n;
	cout << "The primes smaller n is: \n"; 
	eras(n);
}
