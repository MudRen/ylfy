inherit ROOM;

int do_drink();
void create()
{
        set("short", "������");
        set("long", @LONG
��������ʱ������ȥ����ǰ���ص��������ռ���һЩ��Ϻ֮��Ķ���
�������俪��ʯ����̶���ˮ���������������á��������������������
���Ķ����ڹ���
LONG );
        set("resource/water", 1);

	set("valid_startroom",1);
        set("exits", ([
                "east" : __DIR__"mishi",
        ]));

/*
        set("objects", ([
            __DIR__"/obj/xia" : random(3),
            __DIR__"/obj/yu" : random(3),
        ]));
*/
//        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink()
{
        int current_water;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
		me->set("water", current_water+30);
		message("vision", me->name()+"����һ��ˮ��\n"
		, environment(me), ({me}) );
        }
        else write("���Ѿ��ȱ��ˡ�\n");

        return 1;
}

