// Room: shanya.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�Ժ�ˮ�����ߣ�����һ�����͵�ɽ�¡����������ƣ�����ף�ɽ
�����������ڣ��������ƣ������쳣������ɽ��������һ��ʯͷ���ò���
�������ɼ��������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hongshuiqi",
]));
        set("no_clean_up", 0);

        setup();
}
void init()
{
          add_action("do_jumpdown", "jumpdown");
}

int do_jumpdown(string arg)
{
        object me;
        me = this_player();
if (me->is_busy())
return notify_fail("����һ��������û����ɣ�\n");

        message_vision("$N�������ǣ�һ������������ȥ��\n", me);
                environment(me), ({me});
me->move("/d/mingjiao/banshanyao.c"); 	
message_vision("$N���б任���Σ�һ���շ�����ƮƮ�����ڵ��ϣ�\n", me);
                environment(me), me;
                return 1;
}



