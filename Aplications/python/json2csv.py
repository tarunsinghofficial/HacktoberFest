import pandas as pd
df = pd.read_json (r'C:\\Users\\Rohit\\Desktop\\JSON\\0.json')
df.to_csv (r'C:\\Users\\Rohit\\Desktop\\JSON\\0.csv', index = None)
