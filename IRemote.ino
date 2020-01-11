#define IR 2
#define mic 13
#define soundPin 5
#define timedPin 6
#define instantPin 7
#define buttonPin 3

int delaytime = 3;
int mode = 0;

void setup() {
pinMode(IR, OUTPUT);
pinMode(mic, INPUT);
pinMode(soundPin, OUTPUT);
pinMode(timedPin, OUTPUT);
pinMode(instantPin, OUTPUT);
pinMode(buttonPin, INPUT);
}

void loop() {
  
  if (mode == 0){
    digitalWrite(instantPin, HIGH);
    digitalWrite(timedPin, LOW);
  }
  else if (mode == 1){
    digitalWrite(instantPin, LOW);
    digitalWrite(timedPin, HIGH);
    }
  if (digitalRead(buttonPin) == HIGH){
    mode++;
    mode = mode%2;
    delay(250);
    }
  if (digitalRead(mic) == HIGH && mode == 0){
    digitalWrite(soundPin, HIGH);
    photo();
    delay(1000);
  }
  else if (digitalRead(mic) == HIGH && mode == 1){
    digitalWrite(soundPin, HIGH);
    delay(delaytime * 1000);
    photo();
  } 
  else digitalWrite(soundPin, LOW);

}

void photo(void) {
  
  cycle(76); // 76 cycles in 2000 µs
  delay(28); 
  cycle(15); // 15 cycles in 400 µs
  delayMicroseconds(1580);
  cycle(15); // 15 cycles in 400 µs
  delayMicroseconds(3580);
  cycle(15); // 15 cycles in 400 µs
}

void cycle(int n) {
  for (int i = 0; i < n; i++) {
    digitalWrite(IR, HIGH);
    delayMicroseconds(6);
    digitalWrite(IR, LOW);
    delayMicroseconds(6);
    }
  }

  
