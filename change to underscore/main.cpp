#include <iostream>

using namespace std;

void change_to_undersores(char *text){
    for(int i=0;text[i]!= NULL ;i++){
        if((text[i]<'0'||text[i]>'9') &&
           (text[i]<'A'||text[i]>'Z') &&
           (text[i]<'a'||text[i]>'z')    ){
            text[i]='_';
        }
    }

};
int main()
{
    char text[] = "Text#with@weird^signs@()-";
    change_to_undersores(text);
    std::cout << text << std::endl;
    return 0;
}
