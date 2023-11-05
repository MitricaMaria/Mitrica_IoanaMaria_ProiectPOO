#include<iostream>
using namespace std;
//DOMENIU: MUZICA

class Playlist {
private:
	const int idUser;
	static int accesari;
	string nume;
	int nrMelodii;
	float* durataMelodii;
public:
	static int getAccesari() {
		return Playlist::accesari;
	}
	static void setAccesari(int acc) {
		if (acc >= 0) {
			Playlist::accesari = acc;
		}
	}
	string getNume() {
		return nume;
	}
	void setNume(string name) {
		if (name.length() > 0) {
			nume = name;
		}
	}
	//nu avem setter pentru idUser
	const int getIdUser() {
		return idUser;
	}
	int getNrMelodii() {
		return nrMelodii;
	}
	float* getDurataMelodii() {
		return durataMelodii;
	}
	void setMelodii(int nr, float* durata) {
		if (nr > 0) {
			nrMelodii = nr;
			if (this->durataMelodii != NULL)
				delete[]this->durataMelodii;
			this->durataMelodii = new float[nr];
			for (int i = 0; i < nr; i++)
				this->durataMelodii[i] = durata[i];
		}
	}
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
	Playlist(int id, string nume) :idUser(id), nume(nume) {
		nrMelodii = 0;
		durataMelodii = NULL;
	}
	~Playlist() {
		if (this->durataMelodii != NULL)
			delete[]this->durataMelodii;
	}
	Playlist(const Playlist& p) :idUser(p.idUser) {  //constructor copiere
		nume = p.nume;
		nrMelodii = p.nrMelodii;
		if (nrMelodii) {
			durataMelodii = new float[nrMelodii];
			for (int i = 0; i < nrMelodii; i++)
				durataMelodii[i] = p.durataMelodii[i];
		}
		else
			durataMelodii = NULL;
	}
	Playlist operator=(const Playlist& p) {         //operator=
		if (this != &p) {
			if (this->durataMelodii != NULL)
				delete[]this->durataMelodii;
			nume = p.nume;
			nrMelodii = p.nrMelodii;
			if (nrMelodii) {
				durataMelodii = new float[nrMelodii];
				for (int i = 0; i < nrMelodii; i++)
					durataMelodii[i] = p.durataMelodii[i];
			}
			else
				durataMelodii = NULL;
		}
		return *this;
	}
	float operator[](int index) {                  //operator[]
		if (index >= 0 && index < nrMelodii) {
			return durataMelodii[index];
		}
	}
	//& in fata lui ostream pentru apelul in cascada
	friend ostream& operator<< (ostream& abc, Playlist p) { //operator<<, afisare, nu modif nimic
		abc << "Nume playlist: " << p.getNume() << endl;
		abc << "ID User: " << p.getIdUser() << endl;
		abc << "Numar melodii: " << p.getNrMelodii() << endl;
		abc << "Numar accesari: " << p.getAccesari() << endl;
		abc << "Durata: ";
		if (p.getDurataMelodii() != NULL) {
			for (int i = 0; i < p.getNrMelodii(); i++)
				abc << p.getDurataMelodii()[i] << "  ";
			abc << "minute";
		}
		else
			abc << "0 minute";
		abc << endl << endl;
		return abc;
	}
	friend istream& operator>> (istream& xyz, Playlist& p) { //operator >>, citire, exista modif.
		//fara idUser
		cout << "Nume: ";
		xyz >> p.nume;
		cout << "Numar melodii: ";
		xyz >> p.nrMelodii;
		if (p.durataMelodii != NULL)
			delete[]p.durataMelodii;
		if (p.nrMelodii > 0) {
			p.durataMelodii = new float[p.nrMelodii];
			for (int i = 0; i < p.nrMelodii; i++) {
				cout << "Durata melodiei " << i + 1 << ": ";
				xyz >> p.durataMelodii[i];
			}
		}
		else {
			cout << "Nu avem melodii";
			p.durataMelodii = NULL;
		}
		return xyz;
	}
	static int cateAccesari() {
		return accesari;
	}
	friend float durataTotala(const Playlist& durata);
};
int Playlist::accesari = 0;

