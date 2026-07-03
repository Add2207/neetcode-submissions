class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pmap = { '}': '{', ']': '[', ')':'('}
        for ch in s:
            if ch in pmap:
                if not stack or stack[-1] != pmap[ch]:
                    return False
                stack.pop()
            else:
                stack.append(ch)
        return len(stack) == 0