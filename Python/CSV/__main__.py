import os
import csv
import operator

DATABASE = {"Key" : 0}

def main():
  for file in os.listdir(os.getcwd()):
    with open(file) as csv_data:
      for row in csv_data:
        reader = csv.reader(csv_data, delimiter=',')
        row_data = list(reader)
        volume = 0
        for index in row_data:
          try:
            volume += float(index[12])
          except:
            # print(f"ERROR (Incompatible File): {file}")
            pass
    DATABASE[f"{file[:-4]}".replace("_", " ").title()] = volume

  top = sorted(DATABASE.items(), key = lambda x: x[1], reverse = True)[:100]

  print(type(top))
  for company in top:
    print(company)

if __name__ == "__main__":
  main()
