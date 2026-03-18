#include <iostream>
#include <algorithm> //per utilizzare le funzioni std::min(), std::max()
#include <cmath>     // per utilizzare la funzione std::sqrt()
int main()
{
    static const int N = 10;
    double arr[N]={2.3,2.5,5.6,7.8,5.2,3.9,9.4,4.6,5.7,4.9};
    //inizializzo come min e max il primo elemento dell'array
    double minimo=arr[0];
    double massimo=arr[0];
    double somma=0.0;
    //calcolo di min e max e somma
    for (int i=0; i<N; ++i) {  //il comando++ fa il calcolo e salva i risultato, + solo il calcolo
        minimo=std::min(minimo,arr[i]);
        massimo=std::max(massimo,arr[i]);
        somma += arr[i];
    }
    
    double media=somma/N;
    //calcolo la varianza
    double somma_quadrati_scarti = 0.0;
    for (int i = 0; i < N; ++i) {
        // (x_i - media)^2
        double scarto = arr[i] - media;
        somma_quadrati_scarti += (scarto * scarto);
    }

    double varianza = somma_quadrati_scarti / N;

    // Calcolo deviazione standard usando std::sqrt
    double deviazione_standard = std::sqrt(varianza);

    std::cout << "Minimo: " << minimo << std::endl;
    std::cout << "Massimo: " << massimo << std::endl;
    std::cout << "Media: " << media << std::endl;
    std::cout << "Deviazione standard: " << deviazione_standard << std::endl;

    return 0;
}