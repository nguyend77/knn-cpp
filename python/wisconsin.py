import time
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import classification_report

cancer = load_breast_cancer()
X = cancer.data
y = cancer.target

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

knn = KNeighborsClassifier(n_neighbors=3)

start = time.perf_counter()
knn.fit(X_train_scaled, y_train)
y_pred = knn.predict(X_test_scaled)
end = time.perf_counter()

print(f"Execution time: {(end-start)*1000:.0f} ns")
print(classification_report(y_test, y_pred))