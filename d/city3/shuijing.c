
inherit ROOM;

void create()
{
        set("short", "ˮ��");
	set("long", @LONG
��һ���峺���׵�ˮ�������Դ���С�������м�����������
���ϴ�£�һ��˵˵ЦЦ�����и����ˣ�������������Ͱ��ˮ��
�������Ƶس�����ȥ�����������ȿ�ˮ��
LONG
	);
	set("resource/water", 1);

	set("exits", ([
                "south" : __DIR__"dongjie3",
	]));

	setup();
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = me->max_water_capacity();
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"ſ��Ϫ�ߣ�����һ�ھ�ˮ���£�ֻ��һ��������ֱ͸�ķΡ�\n"
            , environment(me), ({me}) );
            write("������һ�ھ�ˮ���£�ֻ��һ��������ֱ͸�ķΡ�\n");
        }
        else write("�������ƶ��Ӱ�������\n");
        return 1;
}

