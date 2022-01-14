import requests
from bs4 import BeautifulSoup
import pandas as pd
import re

url = 'https://genshin-impact.fandom.com/wiki/'
csv_out = 'materials2.csv'
csv_in = 'furniture2.csv'

df = pd.read_csv(csv_in, header=1)
# print(df)
s = requests.Session()

item_name = []
item_qty = []

for item, num in df.itertuples(index=False):
  # solve string
  sub = item.replace(" ", "_")
  print(sub)

  r = s.get(url + sub)

  soup = BeautifulSoup(r.text, 'html.parser')

  try:
    parent = soup.find_all("div", class_="new_genshin_recipe_body")
    children = parent[0].find_all("div", class_="card_with_caption hidden")
    for chi in children[:len(children)-1]:
      txt = chi.text
      _, qty, name = re.split(r'(\d+)', txt)
      item_name.append(name)
      item_qty.append(int(qty)*num)
  except:
    print("Not a craftable item")

print(item_name)
print(item_qty)


# d = {
#   "Name": item_name,
#   "Quantity": item_qty
# }

# df = pd.DataFrame(d)
# print(df)

# df.to_csv(csv_out, index=False)