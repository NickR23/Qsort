//
//  main.cpp
//  QuickSort
//
//  Created by Nicholas on 4/7/17.
//  Copyright © 2017 Nicholas. All rights reserved.
//

#include <iostream>
using namespace std;
const int arrysze=8;


void ref(int num[], int s , int e){
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Start = "<<s<<endl<<"End = "<<e<<endl;
    cout<<"List: "<<endl;
    for(int i=0;i<arrysze;i++){
        cout<<num[i]<<",";
    }
    cout<<endl;
    
}



void checker(int num[]){
    bool check=true;
    for(int i=0;i<arrysze;i++){
        for(int c=i+1;c<arrysze;c++){
            if(num[i]>num[c]){
                check=false;
            }
        }
    }
    if(check==false){
        cout<<"ERROR :("<<endl;
    }
    else{
        cout<<"\n\n\n\n\\*****************\\\n \\ ALL IS Well :)  \\\n  \\*****************\\";
    }cout<<"\n\t";
    for(int i=0;i<arrysze;i++){
        cout<<num[i];
        if(i+1!=arrysze){
            cout<<",";
        }
    }cout<<"\n\n\n\n\n";
}

void Qsort(int num[],int s,int e){
    ref(num,s,e);
    
    int p=s-1;
    int f=s;
    int l=e;
    
    int pval=num[p];
    int fval=num[f];
    int lval=num[l];
    
    cout<<"Pval = "<<pval<<endl<<"Fval = "<<fval<<endl<<"Lval = "<<lval<<endl;
    cout<<"#################"<<endl;
    while(num[p]<=num[l]&&(l!=p+1)){
        l--;
        lval=num[l];
    }
    //f is able to get too large!!
    while(num[p]>num[f]&&(f<e)){
        f++;
        fval=num[f];
    }
    cout<<"Pval = "<<pval<<endl<<"Fval = "<<fval<<endl<<"Lval = "<<lval<<endl;
    
    if(s==e && num[p]>num[e]){
        int hold=num[p];
        num[p]=num[e];
        num[e]=hold;
        cout<<"Switched two vals";
    }
    else if(f>l&&e-s>=2){
        cout<<"@Switching pivot("<<num[p]<<") ~and~ lval("<<num[l]<<") ........";
        num[p]=num[l];
        num[l]=pval;
        Qsort(num,s,l-1);
        Qsort(num,l+2,e);
        
        
    }
    else if(f<l){
        cout<<"$Switching fval("<<num[f]<<") ~and~ lval("<<num[l]<<") ........";
        
        num[f]=num[l];
        num[l]=fval;
        Qsort(num,s,e);
    }
    else if(f==e){
        cout<<"#LEFT SIDE NEXT @Switching pivot("<<num[p]<<") ~and~ lval("<<num[l]<<") ........";
        num[p]=num[l];
        num[l]=pval;
        Qsort(num,s,e-1);
    }
    else if(f==l){
        Qsort(num,s+1,e);
    }
    
    
    ref(num,s,e);
    cout<<"Pval = "<<num[p]<<endl<<"Fval = "<<num[f]<<endl<<"Lval = "<<num[l]<<endl;
    
    
    checker(num);
}





int main() {
    int num[arrysze];
    int s,e;
    num[0]=87;
    num[1]=23;
    num[2]=13;
    num[3]=10;
    num[4]=9;
    num[5]=8;
    num[6]=2;
    num[7]=1;
    
    s=1;
    e=arrysze-1;
    Qsort(num,s,e);
    cout<<"Done :)"<<endl;
    
    
}
