import matplotlib.pyplot as pl
import numpy as np
import csv
from matplotlib import style

#default stlye for matplotlib
style.use('fivethirtyeight')

#we are defining figure so we can divide the axes in our plot
fig=pl.figure()


#defining lists to store elements
elements=[]
swap=[]
comp=[]
execution=[]

#opening file to import swap data
with open('swapout.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        elements.append(int(row[0]))
        swap.append(int(row[1]))
no_elements = np.array(elements)
swap_data = np.array(swap)


#opening file to import comparsion data
with open('compout.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        comp.append(int(row[1]))
comp_data = np.array(swap)


#opening file to import execution data
with open('executionout.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        execution.append(float(row[1]))
execution_data = np.array(execution)

#dividing graph into subplots
ax1=fig.add_subplot(221)
ax2=fig.add_subplot(222)
ax3=fig.add_subplot(212)


#plotting swaps
ax1.set_xlabel("Number of elements")
ax1.set_ylabel("Number of swaps")
ax1.bar(no_elements,swap_data,color='red',width=1)

#plotting comparsion
ax2.set_xlabel("Number of elements")
ax2.set_ylabel("Number of comparsion")
ax2.bar(no_elements,comp_data,color='red',width=1)

#plotting execution time
ax3.set_xlabel("Number of elements")
ax3.set_ylabel("Execution Time")
ax3.bar(no_elements,execution_data,color='red',width=1)

pl.show()
