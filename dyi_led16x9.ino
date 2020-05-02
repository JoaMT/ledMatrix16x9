//Jesus Ortega Abad
//2019.11.23

const int latch=7;  //74HC595  pin 9 STCP       10
const int clock=8; //74HC595  pin 10 SHCP       11
const int data=6;   //74HC595  pin 8 DS          9
const int sinlge=3;  // Aditional Single Row Pin 8

const unsigned char lineScan[]=
{0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

const int fpsDelay=35; // frame duration 350=1s

const unsigned char animacionOnda[55][8] PROGMEM = {
    { B00000000,B00000000,B00000000,B00000000,B00000001,B00000000,B00000000,B00000000},//
    { B00000000,B00000000,B00000000,B00000000,B00000011,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B00000111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B00001111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B00011111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B00111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B01111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B01111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000001,B11111110,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000010,B11111101,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000100,B11111010,B00000001,B00000001,B00000000},
    { B00000000,B00000000,B00000000,B00001000,B11110100,B00000010,B00000011,B00000000},
    { B00000000,B00000000,B00000000,B00010000,B11101001,B00000101,B00000110,B00000000},
    { B00000000,B00000000,B00000001,B00100001,B11010010,B00001010,B00001100,B00000000},
    { B00000001,B00000001,B00000010,B01000010,B10100100,B00010100,B00011000,B00000000},
    { B00000010,B00000010,B00000101,B10000101,B01001000,B00101000,B00110000,B00000000},
    { B00000100,B00000100,B00001010,B00001010,B10010001,B01010001,B01100000,B00000000},
    { B00001000,B00001000,B00010100,B00010100,B00100010,B10100010,B11000001,B00000001},
    { B00010000,B00010000,B00101000,B00101000,B01000101,B01000101,B10000010,B00000010},
    { B00100000,B00100000,B01010000,B01010001,B10001010,B10001010,B00000100,B00000100},
    { B01000000,B01000000,B10100001,B10100010,B00010100,B00010100,B00001000,B00001000},
    { B10000000,B10000000,B01000010,B01000101,B00101000,B00101000,B00010000,B00010000},
    { B00000000,B00000000,B10000100,B10001010,B01010001,B01010000,B00100000,B00100000},
    { B00000000,B00000000,B00001000,B00010101,B10100010,B10100000,B01000000,B01000000},
    { B00000000,B00000000,B00010000,B00101010,B01000101,B01000000,B10000000,B00000000},
    { B00000000,B00000000,B00100000,B01010100,B10001011,B10000000,B00000000,B00000000},
    { B00000000,B00000000,B01000000,B10101000,B00010111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B10000000,B01010000,B00101111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B10000000,B10100000,B01011111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B01000000,B10111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B10000000,B01111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B01111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111110,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111100,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11111000,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11110000,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11100000,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B11000000,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B10000000,B00000000,B00000000,B00000000},
    { B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000},
};

const unsigned char animacionBarrotes[15][8] PROGMEM = {   
    { B01010101,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10101010},//
    { B01010101,B01010101,B00000000,B00000000,B00000000,B00000000,B10101010,B10101010},
    { B01010101,B01010101,B01010101,B00000000,B00000000,B10101010,B10101010,B10101010},
    { B01010101,B01010101,B01010101,B01010101,B10101010,B10101010,B10101010,B10101010},
    { B01010101,B01010101,B01010101,B11111111,B11111111,B10101010,B10101010,B10101010},
    { B01010101,B01010101,B11111111,B11111111,B11111111,B11111111,B10101010,B10101010},
    { B01010101,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B10101010},
    { B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111},
    { B10101010,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B01010101},
    { B10101010,B10101010,B11111111,B11111111,B11111111,B11111111,B01010101,B01010101},
    { B10101010,B10101010,B10101010,B11111111,B11111111,B01010101,B01010101,B01010101},
    { B10101010,B10101010,B10101010,B10101010,B01010101,B01010101,B01010101,B01010101},
    { B10101010,B10101010,B10101010,B00000000,B00000000,B01010101,B01010101,B01010101},
    { B10101010,B10101010,B00000000,B00000000,B00000000,B00000000,B01010101,B01010101},
    { B10101010,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01010101},
};

const unsigned char animacionHelice[10][8] PROGMEM = {
    { B10000001,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10000001},
    { B01000010,B11000011,B00000000,B00000000,B00000000,B00000000,B11000011,B01000010},
    { B00100100,B00100100,B11100111,B00000000,B00000000,B11100111,B00100100,B00100100},
    { B00011000,B00011000,B00011000,B11111111,B11111111,B00011000,B00011000,B00011000},
    { B00110000,B00110000,B00011011,B00111111,B11111100,B11011000,B00001100,B00001100},//
    { B00100000,B01110010,B00011011,B00111110,B01111100,B11011000,B01001110,B00000100},
    { B00000010,B11110110,B01110110,B00011110,B01111000,B01101110,B01101111,B01000000},
    { B00000110,B11100110,B11110110,B00011100,B00111000,B01101111,B01100111,B01100000},
    { B00001100,B00001100,B11101100,B11111000,B00011111,B00110111,B00110000,B00110000},
    { B00011000,B00011000,B00011000,B11111111,B11111111,B00011000,B00011000,B00011000},//
};

const unsigned char animacionOlas[12][8] PROGMEM = {
    { B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B11111111},
    { B00000000,B00000000,B00000000,B00000000,B00000000,B10000001,B11000011,B11111111},
    { B00000000,B00000000,B00000000,B10000001,B10000001,B11000011,B11100111,B11111111},
    { B00000000,B10000001,B10000001,B11000011,B11100111,B11111111,B11111111,B11111111},
    { B10000001,B10000001,B11000011,B11111111,B11111111,B11111111,B11111111,B11111111},
    { B00000000,B10000001,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111},
    { B00000000,B00011000,B01111110,B11111111,B11111111,B11111111,B11111111,B11111111},
    { B00000000,B00000000,B00111100,B01111110,B01111110,B11111111,B11111111,B11111111},
    { B00000000,B00000000,B00000000,B00000000,B00111100,B01111110,B11111111,B11111111},
    { B00000000,B00000000,B00000000,B00000000,B00000000,B00011000,B00111100,B11111111},
    { B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011000,B11111111},
    { B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10101010},
};

const unsigned char animacionLlenaEsquinas[31][8] PROGMEM = {
    { B10000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000},
    { B11000000,B11000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000},
    { B11100000,B11100000,B11100000,B00000000,B00000000,B00000000,B00000000,B00000000},
    { B11110000,B11110000,B11110000,B11110000,B00000000,B00000000,B00000000,B00000000},
    { B11111000,B11111000,B11111000,B11111000,B11111000,B00000000,B00000000,B00000000},
    { B11111100,B11111100,B11111100,B11111100,B11111100,B11111100,B00000000,B00000000},
    { B11111110,B11111110,B11111110,B11111110,B11111110,B11111110,B11111110,B00000000},
    { B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111},
    { B01111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111},
    { B00111111,B00111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111},
    { B00011111,B00011111,B00011111,B11111111,B11111111,B11111111,B11111111,B11111111},
    { B00001111,B00001111,B00001111,B00001111,B11111111,B11111111,B11111111,B11111111},
    { B00000111,B00000111,B00000111,B00000111,B00000111,B11111111,B11111111,B11111111},
    { B00000011,B00000011,B00000011,B00000011,B00000011,B00000011,B11111111,B11111111},
    { B00000001,B00000001,B00000001,B00000001,B00000001,B00000001,B00000001,B11111111},
    { B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000},
    { B00000001,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000},
    { B00000011,B00000011,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000},
    { B00000111,B00000111,B00000111,B00000000,B00000000,B00000000,B00000000,B00000000},
    { B00001111,B00001111,B00001111,B00001111,B00000000,B00000000,B00000000,B00000000},
    { B00011111,B00011111,B00011111,B00011111,B00011111,B00000000,B00000000,B00000000},
    { B00111111,B00111111,B00111111,B00111111,B00111111,B00111111,B00000000,B00000000},
    { B01111111,B01111111,B01111111,B01111111,B01111111,B01111111,B01111111,B00000000},
    { B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111},
    { B11111110,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111},
    { B11111100,B11111100,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111},
    { B11111000,B11111000,B11111000,B11111111,B11111111,B11111111,B11111111,B11111111},
    { B11110000,B11110000,B11110000,B11110000,B11111111,B11111111,B11111111,B11111111},
    { B11100000,B11100000,B11100000,B11100000,B11100000,B11111111,B11111111,B11111111},
    { B11000000,B11000000,B11000000,B11000000,B11000000,B11000000,B11111111,B11111111},
    { B10000000,B10000000,B10000000,B10000000,B10000000,B10000000,B10000000,B11111111},
};

const unsigned char animacionGepeto[4][8] PROGMEM = {
    {0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x20, 0xc0},
    {0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x20, 0xc0},
    {0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x04, 0x03},
    {0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x04, 0x03},
};

const byte tetris[7][4][4] PROGMEM = {
   {  // cuadrdado                    
    {B11000000,   
     B11000000,    
     B00000000,    
     B00000000},
    {B11000000,   
     B11000000,    
     B00000000,    
     B00000000}, 
    {B11000000,   
     B11000000,    
     B00000000,    
     B00000000},
    {B11000000,   
     B11000000,    
     B00000000,    
     B00000000}
  },
  {   // palo                   
    {B01000000,   
     B01000000,    
     B01000000,    
     B01000000},
    {B01000000,   
     B01000000,    
     B01000000,    
     B01000000}, 
    {B00000000,   
     B11110000,    
     B00000000,    
     B00000000},
    {B01000000,   
     B01000000,    
     B01000000,    
     B01000000}
  },   
  {   // L                   
    {B10000000,   
     B10000000,    
     B11000000,    
     B00000000},
    {B11100000,   
     B10000000,    
     B00000000,    
     B00000000}, 
    {B11000000,   
     B01000000,    
     B01000000,    
     B00000000},
    {B00100000,   
     B11100000,    
     B00000000,    
     B00000000}
  },   
  {  //L invertida                    
    {B01000000,   
     B01000000,    
     B11000000,    
     B00000000},
    {B10000000,   
     B11100000,    
     B00000000,    
     B00000000}, 
    {B11000000,   
     B10000000,    
     B10000000,    
     B00000000},
    {B11100000,   
     B00100000,    
     B00000000,    
     B00000000}
  },   
  { // T                     
    {B01000000,   
     B11100000,    
     B00000000,    
     B00000000},
    {B10000000,   
     B11000000,    
     B10000000,    
     B00000000}, 
    {B11100000,   
     B01000000,    
     B00000000,    
     B00000000},
    {B01000000,   
     B11000000,    
     B01000000,    
     B00000000}
  },   
  { // Z                      
    {B11000000,   
     B01100000,    
     B00000000,    
     B00000000},
    {B01000000,   
     B11000000,    
     B10000000,    
     B00000000}, 
    {B11000000,   
     B01100000,    
     B00000000,    
     B00000000},
    {B01000000,   
     B11000000,    
     B10000000,    
     B00000000}
  },   
  { // Z invertida                     
    {B01100000,   
     B11000000,    
     B00000000,    
     B00000000},
    {B10000000,   
     B11000000,    
     B01000000,    
     B00000000}, 
    {B01100000,   
     B11000000,    
     B00000000,    
     B00000000},
    {B10000000,   
     B11000000,    
     B01000000,    
     B00000000}  
  }
};

const unsigned char abecedario[26][9] PROGMEM = {
    {
    B01100000,  //A
    B10010000,
    B10010000,
    B10010000,
    B11110000,
    B10010000,
    B10010000,
    B10010000,
    B10010000},
    {
    B11100000,  //B
    B10010000,
    B10010000,
    B10010000,
    B11100000,
    B10010000,
    B10010000,
    B10010000,
    B11100000},
    {
    B01100000,  //C
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B01100000},
    {
    B11000000,  //D
    B10100000,
    B10010000,
    B10010000,
    B10010000,
    B10010000,
    B10010000,
    B10100000,
    B11000000},
    {
    B11100000,  //E
    B10000000,
    B10000000,
    B10000000,
    B11100000,
    B10000000,
    B10000000,
    B10000000,
    B11100000},
    {
    B11110000,  //F
    B10000000,
    B10000000,
    B10000000,
    B11100000,
    B10000000,
    B10000000,
    B10000000,
    B10000000},
    {
    B01100000,  //G******
    B10010000,
    B10000000,
    B10000000,
    B10110000,
    B10010000,
    B10010000,
    B10010000,
    B01110000},
    {
    B1001000,  //H
    B1001000,
    B1001000,
    B1001000,
    B1111000,
    B1001000,
    B1001000,
    B1001000,
    B1001000},
    {
    B10000000,  //I
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000},
    {
    B00010000,  //J
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B10010000,
    B01100000},
    {
    B10001000,  //K*******
    B10010000,
    B10100000,
    B11000000,
    B10000000,
    B11000000,
    B10100000,
    B10010000,
    B10001000},
    {
    B10000000,  //L
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B11110000},
    {
    B10001000,  //M*******
    B11011000,
    B10101000,
    B10101000,
    B10001000,
    B10001000,
    B10001000,
    B10001000,
    B10001000},
    {
    B10001000,  //N*****
    B11001000,
    B11001000,
    B10101000,
    B10101000,
    B10011000,
    B10011000,
    B10001000,
    B10001000},
    {
    B01100000,  //O******
    B10010000,
    B10010000,
    B10010000,
    B10010000,
    B10010000,
    B10010000,
    B10010000,
    B01100000},
    {
    B11100000,  //P
    B10010000,
    B10010000,
    B10010000,
    B11100000,
    B10000000,
    B10000000,
    B10000000,
    B10000000},
    {
    B01110000,  //Q********
    B10001000,
    B10001000,
    B10001000,
    B10001000,
    B10001000,
    B10101000,
    B10010000,
    B01101000},
    {
    B11110000,  //R*****
    B10001000,
    B10001000,
    B10001000,
    B11110000,
    B11000000,
    B10100000,
    B10010000,
    B10001000},
    {
    B01110000,  //S
    B10000000,
    B10000000,
    B10000000,
    B01100000,
    B00010000,
    B00010000,
    B00010000,
    B11100000},
    {
    B11100000,  //T*****
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000},
    {
    B10010000,  //U
    B10010000,
    B10010000,
    B10010000,
    B10010000,
    B10010000,
    B10010000,
    B10010000,
    B01100000},
    {
    B10001000,  //V****
    B10001000,
    B10001000,
    B10001000,
    B10001000,
    B10001000,
    B01010000,
    B01010000,
    B00100000},
    {
    B10001000,  //W****
    B10001000,
    B10001000,
    B10001000,
    B10101000,
    B10101000,
    B10101000,
    B10101000,
    B01010000},
    {
    B10001000,  //X
    B10001000,
    B10001000,
    B01010000,
    B00100000,
    B01010000,
    B10001000,
    B10001000,
    B10001000},
    {
    B10001000,  //Y
    B10001000,
    B10001000,
    B10001000,
    B01010000,
    B00100000,
    B00100000,
    B00100000,
    B00100000},
    {
    B11111000,  //Z
    B00001000,
    B00001000,
    B00010000,
    B00100000,
    B01000000,
    B10000000,
    B10000000,
    B11111000},
};

byte efecto=0;
byte efectoAnterior;
int fotograma=0;
unsigned char pantalla[2][18] = {
    {B10000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000},
    {B10000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000}};

void setup() {
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);

  randomSeed(analogRead(0));

  for (int num=0;num<18;num++){ pantalla[0][num]=0; pantalla[1][num]=0; }
}

