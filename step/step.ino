
int Pin0 = 8;
int Pin1 = 9;
int Pin2 = 10;
int Pin3 = 11;

boolean dir = false;
int _step = 0;
int stepperSpeedUp = 20;
int stepperSpeedDown = 20;

int MAXUP = 1000;
int MAXDOWN = 1000;

int step_up = 0;
int step_down = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Pin0, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
}

void loop() {
//  int sensorValue = analogRead(A1);
//  Serial.println(sensorValue);
//  int n = digitalRead(3);
//  int m = digitalRead(4);
//  Serial.println(n);
////  delay(1000);
//  if (sensorValue < 100) {
//      dir = true;
//  } else {
//    if(dir == true)
//      delay(2000);
//    dir = false;
//  }

//  if(n == 1 && m == 0 && dir == false) {
//    up();
//  }
//  if(n == 0 && m == 1 && dir == true) {
//    up();
//  }
//  if(n == 1 && m == 1) {
//    up();
//  }
  
  stop();
}

void stop() {
  digitalWrite(Pin0, LOW);
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, LOW);
  digitalWrite(Pin3, LOW);
}

void up()
{ 
  
  switch(_step){
    case 0:
    //stepperSpeed++;
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);//32A
    break;
    case 1:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);//10B
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
    break;
    case 2:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
    break;
    case 3:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
    break;
    case 4:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;
    case 5:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;
      case 6:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;
    case 7:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
    break;
    default:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;
  }
  if (dir) {
//    if(step_up < MAXUP) {
//      _step++;
//      step_up++;
//      if(step_down >= MAXUP)
//        step_down = 0;
//    }
    _step++;
    
    delay(stepperSpeedUp);
  }
  else {
//    if(step_down < MAXDOWN) {
//      _step--;
//      step_down++;
//      if(step_up >= MAXUP)
//        step_up = 0;
//    }
    _step--;
    delay(stepperSpeedDown);
  }
 
  if( _step > 7 ) {
    _step = 0;
  }
  if( _step < 0 ) {
    _step = 7;
  }
 
  

}


