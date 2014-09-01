//Author:		A. J. Montenigro
//Date:			08.31.2014
//Time start:	22:41 CST

#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int);
//int arraySize(int&);

int main() {
	int primesList[3432];
	int t = 0;
	int** addLo;
	int** addHi;

	//Generate list of primes
	//3432 prime numbers < 32000
	//31991 is the last prime number < 32000
	/*
	//loop used to find count of primes < 32000
	for(int i = 0; i < 32000; i++){
		if(isPrime(i)) t++;
	}
	cout << t << endl;
	*/
	
	for(int i = 0; i < 31993; i++){
		if(isPrime(i)){
			primesList[t] = i;
			t++;
		}
	}
	//cout << t << endl;

	cin >> n;		//Assumes 1 <= n <= 100
	
	
	return 0;
}


bool isPrime(int num){
	//cout << "trace "<< num << endl;
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

