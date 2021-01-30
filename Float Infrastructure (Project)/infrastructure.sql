-- object: db_admin | type: ROLE --
-- DROP ROLE IF EXISTS db_admin;
CREATE ROLE db_admin WITH 
	SUPERUSER
	CREATEDB
	CREATEROLE
	INHERIT
	LOGIN
	REPLICATION;
-- ddl-end --

-- object: db_cal | type: ROLE --
-- DROP ROLE IF EXISTS db_cal;
CREATE ROLE db_cal WITH 
	LOGIN;
-- ddl-end --

-- object: db_cred | type: ROLE --
-- DROP ROLE IF EXISTS db_cred;
CREATE ROLE db_cred WITH 
	LOGIN;
-- ddl-end --

-- object: db_prov | type: ROLE --
-- DROP ROLE IF EXISTS db_prov;
CREATE ROLE db_prov WITH 
	LOGIN;
-- ddl-end --


-- Database creation must be done outside a multicommand file.
-- These commands were put in this file only as a convenience.
-- -- object: infrastructure | type: DATABASE --
-- -- DROP DATABASE IF EXISTS infrastructure;
-- CREATE DATABASE infrastructure
-- 	ENCODING = 'UTF8'
-- 	TABLESPACE = pg_default
-- 	OWNER = db_admin;
-- -- ddl-end --
-- 

-- object: "Infrastructure Spinner" | type: SCHEMA --
-- DROP SCHEMA IF EXISTS "Infrastructure Spinner" CASCADE;
CREATE SCHEMA "Infrastructure Spinner";
-- ddl-end --
ALTER SCHEMA "Infrastructure Spinner" OWNER TO db_admin;
-- ddl-end --

SET search_path TO pg_catalog,public,"Infrastructure Spinner";
-- ddl-end --

-- object: "Infrastructure Spinner".servers | type: TABLE --
-- DROP TABLE IF EXISTS "Infrastructure Spinner".servers;
CREATE TABLE "Infrastructure Spinner".servers(
	hostname text NOT NULL,
	t_cores integer NOT NULL,
	t_cores_committed integer NOT NULL,
	f_cores integer NOT NULL,
	t_memory integer NOT NULL,
	t_memory_committed integer NOT NULL,
	f_memory integer NOT NULL,
	t_storage integer NOT NULL,
	t_storage_committed integer NOT NULL,
	f_storage integer NOT NULL,
	class char(1) NOT NULL,
	ip_addr inet NOT NULL,
	CONSTRAINT compute_servers_pk PRIMARY KEY (hostname),
	CONSTRAINT ip_addr UNIQUE (ip_addr)

)
TABLESPACE pg_default;
-- ddl-end --
ALTER TABLE "Infrastructure Spinner".servers OWNER TO db_admin;
-- ddl-end --

-- object: "Infrastructure Spinner".credentials | type: TABLE --
-- DROP TABLE IF EXISTS "Infrastructure Spinner".credentials;
CREATE TABLE "Infrastructure Spinner".credentials(
	username text NOT NULL,
	password text NOT NULL,
	CONSTRAINT credentials_pk PRIMARY KEY (username)

)
TABLESPACE pg_default;
-- ddl-end --
ALTER TABLE "Infrastructure Spinner".credentials OWNER TO db_cal;
-- ddl-end --

-- object: "Infrastructure Spinner"."resource_provisioned_PID_seq" | type: SEQUENCE --
-- DROP SEQUENCE IF EXISTS "Infrastructure Spinner"."resource_provisioned_PID_seq" CASCADE;
CREATE SEQUENCE "Infrastructure Spinner"."resource_provisioned_PID_seq"
	INCREMENT BY 1
	MINVALUE -2147483648
	MAXVALUE 2147483647
	START WITH 1
	CACHE 1
	NO CYCLE
	OWNED BY NONE;
-- ddl-end --

-- object: "Infrastructure Spinner"."pricing_BID_seq" | type: SEQUENCE --
-- DROP SEQUENCE IF EXISTS "Infrastructure Spinner"."pricing_BID_seq" CASCADE;
CREATE SEQUENCE "Infrastructure Spinner"."pricing_BID_seq"
	INCREMENT BY 1
	MINVALUE -2147483648
	MAXVALUE 2147483647
	START WITH 1
	CACHE 1
	NO CYCLE
	OWNED BY NONE;
-- ddl-end --

-- object: "Infrastructure Spinner"."resource_provisioned_PID_seq1" | type: SEQUENCE --
-- DROP SEQUENCE IF EXISTS "Infrastructure Spinner"."resource_provisioned_PID_seq1" CASCADE;
CREATE SEQUENCE "Infrastructure Spinner"."resource_provisioned_PID_seq1"
	INCREMENT BY 1
	MINVALUE -2147483648
	MAXVALUE 2147483647
	START WITH 1
	CACHE 1
	NO CYCLE
	OWNED BY NONE;
