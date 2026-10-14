#!/usr/bin/env python
# coding: utf-8

import pandas as pd
import sklearn
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression, LogisticRegression
from sklearn.metrics import mean_squared_error, r2_score

# Load Iris dataset
iris = load_iris()

# Create DataFrame
df = pd.DataFrame(data=iris.data, columns=iris.feature_names)
df['target'] = iris.target

# Load Housing dataset
df1 = pd.read_csv('/home/comp-s1-07/Desktop/archive (2)/housing.csv')

# Split features and target
x = df1.drop('MEDV', axis=1)
y = df1['MEDV']

# Train-test split
x_train, x_test, y_train, y_test = train_test_split(
    x, y, test_size=0.2, random_state=42
)

# Train Linear Regression model
model = LinearRegression()
model.fit(x_train, y_train)

# Predictions
y_pred = model.predict(x_test)

# Evaluation
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

print("Mean Squared Error:", mse)
print("R2 Score:", r2)

# Coefficients
coefficients = pd.DataFrame({
    'Feature': x.columns,
    'Coefficient': model.coef_
})

print(coefficients)