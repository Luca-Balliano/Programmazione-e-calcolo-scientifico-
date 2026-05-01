#include <iostream>
#include <cstdlib>   // per EXIT_SUCCESS
#include <vector>
#include <algorithm> //Per std::sort
#include <iomanip>   //Per std::setw--> funzione che serve ad allineare l'output, ho trovato informazioni sul sito stack overflow 
#include "randfiller.h"
#include "timecounter.h"
#include "Sorts.hpp"

int main() {
    randfiller rf;
    timecounter tc;

    std::cout << "--- BENCHMARK ALGORITMI (Quicksort_nuovo vs std::sort) ---\n";
    std::cout << std::setw(8)  << "Size" 
              << std::setw(20) << "Quicksort_nuovo" 
              << std::setw(20) << "std::sort" << "\n";
    std::cout << std::string(50, '-') << "\n"; //stampa 50 trattini consecutivi e poi va a capo, per formattare l'output 

    // Testo su  dimensioni da 10 a 500 con passo 10
    for (int size=10; size<=500; size+=10) {
        
        //Creo il vettore di 100 vettori, tutti della stessa dimensione 
        std::vector<std::vector<int>> vettore_di_vettori(100, std::vector<int>(size));
        for (int i = 0; i < 100; ++i) {
            rf.fill(vettore_di_vettori[i], -10000, 10000);
        }
        
        //Quicksort nuovo (Ibrido)
        std::vector<std::vector<int>> copia_quick_nuovo=vettore_di_vettori; //Per ogni metodo creo una copia per ordinarla 
        tc.tic(); 
        for (int i=0; i<100; ++i) {
            quick_sort_nuovo(copia_quick_nuovo[i], 0, size - 1);
        }
        double media_quick_nuovo=tc.toc() / 100.0; 
        
        //Std::sort
        std::vector<std::vector<int>> copia_std=vettore_di_vettori;
        tc.tic();
        for (int i=0; i<100; ++i) {
            std::sort(copia_std[i].begin(), copia_std[i].end());
        }
        double media_std = tc.toc() / 100.0;

        // Stampa dei risultati in tabella per questa dimensione
        std::cout << std::setw(8)  << size 
                  << std::setw(20) << media_quick_nuovo 
                  << std::setw(20) << media_std << "\n";
    }
    
    return EXIT_SUCCESS;
}