void setup() {
  // put your setup code here, to run once:
Serial.begin(2000000);
randomSeed(analogRead(0));

  // put your main code here, to run repeatedly:
for (int i = 0; i<=10; i++){
  randomSeed(analogRead(0)); //new seed every 100 random numbers
  for (int i = 0; i<=100; i++){ //print 100 random numbers
    int rr = random(1,21);
    Serial.print(rr);
    Serial.print(",");
  }
  //Serial.print("\n");
}
//Serial.print("done\n");

}

void loop() {}
