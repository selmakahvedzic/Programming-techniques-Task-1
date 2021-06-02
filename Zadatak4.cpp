#include <iostream>
#include <vector>
#include <string>
#include <cctype>


bool SlovoCifra(std::string rijec)
{
	for(int i=0; i<rijec.length(); i++) {
		if((rijec.at(i)>='0' && rijec.at(i)<='9') || (rijec.at(i)>='A' && rijec.at(i)<='Z') || (rijec.at(i)>='a' && rijec.at(i)<='z')) {
			return true;
		}
	}
	return false;
}



bool Palindrom(std::string rijec)
{
	for(int i=0; i<rijec.length()/2; i++) {
		if(toupper(rijec.at(i))!=toupper(rijec.at(rijec.length()-i-1))) return false;
	}
	return true;
}

std::vector<std::string> IzvuciRijeci(std::string s)
{
	std::vector<std::string> rijeci;
	std::string rijec;

	for(int i=0; i<s.length(); i++) {
		if(s.at(i)!=' ') {
			rijec.push_back(s.at(i));
		}

		if(s.at(i)==' ' || i==s.length()-1) {
			if(rijec.length()>1 && SlovoCifra(rijec)) rijeci.push_back(rijec);
			rijec.clear();
		}
	}

	return rijeci;
}

std::vector<std::string> NadjiSimetricneRijeci(std::string recenica)
{
	std::vector<std::string> pomocni=IzvuciRijeci(recenica);
	std::vector<std::string> rezultat;

	for(auto x : pomocni) {
		if(Palindrom(x)==true) {
			rezultat.push_back(x);
		}
	}

	return rezultat;
}




int main ()
{

    std::string recenica;
    std::cout << "Unesite recenicu: " << std::endl;
    std::getline(std::cin, recenica);

    std::vector<std::string> SimetricneRijeci;
    SimetricneRijeci=NadjiSimetricneRijeci(recenica);


	if(SimetricneRijeci.size()==0) {
		std::cout << "Recenica ne sadrzi simetricne rijeci!" << std::endl;
		return 0;
	}

	std::cout<<"Simetricne rijeci unutar recenice su: "<<std::endl;

	for(auto x : SimetricneRijeci) {
		std::cout << x <<std::endl;
	}


	return 0;
}
