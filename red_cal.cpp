#include <iostream>
#include <windows.h>
#include "cals.h"
#include "nred_cal.h"
#include "vlsm_cal.h"
#include "wildcard.h"
#include "wild_num_ip.h"

char hnwild[50][30];
char hn_ip_info[50][30];
char hn_masc_info[50][30];
char* hn_tmp;
char* hn_tmp1;
char* hn_tmp2;
int n_w,f;
int opc_menu;
int x=0,c=0,z=0;
char hn_hn[16];
char* hn_hn_mask;

void problemas();

int main(){
    std::cout<<"Calculadora de red - BETA"<<std::endl;
    problemas();
    std::cout<<"\n\nDigite el numero que quieres hacer[1-5]"<<std::endl;
    do
    {
        std::cout<<"1. Calcular vlsm de 2 o mas redes"<<std::endl;
        std::cout<<"2. Calcular el nombre de la red, a partir de una ip"<<std::endl;
        std::cout<<"3. Calcular el wildcard de 1 o mas redes"<<std::endl;
        std::cout<<"4. Calcular el wildcard de una mascara"<<std::endl;
        std::cout<<"5. Calcular la ip numero X"<<std::endl;
        std::cout<<"Opcion: ";
        std::cin>>opc_menu;
        if(opc_menu>5 || opc_menu<1)std::cout<<"\n---------------\n\n";
    }while(opc_menu>5 || opc_menu<1);
    if(opc_menu==1)//VLSM
    {
        //system("clear");
        system("cls");
        std::cout<<"VLSM: \n"<<std::endl;
        vlsm();
    }
    else if(opc_menu==2)//Nombre de la red
    {
        //system("clear");
        system("cls");
        std::cout<<"Calcular nombre de la red\n"<<std::endl;
        std::cin.ignore();
        nred();
    }
    else if(opc_menu==3)//Wildcard de una o mas redes red
    {

        //system("clear");
        system("cls");
        std::cout<<"Calcular wildcard de una o mas redes\nFormato: ejemplo: 192.168.0.0/24\n\n"<<std::endl;
        std::cout<<"A cuantas mascaras quieres calcular el wildcard: ";
        std::cin>>n_w;
        std::cin.ignore();
        do
        {
            std::cout<<"["<<z+1<<"]"<<" Ingrese el nombre de la red o la mascara: ";
            std::cin.getline(hnwild[z],20,'\n');
            z++;
        }while(z<n_w);
        for(i=0;i<n_w;i++)
        {
            hn_tmp=hnwild[i];
            hn_tmp1=ipp_ipp(hn_tmp);
            hn_tmp2=masc_masc(hn_tmp);
            for(int j=0;j<strlen(hn_tmp1);j++)
            {
                hn_ip_info[i][j]=hn_tmp1[j];
            }
            for(int j=0;j<strlen(hn_tmp2);j++)
            {
                hn_masc_info[i][j]=hn_tmp2[j];
            }
        }
        system("cls");
        //system("clear");
        std::cout<<""<<std::endl;
        for(i=0;i<n_w;i++)
        {
            std::cout<<"Red "<<hnwild[i];
			std::cout<<"\n\nEl wildcard para la mascara ";
			std::cout<<hn_masc_info[i];
			std::cout<<" es:   ";
			wildcard_cout(hn_masc_info[i]);
			std::cout<<"\n\n\n";
        }
    }
    else if(opc_menu==4)
    {
    	
        //system("clear");
        system("cls");
        fflush(stdin);
        fflush(stdout);
		wildcard();
    }
    else if(opc_menu==5)//wildcard numero X
    {
        //system("clear");
        system("cls");
        std::cout<<"Calcular que ip es la numero X\n";
        std::cout<<"Ejemplo: La quinta(5) ip de la red 192.168.0.0, seria 192.168.0.5\n"<<std::endl;
        char x1[16];
        int x2;
        std::cin.ignore();
        std::cout<<"Ingresa la Nombre de la red: ";
        std::cin.getline(x1,16,'\n');
        std::cout<<"Ingresa que numero de ip necesitas: ";
        std::cin>>x2;
        std::cout<<"La ip es: "<<wild_num(x1,x2)<<"\n\n"<<std::endl;

    }
    system("PAUSE");
    return 0;
}

void problemas()
{
    std::cout<<"Si hay problemas con el calculo, por favor avisar a: f.herrera.r@hotmail.com"<<std::endl;
}
