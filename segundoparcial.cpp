#include<iostream>
#include<conio.h>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define color SetConsoleTextAttribute
using namespace std;

struct empleado1{
	int     dni;
	int 	id;
	int 	dias_t;
	string 	nombre;
	string 	puesto;

}op1_empleado;

struct estudiante{
	int     nota1;
	int 	nota2;
	int 	nota3;
	int     carnet;
	string 	nombre;
	string 	carrera;
}op2_estudiante;

struct carreras{
	string carrera;
}op2_carrera[2];

struct producto{
	int     cantidad;
	int 	precio;
	int		codigo;
	string 	nombre;
	string 	origen;
}op3_producto;

struct origen{
	string p_origen;
}op3_origen[2];

struct empleado2{
	int     dni;
	int 	id;
	int 	sueldo;
	string 	nombre;
	string 	departamento;

}op5_empleado;

struct departamento{
	string e_departamento;
}op5_departamento[2];

struct Nodo{
	int ent1;
	int ent2;
	int ent3;
	int ent4;
	string cad1;
	string cad2;
	Nodo *siguiente;
};

void Datos_Empleado1();
void Datos_Estudiante();
void Datos_Producto(int no_case);
void Datos_Empleeado2();
void insertarCola(Nodo *&,Nodo *&,int,int,int,int,string,string);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&, int &, int &,int &,int &, string &, string &);



void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void insertarCola(	Nodo *&frente,
					Nodo *&fin,
					int nodo_ent1,
					int nodo_ent2,
					int nodo_ent3, 
					int nodo_ent4,
					string nodo_cad1,
					string nodo_cad2){

	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->ent1 = nodo_ent1;
	nuevo_nodo->ent2 = nodo_ent2;
	nuevo_nodo->ent3 = nodo_ent3;
	nuevo_nodo->ent4 = nodo_ent4;
	nuevo_nodo->cad1 = nodo_cad1;
	nuevo_nodo->cad2 = nodo_cad2;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
}

bool cola_vacia(Nodo *frente){
	return(frente == NULL)? true : false;
}

void suprimirCola(	Nodo *&frente,
					Nodo *&fin, 
					int &nodo_ent1, 
					int &nodo_ent2, 
					int &nodo_ent3,
					int &nodo_ent4,
					string &nodo_cad1,
					string &nodo_cad2){
	nodo_ent1 = frente->ent1;
	nodo_ent2 = frente->ent2;
	nodo_ent3 = frente->ent3;
	nodo_ent4 = frente->ent4;
	nodo_cad1 = frente->cad1;
	nodo_cad2 = frente->cad2;
	Nodo *aux = frente;

	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente -> siguiente; 
	}
}
void Datos_Empleado1(){
	
	int ent1,ent2,ent3,ent4;
	string cad1, cad2;
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int sueldo=100;
	char op='n';
	int contador=0;

	char bandera1='y';
	int bandera2=0;
	
	while(bandera1!='n'){
			system("cls"); system("cls");

			cout<<"Digite el DNI del empleado        -> ";
			cin>>op1_empleado.dni;

			cout<<"Digite el ID del empleado         -> ";
			cin>>op1_empleado.id;

			cout<<"Digite el nombre del empleado     -> ";
			cin.ignore();
			getline(cin,op1_empleado.nombre);

			cout<<"Digite el puesto del empleado     -> ";
			getline(cin,op1_empleado.puesto);	
			
			cout<<"Digite dias trabajados esta semana-> ";
			cin>>op1_empleado.dias_t;

			ent1=op1_empleado.dni;
			ent2=op1_empleado.id;
			ent3=op1_empleado.dias_t;
			cad1=op1_empleado.nombre;
			cad2=op1_empleado.puesto;
            insertarCola(frente,fin,ent1,ent2,ent3,ent4,cad1,cad2);
			
			if(op1_empleado.dias_t*sueldo>500){
				cout<<"***Despliega Cheque***"<<endl;
				getch();
				system("cls"); system("cls");
			}
			else{
				cout<<"***Recibe un vale de despensa***"<<endl;
				getch();
				system("cls"); system("cls");
			}
				bandera2=0;		
				while(bandera2!=1){
					system("cls"); system("cls");
					cout<<"(y/n) Ingresar Mas Datos Si/No"<<endl;
					cout<<"Digite una opcion entre [y/n]: ";	
					cin>>op;
					if (op=='n'){
						bandera1='n';
						bandera2=1;
					}
					else if(op=='y'){
						bandera2=1;
					}
					else{
						system("cls"); system("cls");
						cout<<"Digite un valor correcto"<<endl;
						getch();
					}
					
				}
			contador++;
			if(contador>5){
				suprimirCola(frente,fin,ent1,ent2,ent3,ent4,cad1,cad2);
				contador=0; 
			}	

	}
	system("cls"); system("cls");
	cout<<"Limpiando Cola: "<<endl;
	while(frente != NULL){
		suprimirCola(frente,fin,ent1,ent2,ent3,ent4,cad1,cad2);

		if(frente != NULL){
			cout<<ent1<<" "<<ent2<<" "<<ent3<<" "<<cad1<<" "<<cad2<<" -> Eliminado"<<endl;
		}
		else{
			cout<<ent1<<" "<<ent2<<" "<<ent3<<" "<<cad1<<" "<<cad2<<" -> Eliminado"<<endl;
			cout<<"Eliminacion Completa";
		}
		getch();
	}
}

