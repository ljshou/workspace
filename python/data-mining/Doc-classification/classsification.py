#!/usr/bin/env 

import nltk
from nltk.corpus import movie_reviews
from nltk.classify import apply_features
import random
from collections import Counter

for category in movie_reviews.categories():
	print category

documents = [(list(movie_reviews.words(fileid)), category)
for category in movie_reviews.categories()
for fileid in movie_reviews.fileids(category)]

random.shuffle(documents)

all_words = nltk.FreqDist(w.lower() for w in movie_reviews.words())
word_features = list(all_words)[:2000]

def document_features(document):
	document_words = set(document)
	features = {}
	for word in word_features:
		features["contains({})".format(word)] = (word in document_words)
	return features	

def document_features2(document):
	words_counter = Counter(document)
	features = {}
	for word in word_features:
		features["count({})".format(word)] = words_counter[word]
	return features

length = len(documents)
test_size = int(0.2 * length)
train_set = apply_features(document_features2, documents[test_size:])
test_set = apply_features(document_features2, documents[:test_size])

classifier = nltk.NaiveBayesClassifier.train(train_set)

print nltk.classify.accuracy(classifier, test_set)

classifier.show_most_informative_features(5)