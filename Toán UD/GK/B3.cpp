#include <bits/stdc++.h>
using namespace std;
long long a[5][5],n;
double res[5][5];
bool doixung(){
    for (int i=1; i<=n; i++)
    for (int j=1; j<=i; j++)
    if (a[i][j]!=a[j][i]) {
        return false;
    }
    return true;
}
void xuli(){
	
	cout<<"Phan ra Cholesky ma tran A = L * D * L^T\n";
	cout<<"Duoc cac ma tran sau\n";
    if (n==1) res[1][1]=a[1][1];
    else 
    if (n==2) {
        res[1][1]=a[1][1];
        res[1][2]=res[2][1]=a[2][1]/res[1][1];
        res[2][2]=sqrt(a[2][2] - res[1][1]*res[2][1]*res[2][1]);
    } else {
        res[1][1]=a[1][1];
        res[1][2]=res[2][1]=a[2][1]/res[1][1];
        res[2][2]=sqrt(a[2][2] - res[1][1]*res[2][1]*res[2][1]);
        res[3][1]=res[1][3]=a[3][1]/res[1][1];
        res[3][2]=res[2][3]=(a[3][2] - res[1][1]*res[2][1]*res[3][1])/res[2][2];
        res[3][3]=a[3][3] - res[1][1]*res[3][1]*res[3][1] - res[2][2]*res[3][2]*res[3][2];
    }
    cout<<"\nL\n";
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) 
        if (j<i) printf("%.5f ",res[i][j]); else 
        if (i==j) cout<<"1.00000 "; else cout<<"0.00000";
        cout<<"\n";
    }
    cout<<"\nD\n"; 
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) 
        if (i==j) printf("%.5f ",res[i][j]); else 
        cout<<"0.00000 ";
        cout<<"\n";
    }

    cout<<"\nL^T\n";
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) 
        if (j>i) printf("%.5f ",res[i][j]); else
        if (i==j) cout<<"1.00000 "; else cout<<"0.00000 ";
        cout<<"\n";
    }
}
int main(){
	n=3;
	a[1][1] = -10;  a[1][2] = 4;  a[1][3] = 7;
	a[2][1] = 4;  a[2][2] = -5;  a[2][3] = 8;
	a[3][1] = 7;   a[3][2] = 8;  a[3][3] = -9;
	
    if (!doixung()) cout<<"ERROR!";
	xuli();
    
}

