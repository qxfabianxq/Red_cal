#ifndef CALS_H_INCLUDED
#define CALS_H_INCLUDED
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>

template <class dd>

char opcion(dd opc_nom='n'){
	std::cout<<"Quiere ponerle nombres a las redes?[y/N]: ";
    std::cin>>opc_nom;
    fflush(stdin);
    return opc_nom;
}

int pot(int poww){
    int num;
	num=pow(2,poww);
	return num;
}

int min(int poww){
    int minn;
	minn=(pow(2,poww))-2+1;
	return minn;
}
int max(int poww){
    int maxx;
    poww++;
	maxx=(pow(2,poww))-2;
	return maxx;
}

int min_host(int nhostt){
	int i=1,t=0,minn,maxx;
	int nhost=nhostt;
	if (nhost>=0 && nhost<=(pow(2,24)-2)){
		while(nhost<pow(2,24)-2 && t<=0){
			i++;
			minn=min(i);
			maxx=max(i);
			if (nhost==1){
			    return 1;
			    t=1;
		    }
		    else if (nhost>=minn && nhost<=maxx){
			    return minn;
			    t=1;
		    }
    	}
	}
	else{
		std::cout<<"Error"<<std::endl;
	}

}

int max_host(int nhostt){
	int i=1,t=0,maxx,minn;
	int nhost=nhostt;
	if (nhost>=0 && nhost<=(pow(2,24)-2)){
		while(nhost<pow(2,24)-2 && t<=0){
			i++;
			minn=min(i);
			maxx=max(i);
			if (nhost==1 || nhost==2){
			    return 2;
			    t=1;
		    }
		    else if (nhost>=minn && nhost<=maxx){
			    return maxx;
			    t=1;
		    }
    	}
	}
	else{
		std::cout<<"Error"<<std::endl;
	}

}
int rango_host(int nhost){
    return max_host(nhost)+2;
}

template <class cdcd>
int rev_mask(cdcd nhostt){
    int maskk=mask_oct(nhostt);
    if(maskk>=8 && maskk<=30){
            return maskk;
    }
}
int mask_oct(int nhostt){
	int i=1,t=0,maxx=0,minn=0,mask_oct=30;
	int nhost=nhostt;
	if (nhost>=1 && nhost<=(pow(2,24)-2)){
	    if (nhost==1 || nhost==2){
			t=1;
		    return 30;
		}
		while(nhost<pow(2,24)-2 && t!=1){
			i++;
			mask_oct--;
			minn=min(i);
			maxx=max(i);
		    if (nhost>=minn && nhost<=maxx){
		    	t=1;
                return mask_oct;
		    }
    	}
	}
	else{
		std::cout<<"Error al calcular la mascara, intente nuevamente"<<std::endl;
	}
}

char* mask_dec(int mask_oct){
	int mask_dec;
	char* mask = new char;
	if (mask_oct>=24 && mask_oct<=30){
		mask_dec=mask_oct-24;
		switch (mask_dec){
			case 0: mask="255.255.255.0";
					break;
			case 1: mask="255.255.255.128";
					break;
			case 2: mask="255.255.255.192";
					break;
			case 3: mask="255.255.255.224";
					break;
			case 4: mask="255.255.255.240";
					break;
			case 5: mask="255.255.255.248";
					break;
			case 6: mask="255.255.255.252";
					break;

		}
	}
	else if (mask_oct>=16 && mask_oct<=23){
		mask_dec=mask_oct-16;
		switch (mask_dec){
			case 0: mask="255.255.0.0";
					break;
			case 1: mask="255.255.128.0";
					break;
			case 2: mask="255.255.192.0";
					break;
			case 3: mask="255.255.224.0";
					break;
			case 4: mask="255.255.240.0";
					break;
			case 5: mask="255.255.248.0";
					break;
			case 6: mask="255.255.252.0";
					break;
			case 7: mask="255.255.254.0";
					break;

		}
	}
	else if (mask_oct>=8 && mask_oct<=15){
		mask_dec=mask_oct-8;
		switch (mask_dec){
			case 0: mask="255.0.0.0";
					break;
			case 1: mask="255.128.0.0";
					break;
			case 2: mask="255.192.0.0";
					break;
			case 3: mask="255.224.0.0";
					break;
			case 4: mask="255.240.0.0";
					break;
			case 5: mask="255.248.0.0";
					break;
			case 6: mask="255.252.0.0";
					break;
			case 7: mask="255.254.0.0";
					break;
		}
	}
	else{
		std::cout<<"Error"<<std::endl;
	}
	return mask;
}

