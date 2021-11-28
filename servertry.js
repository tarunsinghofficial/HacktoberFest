// var http = require('http');
// http.createServer(function (req, res) {
//   res.writeHead(200, {'Content-Type': 'text/plain'});
//   res.end('Hello World!');
// }).listen(8080);

//var http = require('http');
//var dt = require('./dateinfo');
// http.createServer(function (req, res) {
//   res.writeHead(200, {'Content-Type': 'text/html'});
//   res.write("The date and time are currently: " + dt.myDateTime());
//   res.end();
// }).listen(8080);

var http = require('http');
const port = process.env.port || 3000
const server = http.createServer(function(req,res){
    res.statusCode = 200
    res.setHeader('Content-Type','text/html');
    res.end("<h1>Hello</h1>");
})
server.listen(port, ()=>{
    console.log(`Server running at port ${port}`);
})