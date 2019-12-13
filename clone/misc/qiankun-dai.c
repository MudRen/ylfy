// /clone/misc/qiankun-dai.c Ǭ����

inherit ITEM;
inherit F_SAVE;

#ifndef X_StoreD
#define X_StoreD    "/adm/daemons/x_stored"
#endif

void add_cmds();
int set_owner(string id);
int is_chuwu_obj() { return 1; }

void create()
{
    set_name("Ǭ����", ({ "qiankun dai"/*, "chuwu", "dai",*/ }));
    set("long", "һֻ�����˿��ϲ���˿��֯���ɵĴ��ӣ�ԼĪ���ƴ�С��\n");
    set("unit", "ֻ");
    set("no_put", 1);
    set("no_drop", 1);
    set("no_get", 1);
    set("no_steal", 1);
	set("no_jie", 1);
    set("no_sell", 1);
	set("xyzx_sys/bind_type", 2);
	set("xyzx_save_item", 1);
    set("def_name", name(1));
    set("def_long", query("long"));	
    seteuid(getuid());
}

void init()
{
    object me;
    string id, str;

    if((me = this_player()) && environment() == me)
    {
        id = me->query("id");
        set_owner(id);		
        if(!mapp(query("item_list")))
            set("item_list", ([]));
        if(!query("item_max") || query("item_max") <= 0)
            set("item_max", X_StoreD->query_min());
        set("name", sprintf("%s��%s", me->name(1), query("def_name")));			
        str = "\n" + query("def_long");
        str += sprintf("����������˿֯��һ��С�֣�%s(%s)ר����\n",
                        me->name(1), me->query("id"));
        str += X_StoreD->cmds_help();
        set("long", str);
        //if(!query_temp("add_cmds"))
            add_cmds();
        return;
    }
}

void add_cmds()
{
    int i;
    string *key = X_StoreD->able_cmds();

    //if(query_temp("add_cmds"))
    //    return;

    for(i = 0; i < sizeof(key); i++)
        add_action("do_" + key[i], key[i]);
        //set_temp("add_cmds", 1);
}

int query_autoload()
{
    return query("id");
}

string query_save_file()
{
    string id;

    if(!stringp(id = query("owner_id")))
        return 0;

    return DATA_DIR + "chuwu/" + id[0..0] + "/" + id;
}

int set_owner(string id)
{
    set("owner_id", id);
    return restore();
}

int do_chawu()
{
    object me = this_player();
    X_StoreD->do_chawu(me, this_object());
    return 1;
}

int do_chuwu(string arg)
{
    object me = this_player();
    X_StoreD->do_chuwu(me, this_object(), arg);
    return 1;
}

int do_quwu(string arg)
{
    object me = this_player();
    X_StoreD->do_quwu(me, this_object(), arg);
    return 1;
}

/*int do_augment()
{
    object me = this_player();
    X_StoreD->do_augment(me, this_object());
    return 1;
}*/

