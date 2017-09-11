//
//  main.cpp
//  QuickSort
//
//  Created by Nicholas on 4/7/17.
//  Copyright © 2017 Nicholas. All rights reserved.
//

#include <iostream>
using namespace std;

int check1=0;
int check2=0;
int check3=0;
int check4=0;
int check5=0;

const int arrysze = 10;

void switcher(int num[],int i,int c){
    int hold=num[i];
    num[i]=num[c];
    num[c]=hold;
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
    check1++;
    int p=s-1;
    int f=s;
    int l=e;
    
    if(s!=e){
    check2++;
        while(num[p]<=num[l]&&(l!=p+1)){
            l--;
        }
        while(num[p]>num[f]&&(f<e)){
            f++;
        }
            if(s==e && num[p]>num[e]){
                switcher(num,p,e);
            }
            else if(f>l&&e-s>=2){
                switcher(num,p,l);
                check5++;
                Qsort(num,s,l-1);
                Qsort(num,l+2,e);
            }
            else if(f<l){
                switcher(num,f,l);
                Qsort(num,s,e);
            }
            else if(f==e){
                switcher(num,p,l);
                check4++;
                Qsort(num,s,e-1);
            }
            else if(f==l){
                check3++;
                Qsort(num,s+1,e);
            }
        }
    
    else{
        if(num[p]>num[s]){
            switcher(num,p,s);
        }
    }
    
}





int main() {
    int num[arrysze];
    int s,e;
    num[0]=1;
    num[1]=2;
    num[2]=-1;
    num[3]=-2;
    num[4]=3;
    num[5]=4;
    num[6]=-3;
    num[7]=-4;
    num[8]=5;
    num[9]=6;
    cout<<"Initial string: ";
    for(int i=0;i<arrysze;i++){
        cout<<num[i];
        if(i!=arrysze+1){
            cout<<",";
        }
    }cout<<endl;
    
    s=1;
    e=arrysze-1;
    Qsort(num,s,e);
    cout<<"Final string: ";
    for(int i=0;i<arrysze;i++){
        cout<<num[i];
        if(i!=arrysze+1){
            cout<<",";
        }
    }cout<<endl;
    //Checks if the array is actually sorted
    checker(num);
    
    cout<<"Check 1: "<<check1<<endl;
    cout<<"Check 2: "<<check2<<endl;
    cout<<"Check 3: "<<check3<<endl;
    cout<<"Check 4: "<<check4<<endl;
    cout<<"Check 5: "<<check5<<endl;
    
}
