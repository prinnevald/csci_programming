#include <iostream>
#include <vector>
using namespace std;

//  in this algorithm I supposed the elements are
//  chars, but it actually can be anything as long
//  as the elements are comparable to each other

bool subs(vector<char> sequence, vector<char> sub){
    
    int pt = 0;
    
    for(auto word : sub){
        for(int i = pt; i < sequence.size(); i++, pt++){
            if(sequence.at(i) == word) break;
            else if(i == sequence.size()-1) return false;
        }
        pt++;
    }
    
    return true;
}

int main(){
    
    vector<char> sequence = {'a','a','b','a','c','d','a','b','d'};
    vector<char> sub = {'d','a','c'};
    
    if(subs(sequence, sub)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0; 
}