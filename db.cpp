
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned long magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[34];
};
static const struct sqlcxp sqlfpn =
{
    33,
    "d:\\src\\smsc_mediation_1.0.5\\db.pc"
};


static unsigned long sqlctx = 1246396331;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
            void  *sqhstv[29];
   unsigned int   sqhstl[29];
            int   sqhsts[29];
            void  *sqindv[29];
            int   sqinds[29];
   unsigned int   sqharm[29];
   unsigned int   *sqharc[29];
   unsigned short  sqadto[29];
   unsigned short  sqtdso[29];
} sqlstm = {10,29};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned long *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned long *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned long *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(char *, int *); }

 static const char *sq0005 = 
"select FILE_NAME ,CDR_FILE_ID_NO  from sys_smsc_primary_dump_files where DEC\
ODED_DATE is null            ";

 static const char *sq0006 = 
"select FILE_NAME ,CDR_FILE_ID_NO  from sys_smsc_secondary_dump_files where D\
ECODED_DATE is null            ";

 static const char *sq0011 = 
"select NETWORK_ID ,SUB_SERVICE_ID  from MEDV_SMSC_NETWORKS            ";

 static const char *sq0015 = 
"select SERVICE_CENTER  from MED_DIALOG_SERVICE_CENTERS            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{10,4146,0,0,0,
5,0,0,1,0,0,32,64,0,0,0,0,0,1,0,
20,0,0,2,0,0,27,79,0,0,4,4,0,1,0,1,5,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
51,0,0,3,59,0,1,80,0,0,0,0,0,1,0,
66,0,0,4,0,0,30,92,0,0,0,0,0,1,0,
81,0,0,5,105,0,9,125,0,0,0,0,0,1,0,
96,0,0,5,0,0,13,131,0,0,2,0,0,1,0,2,5,0,0,2,3,0,0,
119,0,0,5,0,0,15,146,0,0,0,0,0,1,0,
134,0,0,6,107,0,9,178,0,0,0,0,0,1,0,
149,0,0,6,0,0,13,184,0,0,2,0,0,1,0,2,5,0,0,2,3,0,0,
172,0,0,6,0,0,15,199,0,0,0,0,0,1,0,
187,0,0,7,229,0,5,244,0,0,6,6,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,
3,0,0,
226,0,0,8,0,0,29,257,0,0,0,0,0,1,0,
241,0,0,9,231,0,5,305,0,0,6,6,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,
3,0,0,
280,0,0,10,0,0,29,318,0,0,0,0,0,1,0,
295,0,0,11,70,0,9,402,0,0,0,0,0,1,0,
310,0,0,11,0,0,13,407,0,0,2,0,0,1,0,2,5,0,0,2,3,0,0,
333,0,0,11,0,0,15,430,0,0,0,0,0,1,0,
348,0,0,12,35,0,4,610,0,0,1,0,0,1,0,2,5,0,0,
367,0,0,13,719,0,3,618,0,0,29,29,0,1,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,3,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,3,0,
0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,
498,0,0,14,0,0,29,662,0,0,0,0,0,1,0,
513,0,0,15,66,0,9,685,0,0,0,0,0,1,0,
528,0,0,15,0,0,13,691,0,0,1,0,0,1,0,2,5,0,0,
547,0,0,15,0,0,15,695,0,0,0,0,0,1,0,
562,0,0,16,35,0,4,876,0,0,1,0,0,1,0,2,5,0,0,
581,0,0,17,723,0,3,884,0,0,29,29,0,1,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,3,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,3,0,
0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,
712,0,0,18,0,0,29,928,0,0,0,0,0,1,0,
};



//////////////////////////////////////////////////////////////////////
// db.pc
// Pro*C file for smsc mediation database access methods
// Copyright Millennium IT Software 2003
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <oraca.h>
#include <sqlcpr.h>
#include <sqlda.h>
#include <sqlca.h>

//#include "defines.h"				// CJN
#define CDR_INSERT_BLOCK_SIZE 1000	// CJN
//#define CDR_INSERT_BLOCK_SIZE 1


#ifndef ORA_PROC
#include "db.h"
#include "db_data_containers.h"
#include "cdr.h"
#include <fstream>
#endif


extern decoded_cdr *gsm_cdr_block;
extern decoded_cdr *air_cdr_block;
extern bool debug;
extern int array_insert_size;
extern int global_cdr_counter;
extern ofstream f_log;



#define BUF_LEN 	100
#define FETCH_SIZE	1000
#define BUF_LENTH	20		


/* EXEC SQL DECLARE CDR DATABASE; */ 
 
/* EXEC SQL DECLARE RATING DATABASE; */ 



/* EXEC SQL BEGIN DECLARE SECTION; */ 

	char *login;
/* EXEC SQL END DECLARE SECTION; */ 



