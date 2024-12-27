
#define B1 9
#define B2 8
#define LED 10
int cnt=0;
int LEDR=0;
int R=0;

void setup() {
  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int b1=digitalRead(B1);
  int b2=digitalRead(B2);

  if(b1==0)
  {
    cnt++;
    delay(300);
  }
  if(cnt==1)
  {
    analogWrite(LED, R);
  }
  else if(cnt>1)
  {
    R=0;
    cnt=0;
    analogWrite(LED, R);
  }

  if(b2==0)
  {
    LEDR++;
    if(LEDR>3)
      LEDR=1;
    delay(300);
  }

  switch(LEDR)
  {
    case 1:
      R=85;
      break;

    case 2:
      R=170;
      break;

    case 3:
      R=255;
      break;
  }
  Serial.println(cnt);
} 
