#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    stack<int> s;
    vector<int> answer;
   for(int i = numbers.size() -1 ;i>=0 ;i--){
       if(s.empty()){
           s.push(numbers[i]);
           answer.push_back(-1);
           continue;
       }
       int temp = s.top();
       if(temp > numbers[i]){
           answer.push_back(temp);
           s.push(numbers[i]);
       }
     
       else{
           while(1){
                s.pop();
                if(s.empty()){
                   answer.push_back(-1);
                    s.push(numbers[i]);
                   break;
               }
               temp = s.top();
               if(temp > numbers[i]){
                   answer.push_back(temp);
                   s.push(numbers[i]);
                   break;
               }
      
           }
       }
   }
    reverse(answer.begin(),answer.end());
    return answer;
}