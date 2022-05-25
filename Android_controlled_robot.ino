#include <SoftwareSerial.h>

SoftwareSerial BT(7, 8); //RX, TX

int M_R_1 = 9;    //right motor wire 1
int M_R_2 = 10;   //right motor wire 2
int M_L_1 = 11;   //left motor wire 1;
int M_L_2 = 12;   //left motor wire 2

void setup()
{
  //define 4 pins of motors as output
  pinMode(M_R_1, OUTPUT);
  pinMode(M_R_2, OUTPUT);
  pinMode(M_L_1, OUTPUT);
  pinMode(M_L_2, OUTPUT);
  Serial.begin(115200);
  BT.begin(9600);
  Serial.println("Keyboard Controlled Robot");
}

void loop()
{
  if (BT.available() > 0)
  {
    char data = BT.read();
    Serial.println(data);
    BT.println(data);

    // forward
    if (data == 'w' || data == 'W')
    {
      Serial.println("Forward");
      BT.println("Forward");
      digitalWrite(M_L_1, 1);
      digitalWrite(M_L_2, 0);
      digitalWrite(M_R_1, 1);
      digitalWrite(M_R_2, 0);
    }

    // backward
    else if (data == 'z' || data == 'Z')
    {
      Serial.println("backward");
      BT.println("backward");
      digitalWrite(M_L_1, 0);
      digitalWrite(M_L_2, 1);
      digitalWrite(M_R_1, 0);
      digitalWrite(M_R_2, 1);
    }

    // left
    else if (data == 'a' || data == 'A')
    {
      Serial.println("left");
      BT.println("left");
      digitalWrite(M_L_1, 0);
      digitalWrite(M_L_2, 0);
      digitalWrite(M_R_1, 1);
      digitalWrite(M_R_2, 0);

    }

    // right
    else if (data == 'd' || data == 'D')
    {
      Serial.println("right");
      digitalWrite(M_L_1, 1);
      digitalWrite(M_L_2, 0);
      digitalWrite(M_R_1, 0);
      digitalWrite(M_R_2, 0);
    }

    // stop
    else if (data == 's' || data == 'S')
    {
      Serial.println("stop");
      digitalWrite(M_L_1, 0);
      digitalWrite(M_L_2, 0);
      digitalWrite(M_R_1, 0);
      digitalWrite(M_R_2, 0);

    }
  }
}
