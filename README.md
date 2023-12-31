# Arduino-Summer-Camp
In the summer of 2023, I conducted a  camp to teach students programming and electronics using Arduino and simple components. The camp focused on making real world applications like a five Key Piano, Automatic Piano, Metronome, Weather Station, Range Finder, Collision Alert and Water Overflow Detection systems using a micro controller board (Arduino Uno R3 in our case), sensors like Ultrasonic Sensor, Water Sensor, Potentiometer, and Temperature and Humidity and audio visual actuators or output devices like LEDs, Piezo Buzzer and OLED Display.

I designed the curriculum for middle to high schoolers with no prior experience in coding or electronics. I selected the components, designed a kit, developed lesson plans and conudcted the camp at Casa de Amistad in San Diego. The students were very engaged and had a fun learning and enriching experience.

<img src="./Images/img1.jpg" height = "120" alt="Camp Image 1" /> <img src="./Images/img2.jpg" height = "120" alt="Camp Image 2" /> <img src="./Images/img3.jpeg" height = "120" alt="Camp Image 3" /><img src="./Images/img4.jpeg" height = "120" alt="Camp Image 4" />

<img src="./Images/img5.jpeg" height = "120" alt="Camp Image 5" /><img src="./Images/img6.jpeg" height = "120" alt="Camp Image 6" /><img src="./Images/img7.jpeg" height = "120" alt="Camp Image 7" /><img src="./Images/img8.jpeg" height = "120" alt="Camp Image 8" />

This repostory contains the Code and Explanation for the projects. 

