float setpoint = 30.;
float current = 0.;

int heat = 12;  // pin 12
int cool = 11;  // pin 11

void setup() {
  pinMode(cool, OUTPUT);
  pinMode(heat, OUTPUT);
  analogReference(INTERNAL);
  Serial.begin(9600);
}

void loop() {
  current = (float) analogRead(A0) * 223/1024;
  Serial.println(current);
  if (setpoint > current) {
    digitalWrite(heat, HIGH);
    digitalWrite(cool, LOW);
  }
  else if (setpoint < current) {
    digitalWrite(heat, LOW);
    digitalWrite(cool, HIGH);
  }
  delay(1000);
}
