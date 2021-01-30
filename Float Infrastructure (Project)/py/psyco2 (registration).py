import psycopg2



def entry_credentials(connection): #Registering User
    try:
        cur = connection.cursor() #Defining db control cursor

        length = 5
        while length <= 5:
            u = raw_input("Enter your Username.Must be more than 5 characters : ")
            length = len(u)

            # Username Uniqueness Check
            cur.execute(""" SELECT username FROM "Infrastructure Spinner".credentials""")
            rec = cur.fetchall()
            for row in rec:
                if row[0] == u:
                    print "Username Already Exists.Choose Another!"
                    length = 5 # resetting While




        length = 5
        while length <= 5:
            p = raw_input("Enter your Password.Must be more than 5 characters : ")
            length = len(p)



        record = (u,p)
        cur.execute(""" INSERT INTO "Infrastructure Spinner".credentials(username, password) VALUES (%s,%s)""",record)

        connection.commit()
        count = cur.rowcount
        if count:
            print "Credentials Registered Successfully!"

        return u; #Returning user that was created!

    except (Exception, psycopg2.Error) as error:
        if (connection):
            print("Failed to Register Your Credentials!\nReason:\n",error)





def main():

    try: #Database Connection Check
        connection = psycopg2.connect(user="db_admin",
                                      password="admin",
                                      host="192.168.1.251",
                                      port="5432",
                                      database="infrastructure")
        cursor = connection.cursor()

        #Postgresql Server Details

        # Print PostgreSQL Connection properties
        #print (connection.get_dsn_parameters(), "\n")
        # Print PostgreSQL version
        #cursor.execute("SELECT version();")
        #record = cursor.fetchone()
        #print("You are connected to - ", record, "\n")






        #Application Operational Part
        choice = -1

        print "Welcome to Cloud Infrastructrue Spinner CLI mode\n1.login\n2.Sign up\n"


        #Calling Registration functions
        username = entry_credentials(connection)





    except (Exception, psycopg2.Error) as error:
        print ("Error while connecting to PostgreSQL", error)

    finally:
        # closing database connection.
        if (connection):
            cursor.close()
            connection.close()
            print("PostgreSQL connection is closed")

if __name__ == "__main__":main()