Learn more about each project on my [youtube channel](https://www.youtube.com/channel/UCszrNeQ_xBV6YQfvcIs6uVA).

## 1. Inventory

| S.No. | Part  | Image  | Vendor        | Quantity |
|:-----:|:-----:|:------:|:-------------:|:----:|
| 1.    | Aruino Uno R3 | <img src="./Images/ArduinoUnoR3.jpg" height="120" alt="Image of Arduino Uno R3" /> | RobotShop | 1 | 
| 2.    | Grove Base Shield | <img src="./Images/Grove BS.jpg" height = "120" alt="Image of Grove Base Shield" /> | Seeed Studio | 1 | 
| 3.    | Acrylic 8''x10'' sheet |<img src="./Images/Acrylic.jpg" height = "60" alt="Image of Acrylic Sheet" /> | Amazon | 1 | 
| 4.    | Acrylic 3.5''x2'' panel |<img src="./Images/Acry2.png" height = "60" alt="Image of Acrylic Panel" /> | Amazon | 1 | 
| 5.    | Vinyl Sticker Paper |<img src="./Images/Vinyl.png" height = "60" alt="Image of Vinyl Sticker" />| Amazon | 2 | 
| 6.    | Mini Lamp & Holder|<img src="./Images/MiniBulb.png" height = "60" alt="Image of Mini Bulb" />| Amazon | 1 | 
| 7.    | 3V AA Battery Holder with Knife Switch |<img src="./Images/BatteryHolder.png" height = "60" alt="Image of Battery Holder" />| Adafruit | 1 | 
| 8.    | Grove Yellow Blue OLED Display |<img src="./Images/Grove_Display.png" height = "60" alt="Image of Grove OLED Display" /> | Seeed Studio | 1 |
| 9.    | Grove LED | <img src="./Images/Grove_LED.png" height = "60" alt="Image of Grove LED" /> | Seeed Studio | 1 |
| 10.    | Grove Buzzer | <img src="./Images/Grove_PB.png" height = "60" alt="Image of Grove Piezo Buzzer" />  | Seeed Studio | 1 |
| 11.   | Grove Rotary Sensor | <img src="./Images/Grove_POT.png" height = "60" alt="Image of Grove POT" /> | Seeed Studio | 1 |
| 12.   | Grove Temperature & Humidity Sensor |  <img src="./Images/Grove_TH.png" height = "60" alt="Image of Grove DHT11" /> | Seeed Studio | 1 |
| 13.   | Grove Ultrasonic Sensor |  <img src="./Images/Grove_US.png" height = "60" alt="Image of Grove US" /> | Seeed Studio | 1 |
| 14    | Grove Water Sensor | <img src="./Images/Grove_WS.png" height = "60" alt="Image of Grove Water Sensor" />  | Seeed Studio | 1 |
| 15.   | Grove Cables | <img src="./Images/Grove Cables.png" height = "60" alt="Image of L Brackets" /> | Seeed Studio | 7 |
| 16.   | Gikfun Buttons | <img src="./Images/Button.png" height = "60" alt="Image of Button" /> | Amazon | 5 |
| 17.   | IR Receiver | <img src="./Images/IR_Receiver.png" height = "60" alt="Image of IR Receiver" /> | Adafruit | 1 |
| 18.   | Jumper Cables | <img src="./Images/M2MCables.png" height = "60" alt="Image of Jumper Cables" /> | Adafruit | 12 |
| 19.   | 10k Ohm Resistors | <img src="./Images/R10.png" height = "60" alt="Image of 10K Resistor" /> | RobotShop | 5 |
| 20.   | 330 Ohm Resistors | <img src="./Images/R330.png" height = "60" alt="Image of 330 Resistor" /> | RobotShop | 1 |
| 21.   | M2 F2M Spacer 15mm | <img src="./Images/M2F2M15.png" height = "60" alt="Image of 15mm Spacer" /> | Amazon | 9 |
| 22.   | 9V Battery w/ Barrel Jack | <img src="./Images/9VBNJ.png" height = "60" alt="Image of 9V Battery w/ Jack" /> | RobotShop | 1 |
| 23.   | M2.5 Hex Nut | <img src="./Images/M25.png" height = "60" alt="Image of M2.5 Hex Nut" /> | Amazon | 13 |
| 24.   | M2.5 F2M Spacer 6mm | <img src="./Images/M25 F2M 6.png" height = "60" alt="Image of M2.5 6mm Spacer" /> | Amazon | 7 |
| 25.   | M2.5 6mm Screws | <img src="./Images/M2.5 Screws.png" height = "60" alt="Image of M2.5 Screws" /> | Amazon | 7 |
| 26.   | M2.5 F2M Spacers 25mm | <img src="./Images/M25 F2M 25.png" height = "60" alt="Image of M2.5 25mm Spacer" /> | Amazon | 6 |
| 27.   | M2 6mm Screws | <img src="./Images/M2 5 Screws.png" height = "60" alt="Image of M2 6mm Screws" /> | Amazon | 14 |
| 28.   | M2 F2M Spacers 5mm | <img src="./Images/M2 5 Spacers.png" height = "60" alt="Image of M2 5mm Spacers" /> | Amazon | 5 |
| 29.   | M2 Hex Nut | <img src="./Images/M2 Nuts.png" height = "60" alt="Image of M2 Hex Nuts" /> | Amazon | 14 |
| 30.   | Zip Ties | <img src="./Images/zip ties.png" height = "60" alt="Image of Zip Ties" /> | Amazon | 2 |
| 31.   | L Brackets | <img src="./Images/LShape.jpg" height = "60" alt="Image of L Brackets" /> | Amazon | 2 |
| 32.   | Small Funnel | <img src="./Images/Funnel.png" height = "60" alt="Image of Funnel" /> | Amazon | 1 |
| 33.   | Water Reservoir | <img src="./Images/Water_Reservoir.jpg" height = "60" alt="Image of Water Reservoir" /> | Supplies Store | 1 |
| 34.   | Kit Pack | <img src="./Images/Kit Pack.png" height = "60" alt="Image of Kit Pack" /> | Supplies Store | 1 |

Notes:
1. The Grove components came with the Grove Cables (4 wire cable - red for vcc, black for ground, yellow for signal, white for signal or no connection).
2. An inkject Epson printer was used for printing on the Vinyl Stickers to scale at 200 dpi
3. Fiskars cutting tool was used to cut the printed vinyl sticker precisely
4. A drill with 2mm, 2.4mm, 2.9 mm and 5.4 mm drill bits was used to make holes in the Acrylic
5. A soldering iron was used to make slots and holes in the platic water reservoir
6. All components were collated in a plastic container to hand to each student



## 2. Board Creation
It was important to have all components assembled together so students had an organized workspace and could appreciate what is involved in making real applications and not just a quick demo. For this, I designed a layout in python (Arduino Project Layout.py) of a 8x10 inchees acrylic board. It was printed on vinyl sticker and then pasted on acrylic sheets.

Below are images of a printed layout. This allowed easy drilling of holes. A 3.5in x 2.5 in acrylic panel was used for the installing the Ultrasonic Sensor.

<img src="./Images/USLayout1.jpg" width="240" alt="Image of US Board Layout" /> <img src="./Images/ArduinoLayout.jpg" width="480" alt="Image of Acrylic Board Layout" /> 

The Acrylic Board housed all the componenets:
* Arduino Uno R3
* Grove Base Shield
* Breadboard
* Lamp
* 9V Battery
* Grove Potentiometer
* Grove Temperature & Humidity Sensor (DHT11)
* Grove LED
* Grove Buzzer
* Grove OLED Display
* Grove Ultrasonic Ranger
* Grove Water Sensor

The Aruino Uno R3 is attached to the board using M2.5+6 5mm standoffs or spacers and M2.5 screws and nuts. The breadboard is pasted on the board. 

The water sensor was installed on a plastic water reservoir. Using a soldering iron on a plastic box with lid, I cut out a slot for water sensor and a hole for a funnel to add water. 

Ultrasonic sensor was installled on the small panel using M2.5+6 5mm standoffs, screws and nuts. This small pannel was connected to the mainboard using L shaped brackets with M3 screws and nuts.

Other sensors (POT, DHT11 sensors) were connected using M2+6 5mm standoffs and screws.  The actuators (OLED display, LED, Buzzer) were connected using M2+6 10mm standoffs. The acrylic board used a stand made from M2.5+6 25mm standoffs and nuts.

The 9V battery is secured using 2 zip ties.

<img src="./Images/Acrylic_Board.jpg" alt="Image of Acrylic Board" />

## 3. Basic Circuits
I started the camp by teaching the students circuit basics starting with a lamp, battery and switch. We installed a Lamp and used a 3V battery holder with switch to turn the Lamp on and off.

Then we went through how to use a breadboard to assemnle circuits
* Turning ON and LED on the Breadboard
* Using a potentiometer to change the brightness of the LED
* Using a button to turn the LED ON and OFF

Learn more about these basics in [this video](https://www.youtube.com/watch?v=bQS-vkHR7F8&)

## 3. Basic Circuits with Arduino
We started with a discussion of how the Arduino works and the parts of the Arduino such as the ATMega 328P Chip, Digital Headers, Analog Headerrs, Power Headers, USB Socket, Power Jack, the Printed Circuit Board (PCB) and more. 

After installing the Arduino IDE, we looked at basic Arduino ciruits and small programs for sensors and actuators.

I also provided an [Arduino Function Cheatsheet](https://docs.google.com/document/d/1QYzo4wBym-xJpfdnLt6h2N2m4J6qdlCz4fPCTWNhXuQ/edit?usp=sharing) to help the students out with programming.

### a). Blink
The students created a program to blink the LED ON and OFF. The students learned about the following functions:
* setup(): Called when the program first starts. “Setup” variables, pin modes, libraries, etc. This function only runs once.
* loop(): Occurs after setup function. Code inside here will run forever.
* pinMode(pin, mode): Used to specify if the pin is an INPUT or OUTPUT (for example, we take __input__ from a potentiometer, but send __outputs__ to an LED).
* digitalWrite(pin, value): Writes a HIGH or LOW value to a digital pin.
* delay(ms): Wait for amount of milliseconds specified (Note: tone function runs concurrently).

### b). POT
The students learned how to control and LED using a Potentiometer. The students learned about the following new functions:
* analogRead(pin): Read the value of analog pin (A0, A1, etc.). Value will be from 0-1023
* analogWrite(pin, value): Writes an analog value to a pin. This value should be between 0 and 255.

We also discussed PWM Pins. Learn more about PWM Pins in [this video](https://www.youtube.com/watch?v=s4Tgw_W7Zdg).

### c). Button
The students used a Button with a pull up resistor to turn an LED ON and OFF. 


## 4. Grove Base Shield and Grove Components

A Grove Base Shield and Grove Components were used for the rest of the camp. This ensured faster, error free circuit assembly to allow the students to focus on applications and programming.

The Grove Shield is mounted on top of the Arduino UNO R3 and Grove components are connected to the shield through Digitial, Analog and I2C ports through a 4 wire Grove Cable. There is no need to worry about power, ground, pull up resistors etc.

The Grove Shield also exposes the Arduino Headers allowing the buttons to be connected in a traditional manner on a breadboard.

### a). Actuators or Output Devices:
The micro-controller uses these to initiate specific actions e.g. display something, alter the state of LED or emit a tone.

### b). Sensors or Input Devices:
The micro controller uses these to gets inputs from the user or environment e.g. POT angle,  temperature, humidity, level sensor is submerged in water and distance to an obstacle. Based on these inputs, the micro controller can be programmed to send outputs to actuators.

### c) Circuit Diagram for all the components

The circuit diagram shows how the various components are connected. The Buttons and IR receiver are connected using the Header Pins of the Grove Shield on the breadboard and the corresponding PINs are shown.

The Grove components are connected to the Grove Shield Ports which are shown in the circuit diagram:

<img src="./Images/Circuit_Diagram.jpg" alt="Image of Circuit Diagram" /> 

## 5. Operating the Sensors and Actuators
Before we can use the sensors and actuators to make interesting real world applications, we need to get them working with the relevant libraries and test each component's individual functionality.

### a). Buzzer
The tone() function is used to emit a tone of specifc frequency for a specifc length of time. Note that delay() runs concurrently with tone() and so, we need to choose the time with tone() and delay() appropriate.

Learn more on how to program the buzzer in [this video](https://www.youtube.com/watch?v=_wdFPNxMD30).
The code is in [Buzzer.ino](src/Buzzer.ino).

### b). OLED Display
For the OLED display, we will use the u8g2 library to display text and graphics using the I2C interface. Learn how to display glyphs in [this video](https://www.youtube.com/watch?v=BqO59RuiGiI). The code is in [OLED.ino](src/OLED.ino)

### c). POT
The POT values are ready using analogRead(). Arduino has a 10 bit ADC and so the values range from 0-1023. The values read from the POT can be for exmample used to control the brigtness of a LED. This is done through analogWrite(). Arduino simulates analog through dutycyling on PWM Pins.
Learn more about how to use a Potentiometer with the Arduino in [this video](https://www.youtube.com/watch?v=eoUUbpLZECs) until timestamp 7:41. The code can be found in [Pot.ino](src/Pot.ino).

### d). DHT 11 Temperature & Humidity Sensor
We use the Adafruit DHT11 library to read temperature and humidity values from the DHT11 sensor. A quick way to test the functionality of the sensor is to see the values returned on the serial monitor.

Learn more about how to program the DHT11 sensor in [this video](https://www.youtube.com/watch?v=50Wbibqyy_c). The code is in [THSensor.ino](src/THSensor.ino).

### e). Ultrasonic Sensor
An ultrasonic sensor measures the distance to obsatcle by using the round trip time of a sound wave traveling to the obstacle and its echo coming back to the sensor. For this sensor, we use the Grove Range Finder library.

Learn more about how to program the Ultrasonic sensor in [this video](https://www.youtube.com/watch?v=XCEobsngXzM). The code can be found in [Ultrasonic_Sensor.ino](src/Ultrasonic_Sensor.ino).

### f). Water Sensor
The resistance of the water sensor changes when it has water on it. We use the sensor on Anlog interface and using analogRead() get a sense of how much of the sensor is submerged in water. Note that the salinity of the water affects the resistance read on the water sensor.

Learn more about how to program the Water sensor in [this video](https://www.youtube.com/watch?v=VwHm7wLcO_w). The code is in [Water.ino](src/Water.ino).


## 6. Piano
Now that we know how to program and read inputs from sensors and output to actuators, we are ready to make some reak world interesting applications. The first is how we can use the Buzzer to play keys of a piano.

### a). Five Key Piano
In this project, the students created a mini, portable piano. The following components were used in the project:
* 5 Buttons: Connected on the breadboard, each button will represent a key on the piano, ranging from Middle C (256 Hz frequency) to G (~392 Hz frequency)
* Buzzer: Will be used to emit toness of said frequencies

Learn more about this project in [this video](https://www.youtube.com/watch?v=8YZ9XIKRaRU&). The code for the 5 Key Piano is in [Piano.ino](src/Piano.ino).


### b). Auto Piano
In this project, the students set up their board such that it played can play of tune (in this case, "Twinkle Twinkle Little Stars"). The components we use are:
* Buzzer: Will emit the frequencies that represent notes from Middle C to A
* Potentiometer: The students will use this to change the tempo (more on that in the next section) of the piece
* OLED Display: Will display the tempo selected of the piece

Note: Changing the tempo in the middle of the piece will automatically restart the piece.

Learn more about this project in [this video](https://www.youtube.com/watch?v=-I5X-YtkoWw&). The code is in [Auto_Piano2.ino](src/Auto_Piano2.ino).


## 7. Metronome
In this project, the students created a metronome. A metronome is used in musical practice as a way to keep the beat, or tempo. An image of a metronome is shown below.

<img src="./Images/Metronome.jpg" height="120" alt="Image of Metronome" /> 

The dial shown on this metronome can be used to change the tempo, the numbers at the edge of the dial. The unit of the tempo is BPM, or beats per minute. For example, 60 BPM, means that the metronome will beep and blink 60 times a minute, or once a second.

The students used the following components to create the metronome:
* Buzzer: Will be used to emit the beep
* LED: Will be used to blink in sync with with the beep
* OLED: Will be used to display the BPM
* Potentiometer: Will be used to change the tempo of the metronome

We created this metronome to mimic the one in the image: therefore the BPM will range from 40 BPM to 208 BPM.

Learn more about this project in [this video](https://www.youtube.com/watch?v=qt-YgZJz8uY). The code is in [Metronome.ino](src/Metronome.ino).

## 8. Ultrasonic Ranger Projects
The following 2 projects were created using the Ultrasonic Ranger. The Ultrasonic Ranger can return a distance in centimeters or inches, and we can do different things with this information.

### a). Range Finder
A range finder is commonly used in golf to determine how far away the hole is. This helps one determine which club to use. The students created a simple range finder using the following parts:
* Ultrasonic Ranger: Returned distance to nearest obstacle
* OLED Display: Prints out this value

Learn more about this project in [this video](https://www.youtube.com/watch?v=FXLg-NOD_yA). The code can be found in [RangeFinder.ino](src/RangeFinder.ino).

### b). Collision Alert
Modern cars have different ways to detect if the car is approaching an obstacle. We will be implmeneting a simple Collision Alert in this program using the Ultrasonic Sensor. We will use the following parts:
* Ultrasonic Ranger: Returns distance to nearest obstacle
* OLED Display: Displays an alert: Clear, Caution, Danger, Critical
* Buzzer: Beeps at certain BPM depending on alert and distance
* LED: Blinks at certain speed depending on alert and distance

Learn more about this project in [this video](https://www.youtube.com/watch?v=lpBptqLrOXk). The code is in [CollisionAlert.ino](src/CollisionAlert.ino).

## 9. Weather Station
We will use the following components:
* Grove Temperature and Humidity Sensor: Will read out the temperature and humidity using the DHT 11 Sensor installed
* OLED Display: Will print out the temperature and humidity given from the TH Sensor
This acts as a simple thermostat - there many different applications to this! Notice how after runnign this code, putting your finger on the sensor will increase the temperature and humidity.

Learn more about this project in [this video](https://www.youtube.com/watch?v=xR2um3CB-e0&). The Weather Station can be found in [WeatherStation2.ino](src/WeatherStation2.ino).

## 10. Water Overflow Detector
Our final propject before we put everything together will be a Water Overflow Detector. For this project, I devised a container with a lid such that the Water Sensor can easily fit in the slot, and a funnel can be placed in the circular hole to increase the water level. 

The components used in this project are as follow:
* Water Sensor: Returns the level of water touching the sensor
* OLED Display: Displays either Clear, Caution, Danger, or Critical
* Buzzer: Beeps at different frequencies depending on the water level
* LED: Blinks at different frequencies depending on the water level
* Water Reservoir with slot for water sensor and a hole for funnel for pouring in water

Learn more about this project in [this video](https://www.youtube.com/watch?v=SfWMD1pfpyw&). This code is in [WaterOverflow.ino](src/WaterOverflow.ino)


## 11. Final Project 
In the final project, the students combined all the previous project code into one final script. This was implemented such that even if the students do not have access to the code in the future, they can still run all their projects on the boards, since the Arduino will automatically run the last project that was loaded onto the Arduino once connected to power (hence why we initally installed the 9V battery on the board, allowing the students to power on the Arduino whenever they wish). 

This project cycles through each of the projects one at a time when the user presses the red and black buttons simulatenously. This was a good project to learn switch case constructs.

Learn more about this project in [this video](https://www.youtube.com/watch?v=z6CdSy7QxXw&). The Final Project code can be found in [FinalProject.ino](src/FinalProject.ino).
