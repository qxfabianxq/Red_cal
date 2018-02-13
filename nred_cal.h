#ifndef nred_cal_h
#define nred_cal_h
#include <iostream>
#include "cals.h"

char ip_dec[15],ip_bin,masc_dec[15],masc_bin;
int int_ip_bin,int_masc_bin,aux,tmp,binn,masc_num;
int int_ip_dec1,int_ip_dec2,int_ip_dec3,int_ip_dec4;
int int_masc_dec1,int_masc_dec2,int_masc_dec3,int_masc_dec4;

void ip(){
    std::cout<<"Ingrese su ip: ";
	std::cin.getline(ip_dec,16,'\n');
}

void mascara(){
    std::cout<<"Ingrese su mascara: ";
	std::cin.getline(masc_dec,16,'\n');
}

void var_asign(){
    int_ip_dec1=ipp1(ip_dec);
	int_ip_dec2=ipp2(ip_dec);
	int_ip_dec3=ipp3(ip_dec);
	int_ip_dec4=ipp4(ip_dec);
	int_masc_dec1=ipp1(masc_dec);
	int_masc_dec2=ipp2(masc_dec);
	int_masc_dec3=ipp3(masc_dec);
	int_masc_dec4=ipp4(masc_dec);
	masc_num=masc_cal(int_masc_dec1,int_masc_dec2,int_masc_dec3,int_masc_dec4);
}

void nred_output(){
    std::cout<<"\n"<<std::endl;
	std::cout<<"--------------------------\n"<<std::endl;
	std::cout<<"El nombre de la red es:   ";
	if (masc_num>=24 && masc_num<=30){ //Mascara 24+
		std::cout<<int_ip_dec1<<"."<<int_ip_dec2<<"."<<int_ip_dec3<<"."<<nred_cal(int_ip_dec4,int_masc_dec4)<<std::endl;
	}
	else if (masc_num>=16 && masc_num<=23){ //Mascara 16+
		std::cout<<int_ip_dec1<<"."<<int_ip_dec2<<"."<<nred_cal(int_ip_dec3,int_masc_dec3)<<"."<<0<<std::endl;
	}
	else if (masc_num>=8 && masc_num<=15){ //Mascara 8+
		std::cout<<int_ip_dec1<<"."<<nred_cal(int_ip_dec2,int_masc_dec2)<<"."<<0<<"."<<0<<std::endl;
	}
	else {
		std::cout<<"Mascara incorrecta"<<std::endl;
	}
	std::cout<<"\n"<<std::endl;
}

void nred(){
    ip();
    mascara();
    var_asign();
    nred_output();
}


#endif