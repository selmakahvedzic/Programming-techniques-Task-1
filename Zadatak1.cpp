#include <iostream>
#include <cmath>
#include <vector>


int ObrniBroj(int broj) {
	int novi(0), cifra(0);
	
	while(broj!=0) {
		cifra=broj%10;
		novi=(novi*10)+cifra;
		broj=broj/10;
	}
	
	return novi;
}


int BrojOtpornosti(int element) {
	
	int brojac(0);
	if(element<0) element=-element;
	
	if(element==ObrniBroj(element)) {
		return 0;
	}
	
	do {
		element+=ObrniBroj(element);
		brojac++;
	} while(element!=ObrniBroj(element));
	
	return brojac;
}



std::vector<int>PalindromskaOtpornost(std::vector<int> v) {
	std::vector<int>vektor;
	
	for(int i : v) {
		vektor.push_back(BrojOtpornosti(i));
	}
	
	return vektor;
}



int main () {
	

	
	int n(0);
	do {
	std::cout<<"Koliko zelite unijeti elemenata: ";
	std::cin>> n;
	} while(n<0);
	
	std::vector<int> vektor(n);
	std::vector<int> palindromi(n);
	
	std::cout << "Unesite elemente: ";
	for(int i=0; i<n; i++) {
		std::cin >> vektor.at(i);
	}
	
	palindromi=PalindromskaOtpornost(vektor);
	
    for(int i=0; i<vektor.size(); i++) {
		std::cout<<"Palindromska otpornost broja " << vektor.at(i) <<" iznosi "<<palindromi.at(i)<<std::endl;
		}

	
	return 0;
}
