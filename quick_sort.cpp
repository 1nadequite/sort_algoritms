#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

void quickSort(vector<int>& a, int left, int right) {
  int i = left, j = right;
  int p = a[left + (right - left) / 2];

  while (i <= j) {
    while (a[i] < p)
      i++;
    while (a[j] > p)
      j--;
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }

  if (left < j)
    quickSort(a, left, j);
  if (i < right)
    quickSort(a, i, right);
}

int main() {
  int n = 7;
  vector<int> a = { 5, 3, 7, 3, 9, 6, 1 };

  quickSort(a, 0, n - 1);

  for (auto& x: a)
    cout << x << ' ';
  cout << endl;

  return 0;
}
