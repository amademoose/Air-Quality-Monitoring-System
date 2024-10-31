#include <Wire.h> // 
#include <Adafruit_SSD1306.h> // 
#include <Adafruit_GFX.h> // 

int mq7Pin = A0;
int mq135Pin = A1;
int mq2Pin = A2;

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {

  Serial.begin(9600);
  
  Wire.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.display();
}

void loop() {
  int mq7Value = analogRead(mq7Pin);
  int mq135Value = analogRead(mq135Pin);
  int mq2Value = analogRead(mq2Pin);

 
  Serial.print("MQ-7 Value: ");
  Serial.print(mq7Value);
  Serial.print(" | MQ-135 Value: ");
  Serial.print(mq135Value);
  Serial.print(" | MQ-2 Value: ");
  Serial.println(mq2Value);
  
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
  display.setCursor(0, 0);
  display.print("MQ-7: ");
  display.println(mq7Value);

  display.setCursor(0, 10);
  display.print("MQ-135: ");
  display.println(mq135Value);

  display.setCursor(0, 20);
  display.print("MQ-2: ");
  display.println(mq2Value);
  
  display.display();

 
  delay(1000);
}
