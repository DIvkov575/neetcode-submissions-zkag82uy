
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])

        output = []

        for k in range(min(n,m)//2):
            for i in range(n-2*k-1):
                output.append(matrix[k][k+i])
            for i in range(m-2*k-1):
                output.append(matrix[k+i][n-k-1])
            for i in range(n-2*k-1):
                output.append(matrix[m-k-1][n-k-1-i])
            for i in range(m-2*k-1):
                output.append(matrix[m-k-1-i][k])

        if m > n and n%2 == 1:
            for i in range(m - n + 1):
                output.append(matrix[n//2+i][n//2])

        if n > m and m%2 == 1:
            for i in range(n-m + 1):
                output.append(matrix[m//2][m//2+i])

        if n == m and m%2 == 1 and n%2 == 1:
            output.append(matrix[m//2][n//2])







        

        return output
            
        
        