#include<iostream>
#include<limits.h>
#include<math.h>
#define R 65536
using namespace std;

bool prime[R];

void prime_init(){
    for(int i=2;i<R;i++)
        prime[i]=true;

    for(int i=2;i<=R;i++)
        if(prime[i]){
            for(int j=2*i;j<=R;j+=i)
                prime[j]=false;
        }
}

int main(){
    prime_init();
    //cout<<"!"<<endl;
    long long num;
    int counter=0;
    cin>>num;
    while(num!=0){
        if(num==INT_MAX){
            cout<<"Case "<<++counter<<": 2147483648"<<endl;
            cin>>num;
            continue;
        }
        else if(num==1){
            cout<<"Case "<<++counter<<": 2"<<endl;
            cin>>num;
            continue;
        }


        int ans=0,s=sqrt(num)+1;
        int temp=num;

        for(int i=2;i<=s;i++)
            if(prime[i]&&num%i==0){

                int t,a=1;

                while(temp%i==0){
                    temp/=i;
                    a*=i;
                }
                //cout<<a<<" "<<temp<<endl;
                ans+=a;
            }
        //cout<<ans<<" ";

        if(temp!=1)
            ans+=temp;
        if(ans==num)
            ans++;

        cout<<"Case "<<++counter<<": "<<ans<<endl;


        cin>>num;
    }
    return 0;

}
