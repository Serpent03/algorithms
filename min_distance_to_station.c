#include <assert.h>
#include <limits.h>

#define MIN(a, b) ((a > b) ? b : a)

int helper(int station_costs[4][4], int i, int destination) {
  if (i >= destination) return INT_MAX;
  int cost = station_costs[i][destination];
  for (int j = i + 1; j < destination; j++) {
    int current_cost = station_costs[i][j];
    cost = MIN(cost, helper(station_costs, j, destination) + current_cost);
  }
  return cost;
}

int main() {
  /**
   * @brief From station n to station n-1. 
   * We only move forward, and start at station i, which is why staion[i][i] is a 0.
   * @problem Find out the minimum cost from station 0 to station n-1.
   */
  int station_costs[4][4] = {
    {0, 10, 75, 94},
    {-1, 0, 35, 50},
    {-1, -1, 0, 80},
    {-1, -1, -1, 0}
  };
  assert(helper(station_costs, 0, 2) == 45); /* 10 + 35 */
  assert(helper(station_costs, 0, 3) == 60); /* 10 + 50 */
}
