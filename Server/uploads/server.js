/* 
var http=require('http');
var server=http.createServer((request,response)=>{
    response.writeHead(200, {
        "Conetnt-Type" : "text/plain"
    });
    response.end("Hello World\n");
});
console.log("listening...")
server.listen(8080);
*/

/*
 * NodeJS code.
 */

// Required modules.
var express = require('express');
var http = require('http');
var formidable = require('formidable');
var fs = require('fs');
var path = require('path');
var app = express();

var port = 8080;

app.get('/', (req, res) => {
    res.send('Go to upload');
});

app.get('/upload', (req, res) => {
    res.status(200).sendFile(__dirname + '/index.html');
});

// Upload route.
app.post('/upload', function(req, res) {
    var form = new formidable.IncomingForm();
    form.parse(req, function(err, fields, files) {
        // file is the name of the <input> field of type file

        var old_path = files.file.path;
        var file_size = files.file.size;
        var file_ext = files.file.name.split('.').pop();
        var index = old_path.lastIndexOf('/') + 1;
        var file_name = old_path.substr(index);
//         var new_path = path.join(process.env.PWD, '/uploads/', file_name + '.' + file_ext);
        var new_path = path.join(process.env.PWD, __dirname + '/uploads/', files.file.name);

        fs.readFile(old_path, function(err, data) {
            fs.writeFile(new_path, data, function(err) {
                fs.unlink(old_path, function(err) {
                    if (err) {
                        res.status(500);
                        res.json({'success': false});
                    } else {
                        res.status(200);
                        res.json({'success': true});
                    }
                });
            });
        });
    });
});

app.listen(port, () => console.log('Listening on port: ' + port));