import psycopg2
from os import system

#GLOBAL VARIABLES
session_user = "None" #User Session


#Connections
def db_connect_admin():
    try: #Database Connection Check
        connection = psycopg2.connect(user="db_admin",
                                      password="admin",
                                      host="192.168.1.251",
                                      port="5432",
                                      database="infrastructure")

        return connection  # Returning Conenction Object as "db_admin"


    except (Exception, psycopg2.Error) as error:
        print ("Error while connecting to PostgreSQL as 'db_admin'\n", error)
        raw_input("Press Enter to continue...")


def db_connect_cred():
    try: #Database Connection Check
        connection = psycopg2.connect(user="db_cred",
                                      password="cred",
                                      host="192.168.1.251",
                                      port="5432",
                                      database="infrastructure")

        return connection  # Returning Conenction Object as "db_cred"


    except (Exception, psycopg2.Error) as error:
        print ("Error while connecting to PostgreSQL as 'db_cred'\n", error)
        raw_input("\nPress Enter to continue...")


def db_connect_prov():
    try: #Database Connection Check
        connection = psycopg2.connect(user="db_prov",
                                      password="prov",
                                      host="192.168.1.251",
                                      port="5432",
                                      database="infrastructure")

        return connection  # Returning Conenction Object as "db_prov"


    except (Exception, psycopg2.Error) as error:
        print ("Error while connecting to PostgreSQL as 'db_prov'\n", error)
        raw_input("\nPress Enter to continue...")


def db_connect_cal():
    try: #Database Connection Check
        connection = psycopg2.connect(user="db_cal",
                                      password="cal",
                                      host="192.168.1.251",
                                      port="5432",
                                      database="infrastructure")


        return connection  # Returning Conenction Object as "db_cal"


    except (Exception, psycopg2.Error) as error:
        print ("Error while connecting to PostgreSQL as db_cal\n", error)
        raw_input("\nPress Enter to continue...")






#Controls
def  prov_resource(connection):
    try:
        global session_user
        cur = connection.cursor() #Defining db control cursor
        print "Enter Requirements For New Resource To Be Provisioned "

        comp = 0
        storg = 0
        mem = 0
        status = "P"

        while True:
            comp = int(raw_input("Enter Number of Compute Nodes (Min 0,Max 100):"))
            if comp >=0 and comp <= 100:
                system('clear')
                break
            system('clear')
        while True:
            storg = int(raw_input("Enter Number of Storage Nodes (Min 0,Max 100):"))
            if storg >=0 and storg <= 100:
                system('clear')
                break
            system('clear')

        while True:
            mem = int(raw_input("Enter Number of Memory Nodes (Min 0,Max 100):"))
            if mem >=0 and mem <= 100:
                system('clear')
                break
            #system('clear')
            raw_input("Press Enter to continue...")
            print session_user
        resource = (comp,storg,mem,status,session_user) # Provision Data to be entered into DB
        cur.execute(""" INSERT INTO "Infrastructure Spinner".resource_provision(c_nodes,s_nodes,m_nodes,status,username_credentials) VALUES (%s,%s,%s,%s,%s) RETURNING "PID" """,resource)
        pid = cur.fetchone()[0]
        connection.commit()
        count = cur.rowcount
        if count:
            print "Resource Request Sent Successfully!\n New Assigned PID is:",pid

        cur.close()


    except (Exception, psycopg2.Error) as error:
        if (connection):
            print("Failed to provision resource!\nReason:\n",error)






def pid_resource(connection):
    try:
        global session_user
        cur = connection.cursor()  # Defining db control cursor
        print "Currently Issued PIDs and Resources:"
        cur.execute(""" SELECT * FROM "Infrastructure Spinner".resource_provision """)
        rec = cur.fetchall()
        for row in rec:
            if row[5] == session_user:
                print "PID = ", row[0]
                print "Compute Nodes = ", row[1]
                print "Storage Nodes  = ", row[2]
                print "Memory Nodes  = ", row[3]
                print "Status  = ", row[4],"\n\n"

        cur.close()


    except (Exception, psycopg2.Error) as error:
        if (connection):
            print("Failed to request resources details!\nReason:\n",error)






