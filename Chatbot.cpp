#include <iostream>
#include <fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Registro celular
struct nodo{	   
    int numero; 
    struct nodo *siguiente3; 
};
typedef struct nodo *TAgenda;

// Saldo
struct recarga{
	int num;
	struct recarga *siguiente;
};
typedef struct recarga *Tlista;

//Prestamo
struct prestamo{
	int num2;
	struct prestamo *siguiente2;
};
typedef struct prestamo *Tlista2;

void registrar_numero(TAgenda &lista3){

    TAgenda t,q = new(struct nodo);

    cout<<"REGISTRO CELULAR" <<endl; 
    cout<<"\nCelular: "; cin>>q->numero;
    cout<<endl;

    system("cls");
    q->siguiente3 = NULL;

    if(lista3==NULL){
        lista3 = q;
    } else {
        t = lista3;
        while(t->siguiente3!=NULL){
                t = t->siguiente3;
        }
        t->siguiente3 = q;
    }
}
void listar_numero(TAgenda q){
    system("cls");
    int i=1;
    while(q!=NULL){  
    cout<<"CELULAR: "<<q->numero;     
    q=q->siguiente3;
    i++;
    }
}

int Numero(TAgenda q){
 int num=0;
 while(q!=NULL){
 num=num+q->numero;
 q=q->siguiente3;
 }
 return num;
}

void InsertarSaldo(Tlista &lista, int valor){
	Tlista q;
	q = new(struct recarga);
	q->num = valor;
	q->siguiente = lista;
	lista = q;
}

void ConsultaSaldo(Tlista lista){	
	int i=0;
	
    while(lista!= NULL){
	cout<<' ' <<i+1 <<") " <<lista->num <<endl;
	lista = lista->siguiente;
	i++;
}
}
int SumarSaldo(Tlista lista){
 int suma=0;
 while(lista!=NULL){
 suma=suma+lista->num;
 lista=lista->siguiente;
 }
 return suma;
}
//Ingresar Prestamo
void PrestarSaldo(Tlista2 &lista2, int valor){
	Tlista2 p;
	p = new(struct prestamo);
	p->num2 = valor;
	p->siguiente2 = lista2;
	lista2 = p;
}
void ConsultaPrestamo(Tlista2 lista2){
	int i=0;
	
    while(lista2!= NULL){
	cout<<' ' <<i+1 <<") " <<lista2->num2 <<endl;
	lista2 = lista2->siguiente2;
	i++;
}
}

int SumarPrestamo(Tlista2 lista2){
 int suma=0;
 while(lista2!=NULL){
 suma=suma+lista2->num2;
 lista2=lista2->siguiente2;
 }
 return suma;
}

void EliminarListaSaldo(Tlista &lista, int valor){	
	Tlista aux = lista;
	valor = aux->num;
	lista = aux->siguiente;
	delete aux;
}

void EliminarListaPrestamo(Tlista2 &lista2, int valor){	
	Tlista2 aux = lista2;
	valor = aux->num2;
	lista2 = aux->siguiente2;
	delete aux;
}	
void Menu1(){
	cout<<"\nMENU DE OPCIONES \n\n";
	cout<<" 1. Ingresar Saldo				      "<<endl;
	cout<<" 2. Registro de Saldos				  "<<endl;
	cout<<" 3. Solicitar Prestamo  			      "<<endl;
	cout<<" 4. Registro de Prestamos 			  "<<endl;
	cout<<" 5. Comprar Paquetes         	      "<<endl;
	cout<<" 6. Consultar Deuda                    "<<endl;
	cout<<" 7. Vaciar Lista y eliminar Saldo      "<<endl;
	cout<<" 8. Vaciar Lista y eliminar prestamos  "<<endl;
	cout<<" 9. Salir						      "<<endl;
		
	cout<<"\nIngrese una opcion";
}

