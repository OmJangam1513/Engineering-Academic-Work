#!/usr/bin/env python
# coding: utf-8

import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load dataset
df = sns.load_dataset("titanic")

# Display first rows
print(df.head())

# Check missing values in age
print(df['age'].isnull().sum())

# Drop rows with missing age
df = df.dropna(subset=['age'])

# Check missing values again
print(df.isnull().sum())

# Box Plot – Age vs Gender with Survival
sns.boxplot(x='sex', y='age', hue='survived', data=df)
plt.title("Age Distribution by Gender and Survival")
plt.show()