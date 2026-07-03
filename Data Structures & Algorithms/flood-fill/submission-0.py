class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if not image:
            return image
        ROWS = len(image)
        COLS = len(image[0])
        DIRNS = [[1, 0], [-1, 0], [0, -1], [0, 1]]

        original = image[sr][sc]

        if original == color:
            return image
        
        def dfs(r, c):
            if (r < 0 or r >= ROWS or c < 0 or c >= COLS or image[r][c] != original):
                return
            image[r][c] = color
            for dr, dc in DIRNS:
                dfs(r + dr, c + dc)
        dfs(sr, sc)
        return image
