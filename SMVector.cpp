#include "SMVector.h"
int main(){
    SMVector <int> vec(8);
    vec.push_back( 5);
    vec.push_back( 2);
    vec.push_back( 8);
    vec.push_back( 10);
    vec.push_back( 6);
    vec.push_back( 9);

    SMVector <int> vec2(10);
    vec2.push_back( 10);
    vec2.push_back( 2);
    vec2.push_back( 8);
    vec2.push_back( 5);
    vec2.push_back( 6);
    vec2.push_back( 9);

    
//    vec.pop_back();
//    vec.erase(vec.begin(), vec.end());
//    vec.erase(vec.begin());
//    vec.clear();
//    cout<<(vec==vec2);
}