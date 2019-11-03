#include <iostream>
#include <string>
using namespace std;
int main()
{
    int lcw[100][100],len1,len2,i,j,k,m,lena,lenb;
    string str1,str2,str3;
        // Declaring iterator 
    std::string::iterator it; 
  
    // Declaring reverse iterator 
    std::string::reverse_iterator it1; 
    cout << "Enter a string1 : ";
    getline(cin,str1);
    cout << "Enter a string 2 : ";
    getline(cin,str2);
    len1=str1.size();
    len2=str2.size();
    str3.resize(min(len1,len2));
    for(i=0;i<=len1;i++){
        lcw[len2][i]=0;
    }
    for(i=0;i<=len2;i++){
        lcw[i][len1]=0;
    }
    for(i=len1-1;i>=0;i--){
        for(j=len2-1;j>=0;j--){
            if(str1[i]==str2[j]){

                lcw[i][j]=1+lcw[i+1][j+1];

            }else{
                lcw[i][j]=max(lcw[i+1][j],lcw[i][j+1]);
            }

            
         }
    }
 
    cout << "Length of longest common subsequence=\t"<<lcw[0][0]<<endl;
    m=lcw[0][0];
    i=0;
    j=0;
    lena=max(len1,len2);
    lenb=max(len1,len2);

        while(m>0){

        if (lcw[i][j+1]!=m){
            if(lcw[i+1][j]!=m){
                str3.push_back(str1[i]);
                m-=1;
                i++;
                j++;

            }else{
                i++;
            }
        }else{
            j++;
        }
        }
           
    
    
    cout <<str3<< endl; 
    return 0;
}