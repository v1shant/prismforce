#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        vector<int> v(11); 
        int power, skip, recharge;
        priority_queue<int> pq;                 //we take a priority queue (max heap) to store the powers from highest to lowest
        
        for(int i=0;i<11;i++){                  //taking powers of 11 circles as input
            int x;  cin>>x;                
            if(i==2 || i==6){                   //as k3 & k7 can regenerate with half pwer, we make it 1.5 times
                pq.push(x*1.5);
            }
            else pq.push(x);
        }

        cin>>power>>skip>>recharge;                            //taking p, a, b as input

        int sum=0;

        for(int i=0;i<11;i++){  //iterating the priority queue
            if(skip>0) {        //we pop till skip count=0, as he can skip the circles with highest power 
                pq.pop();
                skip--;
            }
            else{
                sum+=pq.top();
                pq.pop();
            }    
        }
        if(sum<=power*(recharge+1)){  //we check if the sum of power of remaining circles is less than the total power of Abhimanyu
            cout<<"Abhimanyu can cross Chakravyuh "<<endl;
        }
        else{
            cout<<"Abhimanyu cannot cross Chakravyuh"<<endl;
        }
    }
}