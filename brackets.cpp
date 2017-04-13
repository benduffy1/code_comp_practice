#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <set>
#include <stack>



using namespace std;

int main(){
	ifstream fid("brackets.in");
	vector<string> output(550);
	string line;
	
	//stack<char> mystack;
	
	int linenumber = -1;
	while (getline(fid,line)){
	linenumber++;
	stack<char> mystack;
	//cout <<line<<endl;
	int i;
	for (i=0;i<line.length();i++){
		
		//bool openbracket = ((line[i] == '(') | (line[i] == '['));
		
			//cout<<line[i]<<endl;
			//cout <<i<<endl;
		
		if (i == 0 && ((line[i] == ']') | (line[i] == ')'))){
			mystack.push('s');
			output[linenumber] = "NO";
			break;
		}
		
		
		if ((line[i] == '(') | (line[i] == '[')){
			
			//cout<<line[i]<<endl;
		//	cout <<i<<endl;
			//mystack.push(line[i]);
			
			if (line[i]=='('){
				mystack.push(')');
			//cout <<line[i]<<" therefore pushed "<<')'<<endl;

			}else{
				mystack.push(']');
			//	cout <<line[i]<<" therefore pushed "<<']'<<endl;
			}
			
		//	cout <<"pushed"<<line[i]<<endl;
			
		}else{
			
			if (mystack.empty()){
				output[linenumber] = "NO";
			//	cout <<"NO"<<endl;
				break;
			}
			
			if (line[i] == mystack.top()){
			//	cout <<"stacksize "<< mystack.size()<<endl;
			//	cout <<"popped"<<mystack.top()<<endl;
				mystack.pop();
				
			//	cout<<"closed bracket"<<line[i]<<endl;
			//	cout <<"stacksize "<< mystack.size()<<endl;
			}else{
					output[linenumber] = "NO";

				break;
			}
		}
	}
	
	if (mystack.empty()){
	//	cout <<"Yes"<<endl;
	
	if (output[linenumber]=="NO"){
		
	}else{
		output[linenumber] = "YES";
	}	
		
		
	}else{
		output[linenumber] = "NO";
	}
	}
std::ofstream f("brackets.out");
string string1;
for(vector<string>::const_iterator i = output.begin(); i != output.end(); ++i) {
	
	string1 = *i;
	if (string1.empty()){
		break;
	}
    f << *i << '\n';
}

	return 0;
}