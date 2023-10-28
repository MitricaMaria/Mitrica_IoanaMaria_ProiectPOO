#include<iostream>
using namespace std;
//DOMENIU: MUZICA

class Playlist {
public:
	const int idUser;
	static int accesari;
	string nume;
	int nrMelodii;
	float* durataMelodii;

	Playlist() :idUser(5525) {
		nume = "Relaxare";
		nrMelodii = 5;
		durataMelodii = new float[5];
		durataMelodii[0] = 1.7;
		durataMelodii[1] = 2.3;
		durataMelodii[2] = 4;
		durataMelodii[3] = 2.5;
		durataMelodii[4] = 2;
    }
	Playlist(int id, string nume, int nrMelodii, float* durataMelodii) :idUser(id), nume(nume), nrMelodii(nrMelodii) {
		if (nrMelodii) {
			this->durataMelodii = new float[nrMelodii];
			for (int i = 0; i < nrMelodii; i++)
				this->durataMelodii[i] = durataMelodii[i];
		}
		else
			this->durataMelodii = NULL;
	}
	Playlist(int id,string nume) :idUser(id),nume(nume) {
		nrMelodii = 0;
		durataMelodii = NULL;
	}
	~Playlist() {
		if (this->durataMelodii != NULL)
			delete[]this->durataMelodii;
	}
	void afisare() {
		cout << "Playlist-ul " << nume << " creat de user-ul cu id-ul " << idUser << " are " << nrMelodii << " melodii, "<<accesari<<" accesari, cu o durata de ";
		if (nrMelodii) {
			for (int i = 0; i < nrMelodii; i++)
				cout << durataMelodii[i] << " ";
				cout << "minute. ";
		}
		else
			cout << "0 minute. ";
		cout << endl;
	}
	
	static int cateAccesari() {
		return accesari;
	}
};
int Playlist::accesari = 0;


class Chitara {
public:
	const int nrExemplar;
	static int lungimeCm;
	char* producator;
	int nrCorzi;
	bool esteElectrica;
	float ratingEmag;

	Chitara():nrExemplar(25) {
		nrCorzi = 6;
		esteElectrica = false;
		ratingEmag = 4.5;
		producator = new char[strlen("Valencia") + 1];
		strcpy_s(producator, strlen("Valencia") + 1, "Valencia");
	}
	Chitara(int exemplar, const char* numeProd, int nrCorzi, float rating):nrExemplar(exemplar) {
		this->producator = new char[strlen(numeProd)+1];
		strcpy_s(producator, strlen(numeProd) + 1, numeProd);
		this->nrCorzi = nrCorzi;
		esteElectrica = false;
		this->ratingEmag = rating;
	}
	Chitara(int exemplar, int nrCorzi, const char* numeProd, bool electrica):nrExemplar(exemplar) {
		this->producator = new char[strlen(numeProd) + 1];
		strcpy_s(producator, strlen(numeProd) + 1, numeProd);
		this->nrCorzi = nrCorzi;
		esteElectrica = electrica;
		if (electrica == true)
			ratingEmag = 0;
		else
			ratingEmag = NULL;
	}
	~Chitara() {
		if (this->producator != NULL)
			delete[]this->producator;
	}
	void afisare() {
		cout << "Chitara cu numarul " << nrExemplar << " produsa de " << producator << " are " << nrCorzi << " corzi, o lungime de " << lungimeCm << " centimetri. Aceasta " << (esteElectrica ? "este" : "nu este") << " electrica, avand un rating de ";
		if (ratingEmag == NULL)
			cout << "- stele. Emag nu comercializeaza chitare electrice." << endl;
		else
			cout << ratingEmag << " stele." << endl;
	}
	void modificareRating(float nouRating) {
		this->ratingEmag = nouRating;
	}
	static int catiCm() {
		return lungimeCm;
	}
};
int Chitara::lungimeCm = 100;


class Trupa {
public:
	const int anulFormarii;
	static float miiFani;
	string nume;
	int nrAlbume;
	int* nrMelodiiAlbume;
	
	Trupa():anulFormarii(2014) {
		nume = "Chase Atlantic";
		nrAlbume = 3;
		nrMelodiiAlbume = new int[3];
		nrMelodiiAlbume[0] = 14;
		nrMelodiiAlbume[1] = 12;
		nrMelodiiAlbume[2] = 18;
	}
	Trupa(int an, string nume, int albume, int* nrMelodii) :anulFormarii(an) {
		this->nume = nume;
		nrAlbume = albume;
		if (albume != NULL) {
			nrMelodiiAlbume = new int[albume];
			for (int i = 0; i < albume; i++) {
				nrMelodiiAlbume[i] = nrMelodii[i];
			}
		}
		else
			nrMelodiiAlbume = NULL;
	}
	Trupa(int an, string nume) :anulFormarii(an), nume(nume) {
		nrAlbume = 0;
		nrMelodiiAlbume = NULL;
	}
	~Trupa() {
		if (this->nrMelodiiAlbume != NULL)
			delete[]this->nrMelodiiAlbume;
	}
	void afisare() {
		cout << "Trupa "<< nume << " formata in anul "<<anulFormarii<<", cu circa "<<miiFani<<" mii de fani, a lansat, pana in prezent, "<<nrAlbume<<" albume, fiecare album avand ";
		if (nrAlbume) {
			for (int i = 0; i < nrAlbume; i++)
				cout << nrMelodiiAlbume[i] << " ";
			cout << "melodii.";
		}
		else
			cout << "- melodii.";
		cout << endl;
	}
	static float catiFani() {
		return miiFani;
	}
	void modificareNrAlbume(int nrNou) {
		if(nrNou==0)
		nrAlbume = nrNou;

	}
};
float Trupa::miiFani = 20.5;

void main() {
//clasa Playlist	
	Playlist playlist1;
	playlist1.afisare();

	float* playlist;
	playlist = new float[2];
	playlist[0] = 1.2;
	playlist[1] = 4.2;
	Playlist playlist2(1234, "Energie", 2, playlist);
	playlist2.afisare();

	Playlist playlist3(1235, "Rock");
	playlist3.afisare();

	cout<<"Playlist-ul are "<< Playlist::cateAccesari() << " accesari." << endl;
	cout << endl;


//clasa Chitara
	Chitara chitara1;
	chitara1.afisare();
	
	chitara1.modificareRating(5);
	chitara1.afisare();

	Chitara chitara2(26,"Cutaway",6,4);
	chitara2.afisare();

	Chitara chitara3(10,7,"Valencia",true);
	chitara3.afisare();

	cout << "Chitarele au o lungime medie de " << Chitara::catiCm() << " centimetri." << endl;
	cout << endl;


//clasa Trupa
	Trupa trupa1;
	trupa1.afisare();

	int* cateMelodii = new int[7];
	cateMelodii[0] = 7;
	cateMelodii[1] = 8;
	cateMelodii[2] = 5;
	cateMelodii[3] = 12;
	cateMelodii[4] = 9;
	cateMelodii[5] = 8;
	cateMelodii[6] = 10;
	Trupa trupa2(2003, "Maroon5", 7, cateMelodii);
	trupa2.afisare();

	Trupa trupa3(2023, "Unknown");
	trupa3.afisare();

	trupa2.modificareNrAlbume(0); //daca modificam in 0 albume, nu mai exista nici melodii
	trupa2.afisare();

	trupa1.modificareNrAlbume(2); //daca schimbam cu orice alt numar, nu se modifica nimic
	trupa1.afisare();

	cout << "Trupele au circa " << Trupa::catiFani() << " mii de fani.";
	cout << endl;
}