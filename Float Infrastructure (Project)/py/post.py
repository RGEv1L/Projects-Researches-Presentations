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




except (Exception, psycopg2.Error) as error:
    print ("Error while connecting to PostgreSQL", error)

finally:
    # closing database connection.
    if (connection):
        cursor.close()
        connection.close()
        print("PostgreSQL connection is closed")



