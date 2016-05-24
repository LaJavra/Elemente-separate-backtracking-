// deocamdata nu afisez in fisier ca se blocheaza pc

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("permutari.in");
ofstream fout("permutari.out");

long a[10],b[10];
int y[2];
int t;
void back(int k,int len,int k1,int k2)
{       if(k-1 == len)   //afisam solutia
        {
         for(int i = 1; i <= len;i++){
            if(a[i]==k1 || a[i]==k2){
                    y[t]=i;
                    t++;}}
        if(abs(y[1]-y[0])==2)
            {
            for(int j=1; j <= len; j++)
                {
                fout<<a[j];}
                fout<<endl;
                }t=0;
                }
     else
     {
         for(int  i = 1; i <= len; i++)
            if(!b[i])  //daca valoarea nu-i folosita
           {
                 a[k] = i;
                 b[i] = 1; //o folosim
                 back(k+1,len,k1,k2);//trecem la pasul urmator
                 b[i] = 0; //o eliberam
           }
     }

}
int main()
{
    int z,k1,k2;
    fin>>z>>k1>>k2;
    back(1,z,k1,k2);
    fin.close();
    fout.close();
    return 0;
}
