#include <iostream>
#include <cstdlib>   // per EXIT_SUCCESS
#include <vector>
#include <algorithm> //Per std::sort
#include <iomanip> //Per std::setw--> funzione che sereve ad allineare l'output, ho trovato informazioni sul sito stack overflow 
#include "randfiller.h"
#include "timecounter.h"
#include "Sorts.hpp"

int main() {
    randfiller rf;
    timecounter tc;

    std::cout << "--- BENCHMARK ALGORITMI (Vettori Piccoli) ---\n";
    std::cout << std::setw(8)  << "Size" 
              << std::setw(15) << "Bubble" 
              << std::setw(15) << "Selection" 
              << std::setw(15) << "Insertion" 
              << std::setw(15) << "Merge" 
              << std::setw(15) << "Quick"
              << std::setw(15) << "std::sort" << "\n";
    std::cout << std::string(100, '-') << "\n"; //stampa 100 trattini consecutivi e poi va a capo, per formattare l'output 

    // Testiamo le dimensioni da 10 a 500 con passi di 10
    for (int size=10; size<=500; size+=10) {
        
        //Creo il vettore di 100 vettori, tutti della stessa dimensione 
        std::vector<std::vector<int>> vettore_di_vettori(100, std::vector<int>(size));
        for (int i = 0; i < 100; ++i) {
            rf.fill(vettore_di_vettori[i], -1000, 1000);
        }
        
        //Bubblesort
        std::vector<std::vector<int>> copia_bubb=vettore_di_vettori; //Per ogni metodo creo una copia per ordinarla 
        tc.tic(); 
        for (int i=0; i<100; ++i) {
            bubble_sort(copia_bubb[i]);
        }
        double media_bubble=tc.toc() / 100.0; 

        //Selectionsort
        std::vector<std::vector<int>> copia_select=vettore_di_vettori;
        tc.tic();
        for (int i=0; i<100; ++i) {
            selection_sort(copia_select[i]);
        }
        double media_selection=tc.toc() / 100.0;

        //Insertionsort
        std::vector<std::vector<int>> copia_inser=vettore_di_vettori;
        tc.tic();
        for (int i=0; i<100; ++i) {
            insertion_sort(copia_inser[i]);
        }
        double media_insertion=tc.toc() / 100.0;

        //Mergesort
        std::vector<std::vector<int>> copia_merg=vettore_di_vettori;
        tc.tic();
        for (int i=0; i<100; i++) {
            merge_sort(copia_merg[i], 0, size - 1);
        }
        double media_merge=tc.toc() / 100.0;

        //Quicksort
        std::vector<std::vector<int>> copia_quick=vettore_di_vettori;
        tc.tic();
        for (int i=0; i<100; ++i) {
            quick_sort(copia_quick[i], 0, size - 1);
        }
        double media_quick=tc.toc() / 100.0;
        
        //Std::sort
        std::vector<std::vector<int>> copia_std=vettore_di_vettori;
        tc.tic();
        for (int i=0; i<100; ++i) {
            std::sort(copia_std[i].begin(), copia_std[i].end());
        }
        double media_std = tc.toc() / 100.0;

        // Stampa dei risultati in tabella per questa dimensione
        std::cout << std::setw(8)  << size 
                  << std::setw(15) << media_bubble 
                  << std::setw(15) << media_selection 
                  << std::setw(15) << media_insertion 
                  << std::setw(15) << media_merge 
                  << std::setw(15) << media_quick
                  << std::setw(15) << media_std << "\n";
    }
    

    return EXIT_SUCCESS;
}