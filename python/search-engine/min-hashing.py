#!/usr/bin/env python
import random

totalshingles = 23880

class MinHash(object):
	"""docstring for MinHash"""
	setA = setB = []
	signatureA = signatureB = []
	k = 10
	def __init__(self, setA, setB, k=10):
		super(MinHash, self).__init__()
		assert k > 0
		self.setA = setA
		self.setB = setB
		self.k = k
		self.signatureA = [totalshingles] * k
		self.signatureB = [totalshingles] * k
		hash_funcs = self._hash(k)

		for i in range(k):
			self.signatureA[i] = self._compute_signature(setA, hash_funcs[i])
			self.signatureB[i] = self._compute_signature(setB, hash_funcs[i])

	def _compute_signature(self, setA, hash_func):
		x = totalshingles
		for i in range(len(setA)):
			hash_val = hash_func(setA[i])
			x = min(x, hash_val)
		return x

	def _generateRandList(self, k):
		randList = []
		for i in range(k):
			x = random.randint(0, totalshingles)
			while x in randList:
				x = random.randint(0, totalshingles)
			randList.append(x)
		return randList

	def _hash(self, k):
		hash_funcs = []
		randListA = self._generateRandList(k)
		randListB = self._generateRandList(k)

		for i in range(k):
			hash_funcs.append(lambda x, i=i: ((randListA[i]*x + randListB[i]) % totalshingles))
			# carefull with lambda function to capture variables outside the scope

		return hash_funcs

	def similarity(self):
		cnt = 0
		for i in range(self.k):
			# print self.signatureA[i], self.signatureB[i]
			if self.signatureA[i] == self.signatureB[i]:
				cnt += 1
		return cnt * 1.0 / self.k


if __name__ == "__main__":
	setA = [1, 2, 3, 4]
	setB = [2, 3, 4]
	print len(set(setA).intersection(setB)) * 1.0 / len(set(setA).union(setB)) 
	minhash = MinHash(setA, setB, 100)
	print minhash.similarity()
