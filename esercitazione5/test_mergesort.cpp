#include <iostream>
#include <vector>
#include <string> //necessaria per le stringhe 
#include <cstdlib> // per EXIT_SUCCES e EXIT_FAILURE
#include "Sorts.hpp"
#include "randfiller.h"
int main(void){
	randfiller rf;
	//creo vettore di 100 elementi che contiene dimensioni randomiche da 1 a 1000
	std::vector<int> dimensioni;
	dimensioni.resize(100);
	rf.fill(dimensioni, 1 ,1000);
	//ora testo sui numeri:
	for(int i = 0; i < 100; i++) { 
        int dim_corrente = dimensioni[i];
        std::vector<int> test_vec;
        test_vec.resize(dim_corrente);
        rf.fill(test_vec, -10000, 10000); 
        
        //uso l'algoritmo
         merge_sort(test_vec,0,dim_corrente-1);
        if(!is_sorted(test_vec)) //L'operatore ! inverte il booleano resituito da is_sorted
        // !TRUE=FALSE
        {
            std::cerr << "Errore: Mergesort ha fallito sui numeri!\n";
            return EXIT_FAILURE; 
        }
    }
    //ora testo sulle stringhe 
    std::vector<std::string> test_stringhe = {"cane", "veterinario", "cuccia", "dimora", "sport", "recinto", "mare", "vendita", "relazione", "colazione"};
    
    merge_sort(test_stringhe,0,9);
    if(!is_sorted(test_stringhe)){
        std::cerr << "Errore: Mergesort ha fallito sulle stringhe!\n";
        return EXIT_FAILURE;
    }

    //Se si arriva qui significa che non si è commesso nessun errore 
    std::cout << "Test Mergesort superato con successo!\n";
    return EXIT_SUCCESS;	
	
	
}