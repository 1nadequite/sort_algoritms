#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;

int get_max(const vector<int>& a, int n) {
  int mx = a[0];
  for (int i = 1; i < n; ++i)
    if (a[i] > mx)
      mx = a[i];
  return mx;
}

void count_sort(vector<int>& a, int n, int exp) {
  vector<int> output(n);
  vector<int> count(10);
  // store count of occurrences in count[]
  for (int i = 0; i < n; ++i)
    count[ (a[i] / exp) % 10 ]++;
  for (int i = 1; i < 10; ++i) 
    count[i] += count[i - 1];
  for (int i = n - 1; i >= 0; --i) {
    output[ count[ (a[i] / exp) % 10 ] - 1 ] = a[i];
    count[ (a[i] / exp) % 10 ]--;
  }
  for (int i = 0; i < n; ++i)
    a[i] = output[i];
}

void radix_sort(vector<int>& a, int n) {
  int mx = get_max(a, n);
  for (int exp = 1; mx / exp > 0; exp *= 10)
    count_sort(a, n, exp);
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  radix_sort(a, n);

  for (int i = 0; i < n; ++i)
    cout << a[i] << ' ';
  cout << endl;

  return 0;
}

