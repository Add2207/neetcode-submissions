class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = {}
        count = []

        for i in nums:
            res[i] = 1 + res.get(i, 0)
        
        for num, freq in res.items():
            count.append([num, freq])
        count.sort()

        arr = []
        while len(arr) < k:
            arr.append(count.pop()[0])
        return arr