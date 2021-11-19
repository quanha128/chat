import csv

n_packet = 0
n_bytes = 0
with open('test.csv') as scv_in:
    reader = csv.DictReader(scv_in)
    for row in reader:
        if float(row['Time']) <= 60:
            if (row['Destination']=='192.168.0.174') and (row['Protocol']=='TCP'):
                n_packet += 1
                n_bytes += int(row['Length'])

print(n_packet ,n_bytes)