int ip_broad1(int ip1,int ip2,int ip3,int ip4,int mask_oct){
    int nnn=pow(2,(32-mask_oct));
    int masip3=0,masip2=0,masip1=0,ip1r,ip2r,ip3r,ip4r;
    ip4=ip4+nnn-1;
    while(ip2>255 || ip3>255 || ip4>255){
        if(ip4>255){
            ip4=ip4-256;
            ip3++;
        }
        else if(ip3>255){
            ip3=ip3+masip3-256;
            ip2++;
        }
        else if(ip2>255){
            ip2=ip2+masip2-256;
            ip1++;
        }
    }
    return ip1;
}
int ip_broad2(int ip1,int ip2,int ip3,int ip4,int mask_oct){
    int nnn=pow(2,(32-mask_oct));
    int masip3=0,masip2=0,masip1=0,ip1r,ip2r,ip3r,ip4r;
    ip4=ip4+nnn-1;
    while(ip2>255 || ip3>255 || ip4>255){
        if(ip4>255){
            ip4=ip4-256;
            ip3++;
        }
        else if(ip3>255){
            ip3=ip3+masip3-256;
            ip2++;
        }
        else if(ip2>255){
            ip2=ip2+masip2-256;
            ip1++;
        }
    }
    return ip2;
}
int ip_broad3(int ip1,int ip2,int ip3,int ip4,int mask_oct){
    int nnn=pow(2,(32-mask_oct));
    int masip3=0,masip2=0,masip1=0,ip1r,ip2r,ip3r,ip4r;
    ip4=ip4+nnn-1;
    while(ip2>255 || ip3>255 || ip4>255){
        if(ip4>255){
            ip4=ip4-256;
            ip3++;
        }
        else if(ip3>255){
            ip3=ip3+masip3-256;
            ip2++;
        }
        else if(ip2>255){
            ip2=ip2+masip2-256;
            ip1++;
        }
    }
    return ip3;
}
int ip_broad4(int ip1,int ip2,int ip3,int ip4,int mask_oct){
    int nnn=pow(2,(32-mask_oct));
    int masip3=0,masip2=0,masip1=0,ip1r,ip2r,ip3r,ip4r;
    ip4=ip4+nnn-1;
    while(ip2>255 || ip3>255 || ip4>255){
        if(ip4>255){
            ip4=ip4-256;
            ip3++;
        }
        else if(ip3>255){
            ip3=ip3+masip3-256;
            ip2++;
        }
        else if(ip2>255){
            ip2=ip2+masip2-256;
            ip1++;
        }
    }
    return ip4;
}

int ip_red1(int ip1,int ip2,int ip3,int ip4){
    ip4++;
    if(ip4==256){
        ip3++;
        ip4=0;
        if(ip3==256){
            ip2++;
            ip3=0;
            if(ip2==256){
                ip1++;
                ip2=0;
            }
        }
    }
    return ip1;
}
int ip_red2(int ip1,int ip2,int ip3,int ip4){
    ip4++;
    if(ip4==256){
        ip3++;
        ip4=0;
        if(ip3==256){
            ip2++;
            ip3=0;
            if(ip2==256){
                ip1++;
                ip2=0;
            }
        }
    }
    return ip2;
}

int ip_red3(int ip1,int ip2,int ip3,int ip4){
    ip4++;
    if(ip4==256){
        ip3++;
        ip4=0;
        if(ip3==256){
            ip2++;
            ip3=0;
            if(ip2==256){
                ip1++;
                ip2=0;
            }
        }
    }
    return ip3;
}
int ip_red4(int ip1,int ip2,int ip3,int ip4){
    ip4++;
    if(ip4==256){
        ip3++;
        ip4=0;
        if(ip3==256){
            ip2++;
            ip3=0;
            if(ip2==256){
                ip1++;
                ip2=0;
            }
        }
    }
    return ip4;
}

