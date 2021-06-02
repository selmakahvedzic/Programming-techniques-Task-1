#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <complex>

typedef std::vector<std::vector<int>> Matrica;

//Kreira matricu sa zadanim brojem redova i kolona
Matrica KreirajMatricu(int m, int n)
{
	return Matrica(m, std::vector<int> (n));
}

//Vraca broj redova zadane matrice
int BrojRedova(Matrica M)
{
	return M.size();
}

//Vraca broj kolona zadane matrice
int BrojKolona(Matrica M)
{
	if(BrojRedova(M)==0) return 0;
	return M.at(0).size();
}

//Unosi matricu
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

void IspisiMatricu(Matrica M)
{
	for(int i=0; i<BrojRedova(M); i++) {
		for(int j=0; j<BrojKolona(M); j++) {
			std::cout << std::setw(5) << M.at(i).at(j);
		}
		std::cout << std::endl;
	}
}

bool Grbava(Matrica M)
{
	if(BrojRedova(M)==0 || BrojKolona(M)==0) return false;

	int prvi=M.at(0).size();

	for(int i=1; i<BrojRedova(M); i++) {
		if(M.at(i).size()!=prvi) return false;
	}

	return true;
}


std::complex<double> VrhMatrice(Matrica M, int i, int j)
{

	std::complex<double> Vrh;

	if(Grbava(M)==false) {
		throw std::domain_error("Nekorektna matrica");
	}

	if(i<0 || j<0 || i>=BrojRedova(M) || j>=BrojKolona(M)) {
		throw std::range_error("Nekorektna pocetna pozicija");
	}

	int max=M.at(i).at(j);
	int d_red=i-1, g_red=i+1, d_kolona=j-1, g_kolona=j+1;


	if(i==0) d_red=i;
	if(j==0) d_kolona=j;
	if(i==BrojRedova(M)-1) g_red=i;
	if(j==BrojKolona(M)-1) g_kolona=j;

	/*int max_i, max_j;
	for(int m=0; m<BrojRedova(M); m++) {
		for(int n=0; n<BrojKolona(M); n++) {
			int k,l;
			for(k=d_red; k<=g_red; k++) {
				if(k<0 || k>BrojRedova(M)) continue;
				for(l=d_kolona; l<=g_kolona; l++) {
					if(l<0 || l>BrojKolona(M)) continue;
					if(M.at(k).at(l)>max) {
						max=M.at(k).at(l);

						max_i=k;
						max_j=l;


					}
				}

			}

		}
	}

	i=max_i;
	j=max_j;*/
	
	
	for(int k=0; k<BrojKolona(M); k++) {
		for(int l=0; l<BrojKolona(M); l++) {
			if(M.at(k).at(l)>max) {
				i=k;
				j=l;
			}
		}
	}


	return (double){i,j};
}




int main ()
{

	try {

		std::cout << "Unesite broj redova i kolona matrice: ";
		int m(0),n(0);
		std::cin >> m >> n;
		if(m<0 || n<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
			return 0;
		}

		std::cout << "\nUnesite elemente matrice:";
		std::vector<std::vector<int>> M(UnesiMatricu(m,n));


		int k(0),l(0);
		std::cout << "\nUnesite poziciju odakle zapocinje pretraga: ";
		std::cin>>k>>l;
		if(k<0 || l<0 || k>=BrojRedova(M) || l>=BrojKolona(M)) {
			std::cout << "\nGreska: Nekorektna pocetna pozicija";
			return 0;
		}


		std::complex<double> z = VrhMatrice(M,k,l);
		std::cout << "\nNadjen je vrh matrice na poziciji: " << z.real() << z.imag() << std::endl;
		std::cout << "Njegova vrijednost je " << M.at(z.real()).at(z.imag()) << std::endl;

	} catch(std::domain_error e) {
		std::cout << "Izuzetak:" << e.what()<<std::endl;
	} catch(std::range_error c) {
		std::cout << "Izuzetak:" << c.what()<<std::endl;
	} catch(...) {
		throw "Pogrešan izuzetak!";
	}

	return 0;
}
