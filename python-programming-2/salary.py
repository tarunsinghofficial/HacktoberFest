class Emp:
    def __init__(self, a, b, c):
        self.sal=0
        self.age=b
        self.name=a
        self.exp=c
    def setSal(self,dept):
        if dept == 'Software':
            sal=100
        elif dept == 'Market':
            sal = 120
        else:
            sal = 90
        sal = sal + sal*0.1
        self.sal = sal
        return sal
    def getDetails(self):
        print(self.name+" | "+str(self.age)+" | "+str(self.exp)+" | "+str(self.sal))

if __name__ == '__main__':
    emp_li=[]
    for i in range(int(input())):
        inp = list(input().split(" "))
        e = Emp(inp[0], int(inp[1]), int(inp[2]))
        e.setSal(inp[3])
        emp_li.append(e)
    for e in emp_li:
        e.getDetails()
