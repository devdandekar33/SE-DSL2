/* Consider telephone book database of N clients. Make use of a hash table 
implementation to quickly look up client‘s telephone number. Make use 
of two collision handling techniques and compare them using number of 
comparisons required to find a set of telephone numbers (Note: Use linear 
probing with replacement and without replacement) */

#include<iostream>
using namespace std;

void LP_withoutReplacement(int I[10],int Hash[10]){
    for(int i=0;i<10;i++){
        int address;
        address=I[i]%10;
        //if hash array is empty
        if(Hash[address]==-1){
            Hash[address]=I[i];
        }
        //if hash array is not empty
        else{
            while(Hash[address]!=-1){
                if(address==9){
                    address=0;
                }
                else{
                    address++;
                }
            }
            Hash[address]=I[i];
        }
    }
}

void LP_withReplacement(int I[10],int Hash[10]){
    for(int i=0;i<10;i++){
        int addr;
        addr=I[i]%10;
        //if Hash array is empty
        if(Hash[addr]==-1){
            Hash[addr]=I[i];
        }
        else{
            //important 
            int curr_element=Hash[addr];
            int curr_addr=I[addr]%10;
            if(curr_addr!=addr){
                Hash[addr]=I[i];
                //replace
                while(Hash[addr]!=-1){
                    if(addr==9){
                        addr=0;
                    }
                    else{
                        addr++;
                    }
                }
                Hash[addr]=curr_element;
            }
            else{
                //shift
                while(Hash[addr]!=-1){
                    if(addr==9){
                        addr=0;
                    }
                    else{
                        addr++;
                    }
                }
                Hash[addr]=I[i];
            }
        }
    }
}
int main(){
    int I[10];
    int Hash[10];
    cout<<"enter the mobile numbers"<<endl;
    for(int i=0;i<10;i++){
        cout<<i<<" :";
        cin>>I[i];
        Hash[i]=-1;
    }
    int choice;
    cout<<"Choice:"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Linear Probing without replacement "<<endl;
        LP_withoutReplacement(I,Hash);
        cout<<"Hash Table:"<<endl;
        for(int i=0;i<10;i++){
		    cout<<i<<" :"<<Hash[i]<<endl;
	    }
        break;
        
        case 2:
        cout<<"Linear Probing with replacement: "<<endl;
        LP_withReplacement(I,Hash);
        cout<<"Hash Table:"<<endl;
        for(int i=0;i<10;i++){
		    cout<<i<<" :"<<Hash[i]<<endl;
	    }
        break;
    }
}
