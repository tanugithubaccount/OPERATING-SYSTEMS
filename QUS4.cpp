#include<iostream>
using namespace std;
#include<algorithm>

int main(){
    
    cout<<"Enter the number of process you want:";
    int pr;
    cin>>pr;
    
    int arr[pr],bur[pr],comp[pr],temp[pr],p=1,temp2[pr];
    
    for(int i=0;i<pr;i++){
        cout<<"Enter the arrival of "<<p++<<" process is:";
        cin>>arr[i];
        temp[i]=arr[i];
    }
    p=1;
    for(int i=0;i<pr;i++){
        cout<<"Enter the burst time of "<<p++<<" process is:";
        cin>>bur[i];
    }
    
    sort(temp,temp+pr);
    
    int arr1[pr],l=0,f=0,value=0,h=0,t=0;
    for(int i=0;i<pr;i++){
        if(i==0){
            value=temp[i];
        }
        else{
            i+=h-1;
            value=temp[i];
        }
        cout<<"Value is:"<<value<<endl;
        int steps=0;
        h=0;
        for(int k=0;k<pr;k++){
            if(value==arr[k]){
                arr1[h++]=bur[steps];
            }
            steps++;
        }
        sort(arr1,arr1+h);
        
        for(int h1=0;h1<h;h1++){
            comp[l++]=arr1[h1];
        }
        for(int g=0;g<h;g++){
            temp2[f++]=comp[t++];
        }
    }
    
    for(int i=1;i<pr;i++){
        comp[i]=comp[i]+comp[i-1];
    }
    int tat[pr],wat[pr];
    int g1=1,g2=1,g3=1;
    for(int i=0;i<pr;i++){
        tat[i]=comp[i]-temp[i];
        wat[i]=tat[i]-temp2[i];
        
        cout<<"The comp time of "<<g2++<<" process is:"<<comp[i]<<endl;
        cout<<"The tat of "<<g1++<<" process is :"<<tat[i]<<endl;
        cout<<"The wat time of "<<g3++<<" process is:"<<wat[i]<<endl;
    }
    
    int ttat=0,twat=0;
    for(int i=0;i<pr;i++){
        ttat+=tat[i];
        twat+=wat[i];
    }
    
    cout<<"The average tat is :"<<(float)(ttat/pr)<<endl;
    cout<<"The average wat is:"<<(float)(twat/pr)<<endl;
    return 0;
}
