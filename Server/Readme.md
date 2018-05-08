# Prototype for ESP8266 webserver

This is very simple prototype for editing HTML/JS/CSS files that will run on ESP8266 based micro controller. At the expsense of low security, it enables me to do the entire design of the user interface for my next gadget, directly on the Microconroller, which is pretty cool.

## ToDo:

* Make sure that the notition of selection is represented in the list
* Implement deletion of files
* Make sure that the core files can't be deleted (or modified)
* Detect the extension of the file and swicth the editor language
* Upon upload, remember the name of the file and select it automatically
* Implement saving
* Remove the need for the horizontal scrollbar for the editor
* Merge the git repos with the one with the actual ESP8266 code
* Add image of the pin out to the readme
* Hook up the ePaper display and learn to talk to it
* Investigate again Monaco
* It would be cool to remember more of the state
* Implement page which shows the state of the device (only if useful)
* Would be also cool to have some kind of a REPL for later exploits
* UI for the entire thing - for this i think i will need some graphig library or something. 
* Should probably implement authentication
* Clean up the namespace. Don't know abotu the upload and uploads. Something has to give.
* Attach the click events to the anchor node and not the container - dumb
* make up roll over as well as selection in the file list
* test on edge and chrome




