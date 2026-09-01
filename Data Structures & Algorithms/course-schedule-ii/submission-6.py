class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        indegree = [0] * (numCourses)
        for src, dst in prerequisites:
            adj[src].append(dst)
            indegree[dst] += 1
        q = deque()
        for n in range(numCourses):
            if indegree[n] == 0:
                q.append(n)
        
        finish, output = 0, []
        while q:
            node = q.popleft()
            finish += 1
            output.append(node)
            for nei in adj[node]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    q.append(nei)
        if finish != numCourses:
            return []
        return output[::-1]