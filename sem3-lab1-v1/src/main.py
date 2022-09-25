import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
 
 
 
pd.options.display.max_rows = 7
sp = pd.read_csv("AllRandomInt.csv")
#sp = pd.read_csv("population_by_country_2020.csv", header=None, names=["Country (or dependency)", "Population (2020)"])
#sp.set_index("Country (or dependency)", inplace = True)
#sp.set_index("Population (2020)",inplace = True)
 
sp.plot()
#sp.plot.area()
sp.hist()
sp_copy = (sp - sp.mean())/sp.std()
sp_copy.plot(figsize=(10,5))
sp_copy.hist()
 
 
sp.plot.box()
sp.plot.barh(figsize = (10,50))
sp.plot.bar(figsize = (50,10))
sp.plot(kind="hist")
sp.corr()