#include <iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    string text;
       getline(cin,text);
        string reversed_text = {};
        int n = text.length();
        int i=0;
        string sub1 ={};

    while(i<n){
        while(i<n && text[i] ==' '){
                  i++; }
        if(i>=n){
            break;
        }
        int j= i+1;
        while(j<n && text[j]!=' '){
            j++;}
        sub1 = text.substr(i,j-i);

        if(reversed_text.length()==0){
            reversed_text= sub1;
        }
        else
            reversed_text=sub1+ ' '+ reversed_text;
       i=j+1;
    }
            std::cout << reversed_text;

    return 0;
}