int c_gater1(int ip1r,int ip2r,int ip3r,int ip4r){
    if(ip4r==255){
            ip3r++;
            ip4r=0;
            if(ip3r==256){
                ip2r++;
                ip3r=0;
                if(ip2r==256){
                    ip1r++;
                    ip2r=0;
                }
            }
        }else{
            ip4r++;
        }
    return ip1r;
}

int c_gater2(int ip1r,int ip2r,int ip3r,int ip4r){
    if(ip4r==255){
            ip3r++;
            ip4r=0;
            if(ip3r==256){
                ip2r++;
                ip3r=0;
                if(ip2r==256){
                    ip1r++;
                    ip2r=0;
                }
            }
        }else{
            ip4r++;
        }
        return ip2r;
}

int c_gater3(int ip1r,int ip2r,int ip3r,int ip4r){
    if(ip4r==255){
            ip3r++;
            ip4r=0;
            if(ip3r==256){
                ip2r++;
                ip3r=0;
                if(ip2r==256){
                    ip1r++;
                    ip2r=0;
                }
            }
        }else{
            ip4r++;
        }
    return ip3r;
}

int c_gater4(int ip1r,int ip2r,int ip3r,int ip4r){
    if(ip4r==255){
            ip3r++;
            ip4r=0;
            if(ip3r==256){
                ip2r++;
                ip3r=0;
                if(ip2r==256){
                    ip1r++;
                    ip2r=0;
                }
            }
        }else{
            ip4r++;
        }
        return ip4r;
}

int ipp1(char frase[2]){
  char *ptr;
  char* ip[5];
  int i=0;
  int a1,a2,a3,a4;
  ptr = strtok(frase,".");
  while(ptr != NULL)
    {
      i++;
      ip[i]=ptr;
      ptr = strtok(NULL, ".");
    }
  std::istringstream ss1(ip[1]);
  ss1 >> a1;
  return a1;
}
int ipp2(char frase[2]){
  char *ptr;
  char* ip[5];
  int i=0;
  int a1,a2,a3,a4;
  ptr = strtok(frase,".");
  while(ptr != NULL)
    {
      i++;
      ip[i]=ptr;
      ptr = strtok(NULL, ".");
    }
  std::istringstream ss2(ip[2]);
  ss2 >> a2;
  return a2;
}
int ipp3(char frase[2]){
  char *ptr;
  char* ip[5];
  int i=0;
  int a1,a2,a3,a4;
  ptr = strtok(frase,".");
  while(ptr != NULL)
    {
      i++;
      ip[i]=ptr;
      ptr = strtok(NULL, ".");
    }
  std::istringstream ss3(ip[3]);
  ss3 >> a3;
  return a3;
}
int ipp4(char frase[2]){
  char *ptr;
  char* ip[5];
  int i=0;
  int a1,a2,a3,a4;
  ptr = strtok(frase,".");
  while(ptr != NULL)
    {
      i++;
      ip[i]=ptr;
      ptr = strtok(NULL, ".");
    }
  std::istringstream ss4(ip[4]);
  ss4 >> a4;
  return a4;
}

