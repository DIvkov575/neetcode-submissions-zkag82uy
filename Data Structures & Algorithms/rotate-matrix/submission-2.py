


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)

        # def a(k, i):
        #     nonlocal matrix
        #     return matrix[k][i+k]
        # def b(k, i):
        #     nonlocal matrix
        #     return matrix[k+i][n-1-k]
        # def c(k, i):
        #     nonlocal matrix
        #     return matrix[n-1-k][n-1-k - i]
        # def d(k, i):
        #     nonlocal matrix
        #     return matrix[n-1-k - i][k]

        for k in range(n//2):
            for i in range(n-1-2*k):
                a = matrix[k][k+i]
                b = matrix[k+i][n-1-k]
                c = matrix[n-1-k][n-1-k-i]
                d = matrix[n-1-k-i][k]
        
                matrix[k][k+i] = d
                matrix[k+i][n-1-k] = a
                matrix[n-1-k][n-1-k-i] = b
                matrix[n-1-k-i][k] = c
        
        # return matrix
