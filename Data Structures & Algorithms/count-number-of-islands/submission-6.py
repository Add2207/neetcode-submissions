class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return False
        ROWS, COLS = len(grid), len(grid[0])
        DIRNS = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        islands = 0
        visit = set()

        def bfs(r,c):
            q = deque([(r, c)])
            visit.add((r, c))

            while q:
                row, col = q.popleft()
                for dr, dc in DIRNS:
                    nr, nc = row + dr, col + dc
                    if (0 <= nr < ROWS and 0 <= nc < COLS and grid[nr][nc] == "1" and (nr,nc) not in visit):
                        visit.add((nr, nc))
                        q.append((nr, nc))
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == "1" and (r,c) not in visit:
                    bfs(r,c)
                    islands += 1
        return islands