#include <ctime>
#include <cstdio>

// Naive
// f(x) = A・x
void f(float A[1000][1000], float x[1000], float y[1000]) {
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < 1000; ++j) {
      y[i] += A[i][j] * x[j];
    }
  }
}

int main() {
  float A[1000][1000];
  float x[100][1000], y[100][1000];
  // 初期化
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < 1000; ++j) {
      A[i][j] = float(i + j);
    }
  }
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 1000; ++j) {
      x[i][j] = float(i - j);
      y[i][j] = 0;
    }
  }
  clock_t start = clock();
  for (int i = 0; i < 100; ++i) { // DO N=100 times and measure time
    f(A, x[i], y[i]);
  }
  clock_t end = clock();
  const double time =
      static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
  printf("time %lf[ms]\n", time);
  return 0;
}
