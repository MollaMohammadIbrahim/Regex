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
 
    std::regex pattern(R"(\b((0?[1-9]|[12][0-9]|3[01])-(0?[1-9]|1[0-2])-([1-2][0-9]{3}))\b)");

   
    smatch match;
    cin>>n;
    set <string> emals;
    string s;
    while(n--){
        getline(cin,s);
        if(regex_match(s,match,pattern)){
            emals.insert(match[0]);
            cout<<"found"<<endl;
            //cout<<match.position()<<endl;
        }
        else cout<<"notMatched" << endl;
    } 
    
    cout<<endl;
    return 0;
}
