int led1 = D0; // Instead of writing D0 over and over again, we'll write led1
int lastType = -1;
const int single_unit = 150;

void setup() 
{

  pinMode(led1, OUTPUT);

}

void dot()
{
    digitalWrite(led1, HIGH);
    delay(single_unit);
    digitalWrite(led1, LOW);
}

void dash()
{
    digitalWrite(led1, HIGH);
    delay(single_unit * 3);
    digitalWrite(led1, LOW);
}

void endCharacter()
{
    lastType = 2;
    endSegment();
}

void endWord()
{
    lastType = 3;
    endSegment();
}

void endSegment()
{
    switch(lastType)
    {
        case 1: //segment
            delay(single_unit);
            break;
        case 2: //character
            delay(single_unit * 3);
        case 3: //word
            delay(single_unit * 7);
            break;
        default:
            delay(single_unit);
    }
    lastType = 1;
}

void loop() 
{
    //a
    dot();
    endSegment();
    dash();
    endCharacter();
    
    //s
    dot();
    endSegment();
    dot();
    endSegment();
    dot();
    endCharacter();
    
    //h
    dot();
    endSegment();
    dot();
    endSegment();
    dot();
    endSegment();
    dot();
    endWord();
}

