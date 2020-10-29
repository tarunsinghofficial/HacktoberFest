# Makes Individual Multiplication table Files for every no. from 2 to 20
# Developer - Dernyt-TPE


for a in range(2, 21):
    f = open('Multiplication table of ' + str(a), 'w')
    f.write(f"\t\t\t*** Multiplication table of {a} ***\n\n\t")
    for b in range(1, 11):
        table = f.write(f"{a} x {b} = {a * b}\n\t")
    f.close()