void Datos_Estudiante(){

	int ent1,ent2,ent3,ent4;
	string cad1, cad2;
	Nodo *frente = NULL;
	Nodo *fin = NULL;

	op2_carrera[0].carrera="Ingenieria en Sistema";
	op2_carrera[1].carrera="Medicina";
	op2_carrera[2].carrera="Administracion de Empresas";
	char op='n';
	int opcion_carrera;
	int contador=0;

	char bandera1='y';
	int bandera2=0;
	int validar_carrera;
	
	while(bandera1!='n'){
			system("cls"); system("cls");

			cout<<"Digite el carnet del estudiante   -> ";
			cin>>op2_estudiante.carnet;

			cout<<"Digite el nombre del estudiante   -> ";
			cin.ignore();
			getline(cin,op2_estudiante.nombre);

			cout<<"Digite la primera nota            -> ";
			cin>>op2_estudiante.nota1;

			cout<<"Digite la segunda nota            -> ";
			cin>>op2_estudiante.nota2;

			cout<<"Digite la tercera nota            -> ";
			cin>>op2_estudiante.nota3;

			while(validar_carrera!=1){
				cout<<"(1) Ingenieria en Sistemas"<<endl;
				cout<<"(2) Medicina"<<endl;
				cout<<"(3) Administracion de Empresas"<<endl;
				cout<<"Digite una opcion                 ->" ;
				cin>>opcion_carrera;

				if (opcion_carrera==1){
					op2_estudiante.carrera=op2_carrera[0].carrera;
					validar_carrera=1;
				}
				else if (opcion_carrera==2){
					op2_estudiante.carrera=op2_carrera[1].carrera;
					validar_carrera=1;
				}
				else if (opcion_carrera==3){
					op2_estudiante.carrera=op2_carrera[2].carrera;
					validar_carrera=1;
				}
				else{cout<<"Digite una carrera correcta"<<endl;}
			}
			validar_carrera=0;

			ent1=op2_estudiante.nota1;
			ent2=op2_estudiante.nota2;
			ent3=op2_estudiante.nota3;
			ent4=op2_estudiante.carnet;
			cad1=op2_estudiante.nombre;
			cad2=op2_estudiante.carrera;
			insertarCola(frente,fin,ent1,ent2,ent3,ent4,cad1,cad2);

			if(op2_estudiante.carrera==op2_carrera[1].carrera){
				cout<<"***Despliega Boleta de Calificaciones***"<<endl;
				getch();
				system("cls"); system("cls");
			}
			else{
				cout<<"***Despliega Oficio de Citacion***"<<endl;
				getch();
				system("cls"); system("cls");
			}

				bandera2=0;		
				while(bandera2!=1){
					system("cls"); system("cls");
					cout<<"(y/n) Ingresar Mas Datos Si/No"<<endl;
					cout<<"Digite una opcion entre [y/n]: ";	
					cin>>op;
					if (op=='n'){
						bandera1='n';
						bandera2=1;
					}
					else if(op=='y'){
						bandera2=1;
					}
					else{
						system("cls"); system("cls");
						cout<<"Digite un valor correcto"<<endl;
						getch();
					}
					
				}
			contador++;
			if(contador>5){
				suprimirCola(frente,fin,ent1,ent2,ent3,ent4,cad1,cad2);
				contador=0; 
			}	

	}
	system("cls"); system("cls");
	cout<<"Limpiando Cola: "<<endl;
	while(frente != NULL){
		suprimirCola(frente,fin,ent1,ent2,ent3,ent4,cad1,cad2);

		if(frente != NULL){
			cout<<ent1<<" "<<ent2<<" "<<ent3<<" "<<ent4<<" "<<cad1<<" "<<cad2<<" -> Eliminado"<<endl;
		}
		else{
			cout<<ent1<<" "<<ent2<<" "<<ent3<<" "<<ent4<<" "<<cad1<<" "<<cad2<<" -> Eliminado"<<endl;
			cout<<"Eliminacion Completa";
		}
		getch();
	}
}

