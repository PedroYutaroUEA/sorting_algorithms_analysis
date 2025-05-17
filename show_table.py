import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

df = pd.read_csv('resultados.csv')

fig, ax = plt.subplots(figsize=(12, 4))
ax.axis('off')

table_data = []
for _, row in df.iterrows():
    table_data.append([
        f"{row['Base']:,}",
        f"{row['MergeSort_mean']:.2f} ± {row['MergeSortDP']:.2f}",
        f"{row['QuickSort_mean']:.2f} ± {row['QuickSortDP']:.2f}",
        f"{row['HeapSort_mean']:.2f} ± {row['HeapSortDP']:.2f}"
    ])

headers = [
    "Tamanho da Base",
    "MergeSort (ms)",
    "QuickSort (ms)",
    "HeapSort (ms)"
]

table = ax.table(
    cellText=table_data,
    colLabels=headers,
    loc='center',
    cellLoc='center',
    colColours=['#f7f7f7']*4
)

table.auto_set_font_size(False)
table.set_fontsize(12)
table.scale(1.2, 1.5)  # Ajustar tamanho

# Destacar cabeçalhos
for (i, j), cell in table.get_celld().items():
    if i == 0:  # Cabeçalhos
        cell.set_text_props(weight='bold', color='white')
        cell.set_facecolor('#4b61d1')
    else:
        cell.set_facecolor('#f7f7f7')

plt.title('Comparação de Desempenho dos Algoritmos de Ordenação', pad=20)
plt.tight_layout()
plt.show()
