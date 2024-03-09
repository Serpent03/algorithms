#include <stdio.h>
#include <stdlib.h>

void _memset(int *arr, int _val, int _size) {
  while (_size-- > 0) {
    arr[_size] = _val;
  } 
}

int helper(int n, int *cache) {
  if (n == 1 || n == 2) {
    return 1;
  }
  if (cache[n - 1] != -1) {
    return cache[n - 1];
  }
  return cache[n - 1] = helper(n - 1, cache) + helper(n - 2, cache);
}

int main() {
  /**
   * @brief Calculate the nth fibonacci number.
   * @problem Do it within time and memory limits through memoization.
   */
  int n = 80000;
  int *cache = (int*)malloc(n * sizeof(int));
  _memset(cache, -1, n);
  helper(n, cache);

  for (int i = 0; i < n; i++) {
    printf("%u ", cache[i]);
  }
  printf("\n");
}
