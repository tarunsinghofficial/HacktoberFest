
from flask import Flask, jsonify, request, make_response

PORT = 8000
LOCALHOST = '127.0.0.1'

app = Flask(__name__)

info = {
    1:{
        'name':'John Doe',
        'age': 50,
        'gender': 'M',
        'salary': 500000
    },
}

@app.route('/crud', methods=['GET', 'POST'])
def without_id():
    if request.method == 'GET':
        return jsonify(info)
    elif request.method == 'POST':
        info[len(info)] = request.body
        return 'Data added'

@app.route('/crud/<int:id>', methods=['PUT', 'DELETE', 'GET'])
def with_id(id):
    id = int(id)

    if request.method == 'GET':
        return jsonify( info[id] )
    elif request.method == 'PUT':
        info[id] = request.body
        return 'Updated'
    elif request.method == 'DELETE':
        item = info[id]
        del info[id]
        return make_response(jsonify(item), 200)


if __name__ == '__main__':
    app.run(host=LOCALHOST, port=PORT, debug=True)