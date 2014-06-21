
class VUMeter{
	public:
		VUMeter();
		void config(int length, int pins[]);
		void begin();
		void on(int index);
		void off(int index);
		void scrollLeft(int speed,int startIndex=0);
		void scrollRight(int speed,int startIndex=0);
		void fill(int length);
		void fillFrom(int leftIndex,int rightIndex);
		void blink(int index, int speed, int times=1);
		void blinkAll(int speed,int times=1);
		void clear();

		void test();
	private:
		void blinkOnce(int index,int onTime,int offTime);
		//int getPin(int index);
		int pins[20];
		int pinCount;
};

VUMeter::VUMeter(){
	//default pins
	//be 5 pins, 2~6
	pins[0]=2;
	pins[1]=3;
	pins[2]=4;
	pins[3]=5;
	pins[4]=6;
	for(int i=5;i<20;i++){
		this->pins[i]=-1;
	}
}
void VUMeter::config(int length, int pins[]){
	//set the pins used for vu-meter
	//length is the number of pins used,
	//pins is an array of all pins
	for(int i=0;i<length;i++){
		this->pins[i]=pins[i];
	}
	for(int i=length;i<20;i++){
		this->pins[i]=-1;
	}
	this->pinCount=length;
}
void VUMeter::begin(){
	//Must be called before starting
	//set all the attached pins as OUTPUT
	for(int i=0;i<pinCount;i++){
		pinMode(pins[i],OUTPUT);
	}
}
void VUMeter::on(int index){
	//turn the led at index of the list on
	digitalWrite(pins[index],HIGH);
}
void VUMeter::off(int index){
	//turn the led at index of the list on
	digitalWrite(pins[index],LOW);
}
void VUMeter::scrollLeft(int speed,int startIndex){
	//leds will turn on one at a time,
	//each for the duration of speed in milliseconds,
	//start with the startIndex counting from right,
	//go towards left
	clear();
	for(int i=pinCount-1-startIndex;i>-1;i--){
		blinkOnce(i,speed,0);
	}
}
void VUMeter::scrollRight(int speed,int startIndex){
	//leds will turn on one at a time,
	//each for the duration of speed in milliseconds,
	//start with the startIndex counting from left,
	//go towards right

	clear();
	for(int i=0+startIndex;i<pinCount;i++){
		blinkOnce(i,speed,0);
	}
}
void VUMeter::fillFrom(int leftIndex,int rightIndex){
	//Turn a few leds on at the same time
	//From leftIndex to rightIndex
	clear();
	for(int i=leftIndex;i<=rightIndex;i++){
		digitalWrite(pins[i],HIGH);
	}
}
void VUMeter::fill(int length){
	//Turn a few leds on at the same time
	//From first in list to the specific length

	fillFrom(0,length-1);
}
void VUMeter::blink(int index, int speed,int times){
	//blink one leds for a few times(default is once)
	//speed is the delay time for both on and off
	for(int i=0;i<times;i++){
		blinkOnce(index,speed,speed);
	}
}
void VUMeter::blinkAll(int speed,int times){
	//blink all leds for a few times(default is once)
	//speed is the delay time for both on and off
	for(int i=0;i<times;i++){
		fill(pinCount);
		delay(speed);
		clear();
		delay(speed);
	}
}
void VUMeter::test(){
	//for test only, see if pins are connected
	for(int i=0;i<pinCount;i++){
		Serial.print(this->pins[i]);
		digitalWrite(pins[i],HIGH);
	}

}

void VUMeter::blinkOnce(int index,int onTime,int offTime){
	//help function, blink a led once with controlled time
	digitalWrite(pins[index],HIGH);
	delay(onTime);
	digitalWrite(pins[index],LOW);
	delay(offTime);
}

void VUMeter::clear(){
	//help function, set all pins to low
	for(int i=0;i<pinCount;i++){
		digitalWrite(pins[i],LOW);
	}

}

int ledPins[] = {2,3,4,5,6};
int pinCount = 5;
VUMeter vuMeter;
 
int rowCount = 0;
int rowLength = 22;
int delayTime = 9;

boolean message[5][22]={
  // H H H H   O O O O   L L L L   A A A A
  {0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0},
  {0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0},
  {0,1,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,1,0,0},
  {0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0},
  {0,1,0,0,1,0,0,1,1,0,0,1,1,1,1,0,1,0,0,1,0,0}
 
};

void setup(){
  vuMeter.config(pinCount, ledPins);
  vuMeter.begin();
}
 
void loop(){
  if(rowCount == rowLength) {
    rowCount = 0;
  } else {
    for (int i = 0; i < pinCount; i++) {
      if (message[i][rowCount] == 1) {
        vuMeter.on(i);
      } else {
        vuMeter.off(i);
      }
    }
    rowCount++;
  }
 
  delay(delayTime);
}
