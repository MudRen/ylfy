#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_swim(string arg);

void create()
{
        set("short", "����");
        set("long", @LONG
ˮ��������ȫ��ˮ�������ϴ�Ҿ��ȵĿ����㡭
LONG
        );
        set("objects", ([
                  ]));

        setup();
}
void init()
{   
        add_action("do_swim", "swim");
}

void check_trigger()
{
        object me;
        me = this_player();
        if ((int)query("trigger") == 5) {
                message_vision("$N���������˰�, �����ϰ�һ��, ����·��Ѿ������������...\n", me);
                me->move(__DIR__"shandao3");
                delete("trigger");
                return;
        }
      }
int do_swim(string arg)
{
        int i;
        if (!arg || arg == "") {
                write("�������λ��������Σ�\n");
                return 1;
        }
        if (arg == "north" || arg == "n") {
                add("trigger", 1);
                write("������򱱰���ȥ����\n");
                check_trigger();
                return 1;
        }
        if (arg == "south" || arg == "s") {
                i = (int)query("trigger")-1;
                delete("trigger");
                add("trigger", i);
                write("��������ϰ���ȥ����\n");
                check_trigger();
                return 1;
        }
}
void reset()
{
        ::reset();
        delete("trigger");
}
