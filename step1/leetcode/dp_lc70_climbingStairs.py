class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # idea
        # f[n] = f[n-1] + f[n-2]
        # border condition:
        # f[0] = 1

        f = n*[0]
        for i in range(0,n):
            if i == 0:
                f[0] = 1
            elif i == 1:
                f[1] = 2
            else:
                f[i] = f[i-1] + f[i-2]

        return f[n-1]