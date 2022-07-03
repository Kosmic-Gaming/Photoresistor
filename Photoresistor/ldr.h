int defLDR;
int ldrval;
int globdeb;
void defLdr (int ldrd, int deb, float baud){
  defLDR = ldrd;
  pinMode (ldrd, OUTPUT);
  if (deb == 1){
    Serial.begin (baud);
    globdeb = deb;
  }
}
void readisp (int sensitivity){
   ldrval = analogRead (A0);
   if (globdeb == 1){
    Serial.println (ldrval);
  }
  if (ldrval <= sensitivity){
    if (globdeb == 1){
    Serial.println ("LED on");
  }
  digitalWrite (defLDR, HIGH);
}
else {
  if (globdeb == 1){
    Serial.println ("LED off");
  }
  digitalWrite (defLDR, LOW);
}
delay (20);
}
