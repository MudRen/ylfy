inherit ROOM;

void create()
{
        set("short", "�Ÿ�����");
        set("long", @LONG
������������ĶŸ������ˡ������ڣ�С�ţ���ˮ��÷
԰����ͥ�У����д�֮÷����֮�ɣ���֮�գ���֮�����ͣ���
�����У������з���֮��˼���������Ȼ֮������
LONG
        );
        set("exits", ([ 
            "southwest" : __DIR__"xiaoxiang1",
            "east" : __DIR__"cdta",
            "north" : __DIR__"dufu_sleep",
            ]));

        set("no_clean_up", 0);
        set("objects",([
            __DIR__"npc/dufu" : 1,
            __DIR__"npc/xuetong" : 2,
        ]));

        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && (userp(me) && !wizardp(me)))
                return notify_fail("���ǶŸ���˽�����ң���\n");
        return 1;
}

