#include<bits/stdc++.h>

using namespace std;

long long int n;

double fastExp(int p){
    if(p==0) return 1;
    if(p==1) return 0.9;
    if(p%1){
        double aux=fastExp((p-1)/2);
        aux*=aux;
        aux*=0.9;
        return aux;
    }
    double aux=fastExp(p/2);
    aux*=aux;
    return aux;
}

long long int sweets(int step,int k){

    double pot=fastExp(step);
    double aux=pot*n-(((((double)1-pot)/0.1)-1)*k);
    return aux;
}

int findMin(int inStep, int k){
    int step1=0, step2=1;
    while(sweets(inStep+step2, k)>=10){
        step1=step2;
        step2=step2 << 1;
    }
    return inStep+step1;
}


int main(void){

    cin >> n;
    int inStep=1;
    long long int start=1, ended=n-1, med=start+(ended-start)/2;
    while(start!=ended-1){
        int dulces;
        int aux=findMin(1, med);
        while(aux!=inStep){
            inStep=aux;
            aux=findMin(inStep);
        }
    }




    return 0;

}
