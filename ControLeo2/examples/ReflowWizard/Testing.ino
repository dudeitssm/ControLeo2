// Testing menu
// Called from the main loop
// Allows the user to test the outputs
// Buttons: The bottom button moves to the next output
//          The top button toggles the output on and off

// modified 22 August 2020 for DIY Toner Transfer Etched Copperclad Build
// by dudeitssm (https://github.com/dudeitssm)

// Called when in testing mode
// Return false to exit this mode
boolean Testing() {
  static boolean firstRun = true;
  static boolean channelIsOn = true;
  static int channel = 0; 
  
  // Is this the first time "Testing" has been run?
  if (firstRun) {
    firstRun = false;
    lcdPrintLine_P(0, PSTR("Test Outputs"));
    lcdPrintLine_P(1, PSTR("Output 0"));
    displayOnState(channelIsOn);
  }
  
  // Turn the currently selected channel on, and the others off
  for (int i=0; i<3; i++) {
    if (i == channel && channelIsOn)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
  
  // Was a button pressed?
  switch (getButton()) {
    case CONTROLEO_BUTTON_TOP:
      // Toggle the output on and off
      channelIsOn = !channelIsOn;
      displayOnState(channelIsOn);
      break;
    case CONTROLEO_BUTTON_BOTTOM:
      // Move to the next output
      channel = channel + 1;
      if (channel == 3) {
        // Turn all the outputs off
        for (int i=0; i<3; i++)
          digitalWrite(i, LOW);
        // Initialize variables for the next time through
        firstRun = true;
        channel = 0;
        channelIsOn = true;
        // Return to the main menu
        return false;
      }
      lcd.setCursor(7, 1);
      lcd.print(channel);
      displayOnState(channelIsOn);
      break;
  }
  
  // Stay in this mode;
  return true;
}


void displayOnState(boolean isOn) {
  lcd.setCursor(9, 1);
  lcd.print(isOn? "is on ": "is off");
}
