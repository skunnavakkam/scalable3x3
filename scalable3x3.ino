
// For th arrays, change the number in [] to how many items are in the array.

// The array of rows
int rowArray[3] = {33,31,29};

// The array of columns
int columnArray[3] = {27,25,23};

// The number of rows and columns
int numberOfRows = 3;

int numberOfColumns = 3;

// A sample for the format the LED grid takes. The first three digits will light up the first row, the second three will light up the second, etc
int rowValues[9] = {0, 1, 0, 1, 1, 1, 1, 0, 1};

// For each of the letters of the alphabet, this is the nine-digit code for the grid to function
int alphabetGridArray[27][9] = {{0, 1, 0, 1, 1, 1, 1, 0, 1}, {1, 1, 0, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 0, 1, 1, 1}, {1, 1, 0, 1, 0, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 0, 1, 1, 1},{1,1,1,1,1,0,1,0,0},{1,1,0,1,0,1,1,1,1},{1,0,1,1,1,1,1,0,1},{1,1,1,0,1,0,1,1,1},{0,0,1,1,0,1,1,1,1},{1,0,1,1,1,0,1,0,1},{1,0,0,1,0,0,1,1,1},{1,1,1,1,1,1,1,0,1},{1,1,1,1,0,1,1,0,1},{1,1,1,1,0,1,1,1,1},{1,1,1,1,1,1,1,0,0},{1,1,1,1,1,1,0,0,1},{1,1,1,1,0,0,1,0,0},{0,1,1,0,1,0,1,1,0},{1,1,1,0,1,0,0,1,0},{1,0,1,1,0,1,1,1,1},{1,0,1,1,0,1,0,1,0},{1,0,1,1,1,1,1,1,1},{1,0,1,0,1,0,1,0,1},{1,0,1,0,1,0,0,1,0},{1,1,0,0,1,0,0,1,1},{0,0,0,0,0,0,0,0,0}};

// This is all the 26 letters of the alphabet. It is used for some of the alphabet functions.
char alphabet[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
int i;

void setup() {
  // put your setup code here, to run once:

  // goes through the array and turns all the pins off
  for ( i = 0; i <= numberOfRows - 1; i++) {
    // changes the pins to output
    pinMode( rowArray[i], OUTPUT );
    // turns them to low aka off
    digitalWrite(rowArray[i], LOW);
  }

  // does the same but turns the pins on
  for ( i = 0; i <= numberOfColumns - 1; i++) {
    // same as above
    pinMode( columnArray[i], OUTPUT );
    // but this time high turns them on
    digitalWrite(columnArray[i], LOW);
    }
}

void turnOnLEDS(int * rows, int * columns, int * values, int numrow, int numcolumn, float waitTime) {
  int r;
  int c;
  for (r = 0; r <= numrow - 1; r++) {
    digitalWrite(rows[r], HIGH);
    for (c = 0; c <= numcolumn - 1; c++) {
      if (values[c + (r * numcolumn)] == 1) {
        digitalWrite(columns[c], HIGH);
      }
    }
    delay(waitTime);
    digitalWrite(rows[r], LOW);
    for ( c = 0; c <= numcolumn - 1; c++){
      digitalWrite(columns[c], LOW);
    }
    delay(waitTime);
  }
}

int * alphabetToBinaryInput(char inputCharacter) {
  for (i = 0; i<= 26; i++){
    if (alphabet[i] == inputCharacter) {
      return(alphabetGridArray[i]);
  }
}
}

void displayLetters(char * characters, int * rows, int * columns, int numberOfCharacters, int numrow, int numcolumn, int onTime, int offTime) {
  long startTime;
  int v;
  startTime = millis();
  for (v = 0; v <= numberOfCharacters - 1; v++) {
    while ((millis() - startTime) <= onTime) {
      turnOnLEDS(rows, columns, alphabetToBinaryInput(characters[v]), numrow, numcolumn, 3.3); 
      }
    delay(offTime);
    startTime = millis();
    }
  }

void loop() {
  // put your main code here, to run repeatedly:
  char inputArray[6] = {'h','e','l','l','o',' '};

  displayLetters(inputArray, rowArray, columnArray, 6, 3, 3, 1200, 300);
}
