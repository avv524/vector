#include <iostream>
#include <vector>

int main(){
    std::vector<int> chisla;
    int n, k;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> k;
        chisla.push_back(k);
    }
    std::cout << "Your vector is:";
    for(int i = 0; i < n; ++i){
        std::cout << " " << chisla[i];
    }
}