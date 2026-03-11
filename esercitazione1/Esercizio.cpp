#include <iostream> //-->serve per stampare i risultati 
#include <fstream> //--> serve nella lettura dei file 

int main(int argc, const char *argv[])
{	//Controllo sui parametri
	if (argc<2)  //se non ho inserito nessun file avrò solo un elemento (che è l'eseguibile)
	{std:: cerr<< "Errore nell'apertura del file ";
	return 1;	
	}
	//Controllo apertura del file 
	std:: ifstream ifs(argv[1]);
	if(ifs.fail()){
		std:: cerr<< "Errore nell'apertura del file ";
		return 2;
	}
	//Dichiarazione delle variabili per la lettura
    std::string city;
    double t1, t2, t3, t4;

    //Ciclo di lettura: legge riga per riga finché ci sono dati validi
    while (ifs >> city >> t1 >> t2 >> t3 >> t4) // il ciclo deve essere eseguito solo se i dati sono stati prelevati con successo 
    {
        double mean = (t1 + t2 + t3 + t4) / 4.0;
        std::cout << city << " " << mean << "\n";
    }

    return 0;
}