void loop() {
  efectoAnterior=efecto;
  efecto=random(13);
  if (efecto==efectoAnterior){
    efecto++;
  }
  switch(efecto) {
    case 0:
      efectoRandomOff();
    break;
    case 1:
      efectoAnimacionTetris();
    break;
    case 2:
      efectoAnimacionLlenaEsquinas();
    break;
    case 3:
      efectoAnimacionOlas();
    break;
    case 4:
      efectoAnimacionHelice();
    break;
    case 5:
      efectoAnimacionSnakes();
    break;
    case 6:
      efectoAnimacionOnda();
    break;
    case 7:
      efectoAnimacionBarrotes();
    break;
    case 8:
      efectoRandomAjedrez();
    break;
    case 9:
      efectoTextoEgregio();
    break;
    case 10:
      efectoTextoConectica();
    break;
    case 11:
      efectoTextoBienvenidos();
    break;
    case 12:
      efectoAnimacionGepteo();
    break;
    default:
      efectoAnimacionHelice();
    break; 
  } //efecto++;
}

void displayLedMatrix(int scroll){

  if (scroll>0) {
    for (int linesRefresh=0;linesRefresh<fpsDelay;linesRefresh++){
      digitalWrite(latch, LOW) ;
      shiftOut(data, clock, LSBFIRST, lineScan[0]);
      shiftOut(data, clock, LSBFIRST, pantalla[0][scroll]);
      shiftOut(data, clock, LSBFIRST, pantalla[1][scroll]); 
      digitalWrite(sinlge, LOW); 
      digitalWrite(latch, HIGH);
      for (int num = 1; num < 8; num++) {    
         digitalWrite(latch, LOW) ;
         shiftOut(data, clock, LSBFIRST, lineScan[num]);
         shiftOut(data, clock, LSBFIRST, pantalla[0][num+scroll]); 
         shiftOut(data, clock, LSBFIRST, pantalla[1][num+scroll]);
         digitalWrite(latch, HIGH);
      }
      digitalWrite(latch, LOW) ; 
      shiftOut(data, clock, LSBFIRST, 0x00);
      shiftOut(data, clock, LSBFIRST, pantalla[0][8+scroll]);
      shiftOut(data, clock, LSBFIRST, pantalla[1][8+scroll]);
      digitalWrite(sinlge, HIGH);
      digitalWrite(latch, HIGH);
    }
  } else{
     for (int linesRefresh=0;linesRefresh<fpsDelay;linesRefresh++){
      digitalWrite(latch, LOW) ;
      shiftOut(data, clock, LSBFIRST, lineScan[0]);
      shiftOut(data, clock, LSBFIRST, pantalla[0][0]);
      shiftOut(data, clock, LSBFIRST, pantalla[1][0]); 
      digitalWrite(sinlge, LOW); 
      digitalWrite(latch, HIGH);
      for (int num = 1; num < 8; num++) {    
         digitalWrite(latch, LOW) ;
         shiftOut(data, clock, LSBFIRST, lineScan[num]);
         shiftOut(data, clock, LSBFIRST, pantalla[0][num]); 
         shiftOut(data, clock, LSBFIRST, pantalla[1][num]);
         digitalWrite(latch, HIGH);
      }
      digitalWrite(latch, LOW) ; 
      shiftOut(data, clock, LSBFIRST, 0x00);
      shiftOut(data, clock, LSBFIRST, pantalla[0][8]);
      shiftOut(data, clock, LSBFIRST, pantalla[1][8]);
      digitalWrite(sinlge, HIGH);
      digitalWrite(latch, HIGH);
    }
  }
}

