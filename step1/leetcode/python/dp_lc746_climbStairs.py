
class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        # idea:
        # 子问题划分 & 状态确定
        # 到达第i阶梯有两种走法，一种是从第i-1走一步。一种是从第i-2走一步。
        # 到达第I阶梯的最小代价f[i]
        # 1. 等价为从0到第i-1阶梯的最小代价 + 第i阶梯代价
        # 2. 或等价为从0到第i-2阶梯的最小代价 + 第i阶梯代价

        # 边界条件
        # 1.f[0] = cost[0]
        # 2.f[1] = cost[1]

        # 状态转移方程
        # 1. f[n] = min(f[n-1], f[n-2]) + cost[n]
        cost.append(0)

        f = len(cost)*[0]
        for i in range(0,len(cost)):
            if i == 0 or i == 1:
                f[i] = cost[i]
            else:
                f[i] = min(f[i-2],f[i-1]) + cost[i]

        return f[len(cost)-1]
