// ESP32 Banana Piano (Touch input example)


int touchState[4] = {100,100,100,100};
int touchLastState[4] = {100,100,100,100};
int touchHigh = 45;
int touchLow = 18;

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
  touchState[3] = touchRead(T8);	// IO33
  delay(del);

  //Serial.printf(">> %d %d %d\n",touchState[0],touchState[1],touchState[2]);
  for (int i = 0; i < 4; i++)
  {
    if ((touchState[i] < touchLow) && (touchLastState[i] > touchHigh))
    {
      //Serial.printf("== %d: %d - %d\n", i, touchState[i], touchLastState[i]);
      Serial.println(i);
         
    }
    if ((touchState[i] < touchLow) || (touchState[i] > touchHigh))
      touchLastState[i] = touchState[i];
    //Serial.println(touchState[i]);
  }
  
}
