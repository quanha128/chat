import pandas as pd
from pandas import Series, DataFrame
from matplotlib import pyplot as plt
import numpy as np

df = pd.read_csv("master.csv")
df = df[df['country']=='Japan']

df25 = df[df['age']=='25-34 years']
df25_m = df25[df25['sex']=='male']
df25_f = df25[df25['sex']=='female']

df35 = df[df['age']=='35-54 years']
df35_m = df35_54[df35['sex']=='male']
df35_f = df35_54[df35['sex']=='female']