void efectoRandomOff() {
  int posx; int posy;
  for (int num=0;num<9;num++){
    pantalla[0][num]=255; pantalla[1][num]=255; 
  } displayLedMatrix(0);
  while (fotograma<88){
    displayLedMatrix(0);
    fotograma++;
    posy = random(9) ; posx = random(8) ;
    bitWrite(pantalla[0][posy],posx,false);
    bitWrite(pantalla[1][posy],posx,false);
  } fotograma=0;
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; displayLedMatrix(0); }
}

void efectoRandomAjedrez() {
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
  int posx=0;
  int posy=0;
  while (fotograma<96){
    displayLedMatrix(0);
    fotograma++;
    posx=random(9);
    posy=random(4);
    if (posx%2==0){
      bitWrite(pantalla[0][posx],posy*2,true);
      bitWrite(pantalla[1][posx],posy*2,true);
    } else {
      if (posy*2+1>7) {
        bitWrite(pantalla[0][posx],(posy*2)-1,true);
        bitWrite(pantalla[1][posx],(posy*2)-1,true);
      }else {
        bitWrite(pantalla[0][posx],(posy*2)+1,true);
        bitWrite(pantalla[1][posx],(posy*2)+1,true);
      }
    }
  } fotograma=0;
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; displayLedMatrix(0); }
}

