
int moistureIn =  A0; // global variables for the moisture and temp senors inputs
int tempIn =      A1;
int moistureValue;
int row = 0;

void setup() {
  
  Serial.begin(9600);       //beging the serial port for communication
  Serial.println("LABEL,Time,Moisture,Temperature");

  Serial.println("CLEARDATA");  // this clears any data left over from the previous day
  Serial.println("RESETTIMER"); // resets the timer between each reading

}

void loop() {

 int moistureValue = analogRead(moistureIn);  //creating the value variable by reading the measured difference
 int tempReading = analogRead(tempIn); //creating the value variable by reading what the temperature sensor is reading
 float tempCels;

 tempCels = AnalogToVolts(tempReading); //calling the function that converts the analog reading to volts (same exact thing from the lab)

 Serial.print("DATA,TIME,");  // this prints out the columns headers for the monitoring program
                              // the Time is placed in column A
   
 Serial.print(moistureValue); // displaying what the level of moisture is to column B
 Serial.print(",");           // acts as a separator so the program knows to go to the next column
 Serial.print(tempCels);      // same thing, but displaying the temperature in column C
 
 Serial.println(); // telling the program to go to the next row in the Excel sheet
 //delay(10); // used for testing purposees
 delay(3600000);      //delaying for a half hour
                  // a half hour provides enough spacing throughout the day since any less
                  // becomes overwhelming; could set it to every hour or even more,
                  // but I personally like to have this much data being produced evey day
 newDay();
 
}   

float AnalogToVolts(int tempReading)
{
  
  float tempVolts;          //declaring the variables that are used for the conversion equation
  float tempCels;
  
  tempVolts = tempReading/1023.0 * 5.0;
  tempCels = tempVolts * 100 - 50;    // performs the conversion from volts to Celsius that was listed in our lab
 
  return tempCels;

}

void newDay(){
  
 row++;     // increasing the row number 1 each time it outputs a reading

 if(row >= 64){                   // Since it is reading every half hour, once it reads 64, that is an entire
    row = 0;                      // day. The sheet then goes back to the second row (the first row below the
    Serial.println("ROW,SET,2");  // headers) and replaces that data with new readings
 
 }      
}

void tempCheck(){   // this prototype will inform the user if the temperature is too low or
                    // or too high 
                    // I used this for when readings were displayed on the serial monitor.
                    // Right now, it doesn't communicate with PLX-DAQ, but has potential for 
                    // the future to read out this info
  if(tempIn < 20.00){
    Serial.print("TEMPERATURE TOO LOW: INCREASE TEMPERATURE");
  }

  if(tempIn > 21.50){
    Serial.print("TEMPERATURE TOO HIGH: DECREASE TEMPERATURE");
  }
}

