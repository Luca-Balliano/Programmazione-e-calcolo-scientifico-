#pragma once
#include <iostream>
#include <optional>
#include <vector> //per usare la classe dei vettori dinamici
#include <cstdlib> //per usare la funzione rand nel quicksort
#include <utility> //per usare la funzione std::swap nella partition del quicksort

//Implemetazione algoritmo bubblesort
template<typename T>
void bubble_sort(std::vector<T>& vec){
	int N=vec.size();
	for(int i=0; i<=N-2;i++){
		for(int j=N-1;j>=i+1;--j){
			if(vec[j]<vec[j-1]){
				T scambio=vec[j];
				vec[j]=vec[j-1];
				vec[j-1]=scambio;
			}
		}
		
	}
		
}


//Implementazione algoritmo selectionsort
template<typename T>
void selection_sort(std::vector<T>& vec){
	int N=vec.size();
	for(int i=0; i<=N-2;++i){
		int min_index=i;
		for(int j=i+1; j<=N-1;++j){
			if (vec[j]<vec[min_index]){
				min_index=j;
			}
		}
		if (min_index!=i){
			T scambio=vec[min_index];
			vec[min_index]=vec[i];
			vec[i]=scambio;
		}
	}
}


//Implementazione algoritmo insertionsort
template<typename T>
void insertion_sort(std::vector<T>& vec){
	int N=vec.size();
	for(int i=1; i<=N-1; ++i){
		T value=vec[i];
		int j=i-1;
		while(j>=0 && vec[j]>value){
			vec[j+1]=vec[j];
			j=j-1;
		}
		vec[j+1]=value;
	}
}


//Implementazione algoritmo mergesort
template<typename T>
void merge(std::vector<T>& vec, int sx, int centro, int dx) {
    int n_1 = centro - sx + 1;
    int n_2 = dx - centro;
    std::vector<T> L;
    std::vector<T> R;
    L.resize(n_1);
    R.resize(n_2);
    
    for(int j=0; j< n_1; ++j) {
        L[j]=vec[sx + j];
    }
    
    for(int i=0; i<n_2; ++i) {
        //Aggiunto il +1  per partire dalla seconda metà
        R[i]=vec[centro +1 +i]; 
    }
    
    int i=0;
    int j=0;
    int k=sx;
    
    //Inserisco un ciclo wile che si ferma quando uno tra L o R finisce
    while(i<n_1 && j<n_2) {
        if(L[i]<=R[j]) {
            vec[k]=L[i];
            i=i+1;
        } else {
            vec[k]=R[j];
            j=j+1;
        }
        k=k+1;
    }
    
    //Se è avanzato qualcosa in L lo aggiungo (gli elementi di L sono già ordinati)
    while(i < n_1) {
        vec[k]=L[i];
        i=i+1;
        k=k+1;
    }
    
    //Se è avanzato qualcosa in R lo aggiungo (gli elementi di R sono già ordinati)
    while(j<n_2) {
        vec[k]=R[j];
        j=j+1;
        k=k+1;
    }
}

template<typename T>
void merge_sort(std::vector<T>& vec, int sx, int dx){
	if(sx<dx){
		int centro=(sx+dx)/2;
		merge_sort(vec,sx,centro);
		merge_sort(vec,centro+1,dx);
		merge(vec,sx,centro,dx);
		}
	return;}
	

//Implementazione algoritmo Quicksort (versione fatta a lezione con il professore Vicini)
template<typename T>
int partition(std::vector<T>& sl,int s,int p,int d){
    if(p!=d){
        std::swap(sl[p],sl[d]);
    }
    p=d;
    int i=s-1;
    
    for(int j=s;j<=d-1;++j){
        if(sl[j]<=sl[p]){
            i++;
            std::swap(sl[i],sl[j]);
        }
    }
    
    if(i!=d){
        std::swap(sl[i+1],sl[p]);
    }
    
    return i+1;
}

template<typename T>
void quick_sort(std::vector<T>& vec,int sx,int dx){
    if(sx<dx){
        int pivot=sx+rand()%(dx-sx+1); //serve per ottenere un numero random tra s e d
        int rango=partition(vec,sx,pivot,dx);
        quick_sort(vec,sx,rango-1);
        quick_sort(vec,rango+1,dx);
    }
}


//Implementazione algoritmo che in base alla soglia (nel mio caso 320 in modalità release) sceglie l'algoritmo da utlizzare 
template<typename T>
void quick_sort_nuovo(std::vector<T>& vec, int sx, int dx) {
    // La soglia sperimentale n0 calcolata tramite benchmark
    int n0 = 320;  

    if (sx < dx) {
        int dimensione_sottovettore = dx - sx + 1;

        // Se la dimensione scende sotto (o è uguale a) n0, uso algoritmo quadratico
        if (dimensione_sottovettore <= n0) {
            // Insertion Sort applicato solo al sotto-vettore tra sx e dx
            for (int i=sx+1; i<=dx; ++i) {
                T value=vec[i];
                int j=i-1;
                while (j>= sx && vec[j]>value) {
                    vec[j+1]=vec[j];
                    j=j-1;
                }
                vec[j+1]=value;
            }
        } 
        // Altrimenti, si continua  con le chiamate ricorsive dell'algoritmo logaritmico
        else {
            int pivot=sx+rand() % dimensione_sottovettore;
            int rango=partition(vec, sx, pivot, dx);
            quick_sort_nuovo(vec, sx, rango - 1);
            quick_sort_nuovo(vec, rango + 1, dx);
        }
    }
}


//Implementazione funzione che controlla se il vettore è effettivamente ordinato
template<typename T>
// 'bool' perché la risposta è un semplice Vero o Falso
// 'const std::vector<T>&' perché si legge solo il vettore senza modificarlo
bool is_sorted(const std::vector<T>& vec) {
    int N = vec.size();
    for(int i = 0; i < N - 1; ++i) {
        if(vec[i] > vec[i + 1]) {
            return false;
        }
    }
    return true; 
}