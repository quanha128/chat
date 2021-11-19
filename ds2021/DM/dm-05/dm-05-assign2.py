import pandas as pd
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB

csv_in = 'fruits.csv'
df = pd.read_csv(csv_in, skiprows=0, delimiter=',', header=0)
df.columns = ['category', 'text']
X_train = df['text']
y_train = df['category']

while True:
    vectorizer = CountVectorizer()
    vectorizer.fit(X_train)
    vectorizer.get_feature_names()
    X_train_bow = vectorizer.transform(X_train)
    model = MultinomialNB(alpha=1.0, class_prior=[1/3,1/3,1/3])
    model.fit(X_train_bow, y_train)
    print(">>> ", end="")
    X_test = [input()]
    X_test_bow = vectorizer.transform(X_test)
    model.predict_proba(X_test_bow)
    print('Prediction:',model.predict(X_test_bow))