#include "rational.hpp"
#include <iostream>
#include <numeric>

using namespace std;

int main() {
	int a_1;
	int a_2;
	int b_1;
	int b_2;
	cout << "Inserisci il numeratore del primo numero: ";
	cin >> a_1;
	cout << "Inserisci il denominatore del primo numero: ";
	cin >> b_1;
	cout << "Inserisci il numeratore del secondo numero: ";
	cin >> a_2;
	cout << "Inserisci il denominatore del secondo numero: ";
	cin >> b_2;
	cout << "\n";
	rational<int> n_1(a_1, b_1);
    rational<int> n_2(a_2, b_2);
    

    cout << "Risultato Somma: " << n_1 + n_2 << "\n";
    cout << "Risultato Differenza: " << n_1 - n_2 << "\n";
    cout << "Risultato Prodotto: " << n_1 * n_2 << "\n";
    cout << "Risultato Divisione: " << n_1 / n_2 << "\n";
    
    return 0;
}