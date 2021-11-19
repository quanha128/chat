import numpy as np
import matplotlib.pyplot as plt
import timeit

x=np.linspace(1,10,100)

y1=x
y2=np.log(x)
y3=np.log(x)*x

plt.plot(x,y1,color='red',label='$y=$x')
plt.plot(x,y2,color='blue',label='$y=\logx$')
plt.plot(x,y3,color='green',label='$y=x\logx$')

plt.xlim([1,10])
plt.legend()
plt.xlabel('x', fontsize=9)
plt.ylabel('y', fontsize=9)
plt.show()
