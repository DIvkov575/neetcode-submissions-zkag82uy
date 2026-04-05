import copy 
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        output = []


        def perm(buf, options):
            nonlocal output
            if len(options) == 0:
                output.append(copy.deepcopy(buf))
                return

            for i in range(len(options)):
                x = options.pop(i)
                buf.append(x)
                perm(buf, options)

                buf.pop()
                options.insert(i, x)

        
        buf = []
        perm(buf, nums)
        return output




        