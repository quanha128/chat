import requests
from bs4 import BeautifulSoup
import pandas as pd
import re

url = 'https://genshin-impact.fandom.com/wiki/'
csv_out = 'furniture2.csv'

indoor_set = ["Eternal_Domain_of_Fleeting_Dreams", "A_Thousand_Swings", "Of_Maple_and_Tea_Scents_Entwined"]

# df = pd.DataFrame(indoor_set, header=None)
s = requests.Session()

item_name = []
item_qty = []

for item in indoor_set:
  r = s.get(url + item)

  soup = BeautifulSoup(r.text, 'html.parser')

  try:
    parent = soup.find_all("div", class_="new_genshin_recipe_body")
    children = parent[0].find_all("div", class_="card_with_caption hidden")
    for chi in children[:len(children)-1]:
      txt = chi.text
      _, qty, name = re.split(r'(\d+)', txt)
      item_name.append(name)
      item_qty.append(qty)
  except:
    print("Error")

d = {
  "Name": item_name,
  "Quantity": item_qty
}

df = pd.DataFrame(d)
print(df)

df.to_csv(csv_out, index=False)