// Required modules.
var express = require('express');
var http = require('http');
var formidable = require('formidable');
var fs = require('fs');
var path = require('path');
var app = express();

var port = 8080;

function dirList() 
{
    const folder = __dirname + '/uploads/';
    var fileList = [];
    fs.readdirSync(folder).forEach(file => {
        var fileObj = { 'name': file, 'url': '/uploads/' + file };
        fileList.push(fileObj);
    });
    return fileList;
}

app.get('/', (req, res) => {
    res.status(200).sendFile(__dirname + '/index.html');
});

app.get('/upload', (req, res) => {
    res.status(200).json(dirList());
});

app.get('/uploads/:file', (req, res) => {
    var fp = path.join(__dirname, '/uploads/', req.params.file);
    console.log(fp);
    res.status(200).sendFile(fp);
});

app.put('/uploads/:file', function (req, res) {
    var fp = path.join(__dirname, '/uploads/', req.params.file);
    console.log("updating: " + fp);

    var data = "Hellow world"; // req.body

    fs.writeFile(fp, data, (err) => {
        if (err) {
            res.status(500);
            res.json({ 'success': false });
        } else {
            res.status(200).json(dirList());
        }
    });
});

// Upload route.
app.post('/upload', function (req, res) {
    var form = new formidable.IncomingForm();
    form.parse(req, function (err, fields, files) {
        // file is the name of the <input> field of type file
        var old_path = files.file.path;
        var file_size = files.file.size;
        var file_ext = files.file.name.split('.').pop();
        var index = old_path.lastIndexOf(path.sep) + 1;
        var file_name = old_path.substr(index);
        var new_path = path.join(__dirname, '/uploads/', files.file.name);

        fs.readFile(old_path, function (err, data) {
            fs.writeFile(new_path, data, function (err) {
                fs.unlink(old_path, function (err) {
                    if (err) {
                        res.status(500);
                        res.json({ 'success': false });
                    } else {
                        res.status(200).json(dirList());
                    }
                });
            });
        });
    });
});

app.listen(port, () => console.log('Listening on port: ' + port));
