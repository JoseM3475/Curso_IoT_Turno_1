void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12,LOW);
  digitalWrite(14, HIGH);
  delay(500);
  digitalWrite(14, LOW);
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2,LOW);
}
