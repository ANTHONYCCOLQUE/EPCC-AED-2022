#include <iostream>
using namespace std;

class Nodo {
private: 
	int coef;
	int grado;
	Nodo *next;
	friend class Polinomio;
};

class Polinomio{
private:
	Nodo *head;
public:
	Polinomio(){
		head = NULL;
	}
	
	void insertar (int coef, int grado){
		Nodo *nuevo = new Nodo();
		nuevo->coef = coef;
		nuevo->grado = grado;
		
		
		if (head){
			nuevo->next = head;
			head = nuevo;
		}
		else{
			head = nuevo;
		}
	}
		
	void mostrar(){
		Nodo *ptr;
		ptr = head;
		
		if( ptr == NULL)cout<<"Is empty"<<endl;
		
		while(ptr != NULL){
			cout<<ptr->coef<<"x^"<<ptr->grado<<" + ";
			ptr = ptr->next;
		}
	}
		
	void add(int coef, int grado){
		Nodo *nuevo = new Nodo();
		Nodo *aux;//= new Nodo();
		Nodo *ant; //= new Nodo();
		
		nuevo->coef = coef;
		nuevo->grado = grado;
		
		if ( head == NULL ){
			head = nuevo;
		}
		else{
			
			if ( nuevo->grado > head->grado ){
				nuevo->next = head;
				head = nuevo;
			}
			else{
				aux = head;
				ant = head;
				while( aux  ){
					if ( nuevo->grado < aux->grado ){
						ant = aux;
					}
					aux = aux->next;
					
				}
				nuevo->next = ant->next;
				ant->next = nuevo;
			}
		}
	}
	
	/*
	void add(int coef, int grado){
		Nodo *nuevo = new Nodo();
		Nodo *aux;//= new Nodo();
		Nodo *ant; //= new Nodo();
		
		nuevo->coef = coef;
		nuevo->grado = grado;
		
		if ( head == NULL ){
			head = nuevo;
		}
		else{
			
			if ( nuevo->grado > head->grado ){
				nuevo->next = head;
				head = nuevo;
			}
			else{
				if(nuevo->grado == head->grado){
					head->coef =+ nuevo->grado;
				}
				else{
					aux = head;
					ant = head;
					while( aux  ){
						if ( nuevo->grado < aux->grado ){
							ant = aux;
						}
						
						
						aux = aux->next;
						
					}
					nuevo->next = ant->next;
					ant->next = nuevo;
				}
			}
		}
	}*/
};
int main(int argc, char *argv[]) {
	Polinomio p;
	
	p.add(8,7);
	p.add(3,8);
	p.add(4,5);
	p.add(4,9);
	p.add(5,9);
	
	/*
	p.insertar(5,5);
	p.insertar(8,4);
	p.insertar(15,7);
	p.insertar(4,7);
	p.insertar(1,8);*/

	p.mostrar();
}	
				
