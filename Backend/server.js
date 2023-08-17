const http = require('http')
const fs = require('fs')

const filecontent = fs.readFileSync('server.txt')

const server = http.createServer((req,res) =>
{
    res.writeHead(200,{'content-type':'html/txt'});
    res.end(filecontent)
})

server.listen(80,'127.0.0.1',()=>
{
    console.log(`Listening at http://127.0.0.1:80/`)
})