void efectoAnimacionTetris() {
  for (int num=0;num<18;num++){ pantalla[0][num]=0; pantalla[1][num]=0; } displayLedMatrix(0);
  int count=0;
  while (fotograma<102){
    displayLedMatrix(5);
    for (int num=13;num>0;num--){
      pantalla[0][num]=pantalla[0][num-1]; 
      pantalla[1][num]=pantalla[1][num-1]; 
    } pantalla[0][0]=0; pantalla[1][0]=0;
    if (fotograma<88){
      if (--count<1) {
        count=8+random(2);
        tetrisFicha(3+random(3),0); tetrisFicha(3+random(3),1);
         //bitWrite(pantalla[1][0],4,true);
      }
      if (count==3){
        tetrisFicha(random(3),0); tetrisFicha(random(3),1);
      }
    }
    fotograma++;
  } fotograma=0;
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
}

void tetrisFicha(int px, int scr) {
  int ficha=random(6);
  int estado=random(3);
  int py=random(2);
  //bool choca=false;
  //bool screenOut=false;
  /*for(int row=0;row<4;row++) {
    for(int col=0;col<4;col++) {
      if (bitRead(pgm_read_byte(&tetris[ficha][estado][row]),7-col)) {
        if (bitRead(pantalla[0][row+py],7-col-px)) { choca=true; }
        //if (7-col-px>7) { screenOut=true; }
      }
    }
  }*/
  //if (!choca){
    //if (screenOut) { px--; }
    for(int row=0;row<4;row++) {
      for(int col=0;col<4;col++) {
        if (bitRead(pgm_read_byte(&tetris[ficha][estado][row]),7-col)) {
          bitWrite(pantalla[scr][row+py],7-col-px,true);//
          //bitWrite(pantalla[1][row+py],7-col-px,true);//
        }
      }
    }
  //}
}

