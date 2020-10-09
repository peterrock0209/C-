#include <iostream>
#include <cmath>

using namespace std;

struct hamso{
	int bac;
	int heso[20];
};

int main(){
	struct hamso hamso1,hamso2,hamso3;
	cout<<"Nhap bac cua ham so thu nhat"<<endl;
	cin>>hamso1.bac;
	cout<<"Nhap bac cua ham so thu hai"<<endl;
	cin>>hamso2.bac;
	cout<<"Nhap he so cua ham so thu nhat"<<endl;
	for(int i=0; i<hamso1.bac+1;i++){
		cin>>hamso1.heso[i];
	}
	cout<<"Nhap he so cua ham so thu hai"<<endl;
	for(int i=0; i<hamso2.bac+1;i++){
		cin>>hamso2.heso[i];
	}
	cout<<"Tich cua 2 da thuc la : "<<endl;


	hamso3.bac=hamso1.bac+hamso2.bac;
	for(int i=0;i<hamso3.bac+1;i++){
		hamso3.heso[i]=0;
	}
	for(int i=0;i<hamso1.bac+1;i++){
		for(int j=0;j<hamso2.bac+1;j++){
			hamso3.heso[i+j]+=hamso1.heso[i]*hamso2.heso[j];
		}
	}
	for(int i=0;i<hamso3.bac+1;i++){
		if(hamso3.heso[i] >0 && i>0 ){
			
			cout<<"+"<<hamso3.heso[i]<<"x^"<<hamso3.bac-i;
		}
		if(hamso3.heso[i]>0 && i==0){
			cout<<hamso3.heso[i]<<"x^"<<hamso3.bac-i;
		}
		if(hamso3.heso[i]==0){
			cout<<"";
		}
		if(hamso3.heso[i]<0){
			cout<<hamso3.heso[i]<<"x^"<<hamso3.bac-i;
		}
	}
	cout<<"\n";
	double x;
	double S=0.0;
	int bac=hamso3.bac;
	cout<<"Nhap bien x = "<<endl;
	cin>>x;
	cout<<"Voi x = "<<x<<" da thuc co gia tri la : "<<endl;
	for(int i=0;i<hamso3.bac+1;i++){
			S+=pow(x,bac)*hamso3.heso[i];
			bac--;
	}
	cout<<S<<endl;
	return 0;
}
