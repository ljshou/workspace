#!/usr/bin/python

class Student(object):
	def __init__(self, name, age):
		self.__name = name
		self.__age = age

	def print_name(self):
		print 'Name: %s' % self.__name

	def print_age(self):
		print 'Age: %s' % self.__age


