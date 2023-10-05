# Import necessary libraries and modules
import CargaDatos as cd  # Import a module named "CargaDatos" as "cd"
import tensorflow as tf  # Import TensorFlow library as "tf"
import sklearn as sk  # Import scikit-learn library as "sk"
import keras  # Import Keras library
import matplotlib.pyplot as plt  # Import matplotlib.pyplot for plotting

# Load data from the "CargaDatos" module into variables
x_biopsy, y_biopsy, X_train, X_test, X_val, y_train, y_test, y_val = cd.x_biopsy, cd.y_biopsy, cd.X_train, cd.X_test, cd.X_val, cd.y_train, cd.y_test, cd.y_val

# Define a class "NeuralModel" to create and train a neural network
class NeuralModel:
    def __init__(self, x_train, y_train, x_test, y_test, x_val, y_val, epochs, batch_size):
        self.x_train = x_train
        self.y_train = y_train
        self.x_test = x_test
        self.y_test = y_test
        self.x_val = x_val
        self.y_val = y_val
        self.epochs = epochs
        self.batch_size = batch_size
        self.model = keras.models.Sequential()  # Create a Sequential Keras model
        self.history = None
        self.accuracy = None
        self.loss = None
        self.val_accuracy = None
        self.val_loss = None

    # Define a method to create the neural network model
    def create_model(self):
        self.model.add(keras.layers.Dense(128, activation='relu', input_shape=(31,)))  # Add a dense layer with 128 units and ReLU activation
        self.model.add(keras.layers.Dense(64, activation='relu'))  # Add a dense layer with 64 units and ReLU activation
        self.model.add(keras.layers.Dense(32, activation='relu'))  # Add a dense layer with 32 units and ReLU activation
        self.model.add(keras.layers.Dense(1, activation='sigmoid'))  # Add a dense layer with 1 unit and sigmoid activation
        self.model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])  # Compile the model with Adam optimizer and binary cross-entropy loss

    # Define a method to train the neural network
    def train_model(self):
        self.history = self.model.fit(self.x_train, self.y_train, epochs=self.epochs, batch_size=self.batch_size, validation_data=(self.x_val, self.y_val), callbacks=[keras.callbacks.EarlyStopping(patience=3, restore_best_weights=True)])  # Fit the model to the training data with early stopping

    # Define a method to evaluate the trained model
    def evaluate_model(self):
        self.accuracy = self.history.history['accuracy']
        self.loss = self.history.history['loss']
        self.val_accuracy = self.history.history['val_accuracy']
        self.val_loss = self.history.history['val_loss']

    # Define a method to plot the model's training history
    def plot_model(self):
        plt.plot(self.accuracy)
        plt.plot(self.val_accuracy)
        plt.title('Model Accuracy')
        plt.ylabel('Accuracy')
        plt.xlabel('Epoch')
        plt.legend(['Train', 'Val'], loc='upper left')
        plt.show()

        plt.plot(self.loss)
        plt.plot(self.val_loss)
        plt.title('Model Loss')
        plt.ylabel('Loss')
        plt.xlabel('Epoch')
        plt.legend(['Train', 'Val'], loc='upper left')
        plt.show()

    # Define a method to test the model on the test data
    def test_model(self):
        test_loss, test_acc = self.model.evaluate(self.x_test, self.y_test, verbose=2)  # Evaluate the model on the test data
        print('\nTest accuracy:', test_acc)
        print('\nTest loss:', test_loss)

# Create an instance of the NeuralModel class
NeuralModel = NeuralModel(X_train, y_train, X_test, y_test, X_val, y_val, 100, 10)  # Initialize with training and testing data, and set epochs and batch size
NeuralModel.create_model()  # Create the neural network model
NeuralModel.train_model()  # Train the model
NeuralModel.evaluate_model()  # Evaluate the model
NeuralModel.plot_model()  # Plot the training history
NeuralModel.test_model()  # Test the model on the test data
