inherit ROOM;
int do_move(string arg);
void create()
{
        set("short", "ͨ�Է�");
        set("long", @LONG
������ͨ�԰������Са�ķ��� ��һ������ͱ��������
�������׵Ĳ���������ס�ˣ�������м����һ�����ӣ�ǽ��
����һ�Ż������е���������Са���˻������������������
�ǳ��Ե���һ������֮�֡�
LONG
        );
        set("outdoors", "huapu");
        set("exits", ([
                 "south" : __DIR__"tianjin",
                  "west" : __DIR__"sleep_room2",
                  "north" : __DIR__"huayuan",
        ]));
        set("objects", ([
        __DIR__"npc/xiaoxie" : 1,
        __DIR__"npc/xiaoqi" : 1,
        ]));
           set("item_desc", ([
    "��" : "���Ż��ϻ���������Са�����Ż��ƺ������ƶ���\n",
           ]));
        setup();
        set("he",1);
}
void init()
{
        add_action("do_move", "move");
}
int do_move(string arg)
{
  object me,sword,flower;
        me = this_player();
        if( !arg || arg=="" ) return 0;
     if( arg=="��" )
        {
                if ((me->query("family/master_id") !="xiao qi") &&
                        objectp(present("xiao qi", environment(me))))
                {
                        return notify_fail(
"С�ߺȵ�����λ" + RANK_D->query_respect(me) + "������͵������Ҫ�ȹ�����ء�\n");
                        return 1;
                }
                if (!query("had_sword"))
                {
                        message_vision(
"$N�ѻ��Ƶ���һ��,������һ�����С�\n", this_player());
                        flower = new(__DIR__"obj/flower");
               sword=new(__DIR__"obj/he");
            flower->move(sword);
                      sword->move(me);
message("rumor", HIM"��Ӣ�۴��ԡ�"NOR+"��"+HIR"��˵"HIW+this_player()->query("name")+NOR HIB"�õ���˵�е�....."MAG"���ֻ�"HIB"��!\n"NOR, users());
                        set("had_sword", 1);
                        return 1;
}
                message_vision(
"$N�ѻ��Ƶ���һ�ߣ��ŷ�������Ķ����Ѿ�û��...��\n", this_player());
                return 1;
}
        return 0;

}
