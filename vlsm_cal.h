#ifndef vlsm_H
#define vlsm_H
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "cals.h"
#define MAX 401

char nombrered[MAX][30];
int nredes;
int ip1,ip2,ip3,ip4,ip4m,nhost,i=0,gater1,gater2,gater3,gater4,nsobra,t=0;
int maskoct,maskdec,p,ip4b,ip3b,ip2b,ip1b,ip4r,ip3r,ip2r,ip1r,aux0=0,aux1=0,e=1,au=0,cc,pos;
int infored[21][11];
int hnhost[30][2];
char temp[30];
char ipcompleta[15];
char opc_nom;

void nombre(int id){
	for(int i=1;i<=nredes*2;i=i+2){
		if(atoi(nombrered[i])==id){
			std::cout<<"\n\nRed "<<nombrered[i+1]<<":"<<std::endl;
		}
	}
}

void opc_nombre_red(){
    do{
		std::cout<<"Quiere ponerle nombres a las redes?[y/N]: ";
    	std::cin>>opc_nom;
    	fflush(stdin);
    	if (opc_nom=='Y' || opc_nom=='y'){
			opc_nom='y';
		}
		else if (opc_nom=='N' || opc_nom=='n'){
			opc_nom='n';
		}
	}while(!(opc_nom=='Y' || opc_nom=='y' || opc_nom=='N' || opc_nom=='n'));
}
void redes_need(){
    do{
    std::cout<<"\nIngrese el numero de redes que necesita: ";
    std::cin>>nredes;}while(!(nredes>=1 && nredes<=pow(2,24)-2));
}

void nom_host_x_red(){
    e=0;
    i=0;
    while(i<nredes){
        i++;
        e++;
        std::cin.ignore();
        if(opc_nom=='n'){
            do{
            std::cout<<"Ingrese el numero de host que necesita para la red "<<i<<": ";
            std::cin>>nhost;
            hnhost[i][0]=nhost; ///[Nred][0=nhosts 1=nred]
            hnhost[i][1]=i;
            }while(!(nhost>=1 && nhost<=16777213));
        }else if(opc_nom=='y'){
            do{
        	std::cout<<"\n["<<i<<"]"<<" Ingrese el nombre para la red: ";
        	std::cin.getline(temp,30,'\n');
        	strcpy(nombrered[e+1],temp);
            //nombrered[i]=temp;
        	std::cout<<"Ingrese el numero de host que necesita para "<<nombrered[e+1]<<": ";
        	std::cin>>nhost;
        	hnhost[i][0]=nhost; ///[Nred][0=nhosts 1=nred]
        	hnhost[i][1]=i;
        	sprintf(nombrered[e],"%d",i);
            e++;
       		}while(!(nhost>=1 && nhost<=16777213));
       		}
        }
}

void orden_enlasala(){
    e=0;
        i=0;
    	for (e=1;e<=nredes;e++){
            pos=e;
            aux1=hnhost[e][1];///nombre     int
            aux0=hnhost[e][0];///numeros    int
            while(pos>1 && hnhost[pos-1][0] < aux0){
                hnhost[pos][0] = hnhost[pos-1][0];
                hnhost[pos][1] = hnhost[pos-1][1];
                pos--;
            }
            hnhost[pos][1]=aux1;
            hnhost[pos][0]=aux0;
        }
}
void pedir_ip(){
    i=0;
    au=0;
   		do{
   			if (mask_oct(hnhost[i+1][0])<=23 && mask_oct(hnhost[i+1][0])>=16){
   				cc=2;
   				au=1;
			}
			else if(mask_oct(hnhost[i+1][0])<=15 && mask_oct(hnhost[i+1][0])>=8){
				cc=3;
				au=1;
			}
			else{
				cc=1;
				au=1;
			}
		i++;
		}while(nredes!=i && au!=1);
	if(cc==1){
		///do{
            std::cin.ignore();
			std::cout << "\nIngrese una ip clase C[192-233]: ";
    		std::cin.getline(ipcompleta,16,'\n');
    		fflush(stdout);
    		fflush(stdin);
    		ip1=ipp1(ipcompleta);
    	///}while(ip1>=192 && ip1<=233);
		}
	else if(cc==2){
		///do{
			std::cin.ignore();
			std::cout << "\nIngrese una ip clase B[128-191]: ";
   			std::cin.getline(ipcompleta,16,'\n');
   			fflush(stdout);
    		fflush(stdin);
   			//ip1=ipp1(ipcompleta);
   		///}while(ip1>=128 && ip1<=191);
   	}
	else if(cc==3){
		///do{
			std::cin.ignore();
   			std::cout << "\nIngrese una ip clase A[10-127]: ";
   			std::cin.getline(ipcompleta,16,'\n');
   			fflush(stdout);
    		fflush(stdin);
   			//ip1=ipp1(ipcompleta);
   		///}while(ip1>=10 && ip1<=127);
   		///}while(ip1>=10 && ip1<=127 && ip2>=0 && ip2<=255 && ip3>=0 && ip3<=255 && ip4>=0 && ip4<=255);
   		}//asignar cada octeto a una variable separada y pasar de char a int
}

