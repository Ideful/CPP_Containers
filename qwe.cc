// // #include <gtest/gtest.h>
// #include <list>
// #include "list.h"

// int main() {



// class TestList {
//  public:
//   s21::List<int> s21_list_empty;
//   s21::List<int> s21_list_three{1, 2, 3};
//   s21::List<int> s21_lesser{534789,   2479056, 987654, 110101024,
//                             62348710, 1,       35674};
//   s21::List<char> s21_char_list{'L', 'I', 'S', 'T'};
//   s21::List<int> s21_list_ten{1, 2, 3, 5, 9, 10};
//   s21::List<int> s21_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};

//   std::list<int> std_list_empty;
//   std::list<int> std_list_three{1, 2, 3};
//   std::list<int> std_lesser{534789,   2479056, 987654, 110101024,
//                             62348710, 1,       35674};
//   std::list<char> std_char_list{'L', 'I', 'S', 'T'};
//   std::list<int> std_list_ten{1, 2, 3, 5, 9, 10};
//   std::list<int> std_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};
// };


//   TestList tester;
// //   s21::List<int> s21_list_copy(tester.s21_list_three);
// //   std::list<int> std_list_copy(tester.std_list_three);
// //   s21::List<int>::iterator s21_iter = s21_list_copy.Begin();
// //   std::list<int>::iterator std_iter = std_list_copy.begin();

  
// //   while (s21_iter != s21_list_copy.End()) {
// //     std::cout<< *s21_iter << *std_iter;
// //     ++s21_iter;
// //     ++std_iter;
// //   }

//     s21::List<int> a;
//     a.PushBack(2);
//     a.PushBack(3);
//     s21::List<int> b(a);
//     s21::List<int> c(tester.s21_list_three);
//     s21::List<int>d(4);

//     int x = 2;
//     x+=2;


//     // List<std::string> a;
//     // std::string z("qwe");
//     // std::string q("zxc");
//     // a.PushFront(z);
//     // a.PushFront(q);
//     // std::list<int> qwe;
//     // s21::List<int> zxc = {2,4,6,8};

//     // s21::List<int> b;
//     // b.PushBack(3);
//     // b.PushBack(4);

//     // s21::List<int>::const_iterator tst = b.Begin();

    
//     // s21::List<int>::iterator tst2 = b.Begin();
//     // // s21::List<int>::iterator tst2;
//     // // tst2 = b.Begin();
//     // int r = *tst2;
//     // ++tst2;
//     // int r2 = *tst2;
//     // std::cout << r << r2;


// //     s21::List<int> a2{2,3,4,5};
// //     s21::List<int>::ListIterator qwe(a2.Begin());
// //     std::cout<<*qwe;
// //     ++qwe;
// // std::cout<<*qwe;
// //     ++qwe;
// //     std::cout<<*qwe;
// //     ++qwe;
// //     std::cout<<*qwe;
// //     ++qwe;

//     // tst = b.Begin();
//     // std::cout<<*tst;
//     // ++tst;
//     // std::cout<<*tst;
//     // s21::List<int>::const_iterator s21_iter(b.Begin());
//     // s21::List<int>::const_iterator s21_iter2(b.Begin());
//     // s21::List<int>::iterator s21_iter_c(b.Begin());
//     // s21::List<int>::iterator s21_iter_c2(b.Begin());
//     // // ++s21_iter;
//     // // ++s21_iter_c;

//     // std::list<int> a;
//     // a.push_back(3);
//     // a.push_back(4);
//     // std::list<int>::iterator OG(a.begin());
//     // std::list<int>::const_iterator OG_c(a.begin());
//     // std::cout << *OG << *OG_c << std::endl;
//     // ++OG;
//     // ++OG_c;
//     // std::cout << *OG << *OG_c << std::endl;


//     // bool x = s21_iter==s21_iter2;
//     // bool x2 = s21_iter_c==s21_iter_c2;
//     // std::cout << x << '\n' << x2;


//     // std::List<int> zxc = {0,2,4,6};
//     // std::List<int> zxc = {2,4,6,8,9};
//     // std::List<int> qwe = {1,3,5,7};
//     // qwe.swap(zxc);

//     // print(qwe);
//     // List<int> a(4);
//     // List<int> a{11, 22, 13, 434, 5};
//     // std::cout<<"\n\n";
//     // List<int>a = {1,3,5,6,7};
//     // List<int>b = {4,2,0,9};
//     // std::cout <<a.Front();
//     // b.PrintList();
//     // a.Merge(b);
//     // a.PrintList();
//     // List<int>::iterator qwe(a._head->_next);
//     // *qwe = 12321421;
//     // std::cout<<"\n\n\n"<<a._head->_next->_data<<std::endl;

//     // List<int>::const_iterator qwew(a._head->_next);
// }