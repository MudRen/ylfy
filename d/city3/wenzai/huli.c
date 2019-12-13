//bye enter
#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_swim(string arg);

void create()
{
        set("short", "����");
        set("long", @LONG
ˮ��������ȫ��ˮ�������ϴ�Ҿ��ȵĿ����㡭
������Լ����˼�ɵ�£�̫���ˡ��㻹�ǿ���(swim)�ɣ�
LONG
        );
        set("objects", ([
               "/d/npc/m_weapon/tan/npc/fish.c" : 2,
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
        if ((int)query("trigger") == 13) {
                message_vision("$N���������˰�, �����ϰ�һ��, ����·��Ѿ������������...\n", me);
                me->move(__DIR__"xiaodao");
                delete("trigger");
                return;
        }
        if ((int)query("trigger") < 0) {
                message_vision("$N���λ�ԭ���İ���,$N���ϰ�һ��, ����·��Ѿ������������...\n",me);
                me->move(__DIR__"zoulang4");
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
