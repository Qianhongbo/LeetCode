```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # edge check [] / [[]]
        if not grid or not grid[0]:
            return 0

        rows, cols = len(grid), len(grid[0])
        visited = set()
        # define four directions
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        LAND, WATER = '1', '0'
        
        def dfs(r, c):
            #base case
            # 1. check out of bound
            if r < 0 or r >= rows or c < 0 or c >= cols:
                return
            # 2. check visited
            # 3. check is LAND
            if (r, c) in visited or grid[r][c] == WATER:
                return
            visited.add((r, c))
            for dr, dc in directions:
                dfs(r + dr, c +dc)

        count = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == LAND and (r, c) not in visited:
                    dfs(r, c)
                    count += 1
        return count
```

