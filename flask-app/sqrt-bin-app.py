from  flask import Flask

PORT = 8765
LOCALHOST = '127.0.0.1'

app = Flask(__name__)


@app.route('/bin_sqrt/<int:num>')
def sqrt_bin(num):
    num = int(num)

    s = 0
    e = num
    mid = num

    while(s <= e):
        mid = e - (e-s)//2
        if mid**2 == num:
            return mid
        elif mid**2 > num:
            e = mid
        else:
            s = mid+1
    
    return mid


if __name__ == '__main__':
    app.run(host=LOCALHOST, port=PORT, debug=True)