void sql_error(char *msg)
{
	cout << endl << msg << endl;
	sqlca.sqlerrm.sqlerrmc[sqlca.sqlerrm.sqlerrml] = '\0';
	oraca.orastxt.orastxtc[oraca.orastxt.orastxtl] = '\0';
	oraca.orasfnm.orasfnmc[oraca.orasfnm.orasfnml] = '\0';
	cout << sqlca.sqlerrm.sqlerrmc << endl;
	cout << "in " << oraca.orastxt.orastxtc << endl;
	cout << "on line " << oraca.oraslnr << " of " << oraca.orasfnm.orasfnmc
		<< endl << endl;
	
	//-- Roll back any pending changes and disconnect from Oracle.
	/* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 0;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	exit(1);
}


//-- Connect to ORACLE. 
void db_connect(char *in_login)
{
	login = in_login;  // a pointer assignment, in_login has the space acclocation

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error in db_connect--"); */ 


	//cout<<"\nConnecting to ORACLE  as: "<<login<<endl;
	cout<<"\nConnecting to ORACLE  "<<endl;
 
    /* EXEC SQL CONNECT :login; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )20;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)login;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_connect--");
}


	/* EXEC SQL ALTER SESSION SET NLS_DATE_FORMAT="DD/MM/YYYY HH24:MI:SS"; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "alter SESSION SET NLS_DATE_FORMAT = \"DD/MM/YYYY HH24:MI:SS\"";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )51;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_connect--");
}

 
	cout<<"Connected  to Database"<<endl<<endl; 

}





void db_disconnect()
{
	cout<<"\nORACLE  database: DISCONNECT"<<endl;
	/* EXEC SQL COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )66;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_connect--");
}

 
}	




// get cdr files
void cdr_files::db_read_primary()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct cdr_file_t
	{ 
		char file_name[BUF_LEN];			// varchar2(123)
		int file_id;					// called id_no in table number(9)
	} a[FETCH_SIZE]; 
	int rows_to_fetch, rows_before, rows_this_time; 

	/* EXEC SQL END DECLARE SECTION; */ 


	int i;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE;
	 
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error in db_read_primary()"); */ 


    /* EXEC SQL DECLARE c_cdr_file CURSOR FOR 

	SELECT	FILE_NAME,  CDR_FILE_ID_NO
	FROM	sys_smsc_primary_dump_files
	WHERE DECODED_DATE IS NULL; */ 

       
    /* EXEC SQL OPEN c_cdr_file; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0005;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )81;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_read_primary()");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 

	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error:"); */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL FETCH c_cdr_file INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )96;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->file_name;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct cdr_file_t);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqharc[0] = (unsigned int   *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->file_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct cdr_file_t);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqharc[1] = (unsigned int   *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error:");
}

 		 
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d to_fetch=%d\n", rows_this_time, rows_before, rows_to_fetch);


		cdr_file_statistics cd;
		cd.init();
		for(i=0; i<rows_this_time; i++)
		{
			cd.file_id = a[i].file_id;			
			insert(a[i].file_name, cd);
		}
	} 

    /* EXEC SQL CLOSE c_cdr_file; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )119;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error:");
}

 
 
    printf("\n %d  cdr files loaded.\n\n",rows_before);
}

// get cdr files
void cdr_files::db_read_secondary()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct cdr_file_t
	{ 
		char file_name[BUF_LEN];			// varchar2(123)
		int file_id;					// called id_no in table number(9)
	} a[FETCH_SIZE]; 
	int rows_to_fetch, rows_before, rows_this_time; 

	/* EXEC SQL END DECLARE SECTION; */ 


	int i;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE;
	 
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error in db_read_secondary()"); */ 


    /* EXEC SQL DECLARE c_cdr_file_s CURSOR FOR 

	SELECT	FILE_NAME,  CDR_FILE_ID_NO
	FROM	sys_smsc_secondary_dump_files
	WHERE DECODED_DATE IS NULL; */ 

       
    /* EXEC SQL OPEN c_cdr_file_s; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0006;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )134;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_read_secondary()");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 

	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error in db_read_secondary()"); */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL FETCH c_cdr_file_s INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )149;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->file_name;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct cdr_file_t);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqharc[0] = (unsigned int   *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->file_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct cdr_file_t);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqharc[1] = (unsigned int   *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_read_secondary()");
}

 		 
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d to_fetch=%d\n", rows_this_time, rows_before, rows_to_fetch);


		cdr_file_statistics cd;
		cd.init();
		for(i=0; i<rows_this_time; i++)
		{
			cd.file_id = a[i].file_id;			
			insert(a[i].file_name, cd);
		}
	} 

    /* EXEC SQL CLOSE c_cdr_file_s; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )172;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_read_secondary()");
}

 
 
    printf("\n %d  cdr files loaded.\n\n",rows_before);
}

void cdr_files::db_update_primary(cdr_file_statistics s)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct cdr_file_t
	{ 
		 int valid_cdr_count;					//  number(7)
		 int error_count;						//	number(7)
		 int bytes_read;						//	number(9)
		 char first_cdr_date[BUF_LENTH];				//	varchar2(14)
		 char last_cdr_date[BUF_LENTH];				//	varchar2(14)
		 int rating_duration;
		 char rating_start_date[BUF_LENTH];	//	varchar2(14)

		 int id_no;						//	number(9)
 	} a; 

	/* EXEC SQL END DECLARE SECTION; */ 


	//EXEC SQL WHENEVER NOT FOUND GOTO nofile;

//#ifndef code_skip

	 cout << "a.id_no :" <<a.id_no<<endl;
	 cout <<"s.file_id : "<<s.file_id<<endl;
	 a.id_no = s.file_id;
	 cout << "a.id_no :" <<a.id_no<<endl;
	 cout <<"s.file_id : "<<s.file_id<<endl;

	 a.valid_cdr_count = s.valid_cdr_count;
	 a.error_count = s.error_count;
	 a.bytes_read = s.bytes_read;
	 strcpy(a.first_cdr_date, s.first_cdr_date.c_str());
	 strcpy(a.last_cdr_date, s.last_cdr_date.c_str());
	 a.rating_duration = s.rating_duration;
	 strcpy(a.rating_start_date, s.rating_start_date.c_str());
	 
	 	
//#endif

	 /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error in db_update_primary"); */ 

	 /* EXEC SQL	
	 UPDATE sys_smsc_primary_dump_files

	 SET 
		valid_cdr_count			= :a.valid_cdr_count, 
		error_count				= :a.error_count,
		bytes_read				= :a.bytes_read,
		first_cdr_date			= to_date(:a.first_cdr_date,'YYYYMMDDHH24MISS'),
		last_cdr_date			= to_date(:a.last_cdr_date,'YYYYMMDDHH24MISS'),
		//decoded_date		= to_date(:a.rating_start_date,'YYYYMMDDHH24MISS')
		decoded_date		= SYSDATE
	 WHERE cdr_file_id_no  = :a.id_no; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "update sys_smsc_primary_dump_files  set valid_cdr_count=:b0\
,error_count=:b1,bytes_read=:b2,first_cdr_date=to_date(:b3,'YYYYMMDDHH24MISS')\
,last_cdr_date=to_date(:b4,'YYYYMMDDHH24MISS'),decoded_date=SYSDATE where cdr_\
file_id_no=:b5";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )187;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&(a.valid_cdr_count);
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&(a.error_count);
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&(a.bytes_read);
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)(a.first_cdr_date);
  sqlstm.sqhstl[3] = (unsigned int  )20;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)(a.last_cdr_date);
  sqlstm.sqhstl[4] = (unsigned int  )20;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)&(a.id_no);
  sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_update_primary");
}



	 /* EXEC SQL COMMIT; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )226;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_update_primary");
}


 
    printf("\n cdr file id=%d log updated.\n\n", s.file_id);
	//return;
//nofile:
	//printf("\n <ERROR> file id = %d  not found to update.\n\n", s.file_id);
}		

void cdr_files::db_update_secondary(cdr_file_statistics s)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct cdr_file_t
	{ 
		 int valid_cdr_count;					//  number(7)
		 int error_count;						//	number(7)
		 int bytes_read;						//	number(9)
		 char first_cdr_date[BUF_LENTH];				//	varchar2(14)
		 char last_cdr_date[BUF_LENTH];				//	varchar2(14)
		 int rating_duration;
		 char rating_start_date[BUF_LENTH];	//	varchar2(14)

		 int id_no;						//	number(9)
 	} a; 

	/* EXEC SQL END DECLARE SECTION; */ 


	//EXEC SQL WHENEVER NOT FOUND GOTO nofile;