void Datos_Producto(int no_case){

	int ent1,ent2,ent3,ent4;
	string cad1, cad2;
	Nodo *frente = NULL;
	Nodo *fin = NULL;

	op3_origen[0].p_origen="Nacional";
	op3_origen[1].p_origen="Internacional";
	char op='n';
	int opcion_origen;
	int contador=0,reorden;


	char bandera1='y';
	int bandera2=0;
	int validar_origen;
	

	while(bandera1!='n'){
			system("cls"); system("cls");


			cout<<"Digite el codigo del producto     -> ";
			cin>>op3_producto.codigo;

			cout<<"Digite el nombre del producto     -> ";
			cin.ignore();
			getline(cin,op3_producto.nombre);

			while(validar_origen!=1){
				cout<<"(1) Nacional"<<endl;
				cout<<"(2) Internacional"<<endl;
				cout<<"Digite una opcion                 -> " ;
				cin>>opcion_origen;

				if (opcion_origen==1){
					op3_producto.origen=op3_origen[0].p_origen;
					validar_origen=1;
				}
				else if (opcion_origen==2){
					op3_producto.origen=op3_origen[1].p_origen;
					validar_origen=1;
				}
				else {cout<<"Digite una opcion correcta"<<endl;}
			}
			validar_origen=0;

			cout<<"Digite la cantidad                -> ";
			cin>>op3_producto.cantidad;

			cout<<"Digite el precio                  -> ";
			cin>>op3_producto.precio;

			if (no_case==4){
				cout<<"Digite el punto de reorden del producto -> ";
				cin>>reorden;
			}


			ent1=op3_producto.cantidad;
			ent2=op3_producto.precio;
			ent3=op3_producto.codigo;
			cad1=op3_producto.nombre;
			cad2=op3_producto.origen;
			insertarCola(frente,fin,ent1,ent2,ent3,ent4,cad1,cad2);


			if (no_case==4){
				if(op3_producto.cantidad<reorden || op3_producto.origen==op3_origen[0].p_origen){
					cout<<"***Despliega Orden de Compra***"<<endl;
					getch();
					system("cls"); system("cls");
				}
			}
			else if(no_case==3){
				if(op3_producto.origen==op3_origen[0].p_origen){
					cout<<"***Despliega Orden de Compra***"<<endl;
					getch();
					system("cls"); system("cls");
				}
			}


				bandera2=0;		
				while(bandera2!=1){
					system("cls"); system("cls");
					cout<<"(y/n) Ingresar Mas Datos Si/No"<<endl;
					cout<<"Digite una opcion entre [y/n]: ";	
					cin>>op;
					if (op=='n'){
						bandera1='n';
						bandera2=1;
					}
					else if(op=='y'){
						bandera2=1;
					}
					else{
						system("cls"); system("cls");
						cout<<"Digite un valor correcto"<<endl;
						getch();
					}
					
				}
			contador++;
			if(contador>5){
				suprimirCola(frente,fin,ent1,ent2,ent3,ent4,cad1,cad2);
				contador=0; 
			}	

	}
	system("cls"); system("cls");
	cout<<"Limpiando Cola: "<<endl;
	while(frente != NULL){
		suprimirCola(frente,fin,ent1,ent2,ent3,ent4,cad1,cad2);

		if(frente != NULL){
			cout<<ent1<<" "<<ent2<<" "<<ent3<<" "<<cad1<<" "<<cad2<<" -> Eliminado"<<endl;
		}
		else{
			cout<<ent1<<" "<<ent2<<" "<<ent3<<" "<<cad1<<" "<<cad2<<" -> Eliminado"<<endl;
			cout<<"Eliminacion Completa";
		}
		getch();
	}
}


