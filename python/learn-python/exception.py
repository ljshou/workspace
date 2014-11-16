try:
	x = int(raw_input('Please input an integer'))
	y = int(raw_input('Please input an integer'))
	x/y
except ZeroDivisionError:
	print 'divided by zero'


