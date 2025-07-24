
// Bluetooth Controlled Car Code for Arduino Uno
char command;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);  // Motor 1 forward
  pinMode(10, OUTPUT); // Motor 1 backward
  pinMode(11, OUTPUT); // Motor 2 forward
  pinMode(12, OUTPUT); // Motor 2 backward
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    stop();
    if (command == 'F') forward();
    else if (command == 'B') backward();
    else if (command == 'L') left();
    else if (command == 'R') right();
    else if (command == 'S') stop();
  }
}

void forward() {
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
}

void backward() {
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
}

void left() {
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
}

void right() {
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
}

void stop() {
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}
