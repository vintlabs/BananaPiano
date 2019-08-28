# BananaPiano
Use an ESP32 and some bananas to make a piano!

## What you will need:
- An ESP32 development module (I shamelessly recommend mine: https://www.amazon.ca/dp/B07R459KW5)
- Some bananas (I planned to use 5 in this example, but I got hungry and now I only have 4)
- Jumper wires
- Linux PC with python (I'm sure it's easy to make it work on Windows or Mac too!)
- Arduino IDE with ESP32 stuff installed (Good instructions for this can be found at https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)
- 10 minutes to kill

## Steps:

1. Gather materials
![Required Materials](https://raw.githubusercontent.com/vintlabs/BananaPiano/master/images/need.jpeg)

2. Make the connections:
  - IO4 connects to Banana0
  - IO2 connects to Banana1
  - IO27 connects to Banana2
  - IO32 connects to Banana3
  
  ![Connections](https://raw.githubusercontent.com/vintlabs/BananaPiano/master/images/boardConnections.jpeg)
  ![Banana Connection](https://raw.githubusercontent.com/vintlabs/BananaPiano/master/images/bananaConnection.jpeg)
  
  3. Load the sketch into the Arduino IDE, set `debug = true` to test and get values so that you can calibrate the touch sensitivity:
  ![Set Debug](https://raw.githubusercontent.com/vintlabs/BananaPiano/master/images/setDebug.png)
  
  4. Be sure to set the board type - I use "DOIT ESP32 DEVKIT V1" for mine. Also check the port and baudrate.
  ![Setup IDE](https://raw.githubusercontent.com/vintlabs/BananaPiano/master/images/setupArduino.png)
  
  5. Run the sketch with `debug = true`, touch each banana in series to see the values for touched/untouched.
  Here is my example today:
```
VintLabs Banana Piano!
>> 26 35 40 26
>> 32 35 40 25
>> 31 35 40 25
>> 30 35 40 26
>> 10 33 41 26
0
>> 10 33 41 26
>> 31 23 41 27
>> 32 34 41 27
>> 32 34 41 27
>> 31 1 41 27
1
>> 31 12 41 27
>> 31 12 41 27
>> 33 35 40 27
>> 33 35 13 26
2
>> 33 35 13 26
>> 33 35 13 26
>> 33 35 37 27
>> 33 36 40 26
>> 33 36 40 7
3
>> 34 36 40 7
>> 34 36 40 7
>> 34 36 41 26
>> 34 36 41 27
>> 34 36 42 27
>> 34 36 42 27
>> 34 36 42 27
```

After it started I touched each banana one at a time for about a second each and I can see that the "untouch" values are at least 25 for each, and the "touched" values are 13 or less. We want to leave a bit of tolerance, so I'll set `touchHigh` and `touchLow` as follows:
```
int touchHigh = 22;
int touchLow = 17;

bool debug = false;     // Set to true to output touch values to console - must be false for your big performance!
```
Note that I also set debug to false.

6. Test on the serial console:
```
VintLabs Banana Piano!
2
0
2
0
0
0
1
2
3
3
3
2
0
```
You should see a number on the console that corresponds to the banana that you touched. (Expect that there will be some anomalies... this is just a simple example!)

7. Test with the python script to hear your wonderful banana music! (be sure to close the serial console in the Arduino IDE first)
```
pvint@nautilus ~/Arduino/BananaPiano [1]$ python play.py 
3
Playing WAVE './wav-piano-sound/wav/f1.wav' : Signed 16 bit Little Endian, Rate 44100 Hz, Stereo



0
Playing WAVE './wav-piano-sound/wav/c1.wav' : Signed 16 bit Little Endian, Rate 44100 Hz, Stereo



2
Playing WAVE './wav-piano-sound/wav/e1.wav' : Signed 16 bit Little Endian, Rate 44100 Hz, Stereo



0
Playing WAVE './wav-piano-sound/wav/c1.wav' : Signed 16 bit Little Endian, Rate 44100 Hz, Stereo
```

If all went well, you should hear piano notes C, D, E and F for bananas 0 through 3!

