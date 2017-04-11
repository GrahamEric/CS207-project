# CS207-project
The repo for my CS207 class' project.

Ever wanted your plant to talk to you?

This project is great for someone new to microcontrollers, specifically Arduino, and also likes to garden. 

The main point of this project is to create a moisture and temperature sensor to monitor and inform the user about their plant's
condition. The two nails act as moisture sensor by evaluating the current that is able to pass through the soil; more moisture in the 
soil leads to less resistance and less moisture leads to more resistance.

The steps listed below are meant to be followed in the specified order. 

Requirements:
  Arduino Uno
  PC
  Indoor house plant
  Two galvanised nails
  Breadboard
  Wires
  10K resistor
  Temperature Sensor
 
Building the circuitry
  Steps:
    Tape wires to the two nails
    Place the nails in the pot of your plant about five or six centimetres apart
    Attach the other end of the wire of the first nail to +5V on the Arduino Uno
    Attach the other end of the wire of the second nail to A0 on the Uno and ground that connection with a 10K resistor
    Attach the temperature sensor to +5V, ground, and input A1 on the Uno

Calibrating the moisture sensor:
  Each time that the nails are moved or are newly placed, they must be calibrated.
    Steps: 
     view moistureCalibration.ino
     
The data:
  The monitored temperature and moisture levels will be recorded in an Excel sheet. The Excel sheet is meant to be constantly running 
  and evaluating your plant. The data is collected and plotted in real time on the sheet. 
  
  Everyday at 17:00 the Excel sheet will email you the graph for that day. The user can then evaluate the graph and determine if their 
  plant needs to be watered or to change the temperature in the environment. You will have to change the email listed in the code:
    Steps:
       Module2.vb contains the macro for emailing the code to the user
       Change line 25 to your desired email
       
 Now you should be able to have a plant that will check up with you and lets you know if it needs water :)