int dec_to_bin(int num){
	int bin;
	int cal;
	bin=100000000;
	int tmp=0;
	while(tmp==0){
		if ((num-128)>=0){
			bin+=10000000;
			if (num==0){
				std::cout<<bin;
				tmp=1;
			}
			else{
				num-=128;
			}
		}
		else if ((num-64)>=0){
			bin+=1000000;
			if (num==0){
				std::cout<<bin;
				tmp=1;
			}
			else{
				num-=64;
			}
		}
		else if ((num-32)>=0){
			bin+=100000;
			if (num==0){
				std::cout<<bin;
				tmp=1;
			}
			else{
				num-=32;
			}
		}
		else if ((num-16)>=0){
			bin+=10000;
			if (num==0){
				std::cout<<bin;
				tmp=1;
			}
			else{
				num-=16;
			}
		}
		else if ((num-8)>=0){
			bin+=1000;
			if (num==0){
				std::cout<<bin;
				tmp=1;
			}
			else{
				num-=8;
			}
		}
		else if ((num-4)>=0){
			bin+=100;
			if (num==0){
				std::cout<<bin;
				tmp=1;
			}
			else{
				num-=4;
			}
		}
		else if ((num-2)>=0){
			bin+=10;
			if (num==0){
				std::cout<<bin;
				tmp=1;
			}
			else{
				num-=2;
			}
		}
		else if ((num-1)>=0){
			bin+=1;
			if (num==0){
				std::cout<<bin;
				tmp=1;
			}
			else{
				num-=1;
			}
		}
		else {
			tmp=1;
		}
	}
	return bin;
}
int bin(int num_bin){
	int a;
	a=dec_to_bin(num_bin)-100000000;
    return a;
}
int nred_cal(int ip_dec,int masc_dec){
	int nred, ip,masc;
	int desc_bin=100000000;
	int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0;
	int b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0;
	int tmp=0;
	ip=dec_to_bin(ip_dec);
	masc=dec_to_bin(masc_dec);
	while (!(ip==0)){
		if ((ip-desc_bin)>=10000000){
			ip-=10000000;
			a8=1;
		}
		else if ((ip-desc_bin)>=1000000){
			ip-=1000000;
			a7=1;
		}
		else if ((ip-desc_bin)>=100000){
			ip-=100000;
			a6=1;
		}
		else if ((ip-desc_bin)>=10000){
			ip-=10000;
			a5=1;
		}
		else if ((ip-desc_bin)>=1000){
			ip-=1000;
			a4=1;
		}
		else if ((ip-desc_bin)>=100){
			ip-=100;
			a3=1;
		}
		else if ((ip-desc_bin)>=10){
			ip-=10;
			a2=1;
		}
		else if ((ip-desc_bin)>=1){
			ip-=1;
			a1=1;
		}
		else if(ip-desc_bin==0){
			ip-=desc_bin;
		}
	}
	tmp=0;
	while(!(masc==0)){
		if ((masc-desc_bin)>=10000000){
			masc-=10000000;
			b8=1;
		}
		else if ((masc-desc_bin)>=1000000){
			masc-=1000000;
			b7=1;
		}
		else if ((masc-desc_bin)>=100000){
			masc-=100000;
			b6=1;
		}
		else if ((masc-desc_bin)>=10000){
			masc-=10000;
			b5=1;
		}
		else if ((masc-desc_bin)>=1000){
			masc-=1000;
			b4=1;
		}
		else if ((masc-desc_bin)>=100){
			masc-=100;
			b3=1;
		}
		else if ((masc-desc_bin)>=10){
			masc-=10;
			b2=1;
		}
		else if ((masc-desc_bin)>=1){
			masc-=1;
			b1=1;
		}
		else if(masc-desc_bin==0){
			masc-=desc_bin;
		}
	}
	if(a1==b1 && a1==1){
		nred+=1;
	}
	if(a2==b2 && a2==1){
		nred+=2;
	}
	if(a3==b3 && a3==1){
		nred+=4;
	}
	if(a4==b4 && a4==1){
		nred+=8;
	}
	if(a5==b5 && a5==1){
		nred+=16;
	}
	if(a6==b6 && a6==1){
		nred+=32;
	}
	if(a7==b7 && a7==1){
		nred+=64;
	}
	if(a8==b8 && a8==1){
		nred+=128;
	}
	return nred;
}