-- ddl-end --

-- object: "Infrastructure Spinner".resource_provision | type: TABLE --
-- DROP TABLE IF EXISTS "Infrastructure Spinner".resource_provision;
CREATE TABLE "Infrastructure Spinner".resource_provision(
	"PID" integer NOT NULL DEFAULT nextval('"Infrastructure Spinner"."resource_provisioned_PID_seq1"'::regclass),
	c_nodes integer NOT NULL,
	s_nodes integer NOT NULL,
	m_nodes integer NOT NULL,
	status char(1) NOT NULL,
	username_credentials text NOT NULL,
	CONSTRAINT resource_provisioned_pk PRIMARY KEY ("PID")

)
TABLESPACE pg_default;
-- ddl-end --
ALTER TABLE "Infrastructure Spinner".resource_provision OWNER TO db_prov;
-- ddl-end --

-- object: "Infrastructure Spinner".pricing | type: TABLE --
-- DROP TABLE IF EXISTS "Infrastructure Spinner".pricing;
CREATE TABLE "Infrastructure Spinner".pricing(
	cost float,
	c_nodes_t integer,
	s_nodes_t integer,
	m_nodes_t integer,
	"PID_resource_provision" integer NOT NULL
)
TABLESPACE pg_default;
-- ddl-end --
ALTER TABLE "Infrastructure Spinner".pricing OWNER TO db_cal;
-- ddl-end --

-- object: "Infrastructure Spinner".vm_stats | type: TABLE --
-- DROP TABLE IF EXISTS "Infrastructure Spinner".vm_stats;
CREATE TABLE "Infrastructure Spinner".vm_stats(
	vmid text NOT NULL,
	vm_class char(1) NOT NULL,
	vm_ip inet NOT NULL,
	"time" integer,
	hostname_servers text NOT NULL,
	"PID_resource_provision" integer NOT NULL,
	CONSTRAINT vm_stats_pk PRIMARY KEY (vmid,hostname_servers)

)
TABLESPACE pg_default;
-- ddl-end --
ALTER TABLE "Infrastructure Spinner".vm_stats OWNER TO db_prov;
-- ddl-end --

-- object: resource_provision_fk | type: CONSTRAINT --
-- ALTER TABLE "Infrastructure Spinner".pricing DROP CONSTRAINT IF EXISTS resource_provision_fk CASCADE;
ALTER TABLE "Infrastructure Spinner".pricing ADD CONSTRAINT resource_provision_fk FOREIGN KEY ("PID_resource_provision")
REFERENCES "Infrastructure Spinner".resource_provision ("PID") MATCH FULL
ON DELETE NO ACTION ON UPDATE NO ACTION;
-- ddl-end --

-- object: pricing_uq | type: CONSTRAINT --
-- ALTER TABLE "Infrastructure Spinner".pricing DROP CONSTRAINT IF EXISTS pricing_uq CASCADE;
ALTER TABLE "Infrastructure Spinner".pricing ADD CONSTRAINT pricing_uq UNIQUE ("PID_resource_provision");
-- ddl-end --

-- object: servers_fk | type: CONSTRAINT --
-- ALTER TABLE "Infrastructure Spinner".vm_stats DROP CONSTRAINT IF EXISTS servers_fk CASCADE;
ALTER TABLE "Infrastructure Spinner".vm_stats ADD CONSTRAINT servers_fk FOREIGN KEY (hostname_servers)
REFERENCES "Infrastructure Spinner".servers (hostname) MATCH FULL
ON DELETE CASCADE ON UPDATE NO ACTION DEFERRABLE INITIALLY IMMEDIATE;
-- ddl-end --

-- object: resource_provision_fk | type: CONSTRAINT --
-- ALTER TABLE "Infrastructure Spinner".vm_stats DROP CONSTRAINT IF EXISTS resource_provision_fk CASCADE;
ALTER TABLE "Infrastructure Spinner".vm_stats ADD CONSTRAINT resource_provision_fk FOREIGN KEY ("PID_resource_provision")
REFERENCES "Infrastructure Spinner".resource_provision ("PID") MATCH FULL
ON DELETE CASCADE ON UPDATE CASCADE;
-- ddl-end --

-- object: credentials_fk | type: CONSTRAINT --
-- ALTER TABLE "Infrastructure Spinner".resource_provision DROP CONSTRAINT IF EXISTS credentials_fk CASCADE;
ALTER TABLE "Infrastructure Spinner".resource_provision ADD CONSTRAINT credentials_fk FOREIGN KEY (username_credentials)
REFERENCES "Infrastructure Spinner".credentials (username) MATCH FULL
ON DELETE CASCADE ON UPDATE CASCADE;
-- ddl-end --


