
inherit ROOM;
void create()
{
       set("short", "��ɼ����");  
        set("long", @LONG
��ô�ɼ���治��Ϊǧ����ľ����Ҷ��ï,�ϵ�����������Ұ��������˵��
���ʱ���Ƕ���ģ���˱��Ϊ��������ǲ����ĵط���������ż�����ɼ��
���������ӣ��м��ü���ɼ��֦����һ������һ���輸�ˣ��輸�ϰڷ���һ��
������������й������̣�ccb)��
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
        "down": __DIR__"chatroom1",
        ]));
        set("no_fight",1);
        set("no_magic",1);
        set("freeze",1);
        set("objects", ([
                "/d/city3/obj/cch" : 1,
        ]));
        setup();
}
void init()
{
    if (wizardp(this_player())) return;
    add_action("do_swing","swing");
    add_action("discmds",({"respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
}
int discmds()
{
        tell_object(this_player(),"�����㻹��ר������ɣ�\n");
        return 1;
}
int do_swing(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("��Ҫ���ĵ���\n");
      if (me->is_fighting() || me->is_busy() )  return notify_fail("����æ���أ�\n");
        message("vision",
                me->name() + "����������ץ��ɼ��֦������ȥ��\n���ꡱ��һ�����ƺ�����"+me->name()+"�ŵص�����!\n",
                environment(me), ({me}) );
                me->move(__DIR__"chatroom1");
        message("vision",
                me->name() + "ץ��ɼ��֦���������ŵش������ϵ���������\n",
                environment(me), ({me}) );
        return 1;
}
int valid_leave(object me, string dir)
{
        if ( dir=="down" && !wizardp(me))
        return notify_fail("���ɲ�֪�����ĸ����һ￳�ÿ�Ҫ���ˣ�����ֻ�ܵ�(swing)��ȥ�ˣ�\n");
        else return 1;
}
