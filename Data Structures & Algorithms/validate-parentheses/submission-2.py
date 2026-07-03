class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        bmap = { '}': '{', ']': '[', ')': '('}

        for ch in s:
            if ch in bmap:
                if not stack or stack[-1] != bmap[ch]:
                    return False
                stack.pop()
            else:
                stack.append(ch)
        return len(stack) == 0
