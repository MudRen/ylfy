inherit ITEM;
inherit F_SAVE;

void create()
{
    if(! restore()) {
        set_name("��Ʊ",({"cai piao"}));
		set("long","����һ����̶��Ʊ\n");
        }
    set("unit","��");
    seteuid(getuid());
}

string query_save_file() { return  "/clone/caipiao/"+ query("z_num"); } 
