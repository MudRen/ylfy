// Room: hantan.c

inherit ROOM;

void create()
{
        set("short", "��ˮ��̶");
        set("long", @LONG
̶ˮ����̹ǣ���������򺮲������ݡ��ĵġ���ֱ�졣���ε����ߣ�����
����������ݵ���������ϸϸ������
    Ⱥɽ����֮����һ̶�̲����峺���ף�һββ��֪����С�����������
����ȥ���ò��������ڡ��紵̶�棬������ˮ�������������ҫ�£�����
���Բ��⡣��...����һ�������ķ羰����...����������
    �Ȼ�����Ȼ�����鶯�����泩��������������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hantan-hole1",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
}
void init()
{
          add_action("do_jumpup", "jumpup");
}

int do_jumpup(string arg)
{
        object me;
        me = this_player();
if (me->is_busy())
return notify_fail("����һ��������û����ɣ�\n");
        message_vision("$N��ϥ������˫��һ��أ����������εض���\n", me);
                message_vision("���б任���Σ�һ���շ�����ƮƮ�����ڵ��ϣ�\n", me);
me->move("/d/mingjiao/banshanyao");	

        return 1;
}



