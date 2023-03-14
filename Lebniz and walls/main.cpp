#include <iostream>
#include <cmath>

int main()
{
    int max_iter;
    bool method;
    long double approximated_pi = 0;
    std::cout << "Choose method: (0 - Leibniz, 1 - Wallis): " << std::endl;
    std::cin >> method;
    std::cout << "Chosen " << method << " method" << std::endl;
    std::cout << "Choose number of iterations: "<< std::endl;
    std::cin >> max_iter;
    std::cout << "Chosen " << max_iter << " iterations" << std::endl;
    if(method==0){
        for(int i=0;i<max_iter; i++){
        long double sum_leibniz= pow(-1,i)/((2*i)+1);          //Lebniz
        approximated_pi +=sum_leibniz;
        }
        approximated_pi *=4;
    }
    else{
        approximated_pi=1;
        for(int i=1;i<max_iter;i++){
        long double sum_wallis=4*pow(i,2)/(4*pow(i,2)-1);       //wallis
        approximated_pi *=sum_wallis;
        }
        approximated_pi *=2;

    }
    std::cout << "Result: " << approximated_pi << std::endl;
}
