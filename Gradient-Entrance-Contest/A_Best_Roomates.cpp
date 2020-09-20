#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++) {
      cout << A[i] << " ";
    }
    cout << "\n";
  }
}