void vlsm_print(){

    ip1=ipp1(ipcompleta);
    ip2=ipp2(ipcompleta);
   	ip3=ipp3(ipcompleta);
   	ip4=ipp4(ipcompleta);
   	i=0;
    ///Primera red
    ///Numero de la red
    infored[i+1][1]=mask_oct(hnhost[i+1][0]);  ///mascara de la red en decimal
    infored[i+1][2]=ip1;      ///ipred
    infored[i+1][3]=ip2;
    infored[i+1][4]=ip3;
    infored[i+1][5]=ip4;
    infored[i+1][6]=ip_broad1(ip1,ip2,ip3,ip4,mask_oct(hnhost[i+1][0])); ///ipbroad
    infored[i+1][7]=ip_broad2(ip1,ip2,ip3,ip4,mask_oct(hnhost[i+1][0]));
    infored[i+1][8]=ip_broad3(ip1,ip2,ip3,ip4,mask_oct(hnhost[i+1][0]));
    infored[i+1][9]=ip_broad4(ip1,ip2,ip3,ip4,mask_oct(hnhost[i+1][0]));
    while(i<nredes){
    	i++;
    	if(opc_nom=='n'){
    		std::cout<<"\n\nRed "<<hnhost[i][1]<<":"<<std::endl;
		}
		else if(opc_nom=='y'){
			nombre(hnhost[i][1]);
		}
        std::cout<<std::endl;
        std::cout<<"Ip de red: "<<infored[i][2]<<"."<<infored[i][3]<<"."<<infored[i][4]<<"."<<infored[i][5]<<" /"<<infored[i][1]<<std::endl;
        std::cout<<"Ip de broadcast: "<<infored[i][6]<<"."<<infored[i][7]<<"."<<infored[i][8]<<"."<<infored[i][9]<<std::endl;
        std::cout<<"Mascara: ";std::cout<<mask_dec(infored[i][1])<<std::endl;
        //Mas Informacion: Gateway sugerido, ips sobrantes, ip ocupadas.
/**        gater1=c_gater1(infored[i][2],infored[i][3],infored[i][4],infored[i][5]);
        gater2=c_gater2(infored[i][2],infored[i][3],infored[i][4],infored[i][5]);
        gater3=c_gater3(infored[i][2],infored[i][3],infored[i][4],infored[i][5]);
        gater4=c_gater4(infored[i][2],infored[i][3],infored[i][4],infored[i][5]);
        cout<<"IP Gateway sugerido: "<<gater1<<"."<<gater2<<"."<<gater3<<"."<<gater4<<endl;
        cout<<"IPs que necesita: "<<hnhost[i][0]<<endl;
        nhost=hnhost[i][0];
        p=max_host(nhost);
        nsobra=p-nhost;
        cout<<"IPs utilizables que sobran: "<<nsobra<<endl;**/
        if(i<nredes){
            infored[i+1][0]=hnhost[i+1][1]; ///Numero de la red
            nhost=hnhost[i+1][0];
            infored[i+1][1]=mask_oct(nhost);
            maskoct=mask_oct(nhost);
            ip1r=infored[i][6];
            ip2r=infored[i][7];
            ip3r=infored[i][8];
            ip4r=infored[i][9];
            infored[i+1][2]=ip_red1(ip1r,ip2r,ip3r,ip4r);
            infored[i+1][3]=ip_red2(ip1r,ip2r,ip3r,ip4r);
            infored[i+1][4]=ip_red3(ip1r,ip2r,ip3r,ip4r);
            infored[i+1][5]=ip_red4(ip1r,ip2r,ip3r,ip4r);
            ip1b=infored[i+1][2];
            ip2b=infored[i+1][3];
            ip3b=infored[i+1][4];
            ip4b=infored[i+1][5];
            infored[i+1][6]=ip_broad1(ip1b,ip2b,ip3b,ip4b,maskoct);
            infored[i+1][7]=ip_broad2(ip1b,ip2b,ip3b,ip4b,maskoct);
            infored[i+1][8]=ip_broad3(ip1b,ip2b,ip3b,ip4b,maskoct);
            infored[i+1][9]=ip_broad4(ip1b,ip2b,ip3b,ip4b,maskoct);
            }
        }

}

void vlsm(){
    opc_nombre_red();
    redes_need();
    nom_host_x_red();
    orden_enlasala();
    pedir_ip();
    vlsm_print();
}




#endif
