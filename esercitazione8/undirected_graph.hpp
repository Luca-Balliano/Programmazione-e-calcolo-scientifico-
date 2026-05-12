#include <iostream>
#include <set>
#include <map>
#include "undirected_edge.hpp"
#include <concepts> //per usare std::integral
#include <iterator>//per usare distance nel metodo edgenumber 


template <typename I> requires std::integral<I>
class undirected_graph{
	
	std::set<I> nodes;
	std::set<undirected_edge<I>> edges;
	std::map<I,std::set<I>> adj_list;
	public:
	
	//costruttore di default 
	undirected_graph()=default;
	
	//costruttore di copia 
	undirected_graph(const undirected_graph& other){
		nodes=other.nodes;
		edges=other.edges;
		adj_list=other.adj_list;
	}
	
	//metodo che permette di aggiungere un arco al grafo 
	void add_edge(I u, I v){
		undirected_edge <I> arco_nuovo(u,v); //sto utilizzando il costruttore parametrico della classe undirected_edge che ho creato precedentemente 
		edges.insert(arco_nuovo);
		nodes.insert(u);
		nodes.insert(v);
		adj_list[u].insert(v); // l'operatore [u ] se non trova l'elemento che corrisponde alla 
		adj_list[v].insert(u);// chiave u lo crea 
	}
	
	//metodo che permette di trovare i vicini di un nodo 
	std::set<I> neighours(I node) const {
        auto iteratore=adj_list.find(node); //auto serve per dire al compilatore di scegliere il tipo corretto
        //find scorre in tutta la mappa e se non trova il nodo return sposta il puntatore in una oposizione speciale che si chiama end()
        if (iteratore !=adj_list.end()) {
            return iteratore->second; //ritorna il set dei vicini
        }
        return {}; //se il nodo non esiste o è isolato, ritorna un set vuoto
    }
    
    //metodo che permette di restituire tutti gli archi
    std::set<undirected_edge<I>> all_edges() const {
        return edges;
    }

    //metodo che permette di restituire tutti i nodi
    std::set<I> all_nodes() const {
        return nodes;
    }
    
    //metodo che permette di ottenere la numerazione di un arco (la sua posizione nel set)
    int edge_number(const undirected_edge<I>& e) const {
        auto it=edges.find(e);
        if (it !=edges.end()) {
            // std::distance calcola la "distanza" tra l'inizio del set e la posizione trovata
            return std::distance(edges.begin(), it);
        }
        return -1; // Ritorna -1 se l'arco non esiste nel grafo
    }
    
   //metodo che permette di ottenere un arco in base al suo numero
    undirected_edge<I> edge_at(int index) const {
        //faccio un controllo di sicurezza: se l'indice è fuori dai limiti, 
        // restituisco un arco vuoto (usando il costruttore di default)
        if (index < 0 || index >= edges.size()) {
            return undirected_edge<I>(); 
        }

        //parto dall'inizio del set
        auto it=edges.begin();
        //faccio 'index' passi in avanti 
        for (int i=0; i<index; i++) {
            it++; //sposta l'iteratore in avanti di uno
        }

        //restituisco l'arco che si trova sotto al "dito"
        return *it;
    }
   
    //metodo che permette di calcolare la differenza G - G'
    undirected_graph operator-(const undirected_graph& other) const {
        undirected_graph result;
        
        // G - G' significa: prendi tutti gli archi di questo grafo (G)...
        for (const auto& edge : edges) {
            // ...se non s li trovi nell'altro grafo (G')...
            if (other.edges.find(edge) == other.edges.end()) {
                // ...allora aggiungili al grafo risultato
                result.add_edge(edge.from(), edge.to());
            }
        }
        return result;
    }
};
