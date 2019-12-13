// Room: /city/cangku.c
inherit ROOM;
void init();
void create()
{
    set("short", "�ֿ�");
    set("long", @LONG
������һ�������Ĳֿ⣬�����˸��������������һ�ֿ⡣����
���Ǳ��˹������������ġ�
LONG
    );
    set("valid_startroom", 1);
    set("no_fight", 1);
    set("objects", ([
        "clone/food/jitui" : 3,
        "clone/food/jiudai" : 1,
    ]));
    setup();
}
void init()
{
    object ob;
    ob = this_player();
    ob->set("startroom","/d/city/cangku");
}
object do_check(string arg)
{
    object *obj;
    int i;
    if (!arg)   return 0;
    obj=deep_inventory(this_object());
    if (!sizeof(obj))   return 0;
    for (i=0;i<sizeof(obj);i++)
        if (obj[i]->id(arg) && obj[i]->is_character() && !obj[i]->is_corpse())    return obj[i];
    return 0;
}
