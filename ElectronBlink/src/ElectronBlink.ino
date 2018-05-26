
FuelGauge fuel;

void setup() {
  pinMode(D7, OUTPUT);
	Particle.publish("State", "Particle Electron Blink App Started");
}

void loop() {
  float c = fuel.getSoC();
  Particle.publish("ElectronBattery", String::format("{CHARGE: %4.2f}", c));
  digitalWrite(D7, HIGH);
  delay(1000);
  digitalWrite(D7, LOW);
  delay(1000);
}
