import pandas as pd
import matplotlib.pyplot as plt


counta=[]
countb=[]
countc=[]

for line in open("output.txt","r+").readlines():
    line.strip("\n")
    line=[float(i) for i in line.split()]
    counta.append(line[0])
    countb.append(line[1])
    countc.append(line[2])

df = pd.DataFrame({
	'Priorities': [0,20,40,60,80,100],
	'CountA': counta,
	'CountB': countb,
    'CountC': countc
})

df.plot(x="Priorities", y=["CountA", "CountB","CountC"], kind="bar")
plt.ylim(16,17)
plt.show()
