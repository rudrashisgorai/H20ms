#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);



#include <DallasTemperature.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 14                         //D3 pin of nodemcu

OneWire oneWire(ONE_WIRE_BUS);
 
DallasTemperature sensors(&oneWire);            // Pass the oneWire reference to Dallas Temperature.


void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(2000);
  setu();
  /*
  display.setFont(&FreeSerif9pt7b);
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(0,20);             
  display.println("Hello, Mudit");
  display.display();
  delay(2000); 
  */
}
void loop() {
  display.setFont(&FreeSerif9pt7b);
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(0,20);   

  /*
  display.println("Hello, Aditya");
  display.display();
  delay(2000);
  //display.clearDisplay();
  //display.setCursor(0,20); 
  display.println("Hello, Aditya");
  Serial.println("rudra ");
  display.display();
  delay(2000);
  */
  

  
  /*
  sensors.requestTemperatures();                // Send the command to get temperatures  
  Serial.println("Temperature is: ");
  Serial.println(sensors.getTempCByIndex(0));   // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  
  Serial.println("Turbidity: ");
  
  Serial.println(voltage); 
  display.clearDisplay();
  display.setCursor(0,20); 
  display.print("Temp :") ;
  display.print(" ");
  display.println(sensors.getTempCByIndex(0));
  */

  int sensorValue = analogRead(A0);// read the input on analog pin A0:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):

  Serial.println(sensorValue);
  Serial.println(voltage);
  display.print("Turbidity :") ;
  display.print(" ");
  display.println(voltage);
  
  display.display();
  delay(500);


  
  
  
}


void setu()
{
  Serial.begin(9600); 
  sensors.begin();
}
