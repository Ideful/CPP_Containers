#include <gtest/gtest.h>
#include <list>
#include "list.h"
// //_______________________________LIST_TESTS________________________________

class TestList {
 public:
  s21::List<int> s21_list_empty;
  s21::List<int> s21_list_three{1, 2, 3};
  s21::List<int> s21_lesser{534789,   2479056, 987654, 110101024,
                            62348710, 1,       35674};
  s21::List<char> s21_char_list{'L', 'I', 'S', 'T'};
  s21::List<int> s21_list_ten{1, 2, 3, 5, 9, 10};
  s21::List<int> s21_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};

  std::list<int> std_list_empty;
  std::list<int> std_list_three{1, 2, 3};
  std::list<int> std_lesser{534789,   2479056, 987654, 110101024,
                            62348710, 1,       35674};
  std::list<char> std_char_list{'L', 'I', 'S', 'T'};
  std::list<int> std_list_ten{1, 2, 3, 5, 9, 10};
  std::list<int> std_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};
};

TEST(List, default_constructor) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.Size(), tester.std_list_empty.size());
  EXPECT_EQ(tester.s21_list_empty.Empty(), tester.std_list_empty.empty());
}

TEST(List, init_constructor) {
  TestList tester;
  s21::List<int> a(3);
  std::list<int> b(3);
  s21::List<int>::iterator s21_it = a.Begin();
  std::list<int>::iterator std_it = b.begin();
  while (s21_it != a.End()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

// TEST(List, initializer_constructor) {
//   TestList tester;
//   s21::List<int>::iterator s21_iter = tester.s21_list_three.Begin();
//   std::list<int>::iterator std_iter = tester.std_list_three.begin();
//   while (s21_iter != tester.s21_list_three.End()) {
//     EXPECT_EQ(*s21_iter, *std_iter);
//     ++s21_iter;
//     ++std_iter;
//   }
//   EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
//   EXPECT_EQ(tester.s21_list_three.Empty(), tester.std_list_three.empty());
// }

// TEST(List, copy_constructor) {
//   TestList tester;
//   s21::List<int> s21_list_copy(tester.s21_list_three);
//   std::list<int> std_list_copy(tester.std_list_three);
//   s21::List<int>::iterator s21_iter = s21_list_copy.Begin();
//   std::list<int>::iterator std_iter = std_list_copy.begin();
//   while (s21_iter != s21_list_copy.End()) {
//     EXPECT_EQ(*s21_iter, *std_iter);
//     ++s21_iter;
//     ++std_iter;
//   }
//   EXPECT_EQ(s21_list_copy.Size(), std_list_copy.size());
//   EXPECT_EQ(s21_list_copy.Empty(), std_list_copy.empty());
// }

// TEST(List, move_constructor) {
//   TestList tester;
//   s21::List<int> s21_list_move(std::move(tester.s21_list_three));
//   std::list<int> std_list_move(std::move(tester.std_list_three));
//   s21::List<int>::iterator s21_iter = s21_list_move.Begin();
//   std::list<int>::iterator std_iter = std_list_move.begin();
//   while (s21_iter != s21_list_move.End()) {
//     EXPECT_EQ(*s21_iter, *std_iter);
//     ++s21_iter;
//     ++std_iter;
//   }
//   EXPECT_EQ(s21_list_move.Size(), std_list_move.size());
//   EXPECT_EQ(s21_list_move.Empty(), std_list_move.empty());
//   s21::List<int> s21_list_three{1,2,3};
//   std::list<int> s21_list_three_{1,2,3};
//   s21_iter = s21_list_three.Begin();
//   std_iter = s21_list_three_.begin();
//   while (s21_iter != s21_list_three.End()) {
//     EXPECT_EQ(*s21_iter, *std_iter);
//     ++s21_iter;
//     ++std_iter;
//   }
//   EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
//   EXPECT_EQ(tester.s21_list_three.Empty(), tester.std_list_three.empty());
// }

// TEST(List, copy_assigment_lesser) {
//   TestList tester;
//   s21::List<int> s21_list_copy{1, 2};
//   std::list<int> std_list_copy{1, 2};
//   s21_list_copy = tester.s21_lesser;
//   std_list_copy = tester.std_lesser;
//   s21::List<int>::iterator s21_iter = s21_list_copy.Begin();
//   std::list<int>::iterator std_iter = std_list_copy.begin();
//   while (s21_iter != s21_list_copy.End()) {
//     EXPECT_EQ(*s21_iter, *std_iter);
//     ++s21_iter;
//     ++std_iter;
//   }
//   EXPECT_EQ(s21_list_copy.Size(), std_list_copy.size());
//   EXPECT_EQ(s21_list_copy.Empty(), std_list_copy.empty());
// }

// TEST(List, move_assigment) {
//   TestList tester;
//   s21::List<int> s21_list_move{1, 2};
//   std::list<int> std_list_move{1, 2};
//   s21_list_move = std::move(tester.s21_lesser);
//   std_list_move = std::move(tester.std_lesser);
//   s21::List<int>::iterator s21_iter = s21_list_move.Begin();
//   std::list<int>::iterator std_iter = std_list_move.begin();
//   while (s21_iter != s21_list_move.End()) {
//     EXPECT_EQ(*s21_iter, *std_iter);
//     ++s21_iter;
//     ++std_iter;
//   }
//   EXPECT_EQ(s21_list_move.Size(), std_list_move.size());
//   EXPECT_EQ(s21_list_move.Empty(), std_list_move.empty());
// }

// TEST(List, function_front) {
//   TestList tester;
//   EXPECT_EQ(tester.s21_char_list.Front(), tester.std_char_list.front());
// }
// TEST(List, function_front_empty) {
//   TestList tester;

//          s21::List<int> one {1,5,9,3};
//   EXPECT_DOUBLE_EQ(tester.s21_list_empty.Front(), tester.std_list_empty.front());
// }

// TEST(List, function_back) {
//   TestList tester;
//   EXPECT_EQ(tester.s21_char_list.Back(), tester.std_char_list.back());
//     s21::List<char> emptylist;
//     s21::List<char>::const_iterator con_it = emptylist.Begin();
//     EXPECT_TRUE(*con_it == 0);
// }
// TEST(List, function_back_empty) {
//   TestList tester;
//   EXPECT_DOUBLE_EQ(tester.s21_list_empty.Back(), tester.std_list_empty.back());
// }

// TEST(List, iterator_access) {
//   TestList tester;
//   s21::List<char>::const_iterator con_it = tester.s21_char_list.Begin();
//   s21::List<char>::iterator s21_iter(con_it);
//   std::list<char>::iterator std_iter = tester.std_char_list.begin();
//   while (s21_iter != tester.s21_char_list.End()) {
//     EXPECT_EQ(*s21_iter, *std_iter);
//     ++s21_iter;
//     ++std_iter;
//   }
// }

// TEST(List, const_iterator_access) {
//   TestList tester;
//   s21::List<char>::const_iterator s21_const_iter = tester.s21_char_list.Begin();
//   std::list<char>::const_iterator std_const_iter = tester.std_char_list.begin();
//   while (s21_const_iter != tester.s21_char_list.End()) {
//     EXPECT_EQ(*s21_const_iter, *std_const_iter);
//     ++s21_const_iter;
//     ++std_const_iter;
//   }
// }

// TEST(List, function_empty) {
//   TestList tester;
//   EXPECT_EQ(tester.s21_list_empty.Empty(), tester.std_list_empty.empty());
//   EXPECT_EQ(tester.s21_list_three.Empty(), tester.std_list_three.empty());
// }

// TEST(List, function_size) {
//   TestList tester;
//   EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
//   EXPECT_EQ(tester.s21_list_empty.Size(), tester.std_list_empty.size());
// }

// TEST(List, function_clear) {
//   TestList tester;
//   tester.s21_list_three.Clear();
//   tester.std_list_three.clear();
//   EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
// }

// TEST(List, function_insert_begin) {
//   TestList tester;
//   s21::List<int>::iterator s21_it = tester.s21_list_empty.Begin();
//   std::list<int>::iterator std_it = tester.std_list_empty.begin();
//   s21_it = tester.s21_list_empty.Insert(s21_it, 666);
//   std_it = tester.std_list_empty.insert(std_it, 666);
//   ASSERT_EQ(*s21_it, *std_it);
//   s21_it = tester.s21_list_empty.Begin();
//   std_it = tester.std_list_empty.begin();
//   while (s21_it != tester.s21_list_empty.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_empty.Size(), tester.std_list_empty.size());
//   EXPECT_EQ(tester.s21_list_empty.Empty(), tester.std_list_empty.empty());
// }

// TEST(List, function_insert_mid) {
//   TestList tester;
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
//   std::list<int>::iterator std_it = tester.std_list_ten.begin();
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   s21_it = tester.s21_list_ten.Insert(s21_it, 666);
//   std_it = tester.std_list_ten.insert(std_it, 666);
//   ASSERT_EQ(*s21_it, *std_it);
//   s21_it = tester.s21_list_ten.Begin();
//   std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     ASSERT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_insert_end) {
//   TestList tester;
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.End();
//   std::list<int>::iterator std_it = tester.std_list_ten.end();
//   s21_it = tester.s21_list_ten.Insert(s21_it, 666);
//   std_it = tester.std_list_ten.insert(std_it, 666);
//   EXPECT_EQ(*s21_it, *std_it);
//   s21_it = tester.s21_list_ten.Begin();
//   std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_insert_multi) {
//   TestList tester;
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
//   std::list<int>::iterator std_it = tester.std_list_ten.begin();
//   s21_it = tester.s21_list_ten.Insert(s21_it, 666);
//   std_it = tester.std_list_ten.insert(std_it, 666);
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   s21_it = tester.s21_list_ten.Insert(s21_it, 666);
//   std_it = tester.std_list_ten.insert(std_it, 666);
//   EXPECT_EQ(*s21_it, *std_it);
//   s21_it = tester.s21_list_ten.Begin();
//   std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     ASSERT_DOUBLE_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function__begin) {
//   TestList tester;
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
//   std::list<int>::iterator std_it = tester.std_list_ten.begin();
//   tester.s21_list_ten.Erase(s21_it);
//   tester.std_list_ten.erase(std_it);
//   s21_it = tester.s21_list_ten.Begin();
//   std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_erase_mid) {
//   TestList tester;
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
//   std::list<int>::iterator std_it = tester.std_list_ten.begin();
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   tester.s21_list_ten.Erase(s21_it);
//   tester.std_list_ten.erase(std_it);
//   s21_it = tester.s21_list_ten.Begin();
//   std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_erase_end) {
//   TestList tester;
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.End();
//    std::list<int>::iterator std_it = tester.std_list_ten.end();
//   --s21_it;
//   --std_it;
//   tester.s21_list_ten.Erase(s21_it);
//   tester.std_list_ten.erase(std_it);
//   s21_it = tester.s21_list_ten.Begin();
//   std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_erase_multi) {
//   TestList tester;
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
//   std::list<int>::iterator std_it = tester.std_list_ten.begin();
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   tester.s21_list_ten.Erase(s21_it);
//   tester.std_list_ten.erase(std_it);
//   s21_it = tester.s21_list_ten.Begin();
//   std_it = tester.std_list_ten.begin();
//   tester.s21_list_ten.Erase(s21_it);
//   tester.std_list_ten.erase(std_it);
//   s21_it = tester.s21_list_ten.Begin();
//   std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }
// TEST(List, function_push_back) {
//   TestList tester;
//   tester.s21_list_three.PushBack(666);
//   tester.std_list_three.push_back(666);
//   tester.s21_list_three.PushBack(123);
//   tester.std_list_three.push_back(123);
//   s21::List<int>::iterator s21_it = tester.s21_list_three.Begin();
//   std::list<int>::iterator std_it = tester.std_list_three.begin();
//   while (s21_it != tester.s21_list_three.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
//   EXPECT_EQ(tester.s21_list_three.Empty(), tester.std_list_three.empty());
// }

// TEST(List, function_pop_back) {
//   TestList tester;
//   tester.s21_list_ten.PopBack();
//   tester.std_list_ten.pop_back();
//   tester.s21_list_ten.PopBack();
//   tester.std_list_ten.pop_back();
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
//   std::list<int>::iterator std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_push_front) {
//   TestList tester;
//   tester.s21_list_ten.PushFront(666);
//   tester.std_list_ten.push_front(666);
//   tester.s21_list_ten.PushFront(123);
//   tester.std_list_ten.push_front(123);
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
//   std::list<int>::iterator std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_pop_front) {
//   TestList tester;
//   tester.s21_list_ten.PopFront();
//   tester.std_list_ten.pop_front();
//   tester.s21_list_ten.PopFront();
//   tester.std_list_ten.pop_front();
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
//   std::list<int>::iterator std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_swap) {
//   TestList tester;
//   s21::List<int> s21_list_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   std::list<int> std_list_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   tester.s21_lesser.Swap(s21_list_swap);
//   tester.std_lesser.swap(std_list_swap);
//   s21::List<int>::iterator s21_it = s21_list_swap.Begin();
//   std::list<int>::iterator std_it = std_list_swap.begin();
//   while (s21_it != s21_list_swap.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(s21_list_swap.Size(), std_list_swap.size());
//   EXPECT_EQ(s21_list_swap.Empty(), std_list_swap.empty());
//   s21_it = tester.s21_lesser.Begin();
//   std_it = tester.std_lesser.begin();
//   while (s21_it != tester.s21_lesser.End()) {
//     ASSERT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_lesser.Size(), tester.std_lesser.size());
//   EXPECT_EQ(tester.s21_lesser.Empty(), tester.std_lesser.empty());
// }
// TEST(List, function_merge_nonsorted) {
//   TestList tester;
//   s21::List<int> s21_list_merge{77, 125890, 430235, -236, 32858, 7457};
//   std::list<int> std_list_merge{77, 125890, 430235, -236, 32858, 7457};
//   tester.s21_lesser.Merge(s21_list_merge);
//   tester.std_lesser.merge(std_list_merge);
//   s21::List<int>::iterator s21_it = s21_list_merge.Begin();
//   std::list<int>::iterator std_it = std_list_merge.begin();
//   while (s21_it != s21_list_merge.End()) {

//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(s21_list_merge.Size(), std_list_merge.size());
//   EXPECT_EQ(s21_list_merge.Empty(), std_list_merge.empty());
//   s21_it = tester.s21_lesser.Begin();
//   std_it = tester.std_lesser.begin();
//   while (s21_it != tester.s21_lesser.End()) {
//   EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_lesser.Size(), tester.std_lesser.size());
//   EXPECT_EQ(tester.s21_lesser.Empty(), tester.std_lesser.empty());
// }

// TEST(List, function_merge_sorted) {
//   TestList tester;
//   s21::List<int> s21_list_merge{77, 125890, 430235, -236, 32858, 7457};
//   std::list<int> std_list_merge{77, 125890, 430235, -236, 32858, 7457};
//   tester.s21_lesser.Sort();
//   tester.std_lesser.sort();
//   tester.s21_lesser.Merge(s21_list_merge);
//   tester.std_lesser.merge(std_list_merge);
//   s21::List<int>::iterator s21_it = s21_list_merge.Begin();
//   std::list<int>::iterator std_it = std_list_merge.begin();
//   while (s21_it != s21_list_merge.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(s21_list_merge.Size(), std_list_merge.size());
//   EXPECT_EQ(s21_list_merge.Empty(), std_list_merge.empty());
//   s21_it = tester.s21_lesser.Begin();
//   std_it = tester.std_lesser.begin();
//   while (s21_it != tester.s21_lesser.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_lesser.Size(), tester.std_lesser.size());
//   EXPECT_EQ(tester.s21_lesser.Empty(), tester.std_lesser.empty());
// }

// TEST(List, function_splice) {
//   TestList tester;
//   s21::List<int> s21_list_splice{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   std::list<int> std_list_splice{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   s21::List<int>::iterator s21_it = tester.s21_lesser.Begin();
//   std::list<int>::iterator std_it = tester.std_lesser.begin();
//   ++s21_it;
//   ++std_it;
//   tester.s21_lesser.Splice(s21_it, s21_list_splice);
//   tester.std_lesser.splice(std_it, std_list_splice);
//   s21_it = s21_list_splice.Begin();
//   std_it = std_list_splice.begin();
//   while (s21_it != s21_list_splice.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(s21_list_splice.Size(), std_list_splice.size());
//   EXPECT_EQ(s21_list_splice.Empty(), std_list_splice.empty());
//   s21_it = tester.s21_lesser.Begin();
//   std_it = tester.std_lesser.begin();
//   while (s21_it != tester.s21_lesser.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_lesser.Size(), tester.std_lesser.size());
//   EXPECT_EQ(tester.s21_lesser.Empty(), tester.std_lesser.empty());
// }

// TEST(List, function_reverse) {
//   TestList tester;
//   tester.s21_list_ten.Reverse();
//   tester.std_list_ten.reverse();
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
//   std::list<int>::iterator std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_unique) {
//   TestList tester;
//   tester.s21_list_unique.Unique();
//   tester.std_list_unique.unique();
//   s21::List<int>::iterator s21_it = tester.s21_list_unique.Begin();
//   std::list<int>::iterator std_it = tester.std_list_unique.begin();
//   while (s21_it != tester.s21_list_unique.End()) {
//     ASSERT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_unique.Size(), tester.std_list_unique.size());
//   EXPECT_EQ(tester.s21_list_unique.Empty(), tester.std_list_unique.empty());
// }

// TEST(List, function_sort) {
//   TestList tester;
//   tester.s21_lesser.Sort();
//   tester.std_lesser.sort();
//   s21::List<int>::iterator s21_it = tester.s21_lesser.Begin();
//   std::list<int>::iterator std_it = tester.std_lesser.begin();
//   while (s21_it != tester.s21_lesser.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_lesser.Size(), tester.std_lesser.size());
//   EXPECT_EQ(tester.s21_lesser.Empty(), tester.std_lesser.empty());
// }

// TEST(List, function_emplace_begin) {
//   TestList tester;
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
//   std::list<int>::iterator std_it = tester.std_list_ten.begin();
//   s21_it = tester.s21_list_ten.Emplace(s21_it, 666);
//   std_it = tester.std_list_ten.emplace(std_it, 666);
//   ASSERT_EQ(*s21_it, *std_it);
//   s21_it = tester.s21_list_ten.Begin();
//   std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_emplace_mid) {
//   TestList tester;
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
//   std::list<int>::iterator std_it = tester.std_list_ten.begin();
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   s21_it = tester.s21_list_ten.Emplace(s21_it, 666);
//   std_it = tester.std_list_ten.emplace(std_it, 666);
//   ASSERT_EQ(*s21_it, *std_it);
//   s21_it = tester.s21_list_ten.Begin();
//   std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_emplace_end) {
//   TestList tester;
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.End();
//   std::list<int>::iterator std_it = tester.std_list_ten.end();
//   s21_it = tester.s21_list_ten.Emplace(s21_it, 666);
//   std_it = tester.std_list_ten.emplace(std_it, 666);
//   EXPECT_EQ(*s21_it, *std_it);
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_emplace_multi) {
//   TestList tester;
//   s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
//   std::list<int>::iterator std_it = tester.std_list_ten.begin();
//   s21_it = tester.s21_list_ten.Emplace(s21_it, 666);
//   std_it = tester.std_list_ten.emplace(std_it, 666);
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   s21_it = tester.s21_list_ten.Emplace(s21_it, 666);
//   std_it = tester.std_list_ten.emplace(std_it, 666);
//   ASSERT_EQ(*s21_it, *std_it);
//   s21_it = tester.s21_list_ten.Begin();
//   std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_emplace_back) {
//   TestList tester;
//   tester.s21_list_three.EmplaceBack(666);
//   tester.std_list_three.emplace_back(666);
//   tester.s21_list_three.EmplaceBack(123);
//   tester.std_list_three.emplace_back(123);
//   s21::List<int>::iterator s21_it = tester.s21_list_three.Begin();
//   std::list<int>::iterator std_it = tester.std_list_three.begin();
//   while (s21_it != tester.s21_list_three.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
//   EXPECT_EQ(tester.s21_list_three.Empty(), tester.std_list_three.empty());
// }

// TEST(List, function_emplace_front) {
//   TestList tester;
//   tester.s21_list_three.EmplaceFront(666);
//   tester.std_list_three.emplace_front(666);
//   tester.s21_list_three.EmplaceFront(123);
//   tester.std_list_three.emplace_front(123);
//   s21::List<int>::iterator s21_it = tester.s21_list_three.Begin();
//   std::list<int>::iterator std_it = tester.std_list_three.begin();
//   while (s21_it != tester.s21_list_three.End()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
//   EXPECT_EQ(tester.s21_list_three.Empty(), tester.std_list_three.empty());
// }




// TEST(initializer_lists, TEST_1){
//  s21::List<int>A = {};
//  std::list<int>B = {};

//   size_t a = A.Size();
//   size_t b = B.size();
//   ASSERT_EQ(a, b);

// }

// TEST(initializer_lists, TEST_2){
//  s21::List<int>A = {1,2,3,4,5,6,7,8,9,10,456545,987,5423,3454,3673};
//  std::list<int>B = {1,2,3,4,5,6,7,8,9,10,456545,987,5423,3454,3673};

//   size_t a = A.Size();
//   size_t b = B.size();
//   ASSERT_EQ(a, b);

//   s21::List<int>::ListIterator iterA = A.Begin();
//   std::list<int>::iterator iterB =  B.begin();
//     ASSERT_EQ(*iterA, *iterB);

//   iterA = A.End();
//   iterB = B.end();
//   --iterA;
//   --iterB;
 
//   ASSERT_EQ(*iterA, *iterB);
// }

// TEST(initializer_lists, TEST_3){
//  s21::List<double>A{77.987654};
//  std::list<double>B{77.987654};

//   size_t a = A.Size();
//   size_t b = B.size();
//   ASSERT_EQ(a, b);
//   s21::List<double>::ListIterator iterA = A.Begin();
//   std::list<double>::iterator iterB =  B.begin();
//   ASSERT_EQ(*iterA, *iterB);
// }


// TEST(parameterized_constructor, TEST_4){
//  s21::List<double>A(50);
//  std::list<double>B(50);

//   size_t a = A.Size();
//   size_t b = B.size();
//   ASSERT_EQ(a, b);
//   s21::List<double>::ListIterator iterA = A.Begin();
//   std::list<double>::iterator iterB =  B.begin();

//   ASSERT_EQ(*iterA, *iterB);
//   iterA = A.End();
//   iterB = B.end();
//   --iterA;
//   --iterB;
//   ASSERT_EQ(*iterA, *iterB);
// }

// TEST(parameterized_constructor, TEST_5){
//  s21::List<double>A(50);
//  s21::List<double>::ListIterator iterA;
//   double y = 0.5;
//   for (iterA = A.Begin(); iterA != A.End(); ++iterA) {
//     *iterA = 1648.090 + y;
//   }
//   std::list<double> B(50);
//   std::list<double>::iterator iterB;
//   for (iterB = B.begin(); iterB != B.end(); ++iterB) {
//     *iterB = 1648.090 + y;
//   }
//   size_t a = A.Size();
//   size_t b = B.size();
//   EXPECT_EQ(a, b);

//   iterA = A.Begin();
//   iterB = B.begin();
//   EXPECT_DOUBLE_EQ(*iterA, *iterB);

//   iterA = A.End();
//   iterB = B.end();
//   --iterA;
//   --iterB;
//   EXPECT_DOUBLE_EQ(*iterA, *iterB);
// }

// TEST(parameterized_constructor_throw, TEST_1){
// s21::List<double>A(-777);
// EXPECT_EQ(A.Size(), 0);

// }

// TEST(parameterized_constructor_throw, TEST_2){
// s21::List<double>A(0);
//  EXPECT_EQ(A.Size(), 0);
// }



// TEST(copy_constructor, TEST_1){
// s21::List<double>A = {1.0006,21,3,4,51,6,7,8,9,10,765765467.646,6,7,7,53,2,2,45,6,32,1};
//  s21:: List<double>B(A);
//   s21:: List<double>::ListIterator iterA = A.Begin();
//   s21::  List<double>::ListIterator iterB = B.Begin();
//    EXPECT_DOUBLE_EQ(*iterA, *iterB);

//   iterA = A.End();
//   iterB = B.End();

//   EXPECT_DOUBLE_EQ(*iterA, *iterB);

//   size_t a = A.Size();
//   size_t b = B.Size();
//   EXPECT_EQ(a, b);
// }

// TEST(move_constructor, TEST_1){
//   s21:: List<int>A = {1,4,6,4,8};
//   s21:: List<int>B(std::move(A));

//   EXPECT_EQ(A.Size(), 0);

//   EXPECT_EQ(B.Size(), 5);

//   s21:: List<int>::ListIterator iterA = B.Begin();
//    EXPECT_EQ(*iterA, 1);
//    iterA = B.End();
//    --iterA;
//    EXPECT_EQ(*iterA, 8);

//   iterA = A.Begin();
//   EXPECT_EQ(iterA, nullptr);
//   iterA = A.End();
//   EXPECT_EQ(iterA, nullptr);
// }

// TEST(move_operator, TEST_1){
//    s21::List<int>A = {1,4,6,4,8};
//    s21::List<int>B(std::move(A));

//    EXPECT_EQ(A.Size(), 0);

//    EXPECT_EQ(B.Size(), 5);

//    s21::List<int>::ListIterator iterB = B.Begin();
//    EXPECT_EQ(*iterB, 1);
//     iterB = B.End();
//     --iterB;
//     EXPECT_EQ(*iterB, 8);
// }

// TEST(insert_throwTest, TEST_1){
//  s21::  List<int>A{7,7,7};
//  s21::  List<int>B{0,0,0,0};
//  s21::  List<int>::ListIterator it = B.Begin();
//    ++it;
//    EXPECT_ANY_THROW(A.Insert(it,0));
// }




// TEST(insert_test, TEST_1){
//    s21::List<int>A{0,0,0,0,0,0,0};
//   s21:: List<int>::ListIterator it = A.Begin();
//    A.Insert(it,-999);
//    it = A.Begin();

//    std::list<int>orig{0,0,0,0,0,0,0};
//    std::list<int>::iterator it_orig = orig.begin();
//     orig.insert(it_orig,-999);
//     orig.begin();
//     for(it_orig = orig.begin(); it_orig != orig.end(); ++it_orig){
//     EXPECT_EQ(*it,*it_orig);
//     ++it;
//     }
// }


// TEST(insert_test, TEST_2){
//   s21:: List<int>B{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
//    s21::List<int>::ListIterator iter = B.End();

//    iter = B.Insert(iter,0);
 
//     for(s21::List<int>::ListIterator iterat  = B.Begin(); iterat != B.End(); ++iterat){
//       if(iter == iterat){
//      EXPECT_EQ(*iter,0);
//       } else {
//         EXPECT_EQ(*iterat,1);
//       }

//    }
// }

// TEST(insert_test, TEST_3){
//  s21::  List<int>A{0,0,0,0,0,0,0};
//   s21:: List<int>::ListIterator it = A.Begin();
//    A.Insert(it,-999);
//    A.Insert(it,-999);
//    A.Insert(it,-999);
//    A.Insert(it,-999);

//    ++it;
//    ++it;
//    A.Insert(it,-999);
//    it = A.Begin();

//    std::list<int>orig{0,0,0,0,0,0,0};
//    std::list<int>::iterator it_orig = orig.begin();
//     orig.insert(it_orig,-999);
//     orig.insert(it_orig,-999);
//     orig.insert(it_orig,-999);
//     orig.insert(it_orig,-999);
//     ++it_orig;
//     ++it_orig;
//     orig.insert(it_orig,-999);
      
//     for(it_orig = orig.begin(); it_orig != orig.end(); ++it_orig){
//     EXPECT_EQ(*it,*it_orig);
//     ++it;
//     }
// }

// TEST(empty, TEST_1){
//  s21::  List<int>A;
//    std::list<int>orig;
//     bool A_ = A.Empty();
//     bool B = orig.empty();
//     EXPECT_EQ(B,A_);
// }

// TEST(empty, TEST_2){
//   s21:: List<int>A(30);
//    std::list<int>orig(30);
//     bool A_ = A.Empty();
//     bool B = orig.empty();
//     EXPECT_EQ(B,A_);
// }

// TEST(empty, TEST_3){
//   s21:: List<int>A{1,1,1,1};
//    std::list<int>orig{1,1,1,1};
//     bool A_ = A.Empty();
//     bool B = orig.empty();
//     EXPECT_EQ(B,A_);
// }

// TEST(empty, TEST_4){
//   s21:: List<int>A{1,1,1,1};
//    A.Clear();
//    std::list<int>orig{1,1,1,1};
//    orig.clear();
//     bool A_ = A.Empty();
//     bool B = orig.empty();
//     EXPECT_EQ(B,A_);
// }



// TEST(const_reference_front_back, TEST_1){
  
//   std::list<int> A;
//   int ans =  A.front();
//  s21:: List<int>B;
//   int ans_mine =  B.Front();
//   EXPECT_EQ(ans,ans_mine);

//   ans =  A.back();
//   ans_mine =  B.Back();
//   EXPECT_EQ(ans,ans_mine);
// }


// TEST(const_reference_front_back, TEST_2){
  
//   std::list<int> A{1,2,3,4,5,6,7,8,9,0,10};
//   int ans =  A.front();
//   s21::List<int>B{1,2,3,4,5,6,7,8,9,0,10};
//   int ans_mine =  B.Front();
//   EXPECT_EQ(ans,ans_mine);

//   ans =  A.back();
//   ans_mine =  B.Back();
//   EXPECT_EQ(ans,ans_mine);
// }

// TEST(const_reference_front_back, TEST_3){
//   std::list<int> A(20);
//   int ans =  A.front();
//   s21::List<int>B(20);
//   int ans_mine =  B.Front();
//   EXPECT_EQ(ans,ans_mine);

//   ans =  A.back();
//   ans_mine =  B.Back();
//   EXPECT_EQ(ans,ans_mine);
// }

// TEST(const_reference_front_back, TEST_4){
//   std::list<int> A(20);
//   A.clear();
//   int ans =  A.front();
//   s21::List<int>B(20);
//   B.Clear();  
//   int ans_mine =  B.Front();
//   EXPECT_EQ(ans,ans_mine);

//   ans =  A.back();
//   ans_mine =  B.Back();
//   EXPECT_EQ(ans,ans_mine);
// }

// TEST(size_test, TEST_1){
//   std::list<int> A(20);
//   s21::List<int>B(20);
//   size_t mine = B.Size();
//   size_t orig = A.size();
//  EXPECT_EQ(mine,orig);
// }

// TEST(size_test, TEST_2){
//   std::list<int> A(20);
//   s21::List<int>B(20);
//   B.Clear();
//   A.clear();
//   size_t mine = B.Size();
//   size_t orig = A.size();
//  EXPECT_EQ(mine,orig);
// }

// TEST(size_test, TEST_3){
//   std::list<int> A{1,2,3,4,5,5,32,2,4,1,1,1,3};
//   s21::List<int>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
//   size_t mine = B.Size();
//   size_t orig = A.size();
//  EXPECT_EQ(mine,orig);
// }

// TEST(MaxSize_test, TEST_1){
//   s21::List<int>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
//   size_t mine = B.MaxSize();
//  EXPECT_EQ(mine,576460752303423487);
// }

// TEST(MaxSize_test, TEST_2){
//   s21::List<double>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
//   size_t mine = B.MaxSize();
//  EXPECT_EQ(mine,576460752303423487);
// }

// TEST(MaxSize_test, TEST_3){

//   s21::List<char>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
//   size_t mine = B.MaxSize();
//  EXPECT_EQ(mine,576460752303423487);
// }

// TEST(MaxSize_test, TEST_4){
//   s21::List<char>B;
//   size_t mine = B.MaxSize();

//  EXPECT_EQ(mine,576460752303423487);
// }


// TEST(PushBack_front_test, TEST_4){
//   std::list<char> A;
//   A.push_back('I');
//   A.push_front('G');
//   A.push_back('\'');
//    A.push_front('G');
//    A.push_back('m');
//      A.push_back(' ');
//       A.push_front('s');
//      A.push_back('D');
//       A.push_front('!');
//        A.push_front('!');
//   s21::List<char>B;
//     B.PushBack('I');
//       B.PushFront('G');
//     B.PushBack('\'');
//       B.PushFront('G');
//     B.PushBack('m');
//     B.PushBack(' ');
//       B.PushFront('s');
//     B.PushBack('D');
//      B.PushFront('!');
//       B.PushFront('!');

//   size_t mine = B.Size();
//   size_t orig = A.size();
//   EXPECT_EQ(mine,orig);
//  std::list<char>::iterator it = A.begin();
//  s21::List<char>::ListIterator it_mine = B.Begin();
//   for(; it != A.end();++it){
//      EXPECT_EQ(*it,*it_mine);
//      ++it_mine;
//   }
// }


// TEST(erase, TEST_1){
//   std::list<int> A{1,2,3,4,5,5,32,2,4,1,1,1,3};
//   s21::List<int>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
//   std::list<int>::iterator it = A.begin();
//   s21::List<int>::ListIterator it_mine = B.Begin();
//     A.erase(it);
//     B.Erase(it_mine);
//     it = A.begin();
//     it_mine = B.Begin();
//      for(; it != A.end();++it){
//      EXPECT_EQ(*it,*it_mine);
//      ++it_mine;
//   }
//     size_t mine = B.Size();
//   size_t orig = A.size();
//   EXPECT_EQ(mine,orig);
// }

// TEST(erase, TEST_2){

//   s21::List<int>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
//   s21::List<int>::ListIterator it_mine = B.End();
//   EXPECT_ANY_THROW(B.Erase(it_mine));

// }

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
