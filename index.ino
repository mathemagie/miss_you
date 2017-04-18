#include <Process.h> 
#include <Bridge.h> 
#include <Servo.h>

Servo myservo;
void setup() {
  myservo.attach(9);
  Bridge.begin(); // Initialize the Bridge
  Serial.begin(9600); 
}
void loop() {
  Serial.println("run curl command");
  Process p;
  p.runShellCommand("/usr/bin/curl 'http://mathemagie.net/projects/miss_you/get_val.php?id=1'");
  while (p.running());
  // Read command output. runShellCommand() should have passed "Signal: xx&": 
  while (p.available()) {
    int result = p.parseInt(); Serial.println(result);
    if (result == 0) { 
      myservo.write(0);
    }
    if (result == 1) { 
      myservo.write(180); // attend 5 secondes delay(5000); myservo.write(0);
    } 
  }
delay(1000); 
}
