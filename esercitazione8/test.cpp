#include <iostream>
#include <set>
#include "undirected_edge.hpp"
#include "undirected_graph.hpp"

//funzione che serve per stampare il grafo a terminale 
template <typename I>
void stampa_grafo(const undirected_graph<I>& g) {
    std::set<I> nodi=g.all_nodes();
    for (I nodo : nodi) {
        std::cout << "Nodo [" << nodo << "] e' collegato a: ";
        std::set<I> vicini = g.neighours(nodo); 
        
        if (vicini.empty()) {
            std::cout << "(nessuno - nodo isolato)";
        } else {
            for (I v : vicini) {
                std::cout << v << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::cout << "=== INIZIO TEST GRAFO NON ORIENTATO ===\n\n";

    undirected_graph<int> grafo;
    
    //Test Inserimento Archi
    std::cout << "--- Test Inserimento Archi ---\n";
    std::cout << "Inserisco gli archi (1,2), (2,3), (4,1), (3,4), (3,1).\n";
    std::cout << "(I nodi 1, 2, 3, 4 verranno creati automaticamente )\n";
    
    grafo.add_edge(1, 2);
    grafo.add_edge(2, 3);
    grafo.add_edge(4, 1);
    grafo.add_edge(3, 4);
    grafo.add_edge(3, 1);

    std::cout << "Provo a inserire l'arco (2,1) che e' un doppione...\n";
    grafo.add_edge(2, 1); // Il std::set ignorerà questa operazione 

    std::cout << "\nStato del grafo dopo gli inserimenti:\n";
    stampa_grafo(grafo);

    //Test esplorazione del grafo
    std::cout << "\n\n--- Test esplorazione Nodi e Archi ---\n";
    
    std::set<int> nodi=grafo.all_nodes();
    std::cout << "Stampo tutti i nodi con .all_nodes(): ";
    for (int n : nodi) std::cout << n << " ";
    std::cout << "\n";

    std::set<undirected_edge<int>> archi = grafo.all_edges();
    std::cout << "Stampo tutti gli archi con .all_edges() e operatore << : "; 
    for (const auto& a : archi) std::cout << a << " ";
    std::cout << "\n";
    std::cout << "(Si noti come il Set li abbia ordinati perfettamente in automatico)\n";

    //Test vicinato
    std::cout << "\n\n--- Test Neighbours ---\n";
    int nodo_test = 1;
    std::set<int> vicini_di_1=grafo.neighours(nodo_test);
    std::cout << "Stampo tutti i vicini del nodo " << nodo_test << " con .neighours(): ";
    for (int v : vicini_di_1) std::cout << v << " ";
    std::cout << "\n";

    //Test Metodi Indice Archi
    std::cout << "\n\n--- Test Ricerca Archi (edge_number e edge_at) ---\n";
    undirected_edge<int> arco_da_cercare(3, 4);
    int indice = grafo.edge_number(arco_da_cercare);
    
    //se non trova l'arco restituisce -1
    if (indice != -1) {
        std::cout << "Cerco l'indice dell'arco " << arco_da_cercare << " con .edge_number().\n";
        std::cout << "Si trova all'indice: " << indice << "\n";
        
        std::cout << "Verifica dell'indice con .edge_at(" << indice << "): " << grafo.edge_at(indice) << "\n";
    } else {
        std::cout << "Arco " << arco_da_cercare << " non trovato.\n";
    }

    //Test operatore Sottrazione
    std::cout << "\n\n--- Test Sottrazione tra Grafi (operator-) ---\n";
    std::cout << "Rimuovo dal grafo principale un nuovo grafo composto dagli archi (1,2) e (3,4).\n\n";
    
    undirected_graph<int> grafo_da_sottrarre;
    grafo_da_sottrarre.add_edge(1, 2);
    grafo_da_sottrarre.add_edge(3, 4);

    std::cout << "Grafo da sottrarre:\n";
    stampa_grafo(grafo_da_sottrarre);

    undirected_graph<int> grafo_risultato=grafo - grafo_da_sottrarre;
    
    std::cout << "\nRisultato della sottrazione (G - G'):\n";
    stampa_grafo(grafo_risultato);

    std::cout << "\n=== FINE TEST ===\n";
    return 0;
}