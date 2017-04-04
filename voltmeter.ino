float a[50];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

float avg(float p[])
{
  float sum = 0.0;
  for(int i=0; i<50; i++)
  {
    sum = sum + p[i];
  }
  return sum/50.0;
}
void loop() {
  // put your main code here, to run repeatedly:
  float x,in_v,disp_v;
 
  noInterrupts();
  for(int i =0; i<50; i++)
  {
    x = analogRead(A0);
    in_v = x*(5/1024.0);
    a[i] = in_v;
  }
  disp_v = avg(a);
  interrupts();
  char c;
  c = Serial.read();
  if(c == 't')
  {
    if(disp_v * 100 <1)
  {
    Serial.print(in_v*1000, DEC);
    Serial.print(" milivolt");
    Serial.println(" ");
  }
  else if( disp_v * 100000 < 1)
  {
    Serial.print(in_v*100000, DEC);
    Serial.print(" micro volt");
    Serial.println(" ");
  }
  else
  {
    Serial.print(disp_v, DEC);
    Serial.print(" Volt");
    Serial.println(" ");
  }
  
  }

}
