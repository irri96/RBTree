#include "RBTree.h"
#include "AVLTree.h"
#include "BinarySearchTree.h"
#include <set>
#include <iostream>
#include <time.h>
#include <numeric>
#include <algorithm>
 #include <sys/resource.h>
using namespace std;

int main(){
	
	rlimit rl;
	getrlimit(RLIMIT_STACK, &rl);
	rl.rlim_cur=1024L*1024L*256L;//256mb
	setrlimit(RLIMIT_STACK, &rl);
	set<int> set1;
	RBTree set2;
	AVLTree set3;
	BinarySearchTree set4;
	int n;
	cout<<"Numero de elementos"<<endl;
	cin>>n;
	vector<int> v(n);
	iota(v.begin(), v.end(),0);
	random_shuffle(v.begin(), v.end());	//comentar esta linea para entrada ordenada
	//cout<<"desOrdenado"<<endl;
	cout<<"Insert:"<<endl;
	cout<<n<<"\t";
	clock_t start = clock();
	for(int x:v){
		set1.insert(x);
	}
	cout<<(double)(clock()-start)/CLOCKS_PER_SEC<<"\t";
	start = clock();
	for(int x:v){
		//cout<<"inserto "<<x<<endl;
		set2.insert(x);
	}
	cout<<(double)(clock()-start)/CLOCKS_PER_SEC<<"\t";
	start = clock();
	for(int x:v){
		set3.insert(x);
	}
	cout<<(double)(clock()-start)/CLOCKS_PER_SEC<<"\t";
	start = clock();
	for(int x:v){
		set4.insert(x);
	}
	cout<<(double)(clock()-start)/CLOCKS_PER_SEC;

	cout<<endl;
	cout<<"Search"<<endl;
	cout<<n<<"\t";
	start = clock();
	for(int x:v){
		//cout<<"inserto "<<x<<endl;
		set1.count(x);
	}
	cout<<(double)(clock()-start)/CLOCKS_PER_SEC<<"\t";
	start = clock();
	for(int x:v){
		//cout<<"inserto "<<x<<endl;
		set2.search(x);
	}
	cout<<(double)(clock()-start)/CLOCKS_PER_SEC<<"\t";
	start = clock();
	for(int x:v){
		//cout<<"inserto "<<x<<endl;
		set3.search(x);
	}
	cout<<(double)(clock()-start)/CLOCKS_PER_SEC<<"\t";
	start = clock();
	for(int x:v){
		//cout<<"inserto "<<x<<endl;
		set4.search(x);
	}
	cout<<(double)(clock()-start)/CLOCKS_PER_SEC<<"\n";
	
	return 0;	
		
}