#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>::iterator begin, vector<int>::iterator end) {
  if ((begin + 1) == end)
    return;

  auto mid = begin + (end - begin) / 2;
  merge_sort(begin, mid);
  merge_sort(mid, end);
  auto it2 = mid;
  vector<int> buffer;

  for (auto it1 = begin; it1 != mid; ++it1) {
    for (; it2 != end && *it2 < *it1; ++it2)
      buffer.push_back(*it2);
    buffer.push_back(*it1);
  }
  for (; it2 != end; ++it2)
    buffer.push_back(*it2);
  for (int x : buffer) {
    *begin = x;
    begin++;
  }

}

void merge_sort_index(int begin, int end, vector<int>& a) {
  if ((begin + 1) == end)
    return;

  int mid = begin + (end - begin) / 2;
  merge_sort_index(begin, mid, a);
  merge_sort_index(mid, end, a);
  int it2 = mid;
  vector<int> buffer;

  for (int it1 = begin; it1 != mid; ++it1) {
    for (; it2 != end && a[it2] < a[it1]; ++it2)
      buffer.push_back(a[it2]);
    buffer.push_back(a[it1]);
  }
  for (; it2 != end; ++it2)
    buffer.push_back(a[it2]);
  for (int x : buffer) {
    a[begin]= x;
    begin++;
  }
}

int main() {
  vector<int> a = { 3, 5, 10, 1, 8, 3 };

  //merge_sort(a.begin(), a.end());
  merge_sort_index(0, a.size(), a);

  for (auto x : a)
    cout << x << " ";
  cout << endl;

  return 0;
}
