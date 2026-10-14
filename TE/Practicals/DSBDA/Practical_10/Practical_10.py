#!/usr/bin/env python
# coding: utf-8

import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load dataset
df = sns.load_dataset("iris")

# Display first rows
print(df.head())

# Check data types
print(df.dtypes)

# -------------------- PART A: HISTOGRAM --------------------

df.hist(bins=15, figsize=(8, 6))
plt.suptitle("Histogram of Iris Features")
plt.show()

# -------------------- PART B: BOX PLOT --------------------

plt.figure(figsize=(8, 6))
sns.boxplot(data=df)
plt.title("Boxplot of Iris Features")
plt.show()