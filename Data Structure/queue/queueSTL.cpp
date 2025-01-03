#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout<<"size : "<<q.size()<<endl;
    q.pop();
    cout<<"size after pop : "<<q.size()<<endl;

    cout<<"front : "<<q.front()<<endl;
    
    if(q.empty()){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    
    return 0;
}