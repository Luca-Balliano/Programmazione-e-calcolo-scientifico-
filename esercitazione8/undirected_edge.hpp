#pragma once 
#include <iostream>
#include <algorithm> // per utilizzare std::min e std::max
#include <concepts> //per utilizzare std::integral 

template<typename I> requires std::integral<I>
class undirected_edge{
	I node_from;
	I node_to;
	public:
	
	// Costruttore di default (inizializza i nodi a 0)
	undirected_edge() : node_from(0), node_to(0) {}
	
	// Costruttore che prende i due nodi connessi 
	undirected_edge(I u, I v){
		//faccio in modo che il nodo from sia sempre più piccolo del nodo to 
		node_from=std::min(u, v);
		node_to=std::max(u, v);
	}
	// Metodi from() e to()
	I from() const{ return node_from;}
	I to() const{return node_to;}
	
	// operatore< per rendere gli archi ordinabili (l'ordinabilità si userà con std::set e sdt::map)
	bool operator<( const undirected_edge& other ) const {
		//si inizia a valutare dai nodi 
		if(node_from!=other.from()){
			return node_from<other.from();
		}
		// a parità di nodo di partenza controlla nodo d'arrivo
		return node_to<other.to();
	}
	
	// operatore== per controllare se due archi sono identici 
	bool operator==( const undirected_edge& other ) const {
		if (node_from==other.from()){
			return node_to==other.to();
		}
		return false;
	}
	
	// operatore<< per stampare l'arco su terminale
	// si usa "friend" perché l'operatore di stream << appartiene alla libreria standard (std::ostream)--> informazione trovata sul sito stackoverflow 
    friend std::ostream& operator<<(std::ostream& os, const undirected_edge& edge) {
        os << "(" << edge.node_from << ", " << edge.node_to << ")";
        return os;
    }
};