void efectoAnimacionLlenaEsquinas() {
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
  while (fotograma<31){
    displayLedMatrix(0);
    for (int num=0;num<8;num++){
      pantalla[0][num]=pgm_read_byte(&animacionLlenaEsquinas[fotograma][num]);
      pantalla[1][num]=pgm_read_byte(&animacionLlenaEsquinas[fotograma][num]);
    }
    pantalla[0][8]=pantalla[0][7];
    pantalla[1][8]=pantalla[1][7];
    fotograma++;
  } fotograma=0;
  displayLedMatrix(0);
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
}

void efectoAnimacionOlas() {
  byte cont=0;
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
  while (fotograma<12){
  displayLedMatrix(0);
    if (fotograma==11 && cont<5 && random(4)>0) { fotograma=0; cont++; }
    for (int num=0;num<8;num++){
      pantalla[0][num]=pgm_read_byte(&animacionOlas[fotograma][num]);
      pantalla[1][num]=pgm_read_byte(&animacionOlas[fotograma][num]);
    }
    pantalla[0][8]=pantalla[0][7];
    pantalla[1][8]=pantalla[1][7];
    fotograma++;
  } fotograma=0;
  displayLedMatrix(0);
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
}

void efectoAnimacionHelice() {
  byte cont=0;
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
  while (fotograma<10){
    displayLedMatrix(0);
    if (fotograma==9 && cont<10 && random(6)>0) { fotograma=4; cont++; }
    for (int num=0;num<8;num++){
      pantalla[0][num]=pgm_read_byte(&animacionHelice[fotograma][num]);
      pantalla[1][num]=pgm_read_byte(&animacionHelice[fotograma][num]);
    }
    pantalla[0][8]=pantalla[0][7];
    pantalla[1][8]=pantalla[1][7];
    fotograma++;
  } fotograma=3;
  while (fotograma>=0){
    displayLedMatrix(0);
    for (int num=0;num<8;num++){
      pantalla[0][num]=pgm_read_byte(&animacionHelice[fotograma][num]);
      pantalla[1][num]=pgm_read_byte(&animacionHelice[fotograma][num]);
    }
    pantalla[0][8]=pantalla[0][7];
    pantalla[1][8]=pantalla[1][7];
    fotograma--;
  }
  fotograma=0;
  displayLedMatrix(0);
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
}