int main(int argc, char** argv) {
	Tlista lista = NULL;
	Tlista2 lista2 = NULL;
	TAgenda lista3=NULL;
	
	int opcion;
	int op2, op3, op4, opInternet, opsaldopromo;
	int saldo, numero=0, internet=0, SaldoPromo=0;
	int prestamo, deuda;
	int totaldeuda=0, SumaDeuda=0, totalprestamo=0;
	int totalsaldo=0, SumaSaldo=0, SaldoPrestamo=0;
	
	system("color 0b");
	registrar_numero(lista3);
	
	do{
		listar_numero(lista3);
		
		if (totalsaldo > totalprestamo){
			SumaSaldo = totalsaldo-totalprestamo;			
			}else{
				SumaSaldo = 0;		
			}
					
		cout<<" || Su saldo es: " <<SumaSaldo <<" Lps. " <<endl; 			
		Menu1(); 
		cout<<endl;
		cin>>opcion;
		
		switch(opcion){
			//Ingresar saldo
			case 1:
				cout<<"\nINGRESE SALDO" <<endl; 
				cout<<"1. 25Lps" <<endl;
				cout<<"2. 50Lps" <<endl;
				cout<<"3. 100Lps" <<endl;
				cout<<"\nIngrese su Recarga: " <<endl;
				cin>>op2;
				cout<<"\nTransaccion Finalizada..." <<endl;
				switch(op2){
					case 1:
						saldo = 25;
						totalsaldo += 25;					
						break;
					case 2:
						saldo = 50;
						totalsaldo += 50;
						break;
					case 3:
						saldo = 100;
						totalsaldo += 100;
						break;
					default: cout<<"Ingrese una opcion valida " <<endl;
					break;
				}
				
				InsertarSaldo(lista, saldo);
				break;
				
			//Consultar saldo	
			case 2:
				cout<<"\n\nREGISTRO DE SALDOS INGRESADOS\n";
				ConsultaSaldo(lista); 
				cout<<endl;
				cout<<"El total de saldo ingresado es: " <<SumarSaldo(lista) <<" Lps. " <<endl;
				break;
				
			//Ingresar prestamo	
			case 3:
				if(SumaSaldo == 0){
				cout<<"\nINGRESE SU PRESTAMO" <<endl; 
				cout<<"1. 25Lps" <<endl;
				cout<<"2. 50Lps" <<endl;
				cout<<"3. 100Lps" <<endl;
				cout<<"\nIngrese su Prestamo: " <<endl;
				cin>>op3;
				switch(op3){
					case 1:
						prestamo = 25;
						totalprestamo += 25;
						totaldeuda += 25;				
						break;
					case 2:
						prestamo = 50;
						totalprestamo += 50;
						totaldeuda += 50;		
						break;
					case 3:
						prestamo = 100;
						totalprestamo += 100;
						totaldeuda += 100;	
						break;
					default: cout<<"Ingrese una opcion valida " <<endl;
					break;	
				}
				
				PrestarSaldo(lista2, prestamo);	
			}else{
				cout<<"\nYa tiene saldo registrado..." <<endl;
			}
				break;
				
			//Consultar prestamo	
			case 4:
				cout<<"\n\nREGISTRO DE PRESTAMOS INGRESADOS\n";
				ConsultaPrestamo(lista2); cout<<endl;
				cout<<"El total del prestamo solicitado es: " <<SumarPrestamo(lista2) <<" Lps. "<<endl;
				break;
				
			//Comprar paquetes		
			case 5:
		    	cout<<"1.Internet"             <<endl;
				cout<<"2.Llamadas y Mensajes"  <<endl;
				cout<<"3.Consultar Paquetes"   <<endl;
				cout<<"\nIngrese Opcion: "     <<endl;
				cin>>op4;
				cout<<endl;
				switch(op4){
					case 1:
						cout<<"1. 500MB (25 Lps.)"           <<endl;
						cout<<"2. 2GB (50 Lps.)"             <<endl;
						cout<<"3. 5GB (100 Lps.)"            <<endl;
						cout<<"\nIngrese Opcion: " <<endl;
						cin>>opInternet;
						
						switch(opInternet){
							case 1:
								if (SumaSaldo >= 25){
								internet += 500;
								totalsaldo -= 25;														
								}else{
									cout<<"No se pudo completar la transaccion, saldo insuficiente" <<endl;
								}							
								break;
								
							case 2:
								if (SumaSaldo >= 50){
								internet += 2000;
								totalsaldo -= 50;		
								}else{
									cout<<"No se pudo completar la transaccion, saldo insuficiente" <<endl;
								}	
								break;
							case 3:
								if (SumaSaldo >= 100){
								internet += 5000;
								totalsaldo -= 100;		
								}else{
									cout<<"No se pudo completar la transaccion, saldo insuficiente" <<endl;
								}	
								break;
						}
												
						cout<<"\nTransaccion Finalizada, Tiene: " <<internet <<" Megas de internet." <<endl;
						break;
					
					case 2:
						cout<<"Saldo Promocional"     <<endl;
						cout<<"1. 50 Lps. (25 Lps.)"            <<endl;
						cout<<"2. 100 Lps. (50 Lps.)"           <<endl;
						cout<<"3. 200 Lps (100 Lps.)"           <<endl;
						cout<<"\nIngrese Opcion: "    <<endl;
						cin>>opsaldopromo;
						
						switch(opsaldopromo){
							case 1:
								if (SumaSaldo >= 25){
								SaldoPromo += 50;
								totalsaldo -= 25;								
								}else{
									cout<<"No se pudo completar la transaccion, saldo insuficiente" <<endl;
								}						
								break;
							case 2:
								if (SumaSaldo >= 50){
								SaldoPromo += 100;
								totalsaldo -= 50;								
								}else{
									cout<<"No se pudo completar la transaccion, saldo insuficiente" <<endl;
								}			
								break;
							case 3:
								if (SumaSaldo >= 100){
								SaldoPromo += 200;
								totalsaldo -= 100;								
								}else{
									cout<<"No se pudo completar la transaccion, saldo insuficiente" <<endl;
								}			
								break;
						}						
						cout<<"Transaccion Finalizada, Tiene: " <<SaldoPromo <<" Lps promocionales." <<endl;
						break;
						
					case 3:
						cout<<"Internet: " <<internet <<" MB "<<endl;
						cout<<"Saldo Promocional: " <<SaldoPromo <<" Lps. " <<endl;
						break;
				}	  						
				break;
				
			//Consultar Deuda	
			case 6:			
			if (totaldeuda >= totalsaldo){
				SumaDeuda = totaldeuda - totalsaldo;									
				}else{
					SumaDeuda = 0;	
				}
				cout<<"\nSu Deuda es: " <<SumaDeuda <<" Lps. " <<endl;
				break;
					
			//Vaciar lista de saldos	
			case 7:			
				
				while(lista != NULL){
					EliminarListaSaldo(lista, saldo);
					cout<<"Vaciando Lista... " <<endl;											
					}
					cout<<"\nLista Vacia. " <<endl;	
					totalsaldo = 0;									
			break;
			
			//Vaciar lista de prestamos				
			case 8:
				while(lista2 != NULL){
					EliminarListaPrestamo(lista2, prestamo);				
					cout<<"Vaciando Lista... " <<endl;	
				}
				cout<<"\nLista Vacia. " <<endl;	
				totaldeuda = 0;			
			    break;
				
			case 9:
				cout<<"Saliendo del Programa..." <<endl;
				//Guardar txt
				ofstream archivo;
				
				archivo.open("Datos.txt", ios::out);
				if (archivo.fail()){
					cout<<"No se pudo abrir el archivo.";
					exit(1);
				}
				archivo<<"---DATOS DEL USUARIO---" <<endl;
				archivo<<"Número: " <<Numero(lista3) <<endl; 
				archivo<<"Saldo: " <<SumaSaldo  <<" Lps. "<<endl;
				archivo<<"Deuda: " <<SumaDeuda <<" Lps. " <<endl;
				archivo<<"Internet: " <<internet <<" MB "<<endl;
				archivo<<"Saldo Promocional: " <<SaldoPromo <<" Lps." <<endl;
				archivo.close();
				cout<<"\nGuardado Correctamente." <<endl;
				break;
		}
		cout<<endl<<endl;
		system("pause"); system("cls");
	}while(opcion != 9);
	system("pause");
	return 0;
}

