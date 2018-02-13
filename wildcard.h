#ifndef wildcard_cal_h
#define wildcard_cal_h
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include "cals.h"

char mask[16];
char* hn_tmp4;
void pedirDatos()
{
	std::cout<<"Ingrese la mascara en decimal o los 4 octetos\n";
	std::cout<<"Ejemplo: \"/24\" o \"255.255.255.0\": ";
	std::cin.getline(mask,16,'\n');
}
char* trans(char* mascara)
{
    char aux[2],aux1[1],aux2[1];
    char* maskk;
    maskk=mascara;
    char* mas;
    char* tmp;
	if(maskk[0]=='/'){
		aux[0]=maskk[1];//eliminar el '/' y reposicionar la mascara al principio
		maskk[1]=maskk[2];
		maskk[0]=aux[0];
		maskk[2]=NULL;
		mas=mask_dec(atoi(maskk));
		return mas; //mas == mascara en 255.255.255.0 (ej)
	}
	else if(strlen(maskk)<=2)
	{
        mas=mask_dec(atoi(maskk));
        return mas;
	}
    else if(mascara[0]=='2' && mascara[1]=='5' && mascara[2]=='5')
    {
		return "No es necesario";
	}
	else
	{
        return "Error al calcular la mascara";
	}
}

template <class dd>
char* trans_f(dd transp)
{
    dd tmp;
    tmp=trans(transp);
    if(tmp=="No es necesario")
    {
        return transp;
    }
    else
    {
        return tmp;
    }
}

void verf_mask(char* masca)
{
    char* tmp;
    tmp=trans_f(masca);
    for(int i=0;i<15;i++)
    {
        masca[i]=tmp[i];
    }
}

char* calc_wild(char* masca)
{
    char* maskk;
    maskk=masca;
    int broad1=255,broad2=255,broad3=255,broad4=255;
    int mask1=ipp1(maskk);
    int mask2=ipp2(maskk);
    int mask3=ipp3(maskk);
    int mask4=ipp4(maskk);
    int wild1=0,wild2=0,wild3=0,wild4=0;
    char* wildcardd;
    if(broad1>=mask1 && broad2>=mask2 && broad3>=mask3 && broad4>=mask4)
    {
        wild1=broad1-mask1;
        wild2=broad2-mask2;
        wild3=broad3-mask3;
        wild4=broad4-mask4;
    }
    sprintf(wildcardd,"%d.%d.%d.%d",wild1,wild2,wild3,wild4);
    return wildcardd;
}


char* wildcard(){
	pedirDatos();
    verf_mask(mask);
    std::cout<<"\n"<<std::endl;
    hn_tmp4=calc_wild(mask);
    std::cout<<"El wildcard es:       "<<hn_tmp4<<"\n\n"<<std::endl;
}
char* wildcard_sin(char* masc){
    for(int i=0;i<=15;i++)
    {
        mask[i]=masc[i];
    }
    verf_mask(mask);
    return calc_wild(mask);
}
char* wildcard_cout(char* masc){
    for(int i=0;i<=15;i++)
    {
        mask[i]=masc[i];
    }
    verf_mask(mask);
    std::cout<<"\b"<<std::endl;
    std::cout<<calc_wild(mask)<<std::endl;
}
#endif