void Datos_Empleado2(){

	int ent1,ent2,ent3,ent4;
	string cad1, cad2;
	Nodo *frente = NULL;
	Nodo *fin = NULL;

	op5_departamento[0].e_departamento="Produccion";
	op5_departamento[1].e_departamento="Administracion";
	op5_departamento[2].e_departamento="Ventas";
	char op='n';
	int opcion_departamento;
	int contador=0;


	char bandera1='y';
	int bandera2=0;
	int validar_departamento;
	

	while(bandera1!='n'){
			system("cls"); system("cls");


			cout<<"Digite el id del empleado         -> ";
			cin>>op5_empleado.id;

			cout<<"Digite el dni del empleado        -> ";
			cin>>op5_empleado.dni;

			cout<<"Digite el nombre del empleado     -> ";
			cin.ignore();
			getline(cin,op5_empleado.nombre);

			while(validar_departamento!=1){
				cout<<"(1) Produccion"<<endl;
				cout<<"(2) Administracion"<<endl;
				cout<<"(3) Ventas"<<endl;
				cout<<"Digite una opcion                 -> " ;
				cin>>opcion_departamento;

				if (opcion_departamento==1){
					op5_empleado.departamento=op5_departamento[0].e_departamento;
					validar_departamento=1;
				}
				else if (opcion_departamento==2){
					op5_empleado.departamento=op5_departamento[1].e_departamento;
					validar_departamento=1;
				}
				else if (opcion_departamento==3){
					op5_empleado.departamento=op5_departamento[2].e_departamento;
					validar_departamento=1;
				}
				else{cout<<"Digite un departamento correcto"<<endl;}
			}
			validar_departamento=0;

			cout<<"Digite el sueldo del empleado     -> ";
			cin>>op5_empleado.sueldo;


			ent1=op5_empleado.dni;
			ent2=op5_empleado.id;
			ent3=op5_empleado.sueldo;
			cad1=op5_empleado.nombre;
			cad2=op5_empleado.departamento;
			insertarCola(frente,fin,ent1,ent2,ent3,ent4,cad1,cad2);


			if(op5_empleado.sueldo>500 && op5_empleado.departamento==
			   op5_departamento[0].e_departamento){
				cout<<"***Despliega Cheque***"<<endl;
				getch();
				system("cls"); system("cls");
			}
			else{
				cout<<"***Despliega Bono de Despensa***"<<endl;
				getch();
				system("cls"); system("cls");
			}


				bandera2=0;		
				while(bandera2!=1){
					system("cls"); system("cls");
					cout<<"(y/n) Ingresar Mas Datos Si/No"<<endl;
					cout<<"Digite una opcion entre [y/n]: ";	
					cin>>op;
					if (op=='n'){
						bandera1='n';
						bandera2=1;
					}
					else if(op=='y'){
						bandera2=1;
					}
					else{
						system("cls"); system("cls");
						cout<<"Digite un valor correcto"<<endl;
						getch();
					}
					
				}
			contador++;
			if(contador>5){
				suprimirCola(frente,fin,ent1,ent2,ent3,ent4,cad1,cad2);
				contador=0; 
			}	

	}
	system("cls"); system("cls");
	cout<<"Limpiando Cola: "<<endl;
	while(frente != NULL){
		suprimirCola(frente,fin,ent1,ent2,ent3,ent4,cad1,cad2);

		if(frente != NULL){
			cout<<ent1<<" "<<ent2<<" "<<ent3<<" "<<cad1<<" "<<cad2<<" -> Eliminado"<<endl;
		}
		else{
			cout<<ent1<<" "<<ent2<<" "<<ent3<<" "<<cad1<<" "<<cad2<<" -> Eliminado"<<endl;
			cout<<"Eliminacion Completa";
		}
		getch();
	}
}

