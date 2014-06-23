package com.nhpatt.twitterwitharduino;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

import twitter4j.Query;
import twitter4j.QueryResult;
import twitter4j.Status;
import twitter4j.TwitterException;
import twitter4j.TwitterFactory;

public class TwitterClient {

	private static final String QUERY = "aos2k14";

	private final Set<Status> statuses = new HashSet<Status>();

	public boolean getTweets() throws TwitterException {
		final QueryResult result = TwitterFactory.getSingleton().search(
				new Query(QUERY));

		final List<Status> tweets = result.getTweets();
		if (!tweets.isEmpty()) {
			for (final Status status : tweets) {
				System.out.println("@" + status.getUser().getScreenName() + ":"
						+ status.getText());
			}
			final Status lastTweet = tweets.get(0);
			final boolean newTweet = checkIfNewTweets(statuses, lastTweet);
			statuses.addAll(new HashSet<Status>(tweets));
			return newTweet;
		}
		return false;
	}

	private boolean checkIfNewTweets(final Set<Status> oldTweets,
			final Status lastTweet) {
		boolean newTweet = true;
		for (final Status tweet : oldTweets) {
			if (tweet.getId() == lastTweet.getId()) {
				newTweet = false;
			}
		}
		return newTweet;
	}
}
