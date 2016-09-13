#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;

class Base {
private:
	int val;
public :
	Base(){cout << "init base " << val<<endl;}
	Base(int v):val(v){cout << "base "<<val<<endl;};
};

class Drived : public Base{
private:
	Base b1;
	Base b2;
public: 
	Drived(int i, int j ,int k):Base(i),b2(j){cout << "Drived"<<endl;}
};

class A{
public :
	int val;
public :
	A(){
		cout << "default constructor" <<endl; val = 10;
		printf("%p\n",this);
	}
	A(int v):val(v){
		cout << "user_defined" << endl;
		printf("%p\n",this);
	}
	A(const A& tmp){
	   	cout << "A copy constructor val is" << tmp.val<<endl ;
		printf("cp %p to %p\n",&tmp,this);
		this->val = tmp.val;
	}
	A& operator= (const A& tmp){
	   	cout << "A assign constructor val is" << tmp.val<<endl;
		printf("cp %p to %p\n",&tmp,this);
		this->val = tmp.val;
		return *this;
	}
	~A(){
		cout << "delete val is "<<val << endl;
		printf("%p\n",this);
	}
};
int main(){
	//Drived d(1,2,3);
	cout << "-----------------------------"<<endl;
	map<int, A> m;
	m[1] = A(1);
	cout << "-----------------------------"<<endl;
	pair<int , A> p = make_pair(2,A(2));
	cout << "-----------------------------"<<endl;
	m.insert(p);
	cout << "-----------------------------"<<endl;
}
