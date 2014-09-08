//Author:		A. J. Montenigro
//Date:			08.31.2014
//Time start:	22:41 CST

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

bool isPrime(int);
//int arraySize(int&);

int main() {
	int primesList[3432];
	int t,n,x = 0;
	int bound = 0;
	int addendLo;
	int addendHi;
	ifstream infile;
	ofstream outfile;
	infile.open("goldbach.in");
	outfile.open("goldbach.out");

	//Generate list of primes
	//3432 prime numbers < 32000
	//31991 is the last prime number < 32000
	
	//loop used to find count of primes < 32000
	/*
	for(int i = 0; i < 32000; i++){
		if(isPrime(i)) t++;
	}
	cout << t << endl;
	*/
	///*
	for(int i = 0, t = 0; i < 32000; i++){
		if(isPrime(i)){
			primesList[t] = i;
			t++;
		}
	}
	/*
	for (int i = 0; i < 10; i++){
		cout << primesList[i] << endl;
	}
	cout << primesList[3431] << endl;
	//*/

	//cin >> n;		//Assumes 1 <= n <= 100
	infile >> n;
		
	for(int i = 0, u = 0; i < n; i++){
		bool* map;
		infile >> x;	//read the number to factor
		bound = ((int)sqrt(x))+1;	//after this number we've checked all possible combos
		map = new bool[bound];
		for(int j = 0; primesList[j] < bound; j++){
			addendLo = primesList[j];
			addendHi = (x-addendLo);
			map[j] = isPrime(addendHi);
			if(map[j]) u++;
		}
		cout << x << " has " << u << " representation(s)" << endl;
		outfile << x << " has " << u << " representation(s)" << endl;
		for(int j = 0, k = 0; j < bound; k++){
			if(map[k] == false) continue;
			else{
				j++;
				addendLo = primesList[k];
				addendHi = (x-addendLo);
				cout << addendLo << "+" << addendHi << endl;
				outfile << addendLo << "+" << addendHi << endl;
			}
		}
		cout << endl << endl;

		delete[] map;
		map = NULL;
	}
	return 0;
}


bool isPrime(int num){
	//cout << "trace "<< num << endl;
	//I got this algorithm from the Wikipedia page for finding prime numbers
	if (num <= 3){
		if (num <= 1) return false;
        return true;
	}
    //cout << "trace > 3" << endl;
	if ( !(num % 2) || !(num % 3) ) return false;
    
	int bound = ((int)sqrt(num))+1;
    for (int i = 5; i < bound; i+=6){
    	if ( (num%i == 0) || (num%(i+2)) == 0) return false;
    }        
    return true;
}

