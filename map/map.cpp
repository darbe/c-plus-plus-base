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
	m.insert(make_pair(3,A(3)));
	cout << "-----------------------------"<<endl;
}
/*
 * -----------------------------
 *  user_defined
 *  0x7fff2ef11460
 *  default constructor
 *  0x7fff2ef113e0
 *  A copy constructor val is10
 *  cp 0x7fff2ef113e0 to 0x7fff2ef113d4
 *  A copy constructor val is10
 *  cp 0x7fff2ef113d4 to 0x1cb6c44
 *  delete val is 10
 *  0x7fff2ef113d4
 *  delete val is 10
 *  0x7fff2ef113e0
 *  A assign constructor val is1
 *  cp 0x7fff2ef11460 to 0x1cb6c44
 *  delete val is 1
 *  0x7fff2ef11460
 *  -----------------------------
 *  user_defined
 *  0x7fff2ef11470
 *  A copy constructor val is2
 *  cp 0x7fff2ef11470 to 0x7fff2ef11424
 *  delete val is 2
 *  0x7fff2ef11470
 *  -----------------------------
 *  A copy constructor val is2
 *  cp 0x7fff2ef11424 to 0x7fff2ef11484
 *  A copy constructor val is2
 *  cp 0x7fff2ef11484 to 0x1cb6c74
 *  delete val is 2
 *  0x7fff2ef11484
 *  -----------------------------
 *  user_defined
 *  0x7fff2ef114b0
 *  A copy constructor val is3
 *  cp 0x7fff2ef114b0 to 0x7fff2ef114a4
 *  A copy constructor val is3
 *  cp 0x7fff2ef114a4 to 0x7fff2ef11494
 *  A copy constructor val is3
 *  cp 0x7fff2ef11494 to 0x1cb6ca4
 *  delete val is 3
 *  0x7fff2ef11494
 *  delete val is 3
 *  0x7fff2ef114a4
 *  delete val is 3
 *  0x7fff2ef114b0
 *  -----------------------------
 *  delete val is 2
 *  0x7fff2ef11424
 *  delete val is 3
 *  0x1cb6ca4
 *  delete val is 2
 *  0x1cb6c74
 *  delete val is 1
 *  0x1cb6c44
 */
