# %% Importing dataset
from sklearn.datasets import load_boston

boston = load_boston()

# %% train/test split
from sklearn.model_selection import train_test_split

X, y = boston['data'], boston['target']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

print(X_train.shape, y_train.shape, X_test.shape, y_test.shape)

# %% Pipeline
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.impute import SimpleImputer
from sklearn.tree import DecisionTreeRegressor

model_pipeline = Pipeline([
    ('imputer', SimpleImputer()),
    ('scaler', StandardScaler()),
    ('estimator', DecisionTreeRegressor())
])

# %% Training & Scoring
import numpy as np
from sklearn.metrics import mean_squared_error, r2_score

model_pipeline.fit(X_train, y_train)

training_predictions = model_pipeline.predict(X_train)
testing_predictions = model_pipeline.predict(X_test)

def show_metrics(pred, true, name):
    print(f'{name} RMSE: {np.sqrt(mean_squared_error(true, pred))}')
    print(f'{name} R2 Score: {r2_score(true, pred)}')

show_metrics(training_predictions, y_train, 'Training')
show_metrics(testing_predictions, y_test, 'Testing')

# ~4 RMSE
# ~0.8 R2
