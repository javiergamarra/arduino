package com.nhpatt.twitterwitharduino;

import jssc.SerialPort;
import jssc.SerialPortException;
import twitter4j.TwitterException;

public class ArduinoRunnable implements Runnable {

	private static final String PORT = "COM15";
	private final TwitterClient tweets = new TwitterClient();

	@Override
	public void run() {
		boolean working = true;
		while (working) {
			try {
				final boolean newTweet = tweets.getTweets();
				final String message = newTweet ? "T" : "-";
				System.out.println("Message: " + message);
				writeSerialPort(message);
			} catch (final SerialPortException | InterruptedException e) {
				System.err.println("Error: " + e.getMessage());
			} catch (final TwitterException e) {
				System.err.println("Twitter error, must stop: "
						+ e.getMessage());
				working = false;
			}

			sleep();
		}
	}

	private static void writeSerialPort(final String message)
			throws SerialPortException, InterruptedException {
		final SerialPort serialPort = new SerialPort(PORT);

		final boolean portOpened = serialPort.openPort();
		System.out.println("Port opened: " + portOpened);

		final boolean paramsSettled = serialPort.setParams(9600, 8, 1, 0);
		System.out.println("Params setted: " + paramsSettled);

		// Let's wait to the communication to settle
		Thread.sleep(2000);

		final boolean stringWritten = serialPort.writeString(message);
		System.out.println("Writing to port: " + stringWritten);

		final boolean portClosed = serialPort.closePort();
		System.out.println("Port closed: " + portClosed);
	}

	private void sleep() {
		try {
			Thread.sleep(30000);
		} catch (final InterruptedException e) {
			System.err.println("Error: " + e.getMessage());
		}
	}
}
