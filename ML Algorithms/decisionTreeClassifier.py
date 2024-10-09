import numpy as np
import pandas as pd

class DecisionTreeClassifier:
    def __init__(self, max_depth=None):
        self.max_depth = max_depth
    
    # Function to calculate entropy
    def _entropy(self, y):
        unique_labels, label_counts = np.unique(y, return_counts=True)
        prob = label_counts / len(y)
        return -np.sum(prob * np.log2(prob))

    # Function to calculate information gain
    def _information_gain(self, X_col, y, threshold):
        # Split data
        left_idx = X_col <= threshold
        right_idx = X_col > threshold
        
        if len(y[left_idx]) == 0 or len(y[right_idx]) == 0:
            return 0
        
        # Calculate entropy before and after the split
        parent_entropy = self._entropy(y)
        n = len(y)
        n_left, n_right = len(y[left_idx]), len(y[right_idx])
        entropy_left, entropy_right = self._entropy(y[left_idx]), self._entropy(y[right_idx])
        
        # Calculate weighted entropy after the split
        weighted_avg_entropy = (n_left / n) * entropy_left + (n_right / n) * entropy_right
        
        # Information gain is the reduction in entropy
        return parent_entropy - weighted_avg_entropy

    # Split the dataset
    def _best_split(self, X, y):
        best_gain = -1
        best_split = None
        n_features = X.shape[1]
        
        for feature_idx in range(n_features):
            X_col = X[:, feature_idx]
            thresholds = np.unique(X_col)
            
            for threshold in thresholds:
                gain = self._information_gain(X_col, y, threshold)
                if gain > best_gain:
                    best_gain = gain
                    best_split = (feature_idx, threshold)
                    
        return best_split

    # Build the tree recursively
    def _build_tree(self, X, y, depth=0):
        n_samples, n_features = X.shape
        num_classes = len(np.unique(y))
        
        if num_classes == 1 or n_samples == 0 or (self.max_depth and depth >= self.max_depth):
            leaf_value = self._most_common_label(y)
            return {'leaf': True, 'value': leaf_value}
        
        feature_idx, threshold = self._best_split(X, y)
        
        left_idxs = X[:, feature_idx] <= threshold
        right_idxs = X[:, feature_idx] > threshold
        
        left_subtree = self._build_tree(X[left_idxs], y[left_idxs], depth + 1)
        right_subtree = self._build_tree(X[right_idxs], y[right_idxs], depth + 1)
        
        return {'leaf': False, 'feature_idx': feature_idx, 'threshold': threshold, 'left': left_subtree, 'right': right_subtree}

    # Predict a single sample
    def _predict(self, sample, tree):
        if tree['leaf']:
            return tree['value']
        
        feature_idx = tree['feature_idx']
        threshold = tree['threshold']
        
        if sample[feature_idx] <= threshold:
            return self._predict(sample, tree['left'])
        else:
            return self._predict(sample, tree['right'])
    
    def fit(self, X, y):
        self.tree_ = self._build_tree(X, y)
    
    def predict(self, X):
        return np.array([self._predict(sample, self.tree_) for sample in X])
    
    # Utility function to find the most common label
    def _most_common_label(self, y):
        return np.bincount(y).argmax()

# Example usage
if __name__ == "__main__":
    # Example dataset
    X = np.array([[2, 3], [10, 15], [4, 7], [9, 12], [8, 9]])
    y = np.array([0, 1, 0, 1, 1])
    
    tree = DecisionTreeClassifier(max_depth=3)
    tree.fit(X, y)
    
    predictions = tree.predict(X)
    print("Predictions:", predictions)
