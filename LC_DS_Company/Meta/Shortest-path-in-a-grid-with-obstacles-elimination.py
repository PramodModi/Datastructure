# Problem:
"""
Description:
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

Example 1:
https://assets.leetcode.com/uploads/2021/09/30/short1-grid.jpg

Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation:
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
Example 2:
https://assets.leetcode.com/uploads/2021/09/30/short2-grid.jpg

Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0

"""


from collections import deque
def shortestPath(grid, k):
    n = len(grid)
    m = len(grid[0])
    if n == 1 and m == 1:
        return 0
    q = deque([(0,0, k, 0)]) # row, col, k and setps
    visited = set()
    visited.add((0,0,k))
    while q:
        r,c,k, steps = q.popleft()
        for x,y in [(-1,0), (1,0), (0,-1), (0,1)]:
            row = x + r
            col = y +c
            if row >= 0 and row < n and col >= 0 and col < m:
                if grid[row][col] == 1 and k > 0 and (row, col, k-1) not in visited:
                    q.append((row, col, k-1, steps + 1))
                    visited.add((row, col, k-1))
                elif grid[row][col] == 0 and (row, col, k) not in visited:
                    if row + 1 == n and col + 1 == m:
                        return steps+1
                    q.append((row, col, k, steps+1))
                    visited.add((row, col, k))
    return -1

grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]
k = 1
print(shortestPath(grid, k))

grid = [[0,1,1],[1,1,1],[1,0,0]]
k = 1
print(shortestPath(grid, k))
