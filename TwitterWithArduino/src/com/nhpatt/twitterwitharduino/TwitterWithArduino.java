package com.nhpatt.twitterwitharduino;

public class TwitterWithArduino {

	public static void main(final String[] args) throws Exception {
		ArduinoRunnable arduino = new ArduinoRunnable();
		new Thread(arduino).start();
	}

}
