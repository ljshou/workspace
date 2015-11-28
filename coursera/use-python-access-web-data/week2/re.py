#!/usr/bin/env python

import re
from nltk.corpus import movie_reviews

documents = []
n = 10
for category in movie_reviews.categories():
	for fileid in movie_reviews.fileids(category):
		n -= 1
		if n <= 0: break
		documents.append(movie_reviews.raw(fileid))
		# print documents[-1]

for doc in documents:
	patterns = re.findall("^(t.*\')", doc)
	if len(patterns) != 0:
		print patterns[0]