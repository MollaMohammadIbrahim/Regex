#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<regex>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    // mail.length is at most 100
 
    std::regex pattern(R"(((0?[1-9]|[12][0-9]|3[01])-(0?[1-9]|1[0-2])-([1-2][0-9]{3})))");
    smatch match;
    cin>>n;
    set <string> emals;
    string s;
    char a;
    while(n--){
        
        getline(cin,s);
        auto start = sregex_iterator(s.begin(),s.end(),pattern);
        auto end = sregex_iterator();
        if(start != end)cout<<"found "<<endl;
        for( auto k = start; k != end; ++k){
            match = *k;
            cout<<match.str()<<endl;
        }
        // if(regex_match(s,match,pattern)){
        //     cout<<"found"<<endl;
        // }
        // else cout<<"unmatched"<<endl;
    } 

    cout<<endl;
    return 0;
}