//#ifndef code_skip

	 cout << "a.id_no :" <<a.id_no<<endl;
	 cout <<"s.file_id : "<<s.file_id<<endl;
	 a.id_no = s.file_id;
	 cout << "a.id_no :" <<a.id_no<<endl;
	 cout <<"s.file_id : "<<s.file_id<<endl;

	 a.valid_cdr_count = s.valid_cdr_count;
	 a.error_count = s.error_count;
	 a.bytes_read = s.bytes_read;
	 strcpy(a.first_cdr_date, s.first_cdr_date.c_str());
	 strcpy(a.last_cdr_date, s.last_cdr_date.c_str());
	 a.rating_duration = s.rating_duration;
	 strcpy(a.rating_start_date, s.rating_start_date.c_str());
	 
	 	
//#endif

	 /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error in db_update_secondary"); */ 

	 /* EXEC SQL	
	 UPDATE sys_smsc_secondary_dump_files

	 SET 
		valid_cdr_count			= :a.valid_cdr_count, 
		error_count				= :a.error_count,
		bytes_read				= :a.bytes_read,
		first_cdr_date			= to_date(:a.first_cdr_date,'YYYYMMDDHH24MISS'),
		last_cdr_date			= to_date(:a.last_cdr_date,'YYYYMMDDHH24MISS'),
		//decoded_date		= to_date(:a.rating_start_date,'YYYYMMDDHH24MISS')
		decoded_date		= SYSDATE
	 WHERE cdr_file_id_no  = :a.id_no; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "update sys_smsc_secondary_dump_files  set valid_cdr_count=:\
b0,error_count=:b1,bytes_read=:b2,first_cdr_date=to_date(:b3,'YYYYMMDDHH24MISS\
'),last_cdr_date=to_date(:b4,'YYYYMMDDHH24MISS'),decoded_date=SYSDATE where cd\
r_file_id_no=:b5";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )241;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&(a.valid_cdr_count);
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&(a.error_count);
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&(a.bytes_read);
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)(a.first_cdr_date);
  sqlstm.sqhstl[3] = (unsigned int  )20;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)(a.last_cdr_date);
  sqlstm.sqhstl[4] = (unsigned int  )20;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)&(a.id_no);
  sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_update_secondary");
}



	 /* EXEC SQL COMMIT; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )280;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_update_secondary");
}


 
    printf("\n cdr file id=%d log updated.\n\n", s.file_id);
	//return;
//nofile:
	//printf("\n <ERROR> file id = %d  not found to update.\n\n", s.file_id);
}

/*
void sub_service_networks::db_read()
{
	EXEC SQL BEGIN DECLARE SECTION;
	struct network_number 
	{ 
		char	network_id[BUF_LEN]; 
		int 	sub_service_id; 
		
	} a, *n_n_ptr; 
	int i;
	EXEC SQL END DECLARE SECTION;
	
	n_n_ptr = &a;
	
	EXEC SQL  DECLARE c_sub_service_network CURSOR FOR 
		SELECT NETWORK_ID, SUB_SERVICE_ID
		FROM MEDV_SMSC_NETWORKS; 
	
	EXEC SQL OPEN   c_sub_service_network; 
	
	//EXEC SQL WHENEVER NOT FOUND DO break; 
	
	for (i=0; ;i++) 
	{ 
		EXEC SQL FETCH c_sub_service_network INTO :n_n_ptr; 
		insert(n_n_ptr->network_id, n_n_ptr->sub_service_id);
	} 
	
	EXEC SQL  CLOSE c_sub_service_network; 
	
	cout<<setw(8)<<i<<" medv_smsc_network's loaded."<<endl;
}
*/

