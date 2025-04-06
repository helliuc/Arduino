// #include <Arduino.h>

// Funktion zum Teilen des Arduino-Strings in 20-Byte-Blöcke
void splitAndSend(const String &input, size_t block_size = 20) {
  for (size_t i = 0; i < input.length(); i += block_size) {
    String block = input.substring(i, i + block_size);
    
    // Senden über Serial (UART)
    Serial.print("Sending block: ");
    Serial.println(block);
    
    // Hier könnten Sie auch direkt an Hardware-UART senden:
    // Serial1.write(block.c_str(), block.length());
    
    // Kleine Verzögerung für stabile Übertragung
    delay(20);
  }
}

/*
 * Optimierte Funktion zum Senden von Daten in Blöcken
 * Diese Funktion sendet den String in Blöcken von 20 Byte.
 * Sie verwendet Serial.write() für eine schnellere Übertragung.
 */
void sendInBlocksOptimized(const String &input, size_t block_size = 20) {
  const char* data = input.c_str();
  size_t length    = input.length();
  for (size_t i = 0; i < length; i += block_size) {
    size_t remaining = length - i;
    size_t send_size = (remaining < block_size) ? remaining : block_size;
    Serial.write(data + i, send_size);  // Direkter Zugriff auf den Puffer
    // Optional: Frame-Ende-Markierung senden Serial.write('\n');
    delay(5); // Kurze Pause
  }
  Serial.write('\n');
}

void setup() {
  Serial.begin(115200);
  while ( ! Serial ); // Warten auf Serial-Verbindung
  
  String longString = "Dies ist ein sehr langer String, der in 20-Byte-Blöcke "
                     "aufgeteilt werden soll, um über UART gesendet zu werden.";
  
  // splitAndSend(longString);
  sendInBlocksOptimized(longString);
}

void loop() {
  // Nichts zu tun hier
}
