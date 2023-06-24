#include <list>
#include <iostream>

int main() {
    std::list<int> std_list_ten{1, 2, 3, 5, 9, 10};
  std::list<int>::iterator std_it = std_list_ten.begin();

  ++std_it;
  ++std_it;
  ++std_it;
    std_list_ten.insert(std_it,666);
    std_it = std_list_ten.begin();
    for(int i = 0; i < 6;i++) {
        std::cout<<*std_it<<std::endl;
        std_it++;
    }
}