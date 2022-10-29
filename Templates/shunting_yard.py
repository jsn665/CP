def shunting_yard(s):
    n = len(s)
    res = []
    st = []
    i = 0
    check_unary = True
    priority = {'-': 1, '+': 1, '/': 2, '*': 2, '^': 3}
    while i < n:
        if s[i] == ' ':
            i += 1
            continue

        if check_unary:
            check_unary = False
            if s[i] == '-':
                res.append('0')

        if s[i].isdigit():
            dig = 0
            while i < n and s[i].isdigit():
                dig = dig * 10 + int(s[i])
                i += 1
            res.append(str(dig))

        else:
            if s[i] == '(':
                check_unary = True
                st.append(s[i])
            elif s[i] == ')':
                while st and st[i] != '(':
                    res.append(st.pop())
                st.pop()
            else:
                while st and st[-1] != '(' and priority[st[-1]] >= priority[s[i]]:
                    res.append(st.pop())
                st.append(s[i])
            i += 1
    while st:
        res.append(st.pop())

    return ''.join(res)
