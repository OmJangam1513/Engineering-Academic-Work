import pandas as pd
import numpy as np

df =  pd.read_csv('E:\TE\Practicals\DSBDA\iris.csv')

df

df.shape

df.columns

df.columns.values

df.dtypes

df.index

df.describe

df.describe(include='all')

df.head()

df.tail()

df['species']=df['species'].map({'setosa':1,'virginica':2})

df

df = pd.get_dummies(df, columns=['species'])

df