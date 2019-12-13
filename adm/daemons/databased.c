// databased.c
// Create by ���ֺ�(Find@TX).
// Update by Lonely

// databased.c �ṩ���ⲿ������
// 
// ͨ����䣺
//   mixed *db_fetch_row()        - Ϊ����һ��
//   mixed  db_query()            - Ϊִ�����
//   mixed *db_all_query()        - ����������
//   mixed  db_crypt()            - �����ַ���
//   string query_db_status()     - ���ݿ�״̬

// �û�����
//   int db_find_user()           - ��ѯ ID �Ƿ����
//   int db_create_user()         - �����µ��û�
//   int db_remove_user()         - ɾ���û�����
//   int db_set_user()            - �趨�û�����
//   int db_add_user()            - �����û�����
//   int db_query_user()          - ��ѯ�û�����
//   int db_count_user()          - �����û�����

#ifdef LONELY_IMPROVED

#include <mudlib.h>

inherit F_DBASE;

#include "/include/database.h" 

#define REG_BONUS       2100

class target
{
        string host;
        string user;
        mapping quest;
}

#ifdef STATIC_LINK
protected int db_handle = 0;
public int query_db_handle()
{
    return db_handle;
}
#endif

protected mixed *all_target = ({});
string *do_sql(string);
int do_sqlexec(string sql);

// db_save_all() ʱ����ĺü����ֶ�Ӧ�ô� DBASE �������������洢
nosave string *cols = ({
        "id", "name", "surname", "purename", "password", "ad_password", 
        "birthday", "online", "on_time", "fee_time", "save_time", 
        "last_from", "last_on", "last_off", "last_station", "endrgt",
        "login_dbase", "char_idname", "f_autoload", "f_dbase", "f_damage", 
        "f_condition", "f_attack", "f_skill", "f_alias", "f_user" 
});

// ȷ���û���������ʱ�Ƿ�У�����ݺ� ��ʱ�ٴ�
int crc_status() { return query("crc_status"); }
int clean_up() { return 1; }

protected void chat(string msg)
{
#ifdef DEBUG
        CHANNEL_D->do_channel(this_object(), "sys", msg);
        log_file("database", "chat() call : " + msg + "\n");
#endif
}

protected void init_target()
{
        if (! sizeof(all_others_db))
                return;

        foreach (string h, string u in all_others_db)
        {
                class target one;
                one = new(class target);
                one->host = h;
                one->user = u;
                one->quest = ([]);
                all_target += ({ one });
        }
}
                                                
protected void log_error(string func, mixed err)
{       
        log_file("database", sprintf("%s ERROR ** %s\n%O\n", func, ctime(time()), err));
}

int query_db_status()
{
        mixed *ret;
               
#ifdef STATIC_LINK
        ret = DATABASE_D->db_fetch_row("SHOW DATABASES");
        if (db_handle && arrayp(ret) && sizeof(ret) > 0)
                return 1;
#endif
        return 0;
}

#ifdef STATIC_LINK
protected void connect_to_database()
#else
protected int connect_to_database()
#endif
{
        mixed n;

        n = db_connect(DB_HOST, DATABASE, DB_USER);

        if (intp(n) && (n > 0))  // ���ӳɹ�
#ifdef STATIC_LINK
        {
                db_handle = n;
                chat("�Ѿ���MySQL���ݿ⽨�����ӣ����Ӻ��ǣ�" + n);
                return;
        }
#else
                return n;
#endif

        else
        {
                log_error("db_connect", n);
#ifdef STATIC_LINK
                // call_out("connect_to_database", 30);
                return;
#endif
                return 0;
        }
}

protected void close_database(int db)
{
        mixed ret;

        db_handle = 0;

        if (! intp(db) || (db < 1))
                return 0;

        ret = db_close(db);

        if (intp(ret) && (ret == 1))
                return;

        else
                log_error("db_close", ret);
}

protected void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "���ݿ�");
#ifdef STATIC_LINK
        connect_to_database();
        set_heart_beat(15);
#endif
        init_target();
        set("crc_status", 1);
}
 
private void heart_beat()
{
#ifdef STATIC_LINK
        if (! query_db_status())
                connect_to_database();               
#endif
}
       
