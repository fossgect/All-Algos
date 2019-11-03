#include<bits/stdc++.h> 
#define pb push_back 
using namespace std;
int main(){
int n,xdif,ydif,i,x1,y1,x2,y2,a[100][100],x,y,j,m;
cout<<"Enter the intial point"<<endl;
cin>>x1>>y1;
cout<<"Enter the final point"<<endl;
cin>>x2>>y2;
cout<<"Enter the no.of holes"<<endl;
cin>>m;


for(i=x1;i<=x2;i++){
    for(j=y1;j<=y2;j++){
        a[i][j]=-1;

    }
}
for(i=0;i<m;i++){
    cin>>x>>y;
    a[x][y]=0;
}

a[x1][y1]=1;
for(i=y1+1;i<=y2;i++){
    if(a[x1][i]!=0){
        a[x1][i]=1;
        cout<<a[x1][i]<<"\n";
    }

}
for(i=x1+1;i<=x2;i++){
    if(a[i][y1]!=0){
        a[i][y1]=1;
        cout<<a[i][y1]<<"\n";

    }

}

for(i=x1+1;i<=x2;i++){
    for(j=y1+1;j<=y2;j++){
    if(a[i][j]!=0){
        a[i][j]=a[i-1][j]+a[i][j-1];
            cout<<a[i][j]<<"\n";
    }
    }
}

cout<<"No.of ways= "<<a[x2][y2];
return 0;
}
