int segm[7] = {4, 5, 6, 7, 8, 9, 10};
int gnd[2] = {11, 12};
int disp[16][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
  {1, 1, 1, 0, 1, 1, 1}, // A
  {0, 0, 1, 1, 1, 1, 1}, // b
  {1, 0, 0, 1, 1, 1, 0}, // C
  {0, 1, 1, 1, 1, 0, 1}, // d
  {1, 0, 0, 1, 1, 1, 1}, // E
  {1, 0, 0, 0, 1, 1, 1}  // F
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segm[i], OUTPUT);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(gnd[i], OUTPUT);
  }
  Serial.begin(9600);
}

void MostarNumero(int num) {
  if (num >= 0 && num <= 15) {
    digitalWrite(gnd[0], LOW);
    digitalWrite(gnd[1], HIGH);
    for (int i = 0; i < 7; i++) {
      digitalWrite(segm[i], disp[num][i]);
      
    }
  } else {
    // Mostrar número 8 intermitente
    for (int j = 0; j < 5; j++) { // parpadear 5 veces
      digitalWrite(gnd[0], LOW);
      digitalWrite(gnd[1], HIGH);
      for (int i = 0; i < 7; i++) {
        digitalWrite(segm[i], disp[8][i]);
      }
      delay(500);
      digitalWrite(gnd[0], LOW);
      digitalWrite(gnd[1], LOW);
      for (int i = 0; i < 7; i++) {
        digitalWrite(segm[i], LOW);
      }
      delay(500);
    }
  }
}

void loop() {
  if (Serial.available() > 0) {
    int num = Serial.parseInt();
     MostarNumero(num);
    delay(5000);
  }
}
