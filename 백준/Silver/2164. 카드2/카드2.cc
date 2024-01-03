#include<bits/stdc++.h>

using namespace std;

#define MAXSIZE 500000

int N, front=0, back=0;
int card[MAXSIZE];

void push(int x){
    front=(front+1)%MAXSIZE;
    card[back]=x;
    back=(back+1)%MAXSIZE;
}

int main(){
    cin >> N;

    for(;back<N;back++){
        card[back]=back+1;
    }

    while(back-front!=1){
        //pop
        front=(front+1)%MAXSIZE;
        //push back
        push(card[front]);
    }

    cout << card[back-1];
}