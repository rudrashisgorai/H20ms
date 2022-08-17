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

float calibration_value = 16.24;
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10],temp;




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


  for(int i=0;i<10;i++) 
   { 
   buffer_arr[i]=analogRead(A0);
   delay(100);
   }
   for(int i=0;i<9;i++)
   {
   for(int j=i+1;j<10;j++)
   {
   if(buffer_arr[i]>buffer_arr[j])
   {
   temp=buffer_arr[i];
   buffer_arr[i]=buffer_arr[j];
   buffer_arr[j]=temp;
   }
   }
   }
   avgval=0;
   for(int i=2;i<8;i++)
    avgval+=buffer_arr[i];
   float volt=(float)avgval*5.0/1024/6;
   float ph_act = -5.70 * volt + calibration_value;
   //lcd.setCursor(0, 0);
   //lcd.print("pH Val:");
   //lcd.setCursor(8, 0);
   //lcd.print(ph_act);
   //delay(1000);

  Serial.println("ph value");
  Serial.println(ph_act);
  Serial.println("volt value");
  Serial.println(volt);
  Serial.println("avgval");
  Serial.println(avgval);
  display.print("ph value :") ;
  display.print(" ");
  display.println(ph_act);
  
  display.display();
  delay(1000);
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

  //int sensorValue = analogRead(A0);// read the input on analog pin A0:
  //float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  /*
  Serial.println(sensorValue);
  Serial.println(voltage);
  display.print("Turbidity :") ;
  display.print(" ");
  display.println(voltage);
  
  display.display();
  */
  //delay(500);

  
  
  
}


void setu()
{
  Serial.begin(9600); 
  sensors.begin();
}
