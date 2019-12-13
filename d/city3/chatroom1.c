
inherit ROOM;
void create()
{
       set("short", "��ɼ����");
        set("long", @LONG
��˵�������ºó�����û�뵽�����ϸ����졣��ô�ɼ���治��Ϊǧ����ľ��
��������Ҷ��ï����˵�����ʱ���Ƕ���ģ���˱��Ϊ����������ĵط���
������ż�����ɼ�����������ӣ��м��ü���ɼ��֦����һ������һ���輸�ˡ�
����̧ͷ���Ͽ���ʱ���ƺ��и�Ӱ������֮���ƶ�������Ҳ���Ƿ紵������ɵ�
�����
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
        "down": __DIR__"guangchang",
        "up": __DIR__"chessroom",
        ]));
        set("no_fight",1);
        set("no_magic",1);
        set("freeze",1);
      set("valid_startroom","1");
        set("objects", ([
//                "/d/wizard/npc/chaiyao" : 1,
        ]));
        setup();
}
void init()
{
    if (wizardp(this_player())) return;
    add_action("do_jump","tiao");
//    add_action("do_climb", "climb");
    add_action("discmds",({"respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
}
int discmds()
{
        tell_object(this_player(),"�����㻹��ר������ɣ�\n");
        return 1;
}
int do_jump(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("��Ҫ��������\n");
      if (me->is_fighting() || me->is_busy() )  return notify_fail("����æ���أ�\n");
        message("vision",
                me->name() + "��ԥ��һ�£�����������������ȥ��\n���ء���һ���죬�ƺ�����"+me->name()+"�Һ���һ��!\n",
                environment(me), ({me}) );
                me->move(__DIR__"guangchang");
        message("vision",
                me->name() + "�Һ�һ���������ϵ���������\n",
                environment(me), ({me}) );
        return 1;
}
int valid_leave(object me, string dir)
{
        if ( dir=="down" && !wizardp(me))
        return notify_fail("�̸���֪�����ĸ����һ￳���ˣ�����ֻ����(tiao)��ȥ��\n");
        else return 1;
}
int do_climb(string arg)
{
    object me;
    mixed *local;
    local=localtime(time());
    me = this_player();
        if( !arg || arg!="up") return notify_fail("��Ҫ���ĸ���������\n");
    message("vision",
       me->name() + "�������ŵ�ץ�Ŵ�ɼ������֦�����ꡱ��һ����������ȥ��\n",
        environment(me), ({me}) );
        me->move("/d/city3/chessroom.c");
        message("vision",
       me->name() + "ץ�Ŵ�ɼ������֦������������\n",
                environment(me), ({me}) );
    return 1;
}
