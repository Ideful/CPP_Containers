#include <list>
#include <iostream>
#include "list.h"

int main(){
    std::list<int> a{1,2,3,90};
    std::list<int>::iterator qwe(a.end());
    a.insert(qwe,278);
    std::cout<<*qwe;
    // qwe = a.begin();
    // while (qwe != a.end()) {
    //     std::cout<<*qwe<<std::endl;
    //     ++qwe;
    // }
    std::cout<<std::endl;
    std::cout<<std::endl;


    s21::List<int> aq{1,2,3,90};
    s21::List<int>::iterator qqwe(aq.End());
    aq.Insert(qqwe,278);
    --qqwe;
    std::cout<<*qqwe;
    // qqwe = aq.Begin();
    // while (qqwe != aq.End()) {
    //     std::cout<<*qqwe<<std::endl;
    //     ++qqwe;
    // }

}