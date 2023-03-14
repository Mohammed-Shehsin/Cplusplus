#include <iostream>
#include<vector>
#include<iterator>
#include<string>

using namespace std;
bool check_brackets(string math){
    std::vector<char> brackets;
    for(unsigned i=0;i<math.size();i++){
        char word=math.at(i);
        brackets.emplace_back(word);
    }
    brackets.pop_back();
    int size=brackets.size();
   for(int i=0;i<size/4;i++){
       vector<char>::iterator first_el=brackets.begin();
       vector<char>::iterator second_el=brackets.end();
       char e_1=*first_el;
        char e_2=*second_el;
  if(e_1=='{'){
      if(e_2=='}'){
                    return 1;
                 }
             }else if(e_1=='('){
                 if(e_2==')'){
                    return 1;
             }}
       brackets.pop_back();

   }
   return 0;
}

int main(){
std::cout << check_brackets("({5 * [2 * (1 + 2)]}) + 1")<<endl;
std::cout << check_brackets("({5 * [2 * (1 + 2)]} + 1");
    return 0;
}

