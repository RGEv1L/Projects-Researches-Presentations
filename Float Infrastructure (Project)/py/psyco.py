import psycopg2

try:
    connection = psycopg2.connect(user="db_admin",
                                  password="admin",
                                  host="192.168.1.251",
                                  port="5432",
                                  database="infrastructure")
    cursor = connection.cursor()
    # Print PostgreSQL Connection properties
    print (connection.get_dsn_parameters(), "\n")
    # Print PostgreSQL version
    cursor.execute("SELECT version();")
    record = cursor.fetchone()
    print("You are connected to - ", record, "\n")


    #Adding data to credentials table

    postgres_insert_query = """ INSERT INTO "Infrastructure Spinner".credentials(
	username, password)(%s,%s)"""

    record_to_insert = ('AKhan', 'RG')

    cursor.execute(postgres_insert_query, record_to_insert)
    connection.commit()
    count = cursor.rowcount
    print (count, "Record inserted successfully into mobile table")

except (Exception, psycopg2.Error) as error:
    if (connection):
        print("Failed to insert record into mobile table", error)


