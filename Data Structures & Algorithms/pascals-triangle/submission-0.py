class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = [[1]]

        for rown in range(1, numRows):
            buf = [1]

            for i in range(rown-1):
                buf.append(triangle[rown-1][i] + triangle[rown-1][i+1])

            buf.append(1)

            triangle.append(buf)
        
        return triangle


        