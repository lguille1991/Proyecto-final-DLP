#include<iostream>
#include<stdlib.h>
#include<cctype>
#include<locale.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
main()
{
	setlocale(LC_CTYPE,"spanish");
	//Declaración de variables
	int numFactura[20], i=0, j=0, k=0, l=0, m=0, opCred=0, nProd=0, opMen=0, dato=0, fEnc=0, fila=0, columna=0, modificar=0, aux=0;
	string nombre[20], fecha[20];
	double iva=0, acumST[20];
	bool cont=true;
	
	
	while(cont==true)
	{
		system("CLS");
		cout<<"	¡COMPRE AHORA, PAGUE DESPUÉS!"<<endl;
		cout<<"------------------------------------------"<<endl;
		cout<<"\n			MENÚ"<<endl;
		cout<<"**********************************************************"<<endl;
		cout<<":::	[1]Crear nueva factura		:::"<<endl;
		cout<<":::	[2]Modificar factura existente	:::"<<endl;
		cout<<":::	[3]Salir			:::"<<endl;
		cout<<"**********************************************************"<<endl;		
		cout<<"\nIngrese el número correspondiente a la opción que desee: ";
		cin>>opMen;
		cin.get();
		switch(opMen)
		{
			case 1:
				{
					
					system("CLS");
					cout<<"Ingrese el numero de factura (rango 1-20): ";
					cin>>k;
					cin.get();
					numFactura[m]=k;
					cout<<"\nFecha DD/MM/AA: ";
					getline(cin,fecha[k]);
					cin.get();
					cout<<"Nombre del cliente: ";
					getline(cin,nombre[k]);
					cin.get();
					for(i=0;i<=2-1;i++)
					{
						cout<<"Crédito fiscal [1]SI, [2]NO: ";
						cin>>opCred;
						cin.get();
						if(opCred==1)
						{
							iva=0;
							i=2;
						}
						else
						{
							if(opCred==2)
							{
								iva=0.13;
								i=2;
							}
							else
							{
								i--;
							}
						}				
					}
					cout<<"\n¿Cuántos productos desea facturar?: ";
					cin>>nProd;
					cin.get();
					string descripProd[nProd][20];
					double precioUnitario[nProd][20];
					int unidadesProducto[nProd][20];
					for(fila=0;fila<=nProd-1;fila++)
					{
						for(columna=k;columna==k;columna++)
						{
							cout<<"\nDescripción del producto "<<fila+1<<": ";
							getline(cin,descripProd[fila][k]);
							cin.get();
							cout<<"\nIngrese el precio unitario del producto: $";
							cin>>precioUnitario[fila][k];
							cin.get();
							cout<<"\nIngrese las unidades de dicho producto: ";		
							cin>>unidadesProducto[fila][k];
							cin.get();
							acumST[k]=acumST[k]+precioUnitario[fila][k]*unidadesProducto[fila][k];							
						}
					}
					cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
					cout<<"Numero de factura: "<<k<<endl;
					cout<<"Fecha: "<<fecha[k]<<endl;
					cout<<"Nombre del cliente: "<<nombre[k]<<endl;
					cout<<"------------------------------------"<<endl;
					cout<<"		Detalle"<<endl;
					cout<<"Cantidad Descripción Precio Unitario"<<endl;
					for(i=0;i<=nProd-1;i++)
					{
						cout<<"  "<<unidadesProducto[i][k]<<"     "<<descripProd[i][k]<<"       "<<"$"<<precioUnitario[i][k]<<endl;
					}
					cout<<"El subtotal es: $"<<acumST[k]<<endl;
					cout<<"IVA: $"<<acumST[k]*iva<<endl;
					cout<<"El total a pagar es: $"<<acumST[k]+iva*acumST[k]<<endl;
					l++;
					m++;
					k=0;
					aux=nProd;
					system("pause");
					break;
				}
			case 2:
				system("CLS");
				cout<<"Ingrese el número de la factura: ";
				cin>>dato;
				cin.get();
				for(i=0;i<=20-1;i++)
				{
					if(dato==numFactura[i])
					{
						fEnc++;
					}
				}
				if(fEnc>=1)
				{
					cout<<"Factura encontrada"<<endl;
					cout<<"Fecha: "<<fecha[dato]<<endl;
					cout<<"Cliente: "<<nombre[dato]<<endl;
					/////////////////////////////////////////////
					string descripProd[aux][20];
					double precioUnitario[aux][20];
					int unidadesProducto[aux][20];
					cout<<"------------------------------------"<<endl;
					cout<<"		Detalle"<<endl;
					cout<<"Cantidad Descripción Precio Unitario"<<endl;
					for(i=0;i<=aux-1;i++)
					{
						cout<<"  "<<unidadesProducto[i][dato]<<"     "<<descripProd[i][dato]<<"       "<<"$"<<precioUnitario[i][dato]<<endl;
					}
					cout<<"El subtotal es: $"<<acumST[dato]<<endl;
					cout<<"IVA: $"<<acumST[dato]*iva<<endl;
					cout<<"El total a pagar es: $"<<acumST[dato]+iva*acumST[dato]<<endl;
					//////////////////////////////////////////////////
					cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
					for(i=0;i<=2-1;i++)
					{
						cout<<"¿Desea modificar esta compra? [1]SI, [2]NO: ";
						cin>>modificar;
						cin.get();
						if(modificar==1)
						{
							opMen=1;
							i=2;
						}
						else
						{
							if(modificar==2)
							{
								cont=true;
								i=2;
							}
							else
							{
								i--;
							}
						}
					}
				}
				else
				{
					if(fEnc==0)
					{
						cout<<"Factura no encontrada"<<endl;
					}
				}
				fEnc=0;
				dato=0;			
				system("pause");
				break;
			case 3:
				cont=false;
				break;					
				
			default:
				system("CLS");
				cont=true;
				system("pause");				
				break;				
		}
	}
	system("pause");
	return 0;				
}
