void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  float x,in_v;
 
  x = analogRead(A0);
  in_v = x*(5/1024.0);
  
  char c;
  c = Serial.read();
  if(c == 't')
  {
    if(in_v * 100 <1)
  {
    Serial.print(in_v*1000, DEC);
    Serial.print(" milivolt");
    Serial.println(" ");
  }
  else if( in_v * 100000 < 1)
  {
    Serial.print(in_v*100000, DEC);
    Serial.print(" micro volt");
    Serial.println(" ");
  }
  else
  {
    Serial.print(in_v, DEC);
    Serial.print(" Volt");
    Serial.println(" ");
  }
  
  }

}
