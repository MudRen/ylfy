// Room: /d/shaolin/zhulin3.c
// Date: YZC 96/01/19
//Update by Arnzh /97/1/21
inherit ROOM;
int do_snap(string arg);
void create()
{
    set("short", "����С��");
    set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ������������
�ܵ�����(bamboo)�������˼�������Ω�����ߵ��·�棬��ɮ��ľ������
΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ���
���������ڡ�
LONG
    );
    set("exits", ([
        "west" : __DIR__"hsyuan3",
        "south" : __DIR__"zhulin2",
    ]));
        set ("item_desc", ([
        "bamboo" : 
"����һ����ɫ�����ӣ�˵����������(snap)�����������á�\n"
    ])  ) ;
    set("outdoors", "shaolin");
    setup();
//  replace_program(ROOM);
}
void init()
{
    add_action("do_snap","snap");
}
int do_snap(string arg)
{   object zhuzhi;
     if( !arg || arg=="" ) {
message_vision("������ʲô��\n", this_player());         
return 1;
}
        if( arg=="bamboo"||arg=="zhuzhi" ) {
        message_vision(
"$N�����������һ����֦��\n"
                , this_player());
        zhuzhi = new(__DIR__"obj/zhuzhi");         
            zhuzhi->move(this_player());
 
        return 1;
        }
    return 0;
}
