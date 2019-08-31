class Solution(object):
    def divisorGame(self, N):
        """
        :type N: int
        :rtype: bool
        """
        # choose x,  0 < x < N and N % x == 0
        # N := N - x
        if N < 1: 
            return False
        
        #dp[N] = !dp[N-x]
        dp = (N+1) * [0]

        dp[0] = False
        dp[1] = False 
        dp[2] = True

        for n in range(3,N+1):
            for x in range(1,n):
                if n % x == 0 and dp[n-x] == False:
                    dp[n] = True
                else:
                    dp[n] = False 
        return dp[N]

def test(N):
    sln = Solution()
    ans = sln.divisorGame(N)
    print(ans)


if __name__ == "__main__":
    test(2)
    test(3)
    test(4)