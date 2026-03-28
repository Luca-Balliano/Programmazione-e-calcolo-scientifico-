#pragma once // serve per evitare inclusioni multiple del file header 
#include <iostream>
#include <concepts>
#include <numeric> //per il calcolo del MCD
//nei file .hpp non usare il comando using namespace std
template<typename I> requires std::integral<I> 
class rational {
	I numerator;
	I denominator;
	public :
	//costruttore di default con sintassi compatta 
	rational(): numerator(0), denominator(1) {}
	//costruttore user-defined con sintassi compatta 
	rational(I num, I den): numerator(num), denominator(den) {semplificazione();}
	void semplificazione() //dato che è un metodo all'interno della classe ha già accesso agli attributi della classe, non c'è bisogno di passarglieli
	{	
		//gestione caso den=0
		if (denominator==0){
			if(numerator>0){
				numerator=1; // +inf
			}
			else if (numerator<0){
				numerator=-1; // -inf
			}
			else {
				numerator=0; //Nan
			}
			return ;//esce subito dalla funzione -->si evita divisione per zero 
		}
		
		//gestione segno
		if(denominator<0){
			numerator=-numerator;
			denominator=-denominator;
		}
		
		//semplificazione
		I max_comune_divisore=std::gcd(numerator,denominator);
		numerator/=max_comune_divisore;
		denominator/=max_comune_divisore;
	}	
	
	//metodi num e den per restituzione di numertaore e denominatore 
	I num() const{return numerator;}
	I den() const{return denominator;}
	
	//overload operatori:
	

	rational& operator+=(const rational& other) //passaggio per riferimento costante
	{
		numerator=(numerator*other.denominator)+(denominator*other.numerator);
		denominator*=other.denominator;
		semplificazione();
		return *this ;
	}

	rational operator+(const rational& other) const{
		rational ret=*this;
		ret += other;
		return ret;
	}
	
	rational& operator-=(const rational& other) {
		numerator=(numerator*other.denominator)-(denominator*other.numerator);
		denominator*=other.denominator;
		semplificazione();
		return *this ;
	}
	
	rational operator-(const rational& other) const{
		rational ret=*this;
		ret -= other;
		return ret;
	}
	
	 rational& operator*=(const rational& other) {
		numerator *= other.numerator;
		denominator *= other.denominator;
		semplificazione();
		return *this;
	}

	
	rational operator*(const rational& other) const {
		rational ret = *this;
		ret *= other;
		return ret;
	}
    
    rational& operator/=(const rational& other) {
		numerator *= other.denominator;
		denominator *= other.numerator;
		semplificazione();
		return *this;
	}

	rational operator/(const rational& other) const {
		rational ret = *this;
		ret /= other;
		return ret;	
	}
	
	
	
};

//Overload dell'operatore inserimento nello stream (<<)
//per stampare a schermo la frazione
template<typename T> requires std::integral<T>
std::ostream& operator<<(std::ostream& os, const rational<T>& v) {
   //analisi dei casi speciali
    if (v.den() == 0) {
        if (v.num() > 0) {
            os << "Inf";
        } else if (v.num() < 0) {
            os << "-Inf";
        } else {
            os << "NaN";
        }
    } 
    else {
        os << v.num() << "/" << v.den();
    }
    
    return os;
}
