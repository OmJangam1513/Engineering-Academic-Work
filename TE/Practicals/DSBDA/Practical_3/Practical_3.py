import pandas as pd
import numpy as np

df=pd.read_csv('/home/comp-proj-44/Downloads/archive/iris.csv')

df['species']=df['species'].map({'setosa':0,'virginica':1, 'versicolor':2})

df.dtypes

df.head()

df.isnull().sum()

df.describe()

df.shape

df.info()

df.min()

df.max()

df.mean()

df.median()

df.mode()

df.std()

df.groupby('species')['sepal_length'].agg(['mean','median','min','max','std'])

df2=pd.read_csv('/home/comp-proj-44/Downloads/archive/iris.csv')

def stats_summry(data):
    return{
        'Mean':data.mean(),
        'STD dev': data.std(),
        '25th percentile':data.quantile(0.25),
        '50th percentile':data.quantile(0.5),
        '75th percentile':data.quantile(0.75)
    }
for sp in df2['species'].unique():
    print('\n stats for',sp)
    print(stats_summry(df2[df['species']==sp]['petal_length']))

    df.var()

    df[['species',]].groupby(speci).mean()