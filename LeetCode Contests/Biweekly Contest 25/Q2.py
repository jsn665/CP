class Solution:
    def maxDiff(self, num: int) -> int:
        num = str(num)
        copy1 = num
        copy2 = num
        n = len(num)
        x = '9'
        for i in range(n):
            if copy1[i] != '9':
                x = copy1[i]
                break
        copy1 = copy1.replace(x, '9')
        x = '1'
        for i in range(n):
            if copy2[i] != '1' and copy2[i] != '0':
                x = copy2[i]
                break
        copy2 = copy2.replace(x, '0' if str(copy2).index(x) != 0 else '1')
        return int(copy1) - int(copy2)