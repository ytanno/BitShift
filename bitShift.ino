void setup() {

  Serial.begin(9600);

  //send value
  unsigned char sr = B10;
  unsigned char sg = B11;
  unsigned char sb = B01;
  unsigned char sl = B00;
 
  unsigned char sendData = sr << 6 | sg << 4 | sb << 2 | sl;

  Serial.println("SendValue");
  Serial.print(sendData);
  Serial.print(",");
  Serial.println(sendData, BIN);
  Serial.println("---------------------------------------------------------");

  //receive value
  unsigned char filter = B00000011;

  unsigned char rr = sendData >> 6 & filter;
  unsigned char rg = sendData >> 4 & filter;
  unsigned char rb = sendData >> 2 & filter;
  unsigned char rl = sendData & filter;

  Serial.println("ReceiveValue");
  Serial.println(rr, BIN);
  Serial.println(rg, BIN);
  Serial.println(rb, BIN);
  Serial.println(rl, BIN);
  Serial.println("---------------------------------------------------------");

  //stream value 
  unsigned char baseV = B01010101; //85

  unsigned char vr = baseV * rr;
  unsigned char vg = baseV * rg;
  unsigned char vb = baseV * rb;
  unsigned char vl = baseV * rl;
  Serial.println("StreamValue");
  Serial.println(vr);
  Serial.println(vg);
  Serial.println(vb);
  Serial.println(vl);
  
 
}

void loop() {
  // put your main code here, to run repeatedly:

}
