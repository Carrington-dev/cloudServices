
import pandas as pd
url_link = 'https://tradingeconomics.com/currencies?base=usd'
# url_link = 'https://finance.yahoo.com/currencies/'
import requests
r = requests.get(url_link)
r = requests.get(url_link,headers ={'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'})

df = pd.read_html(f'{r.text}')[0]
        
def get_base(x):
    return x.split("/")[0]

def get_prime(x):
    return x.split("/")[1]

prime = df['Name'].apply(lambda x : get_prime(x))
df['Base'] =  (pd.Series(df['Name'].apply(lambda x : get_base(x))))
df['Prime'] =  prime.copy()
df.set_index('Prime', inplace=True)
new_df = df[['Base', 'Last Price']]
a = new_df.to_dict()
price_items = a['Last Price']
base_items = a['Last Price']