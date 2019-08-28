// ESP32 Banana Piano (Touch input example)


int touchState[4] = {100,100,100,100};
int touchLastState[4] = {100,100,100,100};

// These will likely need to be adjusted for your bananas!
// Set debug = true to get serial debugging to see values when touched/untouched
int touchHigh = 40;
int touchLow = 22;

bool debug = true;	// Set to true to output touch values to console - must be false for your big performance!

void setup()
{
  Serial.begin(115200);
  Serial.println("VintLabs Banana Piano!");
}

void loop()
{
  int del = 50;
  touchState[0] = touchRead(T0);	// IO4
  delay(del);
  touchState[1] = touchRead(T2);	// IO2
  delay(del);
  touchState[2] = touchRead(T7);	// IO27
  delay(del);
  touchState[3] = touchRead(T8);	// IO32
  delay(del);

  if (debug)
  	Serial.printf(">> %d %d %d %d\n", touchState[0], touchState[1], touchState[2], touchState[3]);
  
  for (int i = 0; i < 4; i++)
  {
    if ((touchState[i] < touchLow) && (touchLastState[i] > touchHigh))
    {
      Serial.println(i);
    }

    if ((touchState[i] < touchLow) || (touchState[i] > touchHigh))
      touchLastState[i] = touchState[i];
  }
  
}