int main()
{
	

	int op=0,li=0;


	int des=0;

	do{
		li=0;
		system("cls"); system("cls");

		gotoxy(0, li);  cout<<"|******************************";
		gotoxy(31,li);  cout<<"Menu de Opciones";
		gotoxy(47,li);  cout<<"******************************|"; li++;
		

		gotoxy(0, li); cout<<"|";
		gotoxy(1, li); cout<<"1. Datos de un empleado 1";
		gotoxy(77,li); cout<<"|"; li++;
		if (des==1){
			gotoxy(0, li); cout<<"|----------------------------------------------------------------------------|"; li++;
			gotoxy(0, li); cout<<"|Capturar datos de un empleado y desplegarle su cheque o bono semanal        |"; li++;
			gotoxy(0, li); cout<<"|----------------------------------------------------------------------------|"; li++;
		}

		gotoxy(0, li); cout<<"|";
		gotoxy(1, li); cout<<"2. Notas de un estudiante";
		gotoxy(77,li); cout<<"|"; li++;
		if (des==1){
			gotoxy(0, li); cout<<"|----------------------------------------------------------------------------|"; li++;
			gotoxy(0, li); cout<<"|Capturar los datos de un estudiante para construir una boleta de            |"; li++;
			gotoxy(0, li); cout<<"|calificaciones o un citado                                                  |"; li++;
			gotoxy(0, li); cout<<"|----------------------------------------------------------------------------|"; li++;
		}
		

		gotoxy(0, li); cout<<"|";
		gotoxy(1, li); cout<<"3. Datos de un producto extranjero";
		gotoxy(77,li); cout<<"|"; li++;
		if (des==1){
			gotoxy(0, li); cout<<"|----------------------------------------------------------------------------|"; li++;
			gotoxy(0, li); cout<<"|Capturar los datos de un producto, para desplegar una orden de compra,      |"; li++;
			gotoxy(0, li); cout<<"|solo si el producto es de origen nacional                                   |"; li++;
			gotoxy(0, li); cout<<"|----------------------------------------------------------------------------|"; li++;
		}
		

		gotoxy(0, li); cout<<"|";
		gotoxy(1, li);  cout<<"4. Datos de un producto con existencia en tienda";
		gotoxy(77,li);  cout<<"|"; li++;
		if (des==1){
			gotoxy(0, li); cout<<"|----------------------------------------------------------------------------|"; li++;
			gotoxy(0, li); cout<<"|Capturar los datos de un producto, para desplegar una orden de compra, solo |"; li++;
			gotoxy(0, li); cout<<"|si su cantidad es menor al punto de reorden o si es un producto nacional    |"; li++;
			gotoxy(0, li); cout<<"|----------------------------------------------------------------------------|"; li++;
		}

		gotoxy(0, li); cout<<"|";
		gotoxy(1, li); cout<<"5. Pago de cheque de un empleado";
		gotoxy(77,li); cout<<"|"; li++;
		if (des==1){
			gotoxy(0, li); cout<<"|----------------------------------------------------------------------------|"; li++;
			gotoxy(0, li); cout<<"|Capturar los datos de un empleado para desplegar su cheque o bono semanal   |"; li++;
			gotoxy(0, li); cout<<"|============================================================================|"; li++;
		}
		else{
			gotoxy(0, li); cout<<"|============================================================================|"; li++;
		}

	
		

		gotoxy(0, li); cout<<"|";
		gotoxy(1, li); cout<<"(6) Salir del programa";
		gotoxy(77,li); cout<<"|"; li++;
        gotoxy(0, li); cout<<"|============================================================================|"; li++;
		

		gotoxy(0, li); cout<<"Digite una opcion entre [1-6]: ";
		cin>>op;

		switch (op)
		{
	    case 1:
			Datos_Empleado1();
			break;
		case 2:
			Datos_Estudiante();
			break;
		case 3:	
			Datos_Producto(op);
			break;	
		case 4:
			Datos_Producto(op);
			break;
		case 5:
			Datos_Empleado2();
			break;
			
		case 6:
			break;	

		default:
			break;

	
		}
	}while(op!=6);
	return 0;
}
