#!/usr/bin/env python
# coding: utf-8

import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load dataset
df = sns.load_dataset("titanic")

# Display first rows
print(df.head())

# Info and description
print(df.info())
print(df.describe())

# Check missing values
print(df.isnull().sum())

# -------------------- PART A: FINDING PATTERNS --------------------

# Survival count
sns.countplot(x='survived', data=df)
plt.title("Survival Count")
plt.show()

# Survival by gender
sns.countplot(x='sex', hue='survived', data=df)
plt.title("Survival by Gender")
plt.show()

# Survival by passenger class
sns.countplot(x='pclass', hue='survived', data=df)
plt.title("Survival by Passenger Class")
plt.show()

# -------------------- PART B: HISTOGRAM --------------------

plt.hist(df['fare'].dropna(), bins=20)
plt.title("Distribution of Fare")
plt.xlabel("Fare")
plt.ylabel("Frequency")
plt.show()