char data; 

void setup() {
  Serial.begin(9600); 
  pinMode(4, OUTPUT); // Sağ Motor İleri/Geri Kontrolü (IN1)
  pinMode(5, OUTPUT); // Sağ Motor İleri/Geri Kontrolü (IN2)
  pinMode(6, OUTPUT); // Sol Motor İleri/Geri Kontrolü (IN3)
  pinMode(7, OUTPUT); // Sol Motor İleri/Geri Kontrolü (IN4)
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read(); 

    switch (data) {
      case 'F': // İLERİ - İki motor da ileri gitsin
        digitalWrite(4, LOW);  digitalWrite(5, HIGH); 
        digitalWrite(6, LOW);  digitalWrite(7, HIGH);
        break;
        
      case 'B': // GERİ - İki motor da geri gitsin
        digitalWrite(4, HIGH); digitalWrite(5, LOW);
        digitalWrite(6, HIGH); digitalWrite(7, LOW);
        break;

      case 'R': // SAĞA DÖN - Sadece Sağ motor ileri gitsin, Sol dursun
        digitalWrite(4, LOW);  digitalWrite(5, HIGH); 
        digitalWrite(6, LOW);  digitalWrite(7, LOW); 
        break;

      case 'L': // SOLA DÖN - Sadece Sol motor ileri gitsin, Sağ dursun
        digitalWrite(4, LOW);  digitalWrite(5, LOW);
        digitalWrite(6, LOW);  digitalWrite(7, HIGH);
        break;

      case 'S': // DUR - Hepsi kapalı
        digitalWrite(4, LOW);  digitalWrite(5, LOW);
        digitalWrite(6, LOW);  digitalWrite(7, LOW);
        break;
    }
  }
}
