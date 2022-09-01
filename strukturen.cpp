#include <iostream>

using namespace std;

struct schueler {
	int pcNummer;
	char vorname[50];
	char nachname[50];
	int kennnummer;
};

int berechneKennnummer(schueler);

int main() {

	schueler schuelerListe[20];
	int anzahlSchueler = 0;
	for (int i = 0; i < 20; i++) {

		int pcNummerTemp;

		cout << "PCNr: ";
		cin >> pcNummerTemp;
		anzahlSchueler = i;
		if (pcNummerTemp == 0) {
			break;
		}
		anzahlSchueler = i+1;
		schuelerListe[i].pcNummer= pcNummerTemp;

		cout <<  "Vorname: ";
		cin >> schuelerListe[i].vorname;
		cout <<  "Nachname: ";
		cin >> schuelerListe[i].nachname;
		schuelerListe[i].kennnummer = berechneKennnummer(schuelerListe[i]);
	}

	for (int j = 0; j < anzahlSchueler; ++j) {
		cout << endl << "Die Kennnummer des Schülers " << schuelerListe[j].vorname << " " << schuelerListe[j].nachname << " am PC " << schuelerListe[j].pcNummer << " lautet: " << schuelerListe[j].kennnummer << endl;
	}


	return 0;

}

int berechneKennnummer(schueler s) {
	int kennnummer = 0;

	kennnummer += s.vorname[1];
	kennnummer += s.vorname[2];
	kennnummer += s.nachname[1];
	kennnummer += s.nachname[2];
	kennnummer *= s.pcNummer;

	kennnummer *= 5684;
	kennnummer = kennnummer % 10000;

	return kennnummer;
}
