# COMS3930-Module03

<h3>BACKGROUND</h3>
One of my favorite Iphone apps is called Bebot, it's an app that acts like a theremin and has this cute robot which I am attempting to replicate with my case.

For this module, I wanted to build upon the theremin concept from module 2 but make a new encasement with a much smaller footprint and using a different sensor. For this project, I've stripped the ESP32 from the extension board and plugging directly onto the ESP32 pins.

<h3>Items used for project:</h3>
<ul>
 	<li>1 ESP32-WROVER-DEV</li>
 	<li>7 male-to-female wires</li>
 	<li>1 lipo battery</li>
 	<li>Raspberry Pi box (used for case)</li>
 	<li>wire stripper</li>
 	<li>wire tape</li>
 	<li>aluminum foil</li>
</ul>
Software to run project, can use any PC or a Raspberry Pi:
<ul>
 	<li>Python</li>
 	<li>SonicPi</li>
</ul>
<h3>THE BUILD</h3>
The BeBox1000 is a wireless theremin that is neither connected to a computer via usb nor a wired power source and is entirely self contained in a small handheld box using wifi as a communication protocol and a lipo battery for wireless power consumption.

It uses an ultrasonic sensor that measures distance from objects using radar. The ESP32 runs on battery power and sets up a wireless access point for a computer to connect to acting as a server. Once connected, the ESP32 sends distance measurements and touch sensor values via UDP protocol over the wireless network and these measurements are picked up by running the python program. The python program then parses out the sensor values into meaningful variables that are then sent to Sonic-Pi for sonic output.

