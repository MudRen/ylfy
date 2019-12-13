// magic_seal.c

inherit ITEM;

void create()
{
    set_name("����", ({"magic seal","seal"}) );
    set_weight(5);
    set("long",
        "����һ�Ż��õķ��䣬���Խ�����(attach)��ĳ��(��ĳ��)���ϡ�\n");
    set("unit", "��");
    set("temp_value",10);
}

int unequip()
{
    set("equipped", 0);
    return 1;
}

void init()
{
    if (environment()==this_player())
        add_action("do_attach", "attach");
}

int do_attach(string arg)
{
    string sheet, dest,name;
    object ob,zombie,*inv;
    int i;
    if (query("is_equipped"))
        return notify_fail("���ŷ����Ѿ�û�����ˣ�\n");

    if( !arg || sscanf(arg, "%s to %s", sheet, dest)!=2 )
        return notify_fail("ָ���ʽ��attach <����> to <Ŀ��>\n");
    
    if( !id(sheet) ) return 0;
    ob = present(dest, this_player());
    if( !ob ) ob = present(dest, environment(this_player()));
    if( !ob ) return notify_fail("��Ҫ��ʲ�ᶫ��ʹ�����ŷ��䣿\n");
    if (!ob->is_corpse()) return notify_fail("��ֻ�ܶ�ʬ��ʹ�����ŷ��䣡\n");
    if (!ob->is_character() ) return notify_fail("���ʬ��̫�����ˣ�����ʹ�÷��䡣\n");
    if( (int)this_player()->query("jingli") < 200 ) return notify_fail("��ľ��������ˣ�\n");

    message_vision("$N�ó�һ��" + name() + "��$n��ͷ��һ����\n", this_player(), ob);
    message_vision("\n\n$N�������ϵ�$n�૵����˼������$n�鴤�˼��¾�վ��������\n", this_player(), ob);
    this_player()->add("jingli",-200);
    zombie=new("/clone/npc/zombie");
    name=ob->query("name");
    name=replace_string(name,"��ʬ��","");
    zombie->set("victim_name",name);
    move(zombie);
    set("is_equipped", 1);
    zombie->animate(this_player(), query("temp_value"));
    inv=all_inventory(ob);
    for (i=0;i<sizeof(inv);i++){
       inv[i]->move(zombie);
       inv[i]->wear();
       inv[i]->wield();
    }
    zombie->move(environment(ob));
    destruct(ob);
    return 1;
}
int query_autoload() { return 1; }