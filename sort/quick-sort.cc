#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T, class Comp>
class QuickSort
{
  public:
    void sort(vector<T> &vec) {
      inner_sort(vec, 0, vec.size()-1);
    }

  private:
    void inner_sort(vector<T> &vec, int head, int last);
    Comp comp;
};

template <typename T, class Comp>
void QuickSort<T, Comp>::inner_sort(vector<T> &vec, int head, int last)
{
  int left = head;
  int right = last;
  T mid = vec[(left+right)/2];
  do {
    while (comp(vec[left], mid)) left++;
    while (comp(mid, vec[right])) right--;
    if (left <= right) {
      std::swap(vec[left], vec[right]);
      left++;
      right--;
    }
  }while (left < right);
  if (head < right) inner_sort(vec, head, right);
  if (left < last) inner_sort(vec, left, last);
}

template<typename T>
class Compare
{
  public:
    bool operator ()(const T& l, const T& r) {
      return l < r;
    }
};

int main(int argc, char *argv[])
{
  vector<int> example = {1, 123, 12, 4, 32, 12, 6};
  QuickSort<int, Compare<int>> qs;
  qs.sort(example);
  std::for_each(example.begin(), example.end(), [](int &p) { cout << p << " "; });
  cout << endl;
  return 0;
}
