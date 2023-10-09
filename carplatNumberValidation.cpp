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
 
    regex pattern( R"(^(DHA|RAJ|CHI|BAR|GAZ|KHU|RANG) (1\d|2[0-3]{1}) ([1-9]\d{3,}|999))");
   
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
 for (const auto& it : emals) {
    cout << it << ";";
}

    cout<<endl;
    return 0;
}
