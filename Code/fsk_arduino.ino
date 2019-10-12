#include <LiquidCrystal.h>  //library lcd
#include <SFE_BMP180.h>  //library barometer
#include <Wire.h>  //library i2c
#include <SimpleKalmanFilter.h>  //library kalman

SFE_BMP180 tekanan;
SimpleKalmanFilter ketinggian(1 , 1 , 1);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

float terima = 0;
float baseline;
float out;
const int tombol = 8;
int buttonState = 0;


void setup() {
  lcd.begin(16, 2);
  Serial.begin(1200);
  pinMode(tombol,INPUT_PULLUP);

  if (tekanan.begin()){
    lcd.print("Start Barometer");
    delay(1000);
    lcd.clear();
  }
  else
  {
    lcd.print("Pasang Barometer");
    while(1);
  }
  baseline = getPressure();
  lcd.print("BASELINE :");
  lcd.setCursor(0,1);
  lcd.print(baseline);
  delay(1000);
  lcd.clear();
}

void loop() {
  float altitude;
  float P;
  buttonState = digitalRead(tombol);
  P = getPressure();
  altitude = tekanan.altitude(P,baseline);  
  delay(100);
  out = ketinggian.updateEstimate(altitude);
  if(out < 0) out = 0;
  if (buttonState == HIGH){
     Serial.println(out,2);
     lcd.clear();
     lcd.print("Data Kirim : ");
     lcd.setCursor(0,1);
     lcd.print(out,2);
     lcd.setCursor(5,1);
     lcd.print("mdpl");
  }
   else {
    terima = Serial.parseFloat();
    lcd.clear();
    lcd.print("Data Terima : ");
    lcd.setCursor(0,1);
    lcd.print(terima,2);
    lcd.setCursor(5,1);
    lcd.print("mdpl");
  }
}

double getPressure()
{
  char status;
  double T,P,p0,a;

  status = tekanan.startTemperature();
  if (status != 0)
  {
    delay(status);

    status = tekanan.getTemperature(T);
    if (status != 0)
    {
      status = tekanan.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = tekanan.getPressure(P,T);
        if (status != 0)
        {
          return(P);
        }
        else{lcd.print("ERROR");}
      }
      else{lcd.print("ERROR");}
    }
    else{lcd.print("ERROR");}
  }
  else{lcd.print("ERROR");}
}