protected int valid_caller()
{
#ifdef DEBUG
        return 1;
#else
        if (! previous_object() ||
           (previous_object() != find_object(SIMUL_EFUN_OB)))
                return 0;

        else
                return 1;
#endif
}

// �������Ӽ�¼��ֻ���޸��Ѿ��еļ�¼������ֶεĺ���ֵ
int db_remove_player(string id) 
{
        int db;
        string sql;
        mixed ret;

        if (! stringp(id) || id == "")
                return 0;
                
#ifdef STATIC_LINK
        if (! db_handle)
        {
                chat("���ݿ�ʧȥ���ӡ�");
                return 0;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = "delete from users where id='" + id + "'";
        chat("ִ��ɾ����䣡" + sql);
        ret = db_exec(db, sql);
        if (! intp(ret))
        {
                log_error("db_delete.db_exec", ret + "\n" + sql);
                return 0;
        }
        if (ret < 1) return 0;
#ifndef STATIC_LINK
        close_database(db);
#endif
        return ret;
}

// �������Ӽ�¼��ֻ���޸��Ѿ��еļ�¼������ֶεĺ���ֵ
int db_set_player(string id, string prop, mixed value)
{
        int db;
        string sql;
        mixed ret;

        if (! stringp(id)  || id  == "" ||
            ! stringp(prop) || prop == "")
                return 0;
                
        if (member_array(prop, cols) == -1) 
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
        {
                chat("���ݿ�ʧȥ���ӡ�");
                return 0;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        if (prop == "login_dbase" && (value == 0 || 
            ! stringp(value) || sizeof(value) < 2 )) 
                return 0;
                
        // ���ڲ�ͬ���͵�����Ӧ���в�ͬ�������ֶΣ������ͣ�MAPP������
        if (intp(value))
                sql = "update users set " + prop + "=" + value + " where id = '" + id + "'";
        else if (mapp(value) || arrayp(value))
                sql = "update users set " + prop + "=" + DB_STR(save_variable(value)) + " where id = '" + id + "'";
        else if (stringp(value))
                sql = "update users set " + prop + "=" + DB_STR(value) + " where id = '" + id + "'";
        else
        {
                chat("���ݿ⺯��db_set�Ĳ���value���Ͳ���ʶ��");
                return 0;
        }
        ret = db_exec(db, sql);
        if (! intp(ret))
        {
                log_error("db_set.db_exec", ret + "\n" + sql);
                return 0;
        }
        if (ret < 1) return 0;
#ifndef STATIC_LINK
        close_database(db);
#endif
        return ret;
}

mixed db_query_player(string id, string prop)
{
        int db;
        string sql,*res;
        mixed ret;

        if (! stringp(id)  || id  == "" ||
            ! stringp(prop) || prop == "")
                return 0;
                        
        if (member_array(prop, cols) == -1 && 
            prop != "count(*)") 
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
        {
                chat("���ݿ�ʧȥ���ӡ�");
                return 0;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif
        sql = "select " + prop + " from users where id='" + id + "'";
        ret = db_exec(db, sql);

        if (! intp(ret))
        {
                log_error("db_query.db_exec", ret);
                return 0;
        }
        if (ret < 1) return 0;
        res = db_fetch(db, 1);
#ifndef STATIC_LINK
        close_database(db);
#endif
        chat("��ѯ" + id + "��" + prop + "�����ֶ�ֵ�����أ�" + save_variable(res[0]));
        return res[0];
}

int db_new_player(object ob, object user)
{
        int db,n;
        string sql;
        mixed ret;
        mapping my, myob;

        if (! objectp(ob) || ! objectp(user))
                return 0;
                        
        myob = ob->query_entire_dbase();
        my = user->query_entire_dbase();

        if (! stringp(my["id"]) || (my["id"] == "") || 
            ! stringp(my["name"]) || (my["name"] == ""))
        {
                chat("�洢�ֶ�ID��NAMEΪ�գ��ܾ��洢��");
                return -1;
        }

#ifdef STATIC_LINK
        if (! db_handle)
        {
                chat("���ݿ�ʧȥ���ӡ�");
                return -1;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database())) 
                return -1;
#endif

        // ���ж����ݿ����Ƿ��Ѿ��и����¼
        // fee_time�����������޸ģ��ʲ��洢��
        sql = "insert into users set id = '" + my["id"] + "',";
        sql += "name = " + DB_STR(my["name"]) + ", surname = " + 
               DB_STR(myob["surname"]) + ", purename = " + 
               DB_STR(myob["purename"]) + ", password = " + 
               DB_STR(myob["password"]) + ", ad_password = " + 
               DB_STR(myob["ad_password"]);
        sql += ", birthday = now(), online = 1, on_time = 0, fee_time = " + REG_BONUS;
        sql += ", login_dbase = " + DB_STR(save_variable(myob));
        sql += ", f_dbase = " + DB_STR(save_variable(my));
        
        chat("�������ݿⴴ���ʺţ�\n");
        ret = db_exec(db, sql);

        if(!intp(ret))
        {
                chat("���ݿ�洢ʧ��!!!");
                log_error(sprintf("db_new_player(%s).db_exec", my["id"]), ret);
                return -1;
        }

        n = db_affected(db);
#ifndef STATIC_LINK
        close_database(db);
#endif
        return n;
}

int db_restore_all(object user)
{
        int db, n;
        string sql, *res;
        mixed ret;
        mapping my;
        object myob;
        
        myob = user->query_temp("link_ob");
        my = user->query_entire_dbase();

        if (! mapp(my) || ! stringp(my["id"]) || (my["id"] == "") || 
            ! stringp(my["name"]) || (my["name"] == ""))
        {
                chat("�洢�ֶ�ID��NAMEΪ�գ��ܾ��洢��");
                return -1;
        }

#ifdef STATIC_LINK
        if (! db_handle)
        {
                chat("���ݿ�ʧȥ���ӡ�");
                return -1;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database())) 
                return -1;
#endif

        sql = "select login_dbase, f_autoload, f_dbase, f_damage, f_condition," +
              "f_attack, f_skill, f_alias, f_user, char_idname from users where id = '" + my["id"] + "'";
        
        ret = db_exec(db, sql);

        if (! intp(ret))
        {
                chat("���ݿ�洢ʧ��!!!");
                log_error(sprintf("db_restore_all(%s).db_exec",my["id"]),ret);
                return -1;
        }
        if (ret < 1) return 0;
        res = db_fetch(db, 1);
        if(sizeof(res) < 1) 
                n = 0;
        else
        {
                string login_dbase, char_idname, f_autoload, f_dbase, f_damage; 
                string f_condition, f_attack, f_skill, f_alias, f_user;
                
                n = 0;
                login_dbase = res[n];
                f_autoload = res[n + 1];
                f_dbase = res[n + 2];
                f_damage = res[n + 3];
                f_condition = res[n + 4];
                f_attack = res[n + 5];
                f_skill = res[n + 6];
                f_alias = res[n + 7];
                f_user = res[n + 8];
                char_idname = res[n + 9];                
                user->set_dbase(restore_variable(f_dbase));
                user->set_autoload_info(restore_variable(f_autoload));
                user->set_CONDITION(restore_variable(f_condition));
                user->set_ALIAS(restore_variable(f_alias));
                user->set_ATTACK(restore_variable(f_attack));
                user->set_ghost(restore_variable(f_damage));
                user->set_SKILL(restore_variable(f_skill));
                user->set_USER(restore_variable(f_user));
                user->set_IDNAME(restore_variable(char_idname));               
                if (objectp(myob)) myob->set_dbase(restore_variable(login_dbase));
                n = 1;
        }
        
#ifndef STATIC_LINK
        close_database(db);
#endif
        return n;
}

int db_save_all(object user)
{
        int db, n;
        string sql;
        mixed ret;
        mapping my, myob;
        object link_ob = user->query_temp("link_ob");
        
        if (objectp(link_ob)) 
                myob = link_ob->query_entire_dbase();
                
        my = user->query_entire_dbase();

        if (! stringp(my["id"]) || (my["id"] == "") ||
            ! stringp(my["name"]) || (my["name"] == ""))
        {
                chat("�洢�ֶ�ID��NAMEΪ�գ��ܾ��洢��");
                return -1;
        }

#ifdef STATIC_LINK
        if (! db_handle)
        {
                chat("���ݿ�ʧȥ���ӡ�");
                return -1;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database())) 
                return -1;
#endif

        // ���ж����ݿ����Ƿ��Ѿ��и����¼
        // fee_time�����������޸ģ��ʲ��洢��
        sql = "update users set ";
        sql += "name = " + DB_STR(my["name"]);
        
        if (objectp(link_ob) && mapp(myob))
        {
                if (sizeof(myob["password"]))
                        sql += ", password=" + DB_STR(myob["password"]);
                if (sizeof(myob["ad_password"]))
                        sql += ", ad_password = " + DB_STR(myob["ad_password"]);
                sql += ", login_dbase = " + DB_STR(save_variable(myob));
        }
        if (my["on_time"] > 0) // ��Ϊ�Ѿ�Ų�Ƶ�on_time�Ʒ���
                sql += ", online = 1, on_time = " + my["on_time"] + ", save_time = now()";
        else
        {
                sql += ", online = 1, on_time = " + my["mud_age"] + ", save_time = now()";
                // my["on_time"] = my["mud_age"]; ��ΪҪ���¼���sec_id���������ﲻ��������
        }
        sql += ", char_idname = " + DB_STR(save_variable(user->query_IDNAME()));       
        sql += ", f_autoload = " + DB_STR(save_variable(user->query_autoload_info()));
        sql += ", f_dbase = " + DB_STR(save_variable(my));
        sql += ", f_damage = " + DB_STR(save_variable(user->is_ghost()));
        sql += ", f_condition = " + DB_STR(save_variable(user->query_CONDITION()));
        sql += ", f_attack = " + DB_STR(save_variable(user->query_ATTACK()));
        sql += ", f_skill = " + DB_STR(save_variable(user->query_SKILL()));
        sql += ", f_alias = " + DB_STR(save_variable(user->query_all_alias()));
        sql += ", f_user = " + DB_STR(save_variable(user->query_USER()));
        sql += " where id = '" + my["id"] + "'";
        ret = db_exec(db, sql);
        if (! intp(ret))
        {
                chat("���ݿ�洢ʧ��!!!" + sql);
                log_error(sprintf("db_save_all(%s).db_exec", my["id"]), ret);
                return -1;
        }

        n = db_affected(db);
#ifndef STATIC_LINK
        close_database(db);
#endif
        return n;
}

