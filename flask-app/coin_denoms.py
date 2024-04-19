
### A flask app to get the minimum set of coins required to make the given amount

from flask import Flask

app = Flask(__name__)

PORT = 8000
LOCALHOST = '127.0.0.1'

@app.route('/coin-change/<amount>')
def greedy_coin_denoms(amount):
    amount = int(amount)
    denoms = [100, 50, 20, 10, 5, 2, 1]
    res = {}
    highest_denom = 0

    while(amount > 0):
        temp = denoms[highest_denom]
        if amount >= temp:
            if temp not in res:
                res[temp] = 1
            else:
                res[temp] += 1
            amount -= temp
        else:
            highest_denom+=1


    return res


if __name__ == '__main__':
    app.run(host=LOCALHOST, port=PORT, debug=True)