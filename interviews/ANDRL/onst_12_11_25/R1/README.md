1.) Hackerrank problem: you have a led that you need to toggle. 
You need to keep track of the state of the gpio being pushed. 
There are some helper functions that are included like: isbuttonpushed() (true if yes, false if no) . millis() returns the number of milliseconds. changegpiostatue() which is a helper to toggle the led. 
The point of the problem was to toggle the led once the button is pushed in a non-blocking manner. A working solution is to utilize a state machine. this also required knowlege of debouncing. 
This Image is a refernce to the type of debounce logic.
Key concepts:
State Machine
Non-Blocking
Handle debounce and assume a 10ms time for stable state
<img width="1799" height="572" alt="image" src="https://github.com/user-attachments/assets/e5b99062-d7a9-48ff-b1cd-d8fecfef97d9" />
1.) Another Hackerank Problem that had to be assessed for errors/bugs. 
  typical passing array name to function, wrong types, conversions. etc
