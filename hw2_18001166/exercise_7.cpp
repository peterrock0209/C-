#include <bits/stdc++.h> 
#include <cstdlib> 
#include <ctime> 
#include <iostream>
using namespace std; 

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

/* A function to implement bubble sort */
void bubbleSort(int arr[], int n) 
{ 
	int i, j; 
	for (i = 0; i < n-1; i++)	 
	
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1]) 
			swap(&arr[j], &arr[j+1]); 
} 

/* A function to implement insertion sort */
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  

/* A function to implement selection sort */
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        	if (arr[j] < arr[min_idx])  
           		min_idx = j;  

        swap(&arr[min_idx], &arr[i]);  
    }  
} 

/* A function to implement quick sort*/
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];  
    int i = (low - 1);  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++; 
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);    
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

/* main */
int main7() 
{ 	
	int size;
	cout << "- Enter the number of array elements: ";
	cin >> size;
	system("cls");
	int arr[size], count = 0; 
	if(size > 20000)
	{
		cout << "\nWait a minute hehe... ^^  \n";
	}
	srand((unsigned)time(0));
	
	for(int i = 0; i < size; i++)
	{ 
        arr[i] = (rand() % 100) + 1; 
//        cout << setw(5) << arr[i];
//		count ++;
//		if(count % 15 == 0)
//		{
//			cout << endl;
//		}
    } 	
   
	clock_t start1, start2, start3, start4, end1, end2, end3, end4; // khoi tao bien thoi gian chay
	
	start1 = clock();
	bubbleSort(arr, size);
	end1 = clock(); 
	double time1 = double(end1 - start1) / double(CLOCKS_PER_SEC); 
    
    start2 = clock();
	insertionSort(arr, size);  
    end2 = clock(); 
	double time2 = double(end2 - start2) / double(CLOCKS_PER_SEC); 
	
	start3 = clock();
	selectionSort(arr, size);  
    end3 = clock(); 
	double time3 = double(end3 - start3) / double(CLOCKS_PER_SEC); 
	
	start4 = clock();
	quickSort(arr, 0, size - 1);   
    end4 = clock(); 
	double time4 = double(end4 - start4) / double(CLOCKS_PER_SEC); 
	
//	cout << "\n\n- Sorted array: ";  
//    printArray(arr, size); 
	system("cls");
	cout << "\n                                     SORTING ALGORITHMS            \n";
	cout << "\n                  -----------Runtime of sorting algorithms------------ \n";
	cout << "      BUBBLE SORT         INSERTION SORT           SELECTION SORT          QUICK SORT   \n";
	cout << "     " << fixed << time1 << setprecision(5) << " sec    " 
	   	 << "      " << fixed << time2 << setprecision(5) << " sec        "
	   	 << "      " << fixed << time3 << setprecision(5) << " sec      "
	   	 << "      " << fixed << time4 << setprecision(5) << " sec \n\n\n";
	   	 
	return 0; 
} 


