#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>


typedef std::vector<std::vector<int>> Matrica;


Matrica KreirajMatricu(int m, int n)
{
	return Matrica(m, std::vector<int>(n));
}


int BrojRedova(Matrica M)
{
	return M.size();
}


int BrojKolona(Matrica M)
{
	if(BrojRedova(M)==0) return 0;
	return M.at(0).size();
}


Matrica UnesiMatricu(int m, int n)
{
	auto M(KreirajMatricu(m,n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin>>M.at(i).at(j);
		}
	}
	return M;
}



int Sirina(std::vector<std::vector<int>> Matrica)
{
	int najveca(-1);

	//Ako je sirina matrice 0 vraca se 0
	if(Matrica.size()==0) {
		int sirina(0);
		return sirina;
	}

	int sirina(0);
	for(int i=0; i<Matrica.size(); i++) {
		for(int j=0; j<Matrica.at(i).size(); j++) {

			sirina=0;
			if(Matrica.at(i).at(j)<0) {
				sirina+=1;
			}

			while(Matrica.at(i).at(j)!=0) {
				sirina+=1;
				Matrica.at(i).at(j)/=10;
			}

			if(sirina>najveca) {
				najveca=sirina;
			}
		}
	}

	return sirina;
}


//Ispis matrice
void IspisiMatricu(Matrica M)
{
	for(int i=0; i<BrojRedova(M); i++) {
		for(int j=0; j<BrojKolona(M); j++) {
			int sirina=Sirina(M);
			std::cout<<std::setw(sirina+1)<<M.at(i).at(j);
		}
		std::cout << std::endl;
	}
}


bool Grbava(std::vector<std::vector<int>> M)
{

	if(BrojRedova(M)==0) return false;

	int prvi=M.at(0).size(); //Smijem jer sam prethodno provjerila da ima barem jedan vektor sa ovim iznad

	for(int i=1; i<BrojRedova(M); i++) {
		if(M.at(i).size()!=prvi) return true;
	}

	return false;

}

std::vector<std::vector<int>> KroneckerovProizvod(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B)
{

	if(Grbava(A) && Grbava(B)) {
		throw std::domain_error("Parametri nemaju formu matrice");

	} else if(Grbava(A)) {
		throw std::domain_error("Prvi parametar nema formu matrice");

	} else if(Grbava(B)) {
		throw std::domain_error("Drugi parametar nema formu matrice");
	}

	std::vector<std::vector<int>> C(BrojRedova(A)*BrojRedova(B), std::vector<int>(BrojKolona(A)*BrojKolona(B)));

	for(int i=0; i<BrojRedova(A); i++) {
		for(int j=0; j<BrojKolona(A); j++) {
			for(int k=0; k<BrojRedova(B); k++) {
				for(int l=0; l<BrojKolona(B); l++) {
					C.at(k+BrojRedova(B)*i).at(l+BrojKolona(B)*j)=A.at(i).at(j)*B.at(k).at(l);
				}
			}
		}
	}

	return C;
}


int main ()
{


	try {
		std::cout << "Unesite dimenzije prve matrice:\n";
		int m(0),n(0);
		std::cin>>m>>n;
		if(m<0 || n<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!"<<std::endl;
			return 0;
		}

		std::cout << "Unesite elemente prve matrice:\n";
		std::vector<std::vector<int>> A(UnesiMatricu(m,n)) ;


		std::cout << "Unesite dimenzije druge matrice:\n";
		int k(0),l(0);
		std::cin>>k>>l;
		if(k<0 || l<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!"<<std::endl;
			return 0;
		}

		std::cout << "Unesite elemente druge matrice:\n";
		std::vector<std::vector<int>> B(UnesiMatricu(k,l)) ;


		std::vector<std::vector<int>> KroneckerMatrica;
		KroneckerMatrica=KroneckerovProizvod(A,B);
		int sirina=Sirina(KroneckerMatrica);

		std::cout << "Njihov Kroneckerov proizvod glasi: " << std::endl;

		for(int i=0; i<KroneckerMatrica.size(); i++) {
			for(int j=0; j<KroneckerMatrica.at(i).size(); j++) {
				std::cout << std::setw(sirina+2)<<KroneckerMatrica.at(i).at(j);
			}

			std::cout << std::endl;
		}



	} catch(std::domain_error poruka1) {
		std::cout << "Izuzetak:"<<poruka1.what()<<std::endl;
	} catch(...) {
		throw "Pogresan izuzetak!";
	}


	return 0;
}