void efectoAnimacionSnakes() {
  int posx=random(8); int posy=0;
  int incx=1-random(3); int incy=1;
  if (incx==0 && incy==0) { incx=1; }
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0;} displayLedMatrix(0);
  while (fotograma<48){
    displayLedMatrix(0);
    if (posx>7 || posy>8 || posx<0 || posy<0) {
      posx=random(8); posy=0;
      incx=1-random(3); incy=1;
      if (incx==0 && incy==0) { incx=1; }
    }
    bitWrite(pantalla[0][posy],posx,true);
    bitWrite(pantalla[1][posy],posx,true);
    posx+=incx; posy+=incy;
    fotograma++;
  } fotograma=0;
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; displayLedMatrix(0); } 
}

void efectoAnimacionOnda() {
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
  while (fotograma<62){
    displayLedMatrix(0);
    for (int num=0;num<8;num++){
      if (fotograma<55){
        pantalla[0][num]=pgm_read_byte(&animacionOnda[fotograma][num]);
      }
      if (fotograma-8>=0){
        pantalla[1][num]=pgm_read_byte(&animacionOnda[fotograma-8][num]);
      }
    }
    pantalla[0][8]=pantalla[0][7];
    pantalla[1][8]=pantalla[1][7];
    fotograma++;
  } fotograma=0;
  displayLedMatrix(0);
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
}

