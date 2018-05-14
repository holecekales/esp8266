# Prototype for ESP8266 webserver

This is very simple prototype for editing HTML/JS/CSS files that will run on ESP8266 based micro controller. At the expsense of low security, it enables me to do the entire design of the user interface for my next gadget, directly on the Microconroller, which is pretty cool.

## ToDo:

### File manipulation
* Delete file 
* Save file
### UX
* Add tabs to the top for more secctions of the UI
* Figure out the status bar (smaller and sections)
* Show when the file is dirty with a dot
* Shrink to and bottom sections
### State Management 
* Core files can't be deleted (or modified)
* Pre-select file after upload 
* Remember state across sessions (e.g. last loaded file)
* Clean up the namespace. Don't know abotu the upload and uploads. Something has to give.
### House keeping
* Merge the git repos with the one with the actual ESP8266 code
* Add image of the pin out to the readme
### Hardware
* Hook up the ePaper display and learn to talk to it
* Figure out how to update OTA 
### Other
* Investigate again Monaco
* Implement page which shows the state of the device (only if useful)
* Would be also cool to have some kind of a REPL for later exploits
* UI for the entire thing - for this i think i will need some graphig library or something. 
* Should probably implement authentication




