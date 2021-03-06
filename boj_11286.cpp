//
//  11286.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 27..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//abs minimum heap implemeted with pair

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N; //the number of input operations

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int x;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x != 0) q.push({abs(x), x});
        else{ //if x == 0
            if(q.empty()) cout << 0 << '\n';
            else{
                cout << q.top().second << '\n';
                q.pop();
            }
        }
    }
}


