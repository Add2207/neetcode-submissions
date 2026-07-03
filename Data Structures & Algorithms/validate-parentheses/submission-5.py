class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        maps = {'}' : '{', ']': '[', ')': '('}
        for ch in s:
            if ch in maps:
                if not stack or stack[-1] != maps[ch]:
                    return False
                stack.pop()
            else:
                stack.append(ch)
        return len(stack) == 0