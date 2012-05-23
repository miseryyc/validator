import psycopg2
conn = psycopg2.connect("host=proteomics3.ath.cx user=postgres password=Quantum135! dbname=tryptic")
cur = conn.cursor()
cur.execute("SELECT * FROM mapping where geneid = '4156271'")
a = cur.fetchall()
for line in a:
	print line
n.commit()
cur.close()
conn.close()