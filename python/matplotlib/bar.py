"""
Bar chart demo with pairs of bars grouped for easy comparison.
"""
import numpy as np
import matplotlib.pyplot as plt


n_groups = 3

cgal = (2.1536, 21.7631, 215.996)#, 2100)

jaumesh = np.array([1.27, 12.63, 124.11])*1.3#, 2100)

new_strategy = (0.028862, 0.245848, 2.35629)#, 23.0136)

fig, ax = plt.subplots()

index = np.arange(n_groups)
bar_width = 0.25

opacity = 0.8 
error_config = {'ecolor': '0.3'}

rects1 = plt.bar(index, cgal, bar_width,
        alpha=opacity,
        color='b',
        error_kw=error_config,
        label='CGAL')

rects2 = plt.bar(index+bar_width, jaumesh, bar_width,
        alpha=opacity,
        color='y',
        error_kw=error_config,
        label='Jaumesh')


rects3 = plt.bar(index + 2*bar_width, new_strategy, bar_width,
        alpha=opacity,
        color='r',
        error_kw=error_config,
        label='New Strategy')

plt.xlabel('# of cuts')
plt.ylabel('Time/t')
plt.title('Performance Comparison of different Intersection Algos.')
plt.xticks(index + bar_width, ('1e2', '1e3', '1e4'))
plt.legend(loc='best')

#plt.tight_layout()
plt.show()
