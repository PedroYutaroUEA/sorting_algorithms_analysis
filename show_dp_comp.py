import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

df = pd.read_csv('resultados.csv')

plt.figure(figsize=(8, 5))

# Merge Sort
plt.plot(df['Base'], df['MergeSortDP'], marker='o',
         linestyle='-', label='MergeSort', color='red')
plt.plot(df['Base'], df['QuickSortDP'], marker='o',
         linestyle='-', label='QuickSort', color='green')
plt.plot(df['Base'], df['HeapSortDP'], marker='o',
         linestyle='-', label='HeapSort', color='blue')

# fix axis to show adjusted values
plt.xticks(df['Base'], labels=[f"{x:,}" for x in df['Base']], rotation=45)

# fix axis to show adjusted values
y_max = df[['MergeSortDP', 'QuickSortDP', 'HeapSortDP']].max().max()
y_ticks = np.arange(0, y_max + 25, 25)
plt.yticks(y_ticks)

# charts settings
plt.title('Desvio Padrão de cada algoritmo',
          fontsize=14, pad=20)
plt.xlabel('Base size', fontsize=12)
plt.ylabel('Distância da média', fontsize=12)
plt.yscale('linear')
plt.grid(True, which="both", ls="--", alpha=0.3)
# legend
plt.legend(title='Algorithms:', title_fontsize=12, fontsize=11)

plt.show()
