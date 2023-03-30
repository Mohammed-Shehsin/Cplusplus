#include <iostream>

using namespace std;
void showMenu(){
    cout<<"\t WELCOME"<<endl;
    cout<<"********MENU********"<<endl;
    cout<<"1. Balance "<<endl<<"2. Deposit "<<endl<<"3. Withdraw"<<endl<<"0. exit"<<endl<<"************************"<<endl;
}
int main()
{
    int option;
    double balance=1000;
    do{
    showMenu();
    cout<<"Choose an Option : ";
    cin>>option;
    system("cls");
    switch(option){
    case 1: cout<<"Avaliable Balance : "<<balance<<endl<<endl; break;
    case 2: cout<<"Enter the deposit amount : $";
            double deposit;
            cin>>deposit;
            balance +=deposit;
            cout<<endl<<"Balance : $"<<balance<<endl<<endl;
        break;
    case 3: cout<<"Enter the withdraw amount : $";
                  double withdraw;
                  cin>>withdraw;
                  if(withdraw<=balance){
                  balance -=withdraw;
                  cout<<endl<<"Balance : $"<<balance<<endl<<endl;
                  }
                  else
                      cout<<"No enough blance"<<endl<<endl;
        break;
    default: cout<<"INVALID INPUT 000"<<endl<<endl;
    }
    }while(option!=0);
    return 0;
}
