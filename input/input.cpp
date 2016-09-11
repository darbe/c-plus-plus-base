#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<sstream>
using namespace std;
int main(){
/*------------------------------
	string s;
	getline(cin,s);
        stringstream ss(s);
	while(getline(ss,s,',')){
		int val = atoi(s.c_str());
		cout << val <<endl;
	}
---------------------------------------------*/
        string str;
	getline(cin,str);
	char* cstr = const_cast<char*> (str.c_str());
	char * s = strtok(cstr,",");
	while(s){
		int val = atoi(s);
		cout << val <<endl;
		s = strtok(NULL,",");
	}
		
}
