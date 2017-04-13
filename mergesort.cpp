#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
using namespace std;
long long int invcount=0;

void merge(vector<int>& array,int lowind,int midind,int highind){
	
	vector<int> L(array.begin()+lowind,array.begin()+midind+1);
	vector<int> R(array.begin()+midind+1,array.begin()+highind+1);
//		cout<<"L= ";
	for (vector<int>::const_iterator i = L.begin();i!=L.end();i++){
//		cout <<*i<<' ';
	 }

	for (vector<int>::const_iterator i = R.begin();i!=R.end();i++){
//		cout<<*i<<' ';
	 }
//	 cout<<endl;
	int sizeL = midind-lowind +1;
	int sizeR = highind - midind;

//	cout<<"low ind " <<lowind<<endl;
//	cout<<"mid ind" <<midind<<endl;
//	cout<<"high ind" <<highind<<endl;

	int l = 0;
	int r = 0;
	int arrayind = lowind;
	
//	cout<<"sizeL" <<sizeL<<endl;
//	cout<<"sizeR" <<sizeR<<endl;
	
	while (l < sizeL && r < sizeR){
		
		if (L[l]<=R[r]){
			array[arrayind] = L[l];
			l++;
			
		}else{
			array[arrayind]=R[r];
			r++;
			invcount = invcount+ midind-lowind+1-l;
//			cout<<"invcount "<<invcount<<endl;
		}
//		cout<<array[arrayind]<<endl;
		arrayind++;
//		cout<<"r"<<r<<endl;
//		cout<<"l"<<l<<endl;
		}
		
		while (l < sizeL){
			array[arrayind] = L[l];
			l++;
			arrayind++;
		}
		
		while (r < sizeR){
			array[arrayind] = R[r];
			r++;
			arrayind++;
		}

//	cout <<"end of merge"<<endl;
	invcount;
}


void mergesort(vector<int> &array,int lowind,int highind){
	//int invcount1 = 0;
	if (lowind<highind){
		int m = lowind + ((highind-lowind)/2);
		
		mergesort(array,lowind,m);
		mergesort(array,m+1,highind);
		merge(array,lowind,m,highind);
		
		//cout<<"invcount "<<invcount <<endl;
		//cout<<"invcount1 "<<invcount1 <<endl;
		
//		cout<<"lowind "<< lowind;
//		cout<<"m "<< m;
//		cout<<"highind "<< highind;
//	for (vector<int>::const_iterator i = array.begin();i!=array.end();i++){
//		cout <<*i<<" ";
//	 }
	// cout<<endl;
	
	
	}
}


int main(){

//vector<int> test = {20,4,6,7};
vector<int> test;	
	
	//for(vector<int>::const_iterator i = test.begin();i!=test.end();i++){
		//cout<<*i<<endl;
	// }
	
//	merge(test,0,3,7);

ifstream fid("inversions.in");

string line;

  if (fid.is_open())
  {
getline (fid,line);
getline (fid,line);
				
istringstream is( line );
    int n;
    while( is >> n ) {
		test.push_back(n);
    }		
	
//    cout << line << '\n';
	  
    fid.close();
  }

//vector<int> test = {1,8,2,1,4,7,3,2,3,6};
//vector<int> test = {1,8,2,1,4,7,3,2,3,6};

mergesort(test,0,test.size()-1);
	
	for (vector<int>::const_iterator i = test.begin();i!=test.end();i++){
//		cout<<*i<<' ';
	}

std::ofstream f("inversions.out");

f<<invcount<<endl;

cout<<endl<<invcount<<endl;	
	return 0;
}