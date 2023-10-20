#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int l = 0;
    int r = 0;
    map<int,int> first;
    map<int,int> second;
    for(int i = 0 ; i<topping.size(); i++){
        second[topping[i]]++;
    }
  
   
    for(int i = 0 ;i<topping.size(); i++){
        first[topping[i]]++;
        second[topping[i]]--;
        if(second[topping[i]] == 0){
            second.erase(topping[i]);
        }
        
       if(first.size() == second.size()){
           answer++;
       }
    }
    return answer;
}