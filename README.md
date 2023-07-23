# Arduino-Summer-Camp
Code and Explanation for an Arduino Beginner Summer Camp

Learn more about each project on my [youtube channel](https://www.youtube.com/channel/UCszrNeQ_xBV6YQfvcIs6uVA).

## 1. Board Creation
The Acrylic Board which housed all the componenets were created by me. The components on the board include:
* Arduino Uno R3
* Grove Base Shield
* Breadboard
* Lamp
* 9V Battery
* Grove Potentiometer
* Grove Temperature & Humidity Sensor
* Grove LED
* Grove Buzzer
* Grove OLED Display
* Grove Ultrasonic Ranger
* Grove Water Sensor

The majority of these parts are attached to the board via standoffs, screws, and nuts. I drilled holes onto the acrylic board based on an outline I created from a python script. The Water Sensor, Breadboard, and 9V Battery are the only parts not connected via standoffs. The Ultrasonic Ranger is attached using a seperate acrylic board installed perpendicular to make it easier for the students to test out said sensor. 

## 2. Basic Circuits
I started the camp by teaching the students circuit basics:
*Turning ON and LED on the Breadboard
*Using a potentiometer to change the brightness of the LED
*Using a button to turn the LED ON and OFF

We also installed the Lamp. We used a 3V battery holder with switch to turn the Lamp on and off.

Learn more about these basics in [this video](https://www.youtube.com/watch?v=bQS-vkHR7F8&)

## 3. Basic Circuits with Arduino
The following programs were used to teach the students the basics of working with the Arduino. Before we got started, we also discussed more about how the Arduino works and the parts of the Arduino such as the ATMega 328P Chip, Digital Headers, Analog Headerrs, Power Headers, USB Socket, Power Jack, the Printed Circuit Board (PCB) and more. I also provided an [Arduino Function Cheatsheet](https://docs.google.com/document/d/1QYzo4wBym-xJpfdnLt6h2N2m4J6qdlCz4fPCTWNhXuQ/edit?usp=sharing) to help the students out with programming.

### a). Blink
The students created a program to blink the LED ON and OFF. The students learned about the following functions:
* setup(): Called when the program first starts. “Setup” variables, pin modes, libraries, etc. This function only runs once.
* loop(): Occurs after setup function. Code inside here will run forever.
* pinMode(pin, mode): Used to specify if the pin is an INPUT or OUTPUT (for example, we take __input__ from a potentiometer, but send __outputs__ to an LED).
* digitalWrite(pin, value): Writes a HIGH or LOW value to a digital pin.
* delay(ms): Wait for amount of milliseconds specified (Note: tone function runs concurrently).

### b). POT
The students learned how to control and LED using a Potentiometer. T he students learned about the following new functions:
* analogRead(pin): Read the value of analog pin (A0, A1, etc.). Value will be from 0-1023
* analogWrite(pin, value): Writes an analog value to a pin. This value should be between 0 and 255.

We also discussed PWM Pins. Learn more about PWM Pins in [this video](https://www.youtube.com/watch?v=s4Tgw_W7Zdg)

### c). Button
The students used a Button with a pull up resistor to turn an LED ON and OFF. 

## 4. Piano
The following were used to teach the students how to use a buzzer to emit noises similar to a piano in different projects.

### a). 5 Button Piano
In this project, the students created a mini-piano using the buzzer and 5 buttons installed on the breadboard. Learn more about this project in [this video](https://www.youtube.com/watch?v=qt-YgZJz8uY)

### b). Auto Piano
In this project, the students set the buzzer up such that it played "Twinkle Twinkle Little Stars" on its own at a tempo that can be changed using the potentiometer. Learn more about this project in [this video](https://www.youtube.com/watch?v=qt-YgZJz8uY)zz

## 5. Metronome
In this project, the students created a metronome. A metronome is used in musical practice as a way to keep the beat, or tempo. An image of a metronome is shown below.

![alt text](https://images.squarespace-cdn.com/content/v1/5a04b91b914e6b6222be0e26/1551373680221-G9ZWBOR9HGR3H1162KW7/Seiko-Quartz-Metronome.jpg?format=400w)

The dial shown on this metronome can be used to change the tempo, the numbers at the edge of the dial. The unit of the tempo is BPM, or beats per minute. For example, 60 BPM, means that the metronome will beep and blink 60 times a minute, or once a second.

The students will use the following components to create the metronome:
* Buzzer: Will be used to emit the beep
* LED: Will be used to blink in sync with with the beep
* OLED: WIll be used to display the BPM
* Potentiometer: WIll be used to change the tempo of the metronome

We created this metronome to mimic the one in the image: therefore the BPM will range from 40 BPM to 208 BPM.

## 6. Ultrasonic Ranger Projects
The following 2 projects were created using the Ultrasonic Ranger. The Ultrasonic Ranger can return a distance in centimeters or inches, and we can do different things with this information.

### a). Range Finder
A range finder is commonly used in golf to determine how far away the hole is. This helps one determine which club to use. The students created a simple range finder using the following parts:
* Ultrasonic Ranger: Returned distance to nearest obstacle
* OLED Display: Prints out this value

### b). Collision Alert
Modernn cars have different ways to detect if the car will be involved in a collision. We will be implmeneting a simple Collision Alert in this program using the Ultrasonic Sensor. We will use the following parts:
* Ultrasonic Ranger: Returns distance to nearest obstacle
* OLED Display: Displays an alert: Clear, Caution, Danger, Critical
* Buzzer: Beeps at certain BPM depending on alert and distance
* LED: Blinks at certain speed depending on alert and distance

