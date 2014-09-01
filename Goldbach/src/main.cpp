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
	int t = 0;
	int** addLo;
	int** addHi;
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
	for (int i = 0; i < 10; i++){
		cout << primesList[i] << endl;
	}
	cout << primesList[3431] << endl;
	//*/
	//cout << t << endl;
	//cout << isPrime(5) << endl;

	//cin >> n;		//Assumes 1 <= n <= 100
	
	
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

