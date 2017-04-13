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

	int sizeL = midind-lowind +1;
	int sizeR = highind - midind;

	int l = 0;
	int r = 0;
	int arrayind = lowind;
	
	while (l < sizeL && r < sizeR){
		
		if (L[l]<=R[r]){
			array[arrayind] = L[l];
			l++;
			
		}else{
			array[arrayind]=R[r];
			r++;
			invcount = invcount+ midind-lowind+1-l;
		}
		arrayind++;

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

	invcount;
}


void mergesort(vector<int> &array,int lowind,int highind){
	if (lowind<highind){
		int m = lowind + ((highind-lowind)/2);
		
		mergesort(array,lowind,m);
		mergesort(array,m+1,highind);
		merge(array,lowind,m,highind);

	}
}


int main(){

vector<int> test;	

//ifstream fid("inversions.in");

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
	  
    fid.close();
  }


mergesort(test,0,test.size()-1);
	
	for (vector<int>::const_iterator i = test.begin();i!=test.end();i++){
	}

//std::ofstream f("inversions.out");

f<<invcount<<endl;

cout<<endl<<invcount<<endl;	
	return 0;
}