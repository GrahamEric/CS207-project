/*
 * This sketch is used to calibrate the galvanised nails. Each
 * time that the nails are moved or placed into a new pot, they
 * will need to be recalibrated. It is up to you how far you place your
 * nails, but it is advised to place them about five to six cm away
 * from each other for a small indoor potted plant.
 * 
 * This process is done by reading the analog inputs while water
 * is being added to the pot with the nails in it. I typically add 
 * about 10mL every five seconds. We can assume that completely dry soil
 * reads 0 since there is complete resistance. As water is added, the 
 * resistance reduces. The maximum is 1023 as an analog reading.
 * 
 * The ideal moisture level for each plant is dependent on the its
 * environment, but I have found that, for a small sized indoor plant,
 * the moisture level should be around: FILL THIS IN
 * 
 * What is essential in calibrating this, is the excel sheet that 
 * plots Arduino data called PLX-DAQ. It can be found here:
 * https://www.parallax.com/downloads/plx-daq
 */

int moistureIn =  A0;   // connect one of the nails to A0 + ground with a 10K resistor
                        // and the other to +5V
int moistureValue;

void setup() {

 Serial.begin(9600);
 Serial.println("LABEL,Time,Moisture"); // for PLX-DAQ
                                        // these are the headings for the columns

}

void loop() {

 moistureValue = analogRead(moistureIn);  // reading the input from the nails

 Serial.print("DATA,TIME,");    // for PLX-DAQ: sets the first columns as the time of the reading

 Serial.print(moistureValue); // printing the reading to the moisture column

 Serial.println();  // going to the next row in the Excel sheet
 delay(5000);   // reading every five seconds in order to give enough time between 
                // adding the water 
 
}
