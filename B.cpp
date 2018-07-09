#include<bits/stdc++.h>

using namespace std;

int rounds(double aver){
    if(abs(floor(aver)-aver)<0.5){
        int aux=floor(aver);
        return aux;
    }
    int aux=ceil(aver);
    return aux;
}


int main(void){

    int n;
    cin >> n;
    int sum=0;
    vector<int> grades(n);
    for(int i=0; i<n; i++){
        cin >> grades[i];
        sum+=grades[i];
    }
    sort(grades.begin(), grades.end());
    int acum=0;
    int Acum[n];
    double aux1=(double)sum/(double) n;
    if(rounds(aux1)==5){
        cout << 0 << "\n";
        return 0;
    }
    for(int i=0; i<n; i++){
        acum+=grades[i];
        double aux=(double)(sum)-(double)acum;
        aux+=5*(i+1);
        aux/=n;
        if(rounds(aux)==5){
            cout << i+1 << "\n";
            break;
        }
    }


    return 0;
}