float durataTotala(const Playlist& durata) {
	if (durata.durataMelodii == NULL)
		return 0;
	float suma = 0;
	for (int i = 0; i < durata.nrMelodii; i++)
		suma += durata.durataMelodii[i];
	return suma;
}

class Chitara {
private:
	const int nrExemplar;
	static int lungimeCm;
	char* producator;
	int nrCorzi;
	bool esteElectrica;
	float ratingEmag;
public:
	//nu avem setter pentru nrExemplar
	const int getNrExemplar() {
		return nrExemplar;
	}
	static int getLungimeCm() {
		return lungimeCm;
	}
	static void setLungimeCm(int lungime) {
		if (lungime > 50)
			lungimeCm = lungime;
	}
	bool getEsteElectrica() {
		return esteElectrica;
	}
	void setEsteElectrica(bool electrica) {
		if (electrica == 0 || electrica == 1)
			esteElectrica = electrica;
	}
	float getRatingEmag() {
		return ratingEmag;
	}
	void setRatingEmag(float rating) {
		if (rating >= 0)
			ratingEmag = rating;
	}
	char* getProducator() {
		return producator;
	}
	int getNrCorzi() {
		return nrCorzi;
	}
	void setProducator(const char* prod) {
		if (prod != NULL) {
			if (producator != NULL)
				delete[]producator;
			producator = new char[strlen(prod) + 1];
			strcpy_s(producator, strlen(prod) + 1, prod);
		}
	}
	void setNrCorzi(int nr) {
		if (nr >= 3)
			nrCorzi = nr;
	}
	Chitara() :nrExemplar(25) {
		nrCorzi = 6;
		esteElectrica = false;
		ratingEmag = 4.5;
		producator = new char[strlen("Valencia") + 1];
		strcpy_s(producator, strlen("Valencia") + 1, "Valencia");
	}
	Chitara(int exemplar, const char* numeProd, int nrCorzi, float rating) :nrExemplar(exemplar) {
		this->producator = new char[strlen(numeProd) + 1];
		strcpy_s(producator, strlen(numeProd) + 1, numeProd);
		this->nrCorzi = nrCorzi;
		esteElectrica = false;
		this->ratingEmag = rating;
	}
	Chitara(int exemplar, int nrCorzi, const char* numeProd, bool electrica) :nrExemplar(exemplar) {
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
	void modificareRating(float nouRating) {
		this->ratingEmag = nouRating;
	}
	Chitara(const Chitara& c) :nrExemplar(c.nrExemplar) {  //constructor copiere
		nrCorzi = c.nrCorzi;
		esteElectrica = c.esteElectrica;
		ratingEmag = c.ratingEmag;
		producator = new char[strlen(c.producator) + 1];
		strcpy_s(producator, strlen(c.producator) + 1, c.producator);
	}
	Chitara operator=(const Chitara& c) {  //operator=
		if (this != &c) {
			if (this->producator != NULL)
				delete[]this->producator;
			nrCorzi = c.nrCorzi;
			esteElectrica = c.esteElectrica;
			ratingEmag = c.ratingEmag;
			producator = new char[strlen(c.producator) + 1];
			strcpy_s(producator, strlen(c.producator) + 1, c.producator);
		}
		return *this;
	}
	Chitara operator!() {                 //operator!
		Chitara aux = *this;
		aux.esteElectrica = !aux.esteElectrica;
		return aux;
	}
	Chitara* operator->() {               //operator->
		return this;
	}
	Chitara operator--(int) {             //operator--
		nrCorzi--;
		return *this;
	}
	static int catiCm() {
		return lungimeCm;
	}
	friend string chitaraCopii(const Chitara& lungime);
};
int Chitara::lungimeCm = 100;

string chitaraCopii(const Chitara& lungime) {
	string mesaj;
	if (lungime.lungimeCm >= 100)
		mesaj = "este potrivita copiilor peste 12 ani.";
	else
		mesaj = "este potrivita copiilor sub 12 ani.";
	return mesaj;
}

class Trupa {
private:
	const int anulFormarii;
	static float miiFani;
	string nume;
	int nrAlbume;
	int* nrMelodiiAlbume;
public:
	//nu avem setter penmtru anulFormarii
	const int getAnulFormarii() {
		return anulFormarii;
	}
	static float getMiiFani() {
		return miiFani;
	}
	static void setMiiFani(float fani) {
		if (fani >= 0) {
			Trupa::miiFani = fani;
		}
	}
	string getNume() {
		return nume;
	}
	void setNume(string name) {
		if (name.length() >= 3)
			nume = name;
	}
	int getNrAlbume() {
		return nrAlbume;
	}
	int* getNrMelodiiAlbume() {
		return nrMelodiiAlbume;
	}
	void setAlbume(int nr, int* melodii) {
		if (nr > 0) {
			nrAlbume = nr;
			if (this->nrMelodiiAlbume != NULL)
				delete[]this->nrMelodiiAlbume;
			this->nrMelodiiAlbume = new int[nr];
			for (int i = 0; i < nr; i++)
				this->nrMelodiiAlbume[i] = melodii[i];
		}
	}
	Trupa() :anulFormarii(2014) {
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
	Trupa(const Trupa& t) :anulFormarii(t.anulFormarii) { //constructor copiere
		nume = t.nume;
		nrAlbume = t.nrAlbume;
		if (nrAlbume) {
			nrMelodiiAlbume = new int[nrAlbume];
			for (int i = 0; i < nrAlbume; i++)
				nrMelodiiAlbume[i] = t.nrMelodiiAlbume[i];
		}
		else
			nrMelodiiAlbume = NULL;
	}
	Trupa operator=(const Trupa& t) { //operator=
		if (this != &t) {
			if (this->nrMelodiiAlbume != NULL)
				delete[]this->nrMelodiiAlbume;
			nume = t.nume;
			nrAlbume = t.nrAlbume;
			if (nrAlbume) {
				nrMelodiiAlbume = new int[nrAlbume];
				for (int i = 0; i < nrAlbume; i++)
					nrMelodiiAlbume[i] = t.nrMelodiiAlbume[i];
			}
			else
				nrMelodiiAlbume = NULL;
		}
		return *this;
	}
	int operator()(int n, int m) {    //operator()
		int sumaMelodiilor = 0;
		if (n < nrAlbume) {
			for (int i = 0; i < n; i++)
				sumaMelodiilor += nrMelodiiAlbume[i];
			return sumaMelodiilor >= m;
		}
		else
			return 1;

	}
	bool operator==(const Trupa& t) { //operator==
		if (anulFormarii == t.anulFormarii && miiFani == t.miiFani && nume == t.nume && nrAlbume == t.nrAlbume) {
			if (nrMelodiiAlbume != NULL && t.nrMelodiiAlbume != NULL) {
				for (int i = 0; i < nrAlbume; i++)
					if (nrMelodiiAlbume[i] != t.nrMelodiiAlbume[i])
						return 1;

			}
			else
				return 1;
		}
		else
			return 1;
		return 0;
	}
	Trupa operator+ (const Trupa& t) {    //operator+
		Trupa aux = *this;
		aux.nrAlbume= nrAlbume + t.nrAlbume;
		if (aux.nrMelodiiAlbume != NULL)
			delete[]aux.nrMelodiiAlbume;
		if (aux.nrAlbume > 0) {
			aux.nrMelodiiAlbume = new int[aux.nrAlbume];
			for (int i = 0; i < nrAlbume; i++)
				aux.nrMelodiiAlbume[i] = nrMelodiiAlbume[i];
			for (int i = nrAlbume; i < aux.nrAlbume; i++)
				aux.nrMelodiiAlbume[i] = t.nrMelodiiAlbume[i - nrAlbume];
		}
		else
			aux.nrMelodiiAlbume = NULL;
		return aux;
	}
	static float catiFani() {
		return miiFani;
	}
	void modificareNrAlbume(int nrNou) {
		if (nrNou == 0)
			nrAlbume = nrNou;

	}
};
float Trupa::miiFani = 20.5;

void main() {
	//clasa Playlist
	cout << "Clasa Playlist" << endl << endl;
	Playlist playlist1;
	cout << "Nume playlist: " << playlist1.getNume() << endl;
	cout << "ID User: " << playlist1.getIdUser() << endl;
	cout << "Numar melodii: " << playlist1.getNrMelodii() << endl;
	cout << "Numar accesari: " << playlist1.getAccesari() << endl;
	cout << "Durata: ";
	if (playlist1.getDurataMelodii() != NULL) {
		for (int i = 0; i < playlist1.getNrMelodii(); i++)
			cout << playlist1.getDurataMelodii()[i] << "  ";
		cout << "minute";
	}
	else
		cout << "0 minute";
	cout << endl << endl;
	cout << "Apelam setterii pentru acest playlist." << endl << endl;
	playlist1.setNume("Petrecere");
	float durata[7] = { 1.2, 3, 3.2, 4, 2.5, 4.5, 3 };
	playlist1.setMelodii(7, durata);
	playlist1.setAccesari(50);
	cout << "Nume playlist: " << playlist1.getNume() << endl;
	cout << "ID User: " << playlist1.getIdUser() << endl;
	cout << "Numar melodii: " << playlist1.getNrMelodii() << endl;
	cout << "Numar accesari: " << playlist1.getAccesari() << endl;
	cout << "Durata: ";
	if (playlist1.getDurataMelodii() != NULL) {
		for (int i = 0; i < playlist1.getNrMelodii(); i++)
			cout << playlist1.getDurataMelodii()[i] << "  ";
		cout << "minute";
	}
	else
		cout << "0 minute";
	playlist1.setAccesari(0);
	cout << endl << endl;

	float* playlist;
	playlist = new float[2];
	playlist[0] = 1.2;
	playlist[1] = 4.2;
	Playlist playlist2(1234, "Energie", 2, playlist);
	cout << "Nume playlist: " << playlist2.getNume() << endl;
	cout << "ID User: " << playlist2.getIdUser() << endl;
	cout << "Numar melodii: " << playlist2.getNrMelodii() << endl;
	cout << "Numar accesari: " << playlist2.getAccesari() << endl;
	cout << "Durata: ";
	if (playlist2.getDurataMelodii() != NULL) {
		for (int i = 0; i < playlist2.getNrMelodii(); i++)
			cout << playlist2[i] << "  ";  //operator []
		cout << "minute";
	}
	else
		cout << "0 minute";
	cout << endl << endl;

	Playlist playlist3(1235, "Rock");
	cout << "Nume playlist: " << playlist3.getNume() << endl;
	cout << "ID User: " << playlist3.getIdUser() << endl;
	cout << "Numar melodii: " << playlist3.getNrMelodii() << endl;
	cout << "Numar accesari: " << playlist3.getAccesari() << endl;
	cout << "Durata: ";
	if (playlist3.getDurataMelodii() != NULL) {
		for (int i = 0; i < playlist3.getNrMelodii(); i++)
			cout << playlist3.getDurataMelodii()[i] << "  ";
		cout << "minute";
	}
	else
		cout << "0 minute";
	cout << endl << endl;

	Playlist playlist4 = playlist2; //constructor copiere
	cout << "Nume playlist: " << playlist4.getNume() << endl;
	cout << "ID User: " << playlist4.getIdUser() << endl;
	cout << "Numar melodii: " << playlist4.getNrMelodii() << endl;
	cout << "Numar accesari: " << playlist4.getAccesari() << endl;
	cout << "Durata: ";
	if (playlist4.getDurataMelodii() != NULL) {
		for (int i = 0; i < playlist4.getNrMelodii(); i++)
			cout << playlist4.getDurataMelodii()[i] << "  ";
		cout << "minute";
	}
	else
		cout << "0 minute";
	cout << endl << endl;

	float suma = durataTotala(playlist4);
	cout << "Durata totala a melodiilor din playlist-ul " << playlist4.getNume() << " este " << suma << endl << endl;

	playlist3 = playlist1; //operator=
	cout << "Nume playlist: " << playlist3.getNume() << endl;
	cout << "ID User: " << playlist3.getIdUser() << endl;
	cout << "Numar melodii: " << playlist3.getNrMelodii() << endl;
	cout << "Numar accesari: " << playlist3.getAccesari() << endl;
	cout << "Durata: ";
	if (playlist3.getDurataMelodii() != NULL) {
		for (int i = 0; i < playlist3.getNrMelodii(); i++)
			cout << playlist3.getDurataMelodii()[i] << "  ";
		cout << "minute";
	}
	else
		cout << "0 minute";
	cout << endl << endl;

	Playlist playlist5;
	cin >> playlist5; //operator >>
	cout << playlist5 << endl << endl; //operator <<

	cout << "Playlist-ul are " << Playlist::cateAccesari() << " accesari." << endl;
	cout << endl << endl;


	//clasa Chitara
	cout << "Clasa Chitara" << endl << endl;
	Chitara chitara1;
	cout << "Nr. Chitara: " << chitara1.getNrExemplar() << endl;
	cout << "Producator: " << chitara1.getProducator() << endl;
	cout << "Nr. corzi: " << chitara1.getNrCorzi() << endl;
	cout << "Lungime cm: " << chitara1.getLungimeCm() << endl;
	cout << "Electrica: " << (chitara1.getEsteElectrica() ? "da" : "nu") << endl;
	cout << "Rating Emag: ";
	if (chitara1.getEsteElectrica() == 1)
		cout << "- stele, Emag nu comercializeaza chitare electrice." << endl;
	else
		cout << chitara1.getRatingEmag() << " stele" << endl;
	cout << endl;

	chitara1.modificareRating(5);
	cout << "Nr. Chitara: " << chitara1.getNrExemplar() << endl;
	cout << "Producator: " << chitara1.getProducator() << endl;
	cout << "Nr. corzi: " << chitara1.getNrCorzi() << endl;
	cout << "Lungime cm: " << chitara1.getLungimeCm() << endl;
	cout << "Electrica: " << (chitara1.getEsteElectrica() ? "da" : "nu") << endl;
	cout << "Rating Emag: ";
	if (chitara1.getEsteElectrica() == 1)
		cout << "- stele, Emag nu comercializeaza chitare electrice." << endl;
	else
		cout << chitara1.getRatingEmag() << " stele" << endl;
	cout << endl;

	Chitara chitara2(26, "Cutaway", 6, 4);
	cout << "Nr. Chitara: " << chitara2.getNrExemplar() << endl;
	cout << "Producator: " << chitara2.getProducator() << endl;
	cout << "Nr. corzi: " << chitara2.getNrCorzi() << endl;
	cout << "Lungime cm: " << chitara2.getLungimeCm() << endl;
	cout << "Electrica: " << (chitara2.getEsteElectrica() ? "da" : "nu") << endl;
	cout << "Rating Emag: ";
	if (chitara2.getEsteElectrica() == 1)
		cout << "- stele, Emag nu comercializeaza chitare electrice." << endl;
	else
		cout << chitara2.getRatingEmag() << " stele" << endl;
	cout << endl;
	cout << "Apelam setterii pentru acesta chitara." << endl << endl;
	chitara2.setLungimeCm(77);
	chitara2.setEsteElectrica(1);
	chitara2.setNrCorzi(7);
	chitara2.setProducator("Freedom");
	chitara2.setRatingEmag(4.2);
	cout << "Nr. Chitara: " << chitara2.getNrExemplar() << endl;
	cout << "Producator: " << chitara2.getProducator() << endl;
	cout << "Nr. corzi: " << chitara2.getNrCorzi() << endl;
	cout << "Lungime cm: " << chitara2.getLungimeCm() << endl;
	cout << "Electrica: " << (chitara2.getEsteElectrica() ? "da" : "nu") << endl;
	cout << "Rating Emag: ";
	if (chitara2.getEsteElectrica() == 1)
		cout << "- stele, Emag nu comercializeaza chitare electrice." << endl;
	else
		cout << chitara2.getRatingEmag() << " stele" << endl;
	cout << endl;
	cout << "Chitara cu numarul " << chitara2.getNrExemplar() << " produsa de " << chitara2.getProducator() << " " << chitaraCopii(chitara2) << endl << endl;
	chitara2.setLungimeCm(100);

	Chitara chitara3(10, 7, "Valencia", true);
	cout << "Nr. Chitara: " << chitara3.getNrExemplar() << endl;
	cout << "Producator: " << chitara3.getProducator() << endl;
	cout << "Nr. corzi: " << chitara3.getNrCorzi() << endl;
	cout << "Lungime cm: " << chitara3.getLungimeCm() << endl;
	cout << "Electrica: " << (chitara3.getEsteElectrica() ? "da" : "nu") << endl;
	cout << "Rating Emag: ";
	if (chitara3.getEsteElectrica() == 1)
		cout << "- stele, Emag nu comercializeaza chitare electrice." << endl;
	else
		cout << chitara3.getRatingEmag() << " stele" << endl;
	cout <<endl;
	chitara3 = !chitara3; //operator!
	cout << "Nr. Chitara: " << chitara3.getNrExemplar() << endl;
	cout << "Producator: " << chitara3.getProducator() << endl;
	cout << "Nr. corzi: " << chitara3.getNrCorzi() << endl;
	cout << "Lungime cm: " << chitara3.getLungimeCm() << endl;
	cout << "Electrica: " << (chitara3.getEsteElectrica() ? "da" : "nu") << endl;
	cout << "Rating Emag: ";
	if (chitara3.getEsteElectrica() == 1)
		cout << "- stele, Emag nu comercializeaza chitare electrice." << endl;
	else
		cout << chitara3.getRatingEmag() << " stele" << endl;
	cout << endl;

	Chitara chitara4 = chitara1; //constructorul de copiere
	cout << "Nr. Chitara: " << chitara4.getNrExemplar() << endl;
	cout << "Producator: " << chitara4.getProducator() << endl;
	cout << "Nr. corzi: " << chitara4.getNrCorzi() << endl;
	cout << "Lungime cm: " << chitara4.getLungimeCm() << endl;
	cout << "Electrica: " << (chitara4.getEsteElectrica() ? "da" : "nu") << endl;
	cout << "Rating Emag: ";
	if (chitara4.getEsteElectrica() == 1)
		cout << "- stele, Emag nu comercializeaza chitare electrice." << endl;
	else
		cout << chitara4.getRatingEmag() << " stele" << endl;
	cout << endl;

	chitara3 = chitara1;                //operator=
	cout << "Nr. Chitara: " << chitara3.getNrExemplar() << endl;
	cout << "Producator: " << chitara3.getProducator() << endl;
	cout << "Nr. corzi: " << chitara3.getNrCorzi() << endl;
	cout << "Lungime cm: " << chitara3.getLungimeCm() << endl;
	cout << "Electrica: " << (chitara3.getEsteElectrica() ? "da" : "nu") << endl;
	cout << "Rating Emag: ";
	if (chitara3.getEsteElectrica() == 1)
		cout << "- stele, Emag nu comercializeaza chitare electrice." << endl;
	else
		cout << chitara3.getRatingEmag() << " stele" << endl;
	cout << endl;
	chitara3->setProducator("Fender"); //operator->
	cout << chitara3.getProducator() << endl << endl;
	chitara3--;                       //operator--
	cout << chitara3.getNrCorzi() << endl << endl;

	cout << "Chitarele au o lungime medie de " << Chitara::catiCm() << " centimetri." << endl;
	cout << endl;


	//clasa Trupa
	cout << "Clasa Trupa" << endl << endl;
	Trupa trupa1;
	cout << "Trupa: " << trupa1.getNume() << endl;
	cout << "Anul formarii: " << trupa1.getAnulFormarii() << endl;
	cout << "Fani: " << trupa1.getMiiFani() << " mii" << endl;
	cout << "Numar albume: " << trupa1.getNrAlbume() << endl;
	cout << "Fiecare album are: ";
	if (trupa1.getNrAlbume()) {
		for (int i = 0; i < trupa1.getNrAlbume(); i++)
			cout << trupa1.getNrMelodiiAlbume()[i] << " ";
		cout << "melodii.";
	}
	else
		cout << "- melodii.";
	cout << endl << endl;

	int* cateMelodii = new int[7] {7, 8, 5, 12, 9, 8, 10};
	Trupa trupa2(2003, "Maroon5", 7, cateMelodii);
	cout << "Trupa: " << trupa2.getNume() << endl;
	cout << "Anul formarii: " << trupa2.getAnulFormarii() << endl;
	cout << "Fani: " << trupa2.getMiiFani() << " mii" << endl;
	cout << "Numar albume: " << trupa2.getNrAlbume() << endl;
	cout << "Fiecare album are: ";
	if (trupa2.getNrAlbume()) {
		for (int i = 0; i < trupa2.getNrAlbume(); i++)
			cout << trupa2.getNrMelodiiAlbume()[i] << " ";
		cout << "melodii.";
	}
	else
		cout << "- melodii.";
	cout << endl << endl;

	Trupa trupa3(2008, "Unknown");
	cout << "Trupa: " << trupa3.getNume() << endl;
	cout << "Anul formarii: " << trupa3.getAnulFormarii() << endl;
	cout << "Fani: " << trupa3.getMiiFani() << " mii" << endl;
	cout << "Numar albume: " << trupa3.getNrAlbume() << endl;
	cout << "Fiecare album are: ";
	if (trupa3.getNrAlbume()) {
		for (int i = 0; i < trupa3.getNrAlbume(); i++)
			cout << trupa3.getNrMelodiiAlbume()[i] << " ";
		cout << "melodii.";
	}
	else
		cout << "- melodii.";
	cout << endl << endl;
	cout << "Apelam setterii pentru aceasta trupa." << endl << endl;
	trupa3.setNume("Imagine Dragons");
	trupa3.setMiiFani(100);
	int melodii[6] = { 10,12,8,7,10,10 };
	trupa3.setAlbume(6, melodii);
	cout << "Trupa: " << trupa3.getNume() << endl;
	cout << "Anul formarii: " << trupa3.getAnulFormarii() << endl;
	cout << "Fani: " << trupa3.getMiiFani() << " mii" << endl;
	cout << "Numar albume: " << trupa3.getNrAlbume() << endl;
	cout << "Fiecare album are: ";
	if (trupa3.getNrAlbume()) {
		for (int i = 0; i < trupa3.getNrAlbume(); i++)
			cout << trupa3.getNrMelodiiAlbume()[i] << " ";
		cout << "melodii.";
	}
	else
		cout << "- melodii.";
	cout << endl << endl;
	trupa3.setMiiFani(20.5);

	trupa2.modificareNrAlbume(0); //daca modificam in 0 albume, nu mai exista nici melodii
	cout << "Trupa: " << trupa2.getNume() << endl;
	cout << "Anul formarii: " << trupa2.getAnulFormarii() << endl;
	cout << "Fani: " << trupa2.getMiiFani() << " mii" << endl;
	cout << "Numar albume: " << trupa2.getNrAlbume() << endl;
	cout << "Fiecare album are: ";
	if (trupa2.getNrAlbume()) {
		for (int i = 0; i < trupa2.getNrAlbume(); i++)
			cout << trupa2.getNrMelodiiAlbume()[i] << " ";
		cout << "melodii.";
	}
	else
		cout << "- melodii.";
	cout << endl << endl;

	trupa1.modificareNrAlbume(2); //daca schimbam cu orice alt numar, nu se modifica nimic
	cout << "Trupa: " << trupa1.getNume() << endl;
	cout << "Anul formarii: " << trupa1.getAnulFormarii() << endl;
	cout << "Fani: " << trupa1.getMiiFani() << " mii" << endl;
	cout << "Numar albume: " << trupa1.getNrAlbume() << endl;
	cout << "Fiecare album are: ";
	if (trupa1.getNrAlbume()) {
		for (int i = 0; i < trupa1.getNrAlbume(); i++)
			cout << trupa1.getNrMelodiiAlbume()[i] << " ";
		cout << "melodii.";
	}
	else
		cout << "- melodii.";
	cout << endl << endl;

	Trupa trupa4 = trupa2; //constructor copiere
	cout << "Trupa: " << trupa4.getNume() << endl;
	cout << "Anul formarii: " << trupa4.getAnulFormarii() << endl;
	cout << "Fani: " << trupa4.getMiiFani() << " mii" << endl;
	cout << "Numar albume: " << trupa4.getNrAlbume() << endl;
	cout << "Fiecare album are: ";
	if (trupa4.getNrAlbume()) {
		for (int i = 0; i < trupa4.getNrAlbume(); i++)
			cout << trupa4.getNrMelodiiAlbume()[i] << " ";
		cout << "melodii.";
	}
	else
		cout << "- melodii.";
	cout << endl << endl;
	cout << (trupa4(3, 20) ? "Aceasta trupa a lansat cel putin 20 de melodii." : "Aceasta trupa nu a lansat cel putin 20 de melodii.") << endl << endl; //operator()

	cout << "Trupa " << trupa4.getNume() << " si trupa " << trupa2.getNume() << " ";
	if (trupa4 == trupa2)           //operator==
		cout << "sunt identice.";
	else
		cout << "nu sunt identice";
	cout << endl << endl;

	trupa3 = trupa1; //operator=
	cout << "Trupa: " << trupa3.getNume() << endl;
	cout << "Anul formarii: " << trupa3.getAnulFormarii() << endl;
	cout << "Fani: " << trupa3.getMiiFani() << " mii" << endl;
	cout << "Numar albume: " << trupa3.getNrAlbume() << endl;
	cout << "Fiecare album are: ";
	if (trupa3.getNrAlbume()) {
		for (int i = 0; i < trupa3.getNrAlbume(); i++)
			cout << trupa3.getNrMelodiiAlbume()[i] << " ";
		cout << "melodii.";
	}
	else
		cout << "- melodii.";
	cout << endl << endl;

	trupa2 = trupa1 + trupa3; //operator+
	cout << "Trupa: " << trupa2.getNume() << endl;
	cout << "Anul formarii: " << trupa2.getAnulFormarii() << endl;
	cout << "Fani: " << trupa2.getMiiFani() << " mii" << endl;
	cout << "Numar albume: " << trupa2.getNrAlbume() << endl;
	cout << "Fiecare album are: ";
	if (trupa2.getNrAlbume()) {
		for (int i = 0; i < trupa2.getNrAlbume(); i++)
			cout << trupa2.getNrMelodiiAlbume()[i] << " ";
		cout << "melodii.";
	}
	else
		cout << "- melodii.";
	cout << endl << endl;

	cout << "Trupele au circa " << Trupa::catiFani() << " mii de fani.";
	cout << endl;
}