void sub_service_networks::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct net_t
	{ 
		char	network_id[BUF_LEN]; 
		int 	sub_service_id; 
	} *a;

	struct net_ind
	{ 
 		short	network_id_ind;
		short	sub_service_id_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new net_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for medv_smsc_networks fetch"<<endl;
		exit(0);
	}

	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error in sub_service_networks::db_read()"); */ 


 
	/* EXEC SQL  DECLARE c_sub_service_network CURSOR FOR 
	SELECT	NETWORK_ID, 
			SUB_SERVICE_ID
	FROM MEDV_SMSC_NETWORKS; */ 
 

 
	/* EXEC SQL OPEN c_sub_service_network; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0011;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )295;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error in sub_service_networks::db_read()");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL FOR :rows_to_fetch FETCH c_sub_service_network INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )310;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->network_id;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct net_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->network_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct net_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->sub_service_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct net_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->sub_service_id_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct net_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error in sub_service_networks::db_read()");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" medv_smsc_networks=%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			a[i].sub_service_id = (a_ind[i].sub_service_id_ind < 0) ? 99 : a[i].sub_service_id;
			strcpy(a[i].network_id,
				  ((a_ind[i].network_id_ind < 0) ? "UNDEF":a[i].network_id));
					
			if ( a[i].sub_service_id == 1 )
				insert_sub_service_map(a[i].network_id, a[i].sub_service_id);
			else if ( a[i].sub_service_id == 2 )
					insert_applications_map(a[i].network_id, a[i].sub_service_id);
		}
	} 

	/* EXEC SQL CLOSE c_sub_service_network; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )333;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error in sub_service_networks::db_read()");
}

 
	delete a;
	printf("%d  medv_smsc_networks data read.\n\n",rows_before);
}		


void db_insert_decoded_cdr(int cdr_count)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	static struct db_cdr
	{	
		int		file_id;								//  number(9)
		int		file_pos;								//	number(9)
		char	message_source[BUF_LEN];				//	varchar2(10)
		char	destination_address[BUF_LEN];			//	varchar2(30)
		char	originating_address[BUF_LEN];			//	varchar2(30)
		int		traffic_event_type;						//  number(9)
		char	traffic_event_time[BUF_LEN];			//	date
		int		destination_logical_sme;				//  number(9)
		char	call_time[BUF_LEN];						//	date - accept_time/traffic_event_time
		//char	duplicate_message_behaviour[BUF_LEN];	//	varchar2(30)
		char	sme_reference_number[BUF_LEN];			//	varchar2(30)
		//int		first_in_batch;							//  number(9)
		int		call_direction;							//  number(9)
		int		distribution;							//  number(9)
		char	destination_imsi[BUF_LEN];				//	varchar2(30)
		//char	closed_user_group[BUF_LEN];				//	varchar2(30)
		//char	cug_type[BUF_LEN];						//	varchar2(30)
		char	originating_imsi[BUF_LEN];				//	varchar2(30)
		int		first_network_operation;				//	number(9)
		int		first_delivery_network;					//	number(9)
		int		second_network_operation;				//	number(9)
		int		second_delivery_network;				//	number(9)
		//int		second_network_failure_type;			//	number(9)
		//int		second_network_error_returned;			//	number(9)
		//int		second_network_failure_cause;			//	number(9)
		//int		second_delivery_failure_reason;			//	number(9)
		int		priority;								//	number(9)
		//int		protocol_id;							//	number(9)
		int		smsc_reference_number;					//	number(9)
		char	source_node_sccp_address[BUF_LEN];		//	varchar2(30)
		char	destination_node_sccp_address[BUF_LEN];	//	varchar2(30)
		//int		billing_flags;							//	number(9)
		char	rate_address[BUF_LEN];					//	varchar2(30)
		char	rate_call_partner[BUF_LEN];				//	varchar2(30)
		char	rate_call_type[BUF_LEN];				//	varchar2(10)
		int		rate_sub_service_type;					//	number(2)
		int		sub_logical_sme;						//	number(9)
		char	accept_time[BUF_LEN];					//	date
		char	mediated_time[BUF_LEN];					//	date			- sysdate 
	} * a;

	char	med_system_date[20];  

	int rows_to_insert;
	
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error in db_insert_decoded_cdr"); */ 

	
	rows_to_insert = cdr_count;
	
	if((a = new db_cdr[array_insert_size])==NULL)
	{
		cout<<" cant allocate memory for cdr insert"<<endl;
		exit(0);
	}
	
	
	for(int j=0; j<array_insert_size; j++)
	{
		a[j].file_pos = 0;
	}
	
	for(int i=0; i<rows_to_insert; i++)
	{
		a[i].file_id			= gsm_cdr_block[i].file_id; 
		a[i].file_pos			= gsm_cdr_block[i].file_pos;

		strncpy(a[i].message_source, gsm_cdr_block[i].message_source.c_str(), 10);
		strncpy(a[i].destination_address, gsm_cdr_block[i].destination_address.c_str(), 30);
		strncpy(a[i].originating_address, gsm_cdr_block[i].originating_address.c_str(), 30);
		a[i].traffic_event_type	= gsm_cdr_block[i].traffic_event_type;	
		
		reng_date d=gsm_cdr_block[i].d_traffic_event_time_date;
		reng_time t=gsm_cdr_block[i].d_traffic_event_time_time;
		char buf[100];
		buf[0] = '\0';
		sprintf(buf,"%02d%s%02d%s%04d%s%02d%s%02d%s%02d",d.day,"/",d.month,"/",d.year," ",t.hour,":",t.min,":",t.second); 
		strcpy(a[i].traffic_event_time, buf);
			
		a[i].destination_logical_sme	=gsm_cdr_block[i].destination_logical_SME;	
					
		d.init();
		t.init();
		d=gsm_cdr_block[i].d_accept_time_date;
		t=gsm_cdr_block[i].d_accept_time_time;
		buf[0] = '\0';
		sprintf(buf,"%02d%s%02d%s%04d%s%02d%s%02d%s%02d",d.day,"/",d.month,"/",d.year," ",t.hour,":",t.min,":",t.second); 
		strcpy(a[i].accept_time, buf);

		strncpy(a[i].call_time, gsm_cdr_block[i].call_time.c_str(), 19);
		a[i].call_time[19] = '\0';	
							
		//strncpy(a[i].duplicate_message_behaviour, gsm_cdr_block[i].duplicate_message_behaviour.c_str(), 30);	
		strncpy(a[i].sme_reference_number, gsm_cdr_block[i].SME_reference_number.c_str(), 30);			
		//a[i].first_in_batch				=gsm_cdr_block[i].first_in_batch;							
		a[i].call_direction				=gsm_cdr_block[i].call_direction;						
		a[i].distribution				=gsm_cdr_block[i].distribution;							
		strncpy(a[i].destination_imsi,	gsm_cdr_block[i].destination_IMSI.c_str(), 30);				
		//strncpy(a[i].closed_user_group, gsm_cdr_block[i].closed_user_group.c_str(), 30);				
		//strncpy(a[i].cug_type,			gsm_cdr_block[i].CUG_type.c_str(), 30);						
		strncpy(a[i].originating_imsi,	gsm_cdr_block[i].originating_IMSI.c_str(), 30);				
		a[i].first_network_operation	=gsm_cdr_block[i].first_network_operation;				
		a[i].first_delivery_network		=gsm_cdr_block[i].first_delivery_network;					
		a[i].second_network_operation	=gsm_cdr_block[i].second_network_operation;				
		a[i].second_delivery_network	=gsm_cdr_block[i].second_delivery_network;				
		//a[i].second_network_failure_type	=gsm_cdr_block[i].second_network_failure_type;			
		//a[i].second_network_error_returned	=gsm_cdr_block[i].second_network_error_returned;			
		//a[i].second_network_failure_cause	=gsm_cdr_block[i].second_network_failure_cause;		
		//a[i].second_delivery_failure_reason	=gsm_cdr_block[i].second_delivery_failure_reason;			
		a[i].priority					=gsm_cdr_block[i].priority;								
		//a[i].protocol_id				=gsm_cdr_block[i].protocol_id;							
		a[i].smsc_reference_number		=gsm_cdr_block[i].SMSC_reference_number;					
		strncpy(a[i].source_node_sccp_address, gsm_cdr_block[i].source_node_SCCP_address.c_str(), 30);		
		strncpy(a[i].destination_node_sccp_address, gsm_cdr_block[i].destination_node_SCCP_address.c_str(), 30);	
		//a[i].billing_flags				=gsm_cdr_block[i].billing_flags;
		
		strncpy(a[i].rate_address,		gsm_cdr_block[i].rate_address.c_str(), 30);				
		strncpy(a[i].rate_call_partner, gsm_cdr_block[i].rate_call_partner.c_str(), 30);				
		strncpy(a[i].rate_call_type,	gsm_cdr_block[i].rate_call_type.c_str(), 10);						
		a[i].rate_sub_service_type		=gsm_cdr_block[i].rate_sub_service_type;
		a[i].sub_logical_sme			=gsm_cdr_block[i].sub_logical_sme;
							
		
		if ( debug )
		{					
			cout <<"file_id						:" << a[i].file_id 					<<"|"<< endl;
			cout <<"file_pos					:" << a[i].file_pos 				<<"|"<< endl;
			cout <<"message_source				:" << a[i].message_source 			<<"|"<< endl;
			cout <<"destination_address			:" << a[i].destination_address 		<<"|"<< endl;
			cout <<"originating_address			:" << a[i].originating_address		<<"|"<< endl;
			cout <<"traffic_event_type			:" << a[i].traffic_event_type		<<"|"<< endl;
			cout <<"traffic_event_time			:" << a[i].traffic_event_time		<<"|"<< endl;
			cout <<"destination_logical_sme		:" << a[i].destination_logical_sme	<<"|"<< endl;
			cout <<"call_time (accept_time)		:" << a[i].call_time				<<"|"<< endl;
			//cout <<"duplicate_message_behaviour	:" << a[i].duplicate_message_behaviour	<<"|"<< endl;
			cout <<"sme_reference_number		:" << a[i].sme_reference_number		<<"|"<< endl;
			//cout <<"first_in_batch				:" << a[i].first_in_batch			<<"|"<< endl;
			cout <<"call_direction				:" << a[i].call_direction			<<"|"<< endl;
			cout <<"distribution				:" << a[i].distribution				<<"|"<< endl;
			cout <<"destination_imsi			:" << a[i].destination_imsi			<<"|"<< endl;
			//cout <<"closed_user_group			:" << a[i].closed_user_group		<<"|"<< endl;
			//cout <<"cug_type					:" << a[i].cug_type					<<"|"<< endl;
			cout <<"originating_imsi			:" << a[i].originating_imsi			<<"|"<< endl;
			cout <<"first_network_operation		:" << a[i].first_network_operation 	<<"|"<< endl;
			cout <<"first_delivery_network		:" << a[i].first_delivery_network	<<"|"<< endl;
			cout <<"second_network_operation	:" << a[i].second_network_operation	<<"|"<< endl;
			cout <<"second_delivery_network		:" << a[i].second_delivery_network	<<"|"<< endl;
			//cout <<"second_network_failure_type	:" << a[i].second_network_failure_type		<<"|"<< endl;
			//cout <<"second_network_error_returned	:" << a[i].second_network_error_returned<<"|"<< endl;
			//cout <<"second_network_failure_cause	:" << a[i].second_network_failure_cause	<<"|"<< endl;
			//cout <<"second_delivery_failure_reason	:" << a[i].second_delivery_failure_reason<<"|"<< endl;
			cout <<"priority					:" << a[i].priority					<<"|"<< endl;
			//cout <<"protocol_id					:" << a[i].protocol_id				<<"|"<< endl;
			cout <<"smsc_reference_number		:" << a[i].smsc_reference_number	<<"|"<< endl;
			cout <<"source_node_sccp_address	:" << a[i].source_node_sccp_address <<"|"<< endl;
			cout <<"destination_node_sccp_address	:" << a[i].destination_node_sccp_address<<"|"<< endl;
			//cout <<"billing_flags				:" << a[i].billing_flags			<<"|"<< endl;
			
			cout <<"rate_address				:" << a[i].rate_address				<<"|"<< endl;				
			cout <<"rate_call_partner			:" << a[i].rate_call_partner		<<"|"<< endl;				
			cout <<"rate_call_type				:" << a[i].rate_call_type			<<"|"<< endl;					
			cout <<"rate_sub_service_type		:" << a[i].rate_sub_service_type	<<"|"<< endl;
			cout <<"sub_logical_sme				:" << a[i].sub_logical_sme			<<"|"<< endl;
			cout <<"accept_time					:" << a[i].accept_time				<<"|"<< endl;
		}
	}

	/* EXEC SQL
	select sysdate into :med_system_date from dual; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select sysdate into :b0  from dual ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )348;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)med_system_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_insert_decoded_cdr");
}


	
	for(int k=0; k<array_insert_size; k++)
	{
		strcpy(a[k].mediated_time, med_system_date);
	}  

	/* EXEC SQL  FOR :rows_to_insert  INSERT INTO DYN_7_UDR 
	(
		file_id,
		file_pos,
		message_source,
		destination_address,
		originating_address,
		traffic_event_type,
		traffic_event_time,
		destination_logical_sme,
		call_time,						// accept_time
		//duplicate_message_behaviour,
		sme_reference_number,
		//first_in_batch,
		call_direction,
		distribution,
		destination_imsi,
		//closed_user_group,
		//cug_type,
		originating_imsi,
		first_network_operation,
		first_delivery_network,
		second_network_operation,
		second_delivery_network,
		//second_network_failure_type,
		//second_network_error_returned,
		//second_network_failure_cause,
		//second_delivery_failure_reason,
		priority,
		//protocol_id,
		smsc_reference_number,
		source_node_sccp_address,
		destination_node_sccp_address,
		//billing_flags,
		rate_address,
		rate_call_partner,
		rate_call_type_id,
		rate_sub_service_type,
		sub_logical_sme,
		accept_time,
		mediated_time
	) 
	VALUES (:a); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into DYN_7_UDR (file_id,file_pos,message_source,desti\
nation_address,originating_address,traffic_event_type,traffic_event_time,desti\
nation_logical_sme,call_time,sme_reference_number,call_direction,distribution,\
destination_imsi,originating_imsi,first_network_operation,first_delivery_netwo\
rk,second_network_operation,second_delivery_network,priority,smsc_reference_nu\
mber,source_node_sccp_address,destination_node_sccp_address,rate_address,rate_\
call_partner,rate_call_type_id,rate_sub_service_type,sub_logical_sme,accept_ti\
me,mediated_time) values (:s1 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:\
s11 ,:s12 ,:s13 ,:s14 ,:s15 ,:s16 ,:s17 ,:s18 ,:s19 ,:s20 ,:s21 ,:s22 ,:s23 ,:\
s24 ,:s25 ,:s26 ,:s27 ,:s28 ,:s29 )";
 sqlstm.iters = (unsigned int  )rows_to_insert;
 sqlstm.offset = (unsigned int  )367;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&a->file_id;
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&a->file_pos;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)a->message_source;
 sqlstm.sqhstl[2] = (unsigned int  )100;
 sqlstm.sqhsts[2] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)a->destination_address;
 sqlstm.sqhstl[3] = (unsigned int  )100;
 sqlstm.sqhsts[3] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)a->originating_address;
 sqlstm.sqhstl[4] = (unsigned int  )100;
 sqlstm.sqhsts[4] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)&a->traffic_event_type;
 sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)a->traffic_event_time;
 sqlstm.sqhstl[6] = (unsigned int  )100;
 sqlstm.sqhsts[6] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)&a->destination_logical_sme;
 sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[7] = (         void  *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)a->call_time;
 sqlstm.sqhstl[8] = (unsigned int  )100;
 sqlstm.sqhsts[8] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[8] = (         void  *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)a->sme_reference_number;
 sqlstm.sqhstl[9] = (unsigned int  )100;
 sqlstm.sqhsts[9] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[9] = (         void  *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)&a->call_direction;
 sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[10] = (         void  *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)&a->distribution;
 sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[11] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[11] = (         void  *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)a->destination_imsi;
 sqlstm.sqhstl[12] = (unsigned int  )100;
 sqlstm.sqhsts[12] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[12] = (         void  *)0;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)a->originating_imsi;
 sqlstm.sqhstl[13] = (unsigned int  )100;
 sqlstm.sqhsts[13] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[13] = (         void  *)0;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (         void  *)&a->first_network_operation;
 sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[14] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[14] = (         void  *)0;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned int  )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (         void  *)&a->first_delivery_network;
 sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[15] = (         void  *)0;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned int  )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (         void  *)&a->second_network_operation;
 sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[16] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[16] = (         void  *)0;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned int  )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (         void  *)&a->second_delivery_network;
 sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[17] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[17] = (         void  *)0;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned int  )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (         void  *)&a->priority;
 sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[18] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[18] = (         void  *)0;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned int  )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (         void  *)&a->smsc_reference_number;
 sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[19] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[19] = (         void  *)0;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned int  )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (         void  *)a->source_node_sccp_address;
 sqlstm.sqhstl[20] = (unsigned int  )100;
 sqlstm.sqhsts[20] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[20] = (         void  *)0;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned int  )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (         void  *)a->destination_node_sccp_address;
 sqlstm.sqhstl[21] = (unsigned int  )100;
 sqlstm.sqhsts[21] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[21] = (         void  *)0;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned int  )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (         void  *)a->rate_address;
 sqlstm.sqhstl[22] = (unsigned int  )100;
 sqlstm.sqhsts[22] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[22] = (         void  *)0;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned int  )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (         void  *)a->rate_call_partner;
 sqlstm.sqhstl[23] = (unsigned int  )100;
 sqlstm.sqhsts[23] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[23] = (         void  *)0;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned int  )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (         void  *)a->rate_call_type;
 sqlstm.sqhstl[24] = (unsigned int  )100;
 sqlstm.sqhsts[24] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[24] = (         void  *)0;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned int  )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (         void  *)&a->rate_sub_service_type;
 sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[25] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[25] = (         void  *)0;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned int  )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (         void  *)&a->sub_logical_sme;
 sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[26] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[26] = (         void  *)0;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned int  )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (         void  *)a->accept_time;
 sqlstm.sqhstl[27] = (unsigned int  )100;
 sqlstm.sqhsts[27] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[27] = (         void  *)0;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned int  )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (         void  *)a->mediated_time;
 sqlstm.sqhstl[28] = (unsigned int  )100;
 sqlstm.sqhsts[28] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[28] = (         void  *)0;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned int  )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_insert_decoded_cdr");
}


	
	/* EXEC SQL COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )498;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_insert_decoded_cdr");
}


	delete a;
}

void med_dialog_service_centers::db_read()
{
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - db_read_med_dialog_service_centers()"); */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct dialog_service_center 
	{ 
		char	service_center[BUF_LEN]; 
	} a, *dialog_service_center_ptr; 

	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	dialog_service_center_ptr = &a;
	
	/* EXEC SQL  DECLARE c_dialog_service_center CURSOR FOR 
		SELECT SERVICE_CENTER
		FROM MED_DIALOG_SERVICE_CENTERS; */ 
 
	
	/* EXEC SQL OPEN   c_dialog_service_center; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0015;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )513;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_read_med_dialog_service_centers()");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_dialog_service_center INTO :dialog_service_center_ptr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )528;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)dialog_service_center_ptr->service_center;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_read_med_dialog_service_centers()");
}

 
		insert_dialog_service_centers(dialog_service_center_ptr->service_center);
	} 
	
	/* EXEC SQL  CLOSE c_dialog_service_center; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )547;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_read_med_dialog_service_centers()");
}

 
	
	cout<<setw(8)<<i<<" med_dialog_service_centers loaded."<<endl;
	f_log<<setw(8)<<i<<" med_dialog_service_centers loaded."<<endl;
}


void db_insert_air_cdr(int cdr_count)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	static struct db_cdr
	{	
		int		file_id;								//  number(9)
		int		file_pos;								//	number(9)
		char	message_source[BUF_LEN];				//	varchar2(10)
		char	destination_address[BUF_LEN];			//	varchar2(30)
		char	originating_address[BUF_LEN];			//	varchar2(30)
		int		traffic_event_type;						//  number(9)
		char	traffic_event_time[BUF_LEN];			//	date
		int		destination_logical_sme;				//  number(9)
		char	call_time[BUF_LEN];						//	date - accept_time/traffic_event_time
		//char	duplicate_message_behaviour[BUF_LEN];	//	varchar2(30)
		char	sme_reference_number[BUF_LEN];			//	varchar2(30)
		//int		first_in_batch;							//  number(9)
		int		call_direction;							//  number(9)
		int		distribution;							//  number(9)
		char	destination_imsi[BUF_LEN];				//	varchar2(30)
		//char	closed_user_group[BUF_LEN];				//	varchar2(30)
		//char	cug_type[BUF_LEN];						//	varchar2(30)
		char	originating_imsi[BUF_LEN];				//	varchar2(30)
		int		first_network_operation;				//	number(9)
		int		first_delivery_network;					//	number(9)
		int		second_network_operation;				//	number(9)
		int		second_delivery_network;				//	number(9)
		//int		second_network_failure_type;			//	number(9)
		//int		second_network_error_returned;			//	number(9)
		//int		second_network_failure_cause;			//	number(9)
		//int		second_delivery_failure_reason;			//	number(9)
		int		priority;								//	number(9)
		//int		protocol_id;							//	number(9)
		int		smsc_reference_number;					//	number(9)
		char	source_node_sccp_address[BUF_LEN];		//	varchar2(30)
		char	destination_node_sccp_address[BUF_LEN];	//	varchar2(30)
		//int		billing_flags;							//	number(9)
		char	rate_address[BUF_LEN];					//	varchar2(30)
		char	rate_call_partner[BUF_LEN];				//	varchar2(30)
		char	rate_call_type[BUF_LEN];				//	varchar2(10)
		int		rate_sub_service_type;					//	number(2)
		int		sub_logical_sme;						//	number(9)
		char	accept_time[BUF_LEN];					//	date
		char	mediated_time[BUF_LEN];					//	date			- sysdate 
	} * a;

	char	med_system_date[20];  

	int rows_to_insert;
	
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error in db_insert_air_cdr"); */ 

	
	rows_to_insert = cdr_count;
	
	if((a = new db_cdr[array_insert_size])==NULL)
	{
		cout<<" cant allocate memory for cdr insert"<<endl;
		exit(0);
	}
	
	
	for(int j=0; j<array_insert_size; j++)
	{
		a[j].file_pos = 0;
	}
	
	for(int i=0; i<rows_to_insert; i++)
	{
		a[i].file_id			= air_cdr_block[i].file_id; 
		a[i].file_pos			= air_cdr_block[i].file_pos;

		strncpy(a[i].message_source, air_cdr_block[i].message_source.c_str(), 10);
		strncpy(a[i].destination_address, air_cdr_block[i].destination_address.c_str(), 30);
		strncpy(a[i].originating_address, air_cdr_block[i].originating_address.c_str(), 30);
		a[i].traffic_event_type	= air_cdr_block[i].traffic_event_type;	
		
		reng_date d=air_cdr_block[i].d_traffic_event_time_date;
		reng_time t=air_cdr_block[i].d_traffic_event_time_time;
		char buf[100];
		buf[0] = '\0';
		sprintf(buf,"%02d%s%02d%s%04d%s%02d%s%02d%s%02d",d.day,"/",d.month,"/",d.year," ",t.hour,":",t.min,":",t.second); 
		strcpy(a[i].traffic_event_time, buf);
			
		a[i].destination_logical_sme	=air_cdr_block[i].destination_logical_SME;	
					
		d.init();
		t.init();
		d=air_cdr_block[i].d_accept_time_date;
		t=air_cdr_block[i].d_accept_time_time;
		buf[0] = '\0';
		sprintf(buf,"%02d%s%02d%s%04d%s%02d%s%02d%s%02d",d.day,"/",d.month,"/",d.year," ",t.hour,":",t.min,":",t.second); 
		strcpy(a[i].accept_time, buf);

		strncpy(a[i].call_time, air_cdr_block[i].call_time.c_str(), 19);
		a[i].call_time[19] = '\0';	
							
		//strncpy(a[i].duplicate_message_behaviour, air_cdr_block[i].duplicate_message_behaviour.c_str(), 30);	
		strncpy(a[i].sme_reference_number, air_cdr_block[i].SME_reference_number.c_str(), 30);			
		//a[i].first_in_batch				=air_cdr_block[i].first_in_batch;							
		a[i].call_direction				=air_cdr_block[i].call_direction;						
		a[i].distribution				=air_cdr_block[i].distribution;							
		strncpy(a[i].destination_imsi,	air_cdr_block[i].destination_IMSI.c_str(), 30);				
		//strncpy(a[i].closed_user_group, air_cdr_block[i].closed_user_group.c_str(), 30);				
		//strncpy(a[i].cug_type,			air_cdr_block[i].CUG_type.c_str(), 30);						
		strncpy(a[i].originating_imsi,	air_cdr_block[i].originating_IMSI.c_str(), 30);				
		a[i].first_network_operation	=air_cdr_block[i].first_network_operation;				
		a[i].first_delivery_network		=air_cdr_block[i].first_delivery_network;					
		a[i].second_network_operation	=air_cdr_block[i].second_network_operation;				
		a[i].second_delivery_network	=air_cdr_block[i].second_delivery_network;				
		//a[i].second_network_failure_type	=air_cdr_block[i].second_network_failure_type;			
		//a[i].second_network_error_returned	=air_cdr_block[i].second_network_error_returned;			
		//a[i].second_network_failure_cause	=air_cdr_block[i].second_network_failure_cause;		
		//a[i].second_delivery_failure_reason	=air_cdr_block[i].second_delivery_failure_reason;			
		a[i].priority					=air_cdr_block[i].priority;								
		//a[i].protocol_id				=air_cdr_block[i].protocol_id;							
		a[i].smsc_reference_number		=air_cdr_block[i].SMSC_reference_number;					
		strncpy(a[i].source_node_sccp_address, air_cdr_block[i].source_node_SCCP_address.c_str(), 30);		
		strncpy(a[i].destination_node_sccp_address, air_cdr_block[i].destination_node_SCCP_address.c_str(), 30);	
		//a[i].billing_flags				=air_cdr_block[i].billing_flags;
		
		strncpy(a[i].rate_address,		air_cdr_block[i].rate_address.c_str(), 30);				
		strncpy(a[i].rate_call_partner, air_cdr_block[i].rate_call_partner.c_str(), 30);				
		strncpy(a[i].rate_call_type,	air_cdr_block[i].rate_call_type.c_str(), 10);						
		a[i].rate_sub_service_type		=air_cdr_block[i].rate_sub_service_type;
		a[i].sub_logical_sme			=air_cdr_block[i].sub_logical_sme;
							
		
		if ( debug )
		{					
			cout <<"file_id						:" << a[i].file_id 					<<"|"<< endl;
			cout <<"file_pos					:" << a[i].file_pos 				<<"|"<< endl;
			cout <<"message_source				:" << a[i].message_source 			<<"|"<< endl;
			cout <<"destination_address			:" << a[i].destination_address 		<<"|"<< endl;
			cout <<"originating_address			:" << a[i].originating_address		<<"|"<< endl;
			cout <<"traffic_event_type			:" << a[i].traffic_event_type		<<"|"<< endl;
			cout <<"traffic_event_time			:" << a[i].traffic_event_time		<<"|"<< endl;
			cout <<"destination_logical_sme		:" << a[i].destination_logical_sme	<<"|"<< endl;
			cout <<"call_time (accept_time)		:" << a[i].call_time				<<"|"<< endl;
			//cout <<"duplicate_message_behaviour	:" << a[i].duplicate_message_behaviour	<<"|"<< endl;
			cout <<"sme_reference_number		:" << a[i].sme_reference_number		<<"|"<< endl;
			//cout <<"first_in_batch				:" << a[i].first_in_batch			<<"|"<< endl;
			cout <<"call_direction				:" << a[i].call_direction			<<"|"<< endl;
			cout <<"distribution				:" << a[i].distribution				<<"|"<< endl;
			cout <<"destination_imsi			:" << a[i].destination_imsi			<<"|"<< endl;
			//cout <<"closed_user_group			:" << a[i].closed_user_group		<<"|"<< endl;
			//cout <<"cug_type					:" << a[i].cug_type					<<"|"<< endl;
			cout <<"originating_imsi			:" << a[i].originating_imsi			<<"|"<< endl;
			cout <<"first_network_operation		:" << a[i].first_network_operation 	<<"|"<< endl;
			cout <<"first_delivery_network		:" << a[i].first_delivery_network	<<"|"<< endl;
			cout <<"second_network_operation	:" << a[i].second_network_operation	<<"|"<< endl;
			cout <<"second_delivery_network		:" << a[i].second_delivery_network	<<"|"<< endl;
			//cout <<"second_network_failure_type	:" << a[i].second_network_failure_type		<<"|"<< endl;
			//cout <<"second_network_error_returned	:" << a[i].second_network_error_returned<<"|"<< endl;
			//cout <<"second_network_failure_cause	:" << a[i].second_network_failure_cause	<<"|"<< endl;
			//cout <<"second_delivery_failure_reason	:" << a[i].second_delivery_failure_reason<<"|"<< endl;
			cout <<"priority					:" << a[i].priority					<<"|"<< endl;
			//cout <<"protocol_id					:" << a[i].protocol_id				<<"|"<< endl;
			cout <<"smsc_reference_number		:" << a[i].smsc_reference_number	<<"|"<< endl;
			cout <<"source_node_sccp_address	:" << a[i].source_node_sccp_address <<"|"<< endl;
			cout <<"destination_node_sccp_address	:" << a[i].destination_node_sccp_address<<"|"<< endl;
			//cout <<"billing_flags				:" << a[i].billing_flags			<<"|"<< endl;
			
			cout <<"rate_address				:" << a[i].rate_address				<<"|"<< endl;				
			cout <<"rate_call_partner			:" << a[i].rate_call_partner		<<"|"<< endl;				
			cout <<"rate_call_type				:" << a[i].rate_call_type			<<"|"<< endl;					
			cout <<"rate_sub_service_type		:" << a[i].rate_sub_service_type	<<"|"<< endl;
			cout <<"sub_logical_sme				:" << a[i].sub_logical_sme			<<"|"<< endl;
			cout <<"accept_time					:" << a[i].accept_time				<<"|"<< endl;
		}
	}

	/* EXEC SQL
	select sysdate into :med_system_date from dual; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select sysdate into :b0  from dual ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )562;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)med_system_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
// if (sqlca.sqlcode == 1403) break;
 if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_insert_air_cdr");
}


	
	for(int k=0; k<array_insert_size; k++)
	{
		strcpy(a[k].mediated_time, med_system_date);
	}  

	/* EXEC SQL  FOR :rows_to_insert  INSERT INTO DYN_7_AIR_UDR 
	(
		file_id,
		file_pos,
		message_source,
		destination_address,
		originating_address,
		traffic_event_type,
		traffic_event_time,
		destination_logical_sme,
		call_time,						// accept_time
		//duplicate_message_behaviour,
		sme_reference_number,
		//first_in_batch,
		call_direction,
		distribution,
		destination_imsi,
		//closed_user_group,
		//cug_type,
		originating_imsi,
		first_network_operation,
		first_delivery_network,
		second_network_operation,
		second_delivery_network,
		//second_network_failure_type,
		//second_network_error_returned,
		//second_network_failure_cause,
		//second_delivery_failure_reason,
		priority,
		//protocol_id,
		smsc_reference_number,
		source_node_sccp_address,
		destination_node_sccp_address,
		//billing_flags,
		rate_address,
		rate_call_partner,
		rate_call_type_id,
		rate_sub_service_type,
		sub_logical_sme,
		accept_time,
		mediated_time
	) 
	VALUES (:a); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into DYN_7_AIR_UDR (file_id,file_pos,message_source,d\
estination_address,originating_address,traffic_event_type,traffic_event_time,d\
estination_logical_sme,call_time,sme_reference_number,call_direction,distribut\
ion,destination_imsi,originating_imsi,first_network_operation,first_delivery_n\
etwork,second_network_operation,second_delivery_network,priority,smsc_referenc\
e_number,source_node_sccp_address,destination_node_sccp_address,rate_address,r\
ate_call_partner,rate_call_type_id,rate_sub_service_type,sub_logical_sme,accep\
t_time,mediated_time) values (:s1 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9 ,:s1\
0 ,:s11 ,:s12 ,:s13 ,:s14 ,:s15 ,:s16 ,:s17 ,:s18 ,:s19 ,:s20 ,:s21 ,:s22 ,:s2\
3 ,:s24 ,:s25 ,:s26 ,:s27 ,:s28 ,:s29 )";
 sqlstm.iters = (unsigned int  )rows_to_insert;
 sqlstm.offset = (unsigned int  )581;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&a->file_id;
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&a->file_pos;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)a->message_source;
 sqlstm.sqhstl[2] = (unsigned int  )100;
 sqlstm.sqhsts[2] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)a->destination_address;
 sqlstm.sqhstl[3] = (unsigned int  )100;
 sqlstm.sqhsts[3] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)a->originating_address;
 sqlstm.sqhstl[4] = (unsigned int  )100;
 sqlstm.sqhsts[4] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)&a->traffic_event_type;
 sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)a->traffic_event_time;
 sqlstm.sqhstl[6] = (unsigned int  )100;
 sqlstm.sqhsts[6] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)&a->destination_logical_sme;
 sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[7] = (         void  *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)a->call_time;
 sqlstm.sqhstl[8] = (unsigned int  )100;
 sqlstm.sqhsts[8] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[8] = (         void  *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)a->sme_reference_number;
 sqlstm.sqhstl[9] = (unsigned int  )100;
 sqlstm.sqhsts[9] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[9] = (         void  *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)&a->call_direction;
 sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[10] = (         void  *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)&a->distribution;
 sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[11] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[11] = (         void  *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)a->destination_imsi;
 sqlstm.sqhstl[12] = (unsigned int  )100;
 sqlstm.sqhsts[12] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[12] = (         void  *)0;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)a->originating_imsi;
 sqlstm.sqhstl[13] = (unsigned int  )100;
 sqlstm.sqhsts[13] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[13] = (         void  *)0;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (         void  *)&a->first_network_operation;
 sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[14] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[14] = (         void  *)0;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned int  )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (         void  *)&a->first_delivery_network;
 sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[15] = (         void  *)0;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned int  )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (         void  *)&a->second_network_operation;
 sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[16] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[16] = (         void  *)0;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned int  )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (         void  *)&a->second_delivery_network;
 sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[17] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[17] = (         void  *)0;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned int  )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (         void  *)&a->priority;
 sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[18] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[18] = (         void  *)0;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned int  )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (         void  *)&a->smsc_reference_number;
 sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[19] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[19] = (         void  *)0;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned int  )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (         void  *)a->source_node_sccp_address;
 sqlstm.sqhstl[20] = (unsigned int  )100;
 sqlstm.sqhsts[20] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[20] = (         void  *)0;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned int  )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (         void  *)a->destination_node_sccp_address;
 sqlstm.sqhstl[21] = (unsigned int  )100;
 sqlstm.sqhsts[21] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[21] = (         void  *)0;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned int  )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (         void  *)a->rate_address;
 sqlstm.sqhstl[22] = (unsigned int  )100;
 sqlstm.sqhsts[22] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[22] = (         void  *)0;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned int  )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (         void  *)a->rate_call_partner;
 sqlstm.sqhstl[23] = (unsigned int  )100;
 sqlstm.sqhsts[23] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[23] = (         void  *)0;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned int  )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (         void  *)a->rate_call_type;
 sqlstm.sqhstl[24] = (unsigned int  )100;
 sqlstm.sqhsts[24] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[24] = (         void  *)0;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned int  )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (         void  *)&a->rate_sub_service_type;
 sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[25] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[25] = (         void  *)0;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned int  )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (         void  *)&a->sub_logical_sme;
 sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[26] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[26] = (         void  *)0;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned int  )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (         void  *)a->accept_time;
 sqlstm.sqhstl[27] = (unsigned int  )100;
 sqlstm.sqhsts[27] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[27] = (         void  *)0;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned int  )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (         void  *)a->mediated_time;
 sqlstm.sqhstl[28] = (unsigned int  )100;
 sqlstm.sqhsts[28] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[28] = (         void  *)0;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned int  )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
// if (sqlca.sqlcode == 1403) break;
 if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_insert_air_cdr");
}


	
	/* EXEC SQL COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )712;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error in db_insert_air_cdr");
}


	delete a;
}