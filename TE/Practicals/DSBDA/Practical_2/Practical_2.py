import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Load dataset
df = pd.read_csv("E:\TE\Practicals\DSBDA\Practical_2\Student_performance_10k.csv")

# Basic info
df.head()
df.dtypes
df.shape
df.isnull().sum()

# Handle Missing Values
# Numeric
df['reading_score'] = df['reading_score'].fillna(df['reading_score'].median())

# Categorical
df['gender'] = df['gender'].fillna(df['gender'].mode()[0])

# Check again
df.isnull().sum()

# Detect inconsistencies
df[(df['writing_score'] < 25) | (df['writing_score'] > 75)]

# Fix using clipping
df['Attendance'] = df['Attendance'].clip(0, 100)
df['CGPA'] = df['CGPA'].clip(0, 10)

# Detect Outliers (IQR)
Q1 = df['total_score'].quantile(0.25)
Q3 = df['total_score'].quantile(0.75)
IQR = Q3 - Q1

upper_limit = Q3 + 1.5 * IQR
lower_limit = Q1 - 1.5 * IQR

# Handle Outliers (Capping)
df['total_score'] = np.where(
    df['total_score'] > upper_limit, upper_limit,
    np.where(df['total_score'] < lower_limit, lower_limit, df['total_score'])
)

# Verify no outliers
outliers = df[(df['total_score'] < lower_limit) | (df['total_score'] > upper_limit)]

# Summary stats
df['total_score'].describe()

# Histogram
plt.hist(df['total_score'])
plt.title("Histogram of Total Score")
plt.show()

# Reflection transformation
max_att = df['total_score'].max()
df['total_score_reflect'] = max_att + 1 - df['total_score']

# Skewness
df['total_score'].skew()

# Log transformation
df['Log_total_score'] = np.log(df['total_score'])

# Square root transformation
df['sqrt_total_score'] = np.sqrt(df['total_score'])

# Power transformation
df['total_score_transformed'] = df['total_score'] ** 1.7

# Histograms
df['total_score_transformed'].hist()
plt.show()

df['total_score'].hist()
plt.show()