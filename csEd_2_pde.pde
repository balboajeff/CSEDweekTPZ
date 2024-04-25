
import processing.serial.*;

int lf = 10;    // Linefeed in ASCII
String myString = null;
Serial myPort;  // The serial port
int[] inData;
void setup() {
  size(1400,1200);
  // List all the available serial ports
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[2], 9600);
  myPort.clear();
  // Throw out the first reading, in case we started reading 
  // in the middle of a string from the sender.
  myString = myPort.readStringUntil(lf);
  myString = null;
}

void draw() {
  myPort.write('a');
  while (myPort.available() > 0) {
    myString = myPort.readStringUntil(lf);
    if (myString != null) 
    
    {
      inData = int(trim(split(myString, ',')));

      fill(inData[0], inData[1],inData[2]);
  ellipse((inData[3]*1.4),inData[4], random(255), random(255));
    }
  }
  
}
