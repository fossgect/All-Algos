#include <iostream>
#include <vector>

//For swapping two numbers.
void swap(double *var1,double *var2){
    double temp=*var1;
    *var1=*var2;
    *var2=temp;
}

//To partition and to find the partition index.
long int partition(std::vector<double> &vec,long int start,long int stop){
    //Pivoting from the right most element.
    double pivot=vec[stop];
    long int pIndex=start;
    for(long int i=start;i<stop;i++)
        if(vec[i]<pivot){
            swap(&vec[i],&vec[pIndex]);
            ++pIndex;
        }
    swap(&vec[stop],&vec[pIndex]);
    return pIndex;
}

//Quick Sort driver function.
void quickSort(std::vector<double> &vec,long int start,long int stop){
    if(start<stop){
        long int pIndex=partition(vec,start,stop);
        quickSort(vec,start,pIndex-1);
        quickSort(vec,pIndex+1,stop);
    }
}

//To display elements.
void display(const std::vector<double> &vec){
    for(long int i=0;i<vec.size();i++)
        std::cout<<vec[i]<<" ";
    std::cout<<"\n";
}

//Driver function.
int main(){
    long int n;
    std::cout<<"Quick Sort:\n";
    std::cout<<"Enter number of elements:";
    std::cin>>n;
    std::vector<double> vec(n);
    for(long int i=0;i<n;i++)
        std::cin>>vec[i];
    quickSort(vec,0,n-1);
    std::cout<<"Quick Sorted Vector:\n";
    display(vec);
    return 0;
}