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
    //task: find unique email address
    //strings can be separated before and after @
    // a-z, A-Z, 0-9, _, 
    
    regex mail(R"(^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$)");
   
    smatch match;
    cin>>n;
    set <string> emals;
    string s;
    while(n--){
        cin>>s;
        if(regex_match(s,match,mail)){
            emals.insert(match[0]);
            cout<<"found";
            //cout<<match.position()<<endl;
        }
        else cout<<"notMatched"  ;
    }  
 for (const auto& it : emals) {
    cout << it << ";";
}

    cout<<endl;
    return 0;
}
