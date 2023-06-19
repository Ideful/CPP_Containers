#include "queue.h"

int main() {
    s21::Queue<int> z;
    z.Push(1);
    z.Push(2);
    z.Push(3);
    z.Push(4);
    z.Pop();

    s21::Queue<int> a{1,2,3,4};
}