int masc_cal(int mascc1,int mascc2,int mascc3,int mascc4){
	int cal_masc=0;
	int masc1,masc2,masc3,masc4;
	masc1=mascc1;
	masc2=mascc2;
	masc3=mascc3;
	masc4=mascc4;
	if (masc1==255 && masc2==255 && masc3==255 && masc4>=0){//mascara 24-30
		if (masc4 == 0){
			cal_masc=24;
			return cal_masc;
		}
		if (masc4 == 128){
			cal_masc=25;
			return cal_masc;
		}
		if (masc4 == 192){
			cal_masc=26;
			return cal_masc;
		}
		if (masc4 == 224){
			cal_masc=27;
			return cal_masc;
		}
		if (masc4 == 240){
			cal_masc=28;
			return cal_masc;
		}
		if (masc4 == 248){
			cal_masc=29;
			return cal_masc;
		}
		if (masc4 == 252){
			cal_masc=30;
			return cal_masc;
		}
	}
	else if(masc1==255 && masc2==255 && masc3>=0 && masc4==0){//mascara 16-23
		if (masc3==0){
			cal_masc=16;
			return cal_masc;
		}
		if (masc3==128){
			cal_masc=17;
			return cal_masc;
		}
		if (masc3==192){
			cal_masc=18;
			return cal_masc;
		}
		if (masc3==224){
			cal_masc=19;
			return cal_masc;
		}
		if (masc3==240){
			cal_masc=20;
			return cal_masc;
		}
		if (masc3==248){
			cal_masc=21;
			return cal_masc;
		}
		if (masc3==252){
			cal_masc=22;
			return cal_masc;
		}
		if (masc3==254){
			cal_masc=23;
			return cal_masc;
		}
	}
	else if(masc1==255 && masc2>=0 && masc3==0 && masc4==0){//mascara 8-15
		if (masc2==0){
			cal_masc=8;
			return cal_masc;
		}
		if (masc2==128){
			cal_masc=9;
			return cal_masc;
		}
		if (masc2==192){
			cal_masc=10;
			return cal_masc;
		}
		if (masc2==224){
			cal_masc=11;
			return cal_masc;
		}
		if (masc2==240){
			cal_masc=12;
			return cal_masc;
		}
		if (masc2==248){
			cal_masc=13;
			return cal_masc;
		}
		if (masc2==252){
			cal_masc=14;
			return cal_masc;
		}
		if (masc2==254){
			cal_masc=15;
			return cal_masc;
		}
	}
}

int mask_to_maskdec(char* maskkc)
{
    if(maskkc=="255.0.0.0"){
        return 8;
    }
    else if(maskkc=="255.128.0.0"){
        return 9;
    }
    else if(maskkc=="255.192.0.0"){
        return 10;
    }
    else if(maskkc=="255.224.0.0"){
        return 11;
    }
    else if(maskkc=="255.240.0.0"){
        return 12;
    }
    else if(maskkc=="255.248.0.0"){
        return 13;
    }
    else if(maskkc=="255.252.0.0"){
        return 14;
    }
    else if(maskkc=="255.254.0.0"){
        return 15;
    }
    else if(maskkc=="255.255.0.0"){
        return 16;
    }
    else if(maskkc=="255.255.128.0"){
        return 17;
    }
    else if(maskkc=="255.255.192.0"){
        return 18;
    }
    else if(maskkc=="255.255.224.0"){
        return 19;
    }
    else if(maskkc=="255.255.240.0"){
        return 20;
    }
    else if(maskkc=="255.255.248.0"){
        return 21;
    }
    else if(maskkc=="255.255.252.0"){
        return 22;
    }
    else if(maskkc=="255.255.254.0"){
        return 23;
    }
    else if(maskkc=="255.255.255.0")
    {
        return 24;
    }
    else if(maskkc=="255.255.255.128")
    {
        return 25;
    }
    else if(maskkc=="255.255.255.192")
    {
        return 26;
    }
    else if(maskkc=="255.255.255.224")
    {
        return 27;
    }
    else if(maskkc=="255.255.255.240")
    {
        return 28;
    }
    else if(maskkc=="255.255.255.248")
    {
        return 29;
    }
    else if(maskkc=="255.255.255.252")
    {
        return 30;
    }
    else if(maskkc=="255.255.255.254")
    {
        return 31;
    }
    else if(maskkc=="255.255.255.255")
    {
        return 32;
    }
}

char ipd[20];
char* ipf;
char* masf;
char* ipp_ipp(char* ipp)
{
    for(int i=0;i<20;i++)
    {
        ipd[i]=ipp[i];
    }
    char* fin=strtok(ipd,"/");
    ipf=fin;
    fin=strtok(NULL,"/");
    masf=fin;
    return ipf;
}
char* masc_masc(char* mass)
{
    char* tmp3;
    for(int i=0;i<20;i++)
    {
        ipd[i]=mass[i];
    }
    char* fin=strtok(ipd,"/");
    ipf=fin;
    fin=strtok(NULL,"/");
    masf=fin;
    return masf;
}

#endif