def login_credentials(connection): #Loging in user
    try:
        cur = connection.cursor() #Defining db control cursor
        check = 0
        while True: # user Logging in Check
            u = raw_input("Enter username:")
            cur.execute(""" SELECT username FROM "Infrastructure Spinner".credentials""")
            rec = cur.fetchall()
            for row in rec:
                if row[0] == u:
                    count = 0
                    while count < 3: #Password Check (3 Entries Max)
                        p = raw_input("Enter Password:")
                        cur.execute(""" SELECT password FROM "Infrastructure Spinner".credentials""")
                        re = cur.fetchall()
                        for read in re:
                            if read[0] == p:
                                print "Welcome:",u
                                cur.close()
                                return u
                            check = 1
                        count = count + 1

            if check == 1:
                print "Wrong Password"
                break
        cur.close()

    except (Exception, psycopg2.Error) as error:
        if (connection):
            print("Failed to login Your Credentials!\nReason:\n",error)






def reg_credentials(connection): #Registering User
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

        cur.close()
        return u; #Returning user that was created!

    except (Exception, psycopg2.Error) as error:
        if (connection):
            print("Failed to Register Your Credentials!\nReason:\n",error)






def main_menu():
    system('clear')
    print "Welcome to Cloud Infrastructrue Spinner CLI mode"

    while True:
        choice = raw_input("1.Login\n2.Sign up\nEnter:")
        print choice


        if choice == '1':
            connetion = db_connect_cred()
            system('clear')
            global session_user
            session_user = str(login_credentials(connetion))
            raw_input("Press Enter to continue...")
            system('clear')

            if session_user != 'None':
                user_panel()

        if choice == '2':
            system('clear')
            connection = db_connect_cred()
            system('clear')
            reg_credentials(connection)
            raw_input("Press Enter to continue...")
            system('clear')
        system('clear')






def user_panel():
    while True:
        select = raw_input("1.Provision New Resource.\n2.Provisioned Resource.\n3.Logout.\n")
        if select == '1':
            connection = db_connect_admin()
            system('clear')
            prov_resource(connection)
            raw_input("Press Enter to continue...")
            system('clear')
        elif select == '2':
            connection = db_connect_prov()
            system('clear')
            pid_resource(connection)
            raw_input("Press Enter to continue...")
            system('clear')
        elif select == '3':
            global session_user
            session_user ='None'
            system('clear')
            print "Session Ended!"
            raw_input("Press Enter to continue...")
            break
        system('clear')





#MASTER FUNCTION TO CONTROL POSTGRESQL(TESTING PURPUSOE ONLY)
def master_control():
    while True:
        choice = int(raw_input("Select User\n1.Admin\n2.Prov\n3.Cred\n4.Cal"))
        system('clear')

        if choice == 1:
            try:
                connection = db_connect_admin()
                cur = connection.cursor()
                set = raw_input('Enter SQL STRING:')
                cur.execute(set)
                rec = cur.fetchall()
                for row in rec:
                    print row
            except (Exception, psycopg2.Error) as error:
                print ("Error while connecting to PostgreSQL as db_cal\n", error)

        if choice == 2:
            try:
                connection = db_connect_prov()
                cur = connection.cursor()
                set = raw_input('Enter SQL STRING:')
                cur.execute(set)
                rec = cur.fetchall()
                for row in rec:
                    print row
            except (Exception, psycopg2.Error) as error:
                print ("Error while connecting to PostgreSQL as db_cal\n", error)

        if choice == 3:
            try:
                connection = db_connect_cred()
                cur = connection.cursor()
                set = raw_input('Enter SQL STRING:')
                cur.execute(set)
                rec = cur.fetchall()
                for row in rec:
                    print row
            except (Exception, psycopg2.Error) as error:
                print ("Error while connecting to PostgreSQL as db_cal\n", error)

        if choice == 4:
            try:
                connection = db_connect_cal()
                cur = connection.cursor()
                set = raw_input('Enter SQL STRING:')
                cur.execute(set)
                rec = cur.fetchall()
                for row in rec:
                    print row
            except (Exception, psycopg2.Error) as error:
                print ("Error while connecting to PostgreSQL as db_cal\n", error)

        raw_input("Press Enter to continue...")
        system('clear')



#Main Function
def main():
    #main_menu()
    master_control() #Sample Sting = SELECT * FROM "Infrastructure Spinner".credentials











if __name__ == "__main__":main()

