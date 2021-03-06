//초음파 센서의 핀번호를 설정한다.
int echoPin = 4;
int trigPin = 7;

void setup() {
  Serial.begin(9600);
  // trig를 출력모드로 설정, echo를 입력모드로 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  //앞으로 가는 코드
  forward();

  // 초음파를 보낸다. 다 보내면 echo가 HIGH 상태로 대기하게 된다.
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  unsigned long duration = pulseIn(echoPin, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  float distance = ((float)(340 * duration) / 10000) / 2;
  // 수정한 값을 출력
  Serial.print(distance);
  Serial.println("cm");

  if (distance < (float) 30) {
    
    left();
    right();
    forward();
    delay(1000);
    stop_mine();
    delay(10000);
  }
  delay(100);
}
void forward(){
    digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  analogWrite(5, 255);
  analogWrite(6, 250);

}
void left(){
  forward();
  analogWrite(6, 0);
  delay(600);
  forward();
}
void right(){
  forward();
  analogWrite(5, 0);
  delay(600);
  forward();
}
void stop_mine(){
  digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
}
