int M_R_1 = 9;    //right motor wire 1
int M_R_2 = 10;   //right motor wire 2
int M_L_1 = 11;   //left motor wire 1
int M_L_2 = 12;   //left motor wire 2

int l_sens = 7;
int r_sens = 8;

void setup()
{ //define 4 pins of motors as output
  pinMode(M_R_1, OUTPUT);
  pinMode(M_R_2, OUTPUT);
  pinMode(M_L_1, OUTPUT);
  pinMode(M_L_2, OUTPUT);
  // ir sensors as input
  pinMode(l_sens, INPUT);
  pinMode(r_sens, INPUT);

}

void loop()
{
  int L_data = digitalRead(l_sens);
  int R_data = digitalRead(r_sens);

  if (L_data == 1 & R_data == 1 )
  {
    //forward
    digitalWrite(M_L_1, 1);
    digitalWrite(M_L_2, 0);
    digitalWrite(M_R_1, 1);
    digitalWrite(M_R_2, 0);
  }
  else if (L_data == 1 && R_data == 0)
  {
    //right
    digitalWrite(M_L_1, 1);
    digitalWrite(M_L_2, 0);
    digitalWrite(M_R_1, 0);
    digitalWrite(M_R_2, 0);
  }
  else if (L_data == 0 && R_data == 1)
  {
    //left
    digitalWrite(M_L_1, 0);
    digitalWrite(M_L_2, 0);
    digitalWrite(M_R_1, 1);
    digitalWrite(M_R_2, 0);
  }
}
