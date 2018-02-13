#ifndef wild_num_ip_h
#define wild_num_ip_h
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include "cals.h"

int a1=0,a2=0,a3=0,a4=0;
char* wildp;
char* wild_numM;
char tmp1[15];
char tmp2[15];
char* wild_numx;
int ip1_wild,ip2_wild,ip3_wild,ip4_wild;
int ip1_red,ip2_red,ip3_red,ip4_red;
int ip_wild1=0,ip_wild2=0,ip_wild3=0,ip_wild4=0;

char* wild_numip(int numip)
{
    int wild1=0,wild2=0,wild3=0,wild4=0;
    a4=numip;
    while(a1>=256 || a2>=256 || a3>=256 || a4>=256)
    {
        if(numip>=256)
        {
            a3=(numip/256);
            numip-=(a3*256);
            a4=numip;
        }
        if(a3>=255)
        {
            a2=(numip/256);
            numip-=(a2*256);
            a3=numip;
        }
        if(a2>=255)
        {
            a1=(numip/256);
            numip-=(a1*256);
            a2=numip;
        }
    }
    wild1+=a1;
    wild2+=a2;
    wild3+=a3;
    wild4+=a4;
    sprintf(tmp1,"%d.%d.%d.%d",wild1,wild2,wild3,wild4);
    wildp=tmp1;
    return wildp;
}

char* wild_num(char* ipred_wild,int numippp)
{
    wild_numM=wild_numip(numippp);
    ip1_wild=ipp1(wild_numM);
    ip2_wild=ipp2(wild_numM);
    ip3_wild=ipp3(wild_numM);
    ip4_wild=ipp4(wild_numM);
    ip1_red=ipp1(ipred_wild);
    ip2_red=ipp2(ipred_wild);
    ip3_red=ipp3(ipred_wild);
    ip4_red=ipp4(ipred_wild);
    ip_wild1=ip1_red+ip1_wild;
    ip_wild2=ip2_red+ip2_wild;
    ip_wild3=ip3_red+ip3_wild;
    ip_wild4=ip4_red+ip4_wild;
    if(ip_wild4>=256)
    {
        ip_wild3+=1;
        ip_wild4-=256;
    }
    if(ip_wild3>=256)
    {
        ip_wild2+=1;
        ip_wild3-=256;
    }
    if(ip_wild2>=256)
    {
        ip_wild1+=1;
        ip_wild2-=256;
    }
    sprintf(tmp2,"%d.%d.%d.%d",ip_wild1,ip_wild2,ip_wild3,ip_wild4);
    wild_numx=tmp2;
    return wild_numx;
}

#endif
