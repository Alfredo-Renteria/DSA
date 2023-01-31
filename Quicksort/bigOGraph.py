import matplotlib.pyplot as plt

#Constants for input sizes
ONEK = 1000
TENK = 10000
FIFK = 50000
SEVK = 75000
HUNK = 100000
HUNFIFK = 150000
TWOHUNK = 200000

#Real run times
#Returns a list with 'real' run times obtained from input file
def realTimes(filename):
    realY = []
    try:
        with open(filename, 'r') as myfile:
            for line in myfile:
                if line.startswith('real'):
                    time = float(line.split(maxsplit=1)[1])
                    realY.append(time)
    except FileNotFoundError as e:
        print(e)
    return realY


#Fastest sorting algorithm
#Prints to STDOUT the algorithm with the fastest time for each input size
def fastestTime(stl, hoare, lom, xAxis):
    #Ok since all lists are the same size
    size = len(stl)
    for i in range(size):
        print('Fastest time for ' + str(xAxis[i]) + ':')
        if stl[i] == hoare[i] == lom[i]:
            print('There is a tie!:', stl[i])
        elif stl[i] < hoare[i] and stl[i] < lom[i]:
            print('The winner is stl with:', stl[i])
        elif hoare[i] < stl[i] and hoare[i] < lom[i]:
            print('The winner is hoare with:', hoare[i])
        elif lom[i] < stl[i] and lom[i] < hoare[i]:
            print('The winner is lomuto with:', lom[i])
        else:
            print('There is a tie amongst two!:', min(stl[i], hoare[i], lom[i]))

#X-axis values
x = [ONEK, TENK, FIFK, SEVK, HUNK, HUNFIFK, TWOHUNK]

#Y-axis values
stlY = realTimes('stltime.txt')
hoareY = realTimes('hoaretime.txt')
lomutoY = realTimes('lomutotime.txt')

#Create figure with 2 subplots
fig, axs = plt.subplots(2, 2, figsize=(15,10))
fig.suptitle('STL vs. Hoare vs. Lomuto', fontsize=18, fontweight='bold')

#First subplot with all three algorithms on the same plot
axs[0, 0].plot(x, stlY, label='STL')
axs[0, 0].plot(x, hoareY, label='Hoare', color='tab:green')
axs[0, 0].plot(x, lomutoY, label='Lomuto', color='tab:red')
axs[0, 0].set_title('All sorts', fontweight='bold')
axs[0, 0].set_ylabel('Real running time', fontsize=16)
axs[0, 0].legend()

#Individual subplots
axs[1, 0].plot(x, stlY)
axs[1, 0].set_title('STL', fontweight='bold')
axs[1, 0].set_xlabel('Input size n', fontsize=16)
axs[1, 0].set_ylabel('Real running time', fontsize=16)

axs[0, 1].plot(x, hoareY, 'tab:green')
axs[0, 1].set_title('Hoare', fontweight='bold')

axs[1, 1].plot(x, lomutoY, 'tab:red')
axs[1, 1].set_title('Lomuto', fontweight='bold')
axs[1, 1].set_xlabel('Input size n', fontsize=16)

plt.tight_layout()

#Print speed records
fastestTime(stlY, hoareY, lomutoY, x)

plt.show()