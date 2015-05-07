"""
Bar chart demo with pairs of bars grouped for easy comparison.
"""
import numpy as np
import matplotlib.pyplot as plt


n_groups = 6

Soap =  (4*60,  9*60, 2*60,     0,        2*60,     165)
Abyss = (14*60, 9*60, 18*60+33, 33*60+28, 13*60+20, 10*60)
Velvet= (8*60,  136,  824,      1084,     145,      216)
ARCS =  (274,   168,  636,      914,      367,      201)

fig, ax = plt.subplots()

index = np.arange(n_groups)
bar_width = 0.15

opacity = 1 
error_config = {'ecolor': '0.3'}

rects1 = plt.bar(index, Soap, bar_width,
        alpha=opacity,
        color='b',
        error_kw=error_config,
        label='SOAP')

rects2 = plt.bar(index+bar_width, Abyss, bar_width,
        alpha=opacity,
        color='y',
        error_kw=error_config,
        label='ABySS')


rects3 = plt.bar(index + 2*bar_width, Velvet, bar_width,
        alpha=opacity,
        color='g',
        error_kw=error_config,
        label='Velvet')

rects4 = plt.bar(index + 3*bar_width, ARCS, bar_width,
        alpha=opacity,
        color='r',
        error_kw=error_config,
        label='ARCS')

#plt.xlabel('# of cuts')
plt.ylabel('Time/second')
plt.title('Performance Comparison of different Genome Assemblers.')
plt.xticks(index + 2*bar_width, ('E.coli', 'S. aureus', 'd12', 'd9', 'SIM1', 'SIM2'))
plt.legend(loc='best')

#plt.tight_layout()
plt.show()
