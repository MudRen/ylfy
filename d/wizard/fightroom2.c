// Room: /city/dangpu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
        set("short", "���ִ��㳡");
    set("long", @LONG
����һ����Բ��ʮ�ɵĴ�㳡��һ���ð���ʯ�������ɸߵ���̨�����ڹ�
�����룬�����治ʱ����ߺ�����Ͳҽ�������̨���ĸ��߽������ĸ�ʮ���ɸߵ�
��ˣ��ֱ��ý������ŷ��������ĸ����֣��㳡����������ͬ����ʯ������һ	
��С̨��̨������һ������ˣ�һ�Ŵ���(flag)ӭ����չ��
LONG
    );
    set("no_new_clean_up", 0);
        set("no_fight",1);
        set("no_magic",1);
		set("no_fly", 1);
    set("item_desc", ([
                "flag": @TEXT
              ������ѣ�
TEXT
    ]) );
    set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"fightroom1",
                "up" : __DIR__"fightroom3",
        ]));
    setup();
}
void init()
{
       object me=this_player();
    add_action("discmds",({"respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
       if (userp(me) && me->query("no_get") )
           call_out("do_recover",15,me);
}
void do_recover(object me)
{
    if( !me || environment(me) != this_object() ) return;
       me->delete("no_get");
       if (!living(me)) me->revive();
    me->set("eff_jing",me->query("max_jing"));
    me->set("jing",me->query("max_jing"));
    me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("max_qi"));
    if (me->query("neili")<me->query("max_neili"))
        me->set("neili",me->query("max_neili"));
    if (me->query("jingli")<me->query("max_jingli"))
        me->set("jingli",me->query("max_jingli"));
        me->start_busy(0);
    tell_object(me,HIW "�㳡�ƺ���һ�����ص�����������һ�¾��ǣ����ֲ�û�����ˣ�\n"NOR);
}
int discmds()
{
        tell_object(this_player(),"�����㻹��ר�Ŀ�����ɣ�\n");

     return 1;
}
