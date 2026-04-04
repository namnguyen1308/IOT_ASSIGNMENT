import pandas as pd

from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score


def load_dataset():
    return pd.read_csv("dataset.csv", names=["temp", "humidity", "label"], header=0)

def data_preprocessing(df: pd.DataFrame):

    df.drop_duplicates(inplace=True)

    selected_features = ["temp", "humidity"]

    preprocessor = ColumnTransformer([
                        ("num", Pipeline([
                                ("impute", SimpleImputer(strategy="median")),
                                ("scaler", StandardScaler())
                            ]), selected_features)
                    ])
    
    return df, selected_features, preprocessor

df = load_dataset()

df, selected_features, preprocessor = data_preprocessing(df)

X = df[selected_features].copy()
y = df["label"].copy()

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=100, stratify=y)

model = RandomForestClassifier(
        n_estimators=10,
        max_depth=5,
        min_samples_split=2,
        min_samples_leaf=2,
        max_features=None,
        random_state=42)

pipe_model = Pipeline([("prep", preprocessor), ("clf", model)])

pipe_model.fit(X_train, y_train)

y_pred = pipe_model.predict(X_test)
acc = accuracy_score(y_test, y_pred)

print(f"Accuracy: {acc}")