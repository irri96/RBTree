#include "RBTree.h"
#include "AVLTree.h"
#include "BinarySearchTree.h"
#include <set>
#include <iostream>
#include <time.h>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
	set<int> set1;
	RBTree set2;
	AVLTree set3;
	BinarySearchTree set4;
	int n;
	cout<<"Numero de elementos"<<endl;
	cin>>n;
	vector<int> v(n);
	iota(v.begin(), v.end(),0);
	//random_shuffle(v.begin(), v.end());
	cout<<"desOrdenado"<<endl;
	cout<<"Insert:"<<endl;
	clock_t start = clock();
	for(int x:v){
		set1.insert(x);
	}
	cout<<"STL: "<<(double)(clock()-start)/CLOCKS_PER_SEC<<endl;
	start = clock();
	for(int x:v){
		//cout<<"inserto "<<x<<endl;
		set2.insert(x);
	}
	cout<<"RBTree: "<<(double)(clock()-start)/CLOCKS_PER_SEC<<endl;
	start = clock();
	for(int x:v){
		set3.insert(x);
	}
	cout<<"AVLTree: "<<(double)(clock()-start)/CLOCKS_PER_SEC<<endl;
	start = clock();
	for(int x:v){
		set4.insert(x);
	}
	cout<<"BST: "<<(double)(clock()-start)/CLOCKS_PER_SEC<<endl;
	cout<<"voy a destruir la mierda"<<endl;
	return 0;	
}