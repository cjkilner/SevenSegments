int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 8;
int g = 9;

int pins[7] = {a,b,c,d,e,f,g};

void setup(){
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT); 
}

void loop(){
  for(int i=0; i < 16; i++){
    writeNumber(i);
    delay(500);  
  }
}

void turnOn(){
  writeSegments(new int[7]{1,1,1,1,1,1,1});
}

void turnOff(){
  writeSegments(new int[7]{0,0,0,0,0,0,0});
}

//Format: {a,b,c,d,e,f,g}
void writeSegments(int segments[7]){
  for(int i=0; i < 7; i++){
    digitalWrite(pins[i], segments[i]);
  }  
}

/* Seven Segment Mapping
   +---F---+
   |       |
   A       G
   |       |
   +---B---+
   |       |
   E       C
   |       |
   +---D---+
*/
void writeNumber(int Number){
  switch(Number){
    case 0:
      writeSegments(new int[7]{1,0,1,1,1,1,1});
    break;
    case 1:
      writeSegments(new int[7]{0,0,1,0,0,0,1});
    break;
    case 2:
      writeSegments(new int[7]{0,1,0,1,1,1,1});
    break;
    case 3:
      writeSegments(new int[7]{0,1,1,1,0,1,1});
    break;
    case 4:
      writeSegments(new int[7]{1,1,1,0,0,0,1});
    break;
    case 5:
      writeSegments(new int[7]{1,1,1,1,0,1,0});
    break;
    case 6:
      writeSegments(new int[7]{1,1,1,1,1,1,0});
    break;
    case 7:
      writeSegments(new int[7]{0,0,1,0,0,1,1});
    break;
    case 8:
      writeSegments(new int[7]{1,1,1,1,1,1,1});
    break;
    case 9:
      writeSegments(new int[7]{1,1,1,0,0,1,1});
    break;
    case 10: //A
      writeSegments(new int[7]{1,1,1,0,1,1,1});
    break;
    case 11: //B
      writeSegments(new int[7]{1,1,1,1,1,0,0});
    break;
    case 12: //C
      writeSegments(new int[7]{1,0,0,1,1,1,0});
    break;
    case 13: //D
      writeSegments(new int[7]{0,1,1,1,1,0,1});
    break;
    case 14: //E
      writeSegments(new int[7]{1,1,0,1,1,1,0});
    break;
    case 15: //F
      writeSegments(new int[7]{1,1,0,0,1,1,0});
    break;
    default:
      writeSegments(new int[7]{0,0,0,0,0,0,0});
    break;  
  }
  
}

void turnOn(int pin){
  digitalWrite(pin, HIGH);  
}

void turnOff(int pin){
  digitalWrite(pin, LOW);
}




