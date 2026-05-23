import pandas as pd

from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report
from imblearn.combine import SMOTETomek

import m2cgen as m2c


def load_dataset():

    df_temp = pd.read_csv("ashrae_db2.01.csv", encoding="latin1", nrows=1)
    col_height = [c for c in df_temp.columns if "height" in c][0]
    col_weight = [c for c in df_temp.columns if "weight" in c][0]

    columns_to_load = [
        "Air temperature (C)",
        "Relative humidity (%)",
        "Air velocity (m/s)",
        "Clo",
        "Met",
        "Outdoor monthly air temperature (C)",
        "Thermal comfort",
        "Sex",
        "Age",
        "Season",
        col_height,
        col_weight
    ]

    df = pd.read_csv("ashrae_db2.01.csv", encoding="latin1", usecols=columns_to_load, low_memory=False)

    df.rename(columns={
        "Air temperature (C)": "temp",
        "Relative humidity (%)": "humidity",
        "Air velocity (m/s)": "velocity",
        "Clo": "clo",
        "Met": "met",
        "Outdoor monthly air temperature (C)": "outdoor_temp",
        "Sex": "gender",
        "Age": "age",
        "Season": "season",
        col_height: "height",
        col_weight: "weight",
        "Thermal comfort": "label"
    }, inplace=True)

    df["label"] = pd.to_numeric(df["label"], errors="coerce")

    df.dropna(inplace=True)

    df["label"] = df["label"].astype(int)

    # Gom label thành 3 loại: 0 (Khó chịu), 1 (Bình thường), 2 (Dễ chịu)
    def map_comfort(val):
        if val in [1, 2]: return 0
        elif val in [3, 4]: return 1
        elif val in [5, 6]: return 2
        else: return 1

    df["label"] = df["label"].apply(map_comfort)

    # Male=1, Female=0
    gender_map = {"Male": 1, "Female": 0}
    df["gender"] = df["gender"].map(gender_map)

    # Spring=0, Summer=1, Autumn=2, Winter=3
    season_map = {"Spring": 0, "Summer": 1, "Autumn": 2, "Winter": 3}
    df["season"] = df["season"].map(season_map)

    # Young=0, Young Adult=1, Middle Age=2, Senior=3
    def bin_age(age):
        if age <= 18:   return 0  
        elif age <= 35: return 1  
        elif age <= 55: return 2  
        else:           return 3  

    df["age"] = df["age"].apply(bin_age)

    # Tính BMI 
    df["bmi"] = df["weight"] / ((df["height"] / 100) ** 2)

    # Tính chênh lệch nhiệt độ trong nhà và ngoài trời
    df["temp_outdoor_diff"] = df["temp"] - df["outdoor_temp"]

    return df

def data_preprocessing(df: pd.DataFrame):

    df.drop_duplicates(inplace=True)

    selected_features = [
        "temp",
        "humidity",
        "velocity",
        "clo",
        "met",
        "outdoor_temp",
        "gender",
        "age",
        "season",
        "bmi",
        "temp_outdoor_diff"
    ]

    preprocessor = ColumnTransformer([
                        ("num", Pipeline([
                                ("scaler", StandardScaler())
                            ]), selected_features)
                    ])

    return df, selected_features, preprocessor


# === MAIN ===
df = load_dataset()

df, selected_features, preprocessor = data_preprocessing(df)

X = df[selected_features].copy()
y = df["label"].copy()

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y)

# Cân bằng dữ liệu trên tập huấn luyện bằng kỹ thuật SMOTETomek (Kết hợp Oversampling và Undersampling dọn nhiễu)
# smote = SMOTETomek(random_state=42)
# X_train, y_train = smote.fit_resample(X_train, y_train)

model = RandomForestClassifier(
        n_estimators=200,
        max_depth=15,
        min_samples_split=5,
        min_samples_leaf=3,
        max_features="sqrt",
        class_weight="balanced",
        random_state=42)

# pipe_model = Pipeline([("prep", preprocessor), ("clf", model)])
pipe_model = model

pipe_model.fit(X_train, y_train)

y_pred = pipe_model.predict(X_test)
acc = accuracy_score(y_test, y_pred)

report = classification_report(y_test, y_pred, zero_division=0)

print(f"Accuracy: {acc}")
print(f"Report: \n{report}")

# code = m2c.export_to_c(pipe_model)

# output_header_path = "TinyML_RF.h"
# with open(output_header_path, 'w') as f:
#     f.write("/* Random Forest Model converted by m2cgen */\n")
#     f.write("#ifndef MODEL_H\n#define MODEL_H\n\n")
#     f.write(code)
#     f.write("\n\n#endif")

# print(f"Đã xuất mô hình tại: {output_header_path}")