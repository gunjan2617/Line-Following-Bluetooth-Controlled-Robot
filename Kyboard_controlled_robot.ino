int M_R_1 = 9;    //right motor wire 1
int M_R_2 = 10;   //right motor wire 2
int M_L_1 = 11;   //left motor wire 1
int M_L_2 = 12;   //left motor wire 2

void setup()
{
  //define 4 pins of motors as output
  pinMode(M_R_1, OUTPUT);
  pinMode(M_R_2, OUTPUT);
  pinMode(M_L_1, OUTPUT);
  pinMode(M_L_2, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char data = Serial.read();
    Serial.println(data);

    // forward
    if (data == 'f' || data == 'F')
    {
      Serial.println("Forward");
      digitalWrite(M_L_1, 1);
      digitalWrite(M_L_2, 0);
      digitalWrite(M_R_1, 1);
      digitalWrite(M_R_2, 0);
    }

    // backward
    else if (data == 'b' || data == 'B')
    {
      Serial.println("backward");
      digitalWrite(M_L_1, 0);
      digitalWrite(M_L_2, 1);
      digitalWrite(M_R_1, 0);
      digitalWrite(M_R_2, 1);
    }

    // left
    else if (data == 'l' || data == 'L')
    {
      Serial.println("left");
      digitalWrite(M_L_1, 0);
      digitalWrite(M_L_2, 0);
      digitalWrite(M_R_1, 1);
      digitalWrite(M_R_2, 0);

    }

    // right
    else if (data == 'r' || data == 'R')
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