string *do_sql(string sql)
{
        int db;
        string *res;
        mixed ret;

#ifdef STATIC_LINK
        if (! db_handle)
        {
                chat("���ݿ�ʧȥ���ӡ�");
                return 0;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif
        
        ret = db_exec(db,sql);

        if (! intp(ret))
        {
                log_error("do_sql.db_exec", ret);
                return 0;
        }
        if (ret == 0) return 0;         
        //ֻ��������
        res = db_fetch(db, 1);
        
#ifndef STATIC_LINK
        close_database(db);
#endif
        return res;
}

int do_sqlexec(string sql)
{
        int db;
        int ret;

#ifdef STATIC_LINK
        if (! db_handle)
        {
                chat("���ݿ�ʧȥ���ӡ�");
                return -2;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return -2;
#endif
        
        if(!intp(db_exec(db,sql)))
                ret = -1;
        else
                ret = db_affected(db);
        
#ifndef STATIC_LINK
        close_database(db);
#endif
        return ret;
}

mixed *do_sqls(string sql)
{
        int db;
        mixed *res = ({}), tmp;
        mixed ret;

#ifdef STATIC_LINK
        if (! db_handle)
        {
                chat("���ݿ�ʧȥ���ӡ�");
                return 0;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif
        
        ret = db_exec(db, sql);

        if (! intp(ret))
        {
                log_error("do_sql.db_exec", ret);
                return 0;
        }
        if (ret == 0) return 0;
        //Ҫ����������
        //res = allocate(ret);
        for (int i = 0; i < ret; i++)
        {
                tmp = db_fetch(db, i + 1);
                res += ({ tmp });
        }
        
#ifndef STATIC_LINK
        close_database(db);
#endif
        return res;
}

// ��ѯ ID �Ƿ����
int db_find_user(string key, mixed data)
{
        int db;
        mixed ret;
        string sql;

        if (! stringp(key) || key == "" || ! data)
                return 0;
                
#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        if (intp(data))
                sql = sprintf("SELECT id FROM %s WHERE %s = %s", 
                              USER_TABLE, key, data);
        else if (stringp(data))
                sql = sprintf("SELECT id FROM %s WHERE %s = \"%s\"", 
                              USER_TABLE, key, data);
        else sql = sprintf("SELECT id FROM %s WHERE %s = %O", 
                           USER_TABLE, key, data);
        ret = db_exec(db, sql);

#ifndef STATIC_LINK
                close_database(db);
#endif
        if (! intp(ret))
        {
                log_error("db_find_user.db_exec", ret);
                return 0;
        }

        return ret;
}

// �����µ��û�
int db_create_user(string id)
{
        int db;
        mixed ret;
        string sql;
 
        if (! stringp(id) || id == "")
                return 0;
                
#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("INSERT INTO %s SET id = \"%s\"", 
                      USER_TABLE, id);
        ret = db_exec(db, sql);

#ifndef STATIC_LINK
                close_database(db);
#endif
        if (! intp(ret))
        {
                log_error("db_create_user.db_exec", ret);
                return 0;
        }

        return ret;
}

// ɾ���û�
int db_remove_user(string id)
{
        int db, n;
        mixed ret;
        string sql;

        if (! stringp(id) || id == "")
                return 0;
                
#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("DELETE FROM %s WHERE id = \"%s\"", 
                      USER_TABLE, id);
        ret = db_exec(db, sql);
        
        if (! intp(ret))
        {
                log_error(sprintf("db_romove_user(%s).db_exec", id), ret);
                return 0;
        }
        n = db_affected(db);
        if (n < 1)
                log_error(sprintf("db_romove_user(%s).db_exec", id), "Fail to del.\n");

#ifndef STATIC_LINK
                close_database(db);
#endif
        return n;
}

// �趨�û�����
int db_set_user(string id, string key, mixed data)
{
        int db, n;
        mixed ret;
        string sql;
 
        if (! stringp(id)  || id  == "" ||
            ! stringp(key) || key == "")
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        if (intp(data))
                sql = sprintf("UPDATE %s SET %s = %d WHERE id = \"%s\"", 
                              USER_TABLE, key, data, id);
        else if (stringp(data))
                sql = sprintf("UPDATE %s SET %s = \"%s\" WHERE id = \"%s\"", 
                              USER_TABLE, key, data, id);
        else sql = sprintf("UPDATE %s SET %s = %O WHERE id = \"%s\"", 
                           USER_TABLE, key, data, id);
        ret = db_exec(db, sql);
        if (! intp(ret))
        {
                log_error(sprintf("db_set_user(%s).db_exec", id), ret);
                return 0;
        }
                        
        n = db_affected(db);
#ifndef STATIC_LINK
                close_database(db);
#endif            
        return n;
}

// �����û����Ե�
int db_add_user(string id, string key, int num)
{
        int db, n;
        mixed ret;
        string sql;

        if (! stringp(id)  || id  == "" ||
            ! stringp(key) || key == "" ||
            ! intp(num)    || ! num)
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("UPDATE %s SET %s = %s + %d WHERE id = \"%s\"", 
                      USER_TABLE, key, key, num, id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("db_add_user.db_exec", ret);
                
        n = db_affected(db);
        if (n < 1)
        {
                log_error(sprintf("db_set_user(%s).db_exec", id), "Fail to del.\n"); 
                return 0;
        }       
#ifndef STATIC_LINK
                close_database(db);
#endif        
        return n;
}

// ��ѯ�û�����
mixed db_query_user(string id, string key)
{
        int db;
        mixed ret, *res;
        string sql;

        if (! stringp(id)  || id  == "" ||
            ! stringp(key) || key == "")
                return 0;
                
#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT %s FROM %s WHERE id = \"%s\"", 
                      key, USER_TABLE, id);
        ret = db_exec(db, sql);

#ifndef STATIC_LINK
                close_database(db);
#endif
        if (! intp(ret))
        {
                log_error("db_query_user.db_exec", ret);
                return 0;
        }
                
        if (ret > 0)
        {
                res = db_fetch(db, 1);
                return res[0];
        }
        
        else
                return 0;
}

// ���ܺ���
mixed db_crypt(string passwd)
{
        int db;
        mixed *res, ret;
        string sql;

        if (! stringp(passwd) || passwd == "")
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT %s(\"%s\")", 
                      DB_CRYPT, passwd);

        ret = db_exec(db, sql);

        if (ret)
        {
                if (sizeof(res = db_fetch(db, 1)) && stringp(res[0]))
                        ret = res[0];
                else
                        return 0;
        }
#ifndef STATIC_LINK
                close_database(db);
#endif                
        return ret;
}

// ����һ��
varargs mixed *db_fetch_row(string sql, int row)
{
        int db;
        mixed *ret;

        if (! stringp(sql) || sql == "")
                return 0;
                
#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif
        if (stringp(sql) && sql != "")
        {
                db_exec(db, sql);
        }

        if (! row) row = 1;
        ret = db_fetch(db, row);

#ifndef STATIC_LINK
                close_database(db);
#endif
        return ret;
}

// ִ�����
mixed db_query(string sql)
{
        int db;
        mixed *ret;

        if (! stringp(sql) || sql == "")
                return 0;
                
#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        ret = db_exec(db, sql);
        
#ifndef STATIC_LINK
                close_database(db);
#endif
        return ret;
}

// ����������
mixed *db_all_query(string sql)
{
        int db, i;
        mixed max, *ret;

        if (! stringp(sql) || sql == "")
                return 0;
                
#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif
        max = db_exec(db, sql);
        if (intp(max) && max != 0)
        {
                ret = ({ });
                for (i = 1; i <= max; i++)
                        ret += ({ db_fetch(db, i) });
        }
#ifndef STATIC_LINK
                close_database(db);
#endif
        return ret;
}

// �����������
int db_count_user()
{
        int db;
        mixed ret, *res;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        ret = db_exec(db, sprintf("SELECT COUNT(*) FROM %s", USER_TABLE));
        if (! intp(ret) || (ret < 1))
        {
                log_error("count_reg_user", ret);
                return 0;
        }

        res = db_fetch(db, 1);
        
#ifndef STATIC_LINK
        close_database(db);
#endif        
        return res[0];
}

#ifdef STATIC_LINK
void remove(string id)
{
        close_database(db_handle);
}
#endif

// by Lonely
int db_remove_item(string id) 
{
        int db;
        string sql;
        mixed ret;

        if (! stringp(id) || id == "")
                return 0;
                
#ifdef STATIC_LINK
        if (! db_handle)
        {
                chat("���ݿ�ʧȥ���ӡ�");
                return 0;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = "delete from items where id='" + id + "'";
        chat("ִ��ɾ����䣡" + sql);
        ret = db_exec(db, sql);
        if (! intp(ret))
        {
                log_error("db_remove_item.db_exec", ret + "\n" + sql);
                return 0;
        }
        if (ret < 1) return 0;
#ifndef STATIC_LINK
        close_database(db);
#endif
        return ret;
}

mixed db_restore_item(object item)
{
        int db, n;
        string sql, *res;
        mixed ret;
        mapping data;

#ifdef STATIC_LINK
        if (! db_handle)
        {
                chat("���ݿ�ʧȥ���ӡ�");
                return 0;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database())) 
                return 0;
#endif

        sql = "select dbase from items where id = '" + base_name(item) + "'";
        
        ret = db_exec(db, sql);

        if (! intp(ret))
        {
                chat("���ݿ�洢ʧ��!!!");
                log_error(sprintf("db_restore_item(%s).db_exec", base_name(item)), ret);
                return 0;
        }
        if (ret < 1) return 0;
        res = db_fetch(db, 1);

        data = restore_variable(res[n]);
        
#ifndef STATIC_LINK
        close_database(db);
#endif
        return data;
}

int db_save_item(object item)
{
        int db, n;
        string sql;
        mixed ret;
        mapping data;

#ifdef STATIC_LINK
        if (! db_handle)
        {
                chat("���ݿ�ʧȥ���ӡ�");
                return -1;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database())) 
                return -1;
#endif
        
        data = item->query_entire_dbase();
        
        sql = "insert into items set id = '" + base_name(item) + "', ";
        sql += "dbase = " + DB_STR(save_variable(data));
        ret = db_exec(db, sql);
        if (! intp(ret))
        {
                chat("���ݿ�洢ʧ��!!!" + sql);
                log_error(sprintf("db_save_item(%s).db_exec", base_name(item)), ret);
                return -1;
        }

        n = db_affected(db);
#ifndef STATIC_LINK
        close_database(db);
#endif
        return n;
}

#endif
