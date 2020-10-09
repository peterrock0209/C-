/*
 *  hw2_18001166
 *	exercise_6.cpp
 *
 *  Author: Nguyen Van Ninh
 */

// program for polynomial

#include <iostream>
#include <cmath>
using namespace std;

const int MAX_SIZE = 20;
/* struct polynomial */
struct poly{
	int deg;
	int coef[20];
};

void displayPoly(struct poly p)
{
	for(int i = 0 ; i < p.deg + 1 ; i++)
	{
		if(p.coef[i] > 0 && i > 0 )
		{	
			cout << " + " << p.coef[i] << "x^" << p.deg - i;
		}
		if(p.coef[i] > 0 && i == 0 || p.coef[i] < 0 && i == 0)
		{
			cout << p.coef[i] << "x^" << p.deg - i;
		}
		if(p.coef[i] == 0 || i == 0)
		{
			cout << "";
		}
		if(p.coef[i] < 0)
		{
			cout << p.coef[i] << "x^" << p.deg - i;
		}
	}
}

/* main */
int main6()
{
	struct poly poly1, poly2, poly3;
	
	cout << "\n                      MANIPULATE WITH POLYNOMIALS USING STRUCT\n";
	
	cout << "- Enter the degree of the first polynomial: "; // nhap bac cua da thuc 1	
	cin >> poly1.deg;
	cout << "+ Enter the coefficients: " << endl; // nhap cac he so cua da thuc
	for(int i = 0; i < poly1.deg + 1; i++)
	{
		cout << "coef[" << i << "] = ";
		cin >> poly1.coef[i];
	}
	cout << "-> The polynomials is: ";
	displayPoly(poly1);
	
	cout << "\n\n- Enter the degree of the second polynomial: "; // nhap bac cua da thuc 2
	cin >> poly2.deg;
	cout << "+ Enter the coefficients: " << endl; // nhap cac he so cua da thuc
	for(int i = 0; i < poly2.deg + 1; i++)
	{
		cout << "coef[" << i << "] = ";
		cin >> poly2.coef[i];
	}
	cout << "-> The polynomials is: ";
	displayPoly(poly2);
	
	
	poly3.deg = poly1.deg + poly2.deg;

	for(int i = 0; i < poly3.deg + 1; i++)
	{
		poly3.coef[i] = 0;
	}
	
	/* nhan cac he so voi nhau */
	for(int i = 0; i < poly1.deg + 1; i++)
	{
		for(int j = 0; j < poly2.deg + 1; j++)
		{
			poly3.coef[i + j] += poly1.coef[i] * poly2.coef[j];
		} 
	}
	cout << "\n\n- Product of 2 polynomials is: ";
	displayPoly(poly3);
	
	cout << "\n";
	double x;
	double result = 0.0;
	int deg = poly3.deg;
	cout << "- Value of x = ";
	cin >> x;
	for(int i = 0; i < deg + 1;i++)
	{
		result += poly3.coef[i]*pow(x, deg);
	}
	
	cout << "-> The polynomial value at x = " << x << " is " << result << endl;
	return 0;
}



/* -------------------something wrong----------------------------- */
///* functions */
//int readPoly(struct poly []);
//void displayPoly(struct poly p, int term);
//int calculate(struct poly p, int n);
//
//int main()
//{
//	struct poly poly1[MAX_SIZE], poly2[MAX_SIZE], poly3[MAX_SIZE];
//	
//	cout << "- Enter the degree of the first polynomial: "; // nhap bac cua da thuc 1
//	cin >> poly1->deg;
//	readPoly(poly1);
//	
//	cout << "- Enter the degree of the second polynomial: "; // nhap bac cua da thuc 2
//	cin >> poly2->deg;
//	readPoly(poly2);
//}
//
///* read polynomial */
//void readPoly(struct poly p)
//{	
//	cout << "- Enter the coefficients: "; // nhap cac he so cua da thuc
//	for(int i = 0; i < p.deg + 1; i++)
//	{
//		cin >> p.coef[i];
//	}
//}
//
///* display polynomial */
//void displayPoly(struct poly p)
//{
//	for(int i = 0; i < p.deg + 1; i++)
//	{
//		if(p.coef[i] > 0 && i > 0 )
//		{
//			cout << " + "<< p.coef[i] << "x^" << p.deg - i;
//		}
//		if(p.coef[i] > 0 && i == 0){
//			cout << p.coef[i] << "x^" << p.deg - i;
//		}
//		if(p.coef[i] == 0){
//			cout << "";
//		}
//		if(p.coef[i] < 0){
//			cout << p.coef[i] << "x^"<< p.deg - i;
//		}
//	}
//}
//
///* calculate the value of the polynomial at x */
//int calculate(struct poly p[], double x)
//{
//	double value = 0.0;
//	for(int i = 0; i < p->deg + 1; i++)
//	{
//			value += pow(x, p->deg)*p->coef[i];
//			p->deg--;
//	}
//}
//
//
//

