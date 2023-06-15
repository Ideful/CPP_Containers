#include <list>
#include <iostream>
#include "../list.h"
int main() {
    std::list<std::string> a;
    // std::cout << a.begin();

    s21::List<int> b;
    b.PushBack(2);
    b.PushBack(3);
    b.PushBack(4);
    // b.PushBack(5);
    // b.PushBack(6);
    // s21::List<int>::const_iterator qwe(b.Begin());
    // s21::List<int>::iterator qwe(b.Begin());
    // while (qwe != b.End()){
    //     std::cout << *qwe;
    //     ++qwe;
    // }
    // std::list<int>::const_iterator qwe(b.end());
    // std::cout<<*qwe;
    // std::cout << 2;
    // std::list<int> aqw = {1,2,3,5,9,10};
    // std::list<int>::iterator iter=aqw.begin();
    // ++iter;
    // ++iter;
    // ++iter;
    // iter = aqw.insert(iter,222);
    // std::list<int> lesser{534789,   2479056, 987654, 110101024,62348710, 1, 35674};
    // std::list<int> std_list_splice{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // std::list<int>::iterator std_it = lesser.begin();
    // std_it++;
    // lesser.splice(std_it, std_list_splice);
    // std_it = std_list_splice.begin();
    // while( std_it != std_list_splice.end()) {
    //     std::cout<< *std_it<<std::endl;
    //         std_it++;

    // }
    // std::cout<<'\n';
    // std_it = lesser.begin();
    // while( std_it != lesser.end()) {
    //     std::cout<< *std_it<<std::endl;
    //         std_it++;

    // }
    // std::cout<<std::endl;
    // std::cout<<std::endl;
    // std::cout<<std::endl;
    s21::List<int> lezzer{534789,   2479056, 987654, 110101024,62348710, 1, 35674};
    // s21::List<int> splicer{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // s21::List<int>::const_iterator iterrr(lezzer.Begin());
    // ++iterrr;
    // lezzer.Splice(iterrr,splicer);

    // iterrr = lezzer.Begin();
    //     while( iterrr != lezzer.End()) {
    //     std::cout<< *iterrr<<std::endl;
    //         ++iterrr;

    // }
    // s21::List<int> std_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};
    // s21::List<int>::iterator qwe(std_list_unique.Begin());
    // std_list_unique.Unique();
    // while(qwe != std_list_unique.End()) {
    //     std::cout << *qwe << std::endl;
    //     ++qwe;
    // }

    s21::List<int>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
    s21::List<int>::ListIterator it_mine = B.End();
    // B.Erase(it_mine);
    // it_mine = B.Begin();
    // while(it_mine != B.End()) {
    //     std::cout << *it_mine<<std::endl;
    //     ++it_mine;
    // }

    std::list<int>QWE{1,2,3,4,5,5,32,2,4,1,1,1,3};
    std::list<int>::iterator zzz = QWE.end();
    std::cout<<*zzz<<')';
    // QWE.erase(zzz);
    zzz = QWE.begin();
    // while(zzz != QWE.end()) {
    //     std::cout << *zzz<<std::endl;
    //     ++zzz;
    // }
}

// {1, 2, 3, 5, 9, 10};
// 1, 2, 3, 666, 5, 9, 10