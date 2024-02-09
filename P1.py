import matplotlib.pyplot as plt
import numpy as np

num_a = np.array([500,1000,1500,2000,2500,3000,3500,4000,4500,5000])
tc_a = np.array([0.194258,1.52175,1.99094,5.07002,9.56315,11.8094,11.5187,15.7388,19.8269,32.1124])

num_b = np.array([500,1000,1500,2000,2500,3000,3500,4000,4500,5000])
tc_b = np.array([0.167507,0.541027,0.943503,2.66785,3.95831,3.76273,5.07976,6.58913,8.3958,15.8889])

plt.plot(num_a, tc_a, label='Bubble sort')
plt.plot(num_b, tc_b, label='Selection sort')
plt.xlabel('Size of array')
plt.ylabel('Time Complexity')
plt.legend()
plt.title('Bubble Sort vs Selection Sort')
plt.show()