void efectoAnimacionBarrotes() {  
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
  while (fotograma<15){
    displayLedMatrix(0);
    for (int num=0;num<8;num++){
      pantalla[0][num]=pgm_read_byte(&animacionBarrotes[fotograma][num]);
      pantalla[1][num]=pgm_read_byte(&animacionBarrotes[fotograma][num]);
    }
    pantalla[0][8]=pantalla[0][7];
    pantalla[1][8]=pantalla[1][7];
    fotograma++;
  } fotograma=0;
  displayLedMatrix(0);
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
}

void efectoAnimacionGepteo() {  
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
  while (fotograma<50){
    displayLedMatrix(0);
    for (int num=0;num<8;num++){
      if (fotograma<25 && fotograma>15){
        pantalla[0][num]=pgm_read_byte(&animacionGepeto[1][num]);
      }else {
        pantalla[0][num]=pgm_read_byte(&animacionGepeto[0][num]);
      }
      pantalla[1][num]=pgm_read_byte(&animacionGepeto[2][num]);
    }
    fotograma++;
  } fotograma=0;
  displayLedMatrix(0);
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
}


void efectoTextoEgregio(){
  for (int num=0;num<18;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
  while (fotograma<70){
    displayLedMatrix(0);
    printChar(abecedario[4],-8+fotograma);
    printChar(abecedario[6],-12+fotograma);
    printChar(abecedario[17],-17+fotograma);
    printChar(abecedario[4],-23+fotograma);
    printChar(abecedario[6],-27+fotograma);
    printChar(abecedario[8],-32+fotograma);
    printChar(abecedario[14],-34+fotograma);
    printChar(abecedario[4],-41+fotograma);
    printChar(abecedario[17],-45+fotograma);
    printChar(abecedario[4],-51+fotograma);
    printChar(abecedario[18],-55+fotograma);
    fotograma++;
  } fotograma=0;
  displayLedMatrix(0);
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0); 
}

void efectoTextoBienvenidos(){
  for (int num=0;num<18;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
  while (fotograma<70){
    displayLedMatrix(0);
    printChar(abecedario[1],-8+fotograma);
    printChar(abecedario[8],-13+fotograma);
    printChar(abecedario[4],-15+fotograma);
    printChar(abecedario[13],-19+fotograma);
    printChar(abecedario[21],-25+fotograma);
    printChar(abecedario[4],-31+fotograma);
    printChar(abecedario[13],-35+fotograma);
    printChar(abecedario[8],-41+fotograma);
    printChar(abecedario[3],-43+fotograma);
    printChar(abecedario[14],-48+fotograma);
    printChar(abecedario[18],-53+fotograma);
    fotograma++;
  } fotograma=0;
  displayLedMatrix(0);
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0); 
}

void efectoTextoConectica(){
  for (int num=0;num<18;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0);
  while (fotograma<57){
    displayLedMatrix(0);
    printChar(abecedario[2],-8+fotograma);
    printChar(abecedario[14],-12+fotograma);
    printChar(abecedario[13],-17+fotograma);
    printChar(abecedario[4],-23+fotograma);
    printChar(abecedario[2],-27+fotograma);
    printChar(abecedario[19],-31+fotograma);
    printChar(abecedario[8],-35+fotograma);
    printChar(abecedario[2],-37+fotograma);
    printChar(abecedario[0],-41+fotograma);
    fotograma++;
  } fotograma=0;
  displayLedMatrix(0);
  for (int num=0;num<9;num++){ pantalla[1][num]=0; pantalla[0][num]=0; } displayLedMatrix(0); 
}

void printChar(unsigned char letra[7], int posxScr) {
  if (posxScr>13 || posxScr<-8) { return; }
  for(int row=0;row<9;row++) {
    for(int col=2;col<8;col++) {
      if (posxScr+col<8 && posxScr+col>=0){
        bitWrite(pantalla[0][row],posxScr+col,bitRead(pgm_read_byte(&letra[row]),col));
      }
    }
    int posxScr2=posxScr-8;
    for(int col=2;col<8;col++) {
      if (posxScr2+col<8 && posxScr2+col>=0){
        bitWrite(pantalla[1][row],posxScr2+col,bitRead(pgm_read_byte(&letra[row]),col));
      }
    }
  }
}
