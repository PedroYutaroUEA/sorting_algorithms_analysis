import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

df = pd.read_csv('resultados.csv')

plt.figure(figsize=(8, 5))

# Merge Sort
plt.plot(df['Base'], df['MergeSort_mean'], marker='o',
         linestyle='-', label='MergeSort', color='red')
plt.plot(df['Base'], df['QuickSort_mean'], marker='o',
         linestyle='-', label='QuickSort', color='green')
plt.plot(df['Base'], df['HeapSort_mean'], marker='o',
         linestyle='-', label='HeapSort', color='blue')

# fix axis to show adjusted values
plt.xticks(df['Base'], labels=[f"{x:,}" for x in df['Base']], rotation=45)

y_max = df[['MergeSort_mean', 'QuickSort_mean', 'HeapSort_mean']].max().max()
y_ticks = np.arange(0, y_max + 2500, 2500)
plt.yticks(y_ticks)

# charts settings
plt.title('Tempo médio de execução',
          fontsize=14, pad=20)
plt.xlabel('Base size', fontsize=12)
plt.ylabel('Average execution time (ms)', fontsize=12)
plt.yscale('linear')
plt.grid(True, which="both", ls="--", alpha=0.3)
# legend
plt.legend(title='Algorithms:', title_fontsize=12, fontsize=11)

plt.show()
