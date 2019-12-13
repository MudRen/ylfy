// Room: banshanyao.c

inherit ROOM;

void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
�������˸���ͬ������Դ�ĵط��������ǰ�ɽ����ֻ��һ����ƴ��
�ط�������ţ���������ֵ��Ǿ������С�Ĳ�����С�ĵط�ȴ��ǿ����
����һ�����������ĸ������������ʯ�У����˲����е���������ǿ����
�У����ϻ������˹�ʵ�����˴������Σ������Ǻ������һƬ����Ȼ����
�����ڣ��������ƣ������쳣����
LONG
        );
set("objects",([__DIR__"npc/obj/mitao" : 1,
                __DIR__"npc/obj/taoshu" : 1,
]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
           add_action("do_jumpdown", "jumpdown");
         add_action("do_jumpup", "jumpup");
}

int do_jumpdown(string arg)
{
        object me;
        me = this_player();
if (me->is_busy())
return notify_fail("����һ��������û����ɣ�\n");

        message_vision("$N�������ǣ�һ������������ȥ��\n", me);
                environment(me), ({me});
me->move("/d/mingjiao/hantan");
message_vision("$N���б任���Σ�һ���շ�����ƮƮ�����ڵ��ϣ�\n", me);
                environment(me), me;
                return 1;
}
int do_jumpup(string arg)
{
        object me;
        me = this_player();
if (me->is_busy())
return notify_fail("����һ��������û����ɣ�\n");
        message_vision("$N��ϥ������˫��һ��أ����������εض���\n", me);
                message_vision("���б任���Σ�һ���շ�����ƮƮ�����ڵ��ϣ�\n", me);
me->move("/d/mingjiao/shanya");

        return 1;
}

