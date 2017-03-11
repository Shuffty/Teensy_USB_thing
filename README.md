# Teensy_USB_KB_Reverse_Shell_OSX
Playing with a Teensy 3.2 to see what fun things I can do with it.

This works to create a reverse shell on an Mac with OSX 10+ (Not actually sure which versions it will work on). I have tested it on several macbooks / macbookpros and it has worked in all instances. I have encountered timing issues with older Macs, so it may be neccesary to slow things down a bit if the target machine is old or just plain slow!

To listen for the remote shell on your attacking machine us: nc -l -p 1337 -vvv

To clean up the target machine after playing around, simply use: crontab -r

I found lots of information on this website:
https://www.pjrc.com/teensy/index.html

NOTES: When plugged in for the first time, OSX wants you to install the new keyboard. It is a very fast proccess (click next twice if I remember correctly). Then simply remove and replug the Teensy to execute the code. I will update this when I figure out a way to make the Teensy look like a Mac Keyboard.
