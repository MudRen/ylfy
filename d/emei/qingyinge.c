// Room: /d/emei/qingyinge.c ������ ��������С��


inherit ROOM;


void create()
{
        set("short", "��������");
	set("long", @LONG
������һ����ɽС·��·����һʯ��(shibei)����������һ���ڴ�ɽ����
�е�С��¥���˸�λ��ţ�����¡����ﻷ�����ģ������۾���ż��Ҳ�м�����
�У���ʱ��ɽ���лص����ڸ�����ֲ�����Ķž黨��ʮ�ֵ���������������
һ��Сľ��(men)��ȴ�����Ĺر��š��ɴ�������һ������ͤ����·������
����
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "northdown": __DIR__"shenshuige",
                "southwest":__DIR__"bailongdong",
                "eastup":__DIR__"niuxinting",
	]));
       set("item_desc", ([
                "shibei" : @SHIBEI
ʯ������һʫԻ��

���������������� Ȼ �� �� �� �� ����

              �� �� �� �� �� �� �١�

���������������� �� ˫ Ϫ һ �� ����

              �� �� �� ˮ �� ţ �ġ�

����ǡ�����ʮ��ʫ����רӽ�⡰˫����������ʫ��
SHIBEI
        ]));
	setup();
}
void init()
{
    add_action("do_knock", "knock");
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"qingyinge1")) )
        room = load_object(__DIR__"qingyinge1");

    if(objectp(room))
    {
        delete("exits/south");
        message("vision", "�����������ĵİ�ľ�Ź����ˡ�\n",
            this_object());
        room->delete("exits/north");
        if (objectp(room))
           message("vision", "�������ĵĺ�����ľ�š�\n", room);
     }
}
int do_knock(string arg)
{
    object room;

    if (query("exits/south"))
        return notify_fail("�����Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "men" && arg != "south"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!( room = find_object(__DIR__"qingyinge1")) )
        room = load_object(__DIR__"qingyinge1");
    
    if(objectp(room))
    {
        set("exits/south",__DIR__"qingyinge1");
        message_vision("$N������������ţ�ֻ��֨��һ����"
            "һλʦ̫Ӧ���򿪴��ţ�\n",this_player());
        room->set("exits/north", __FILE__);
        message("vision", "���洫��һ��������������Ӧ����ǰ�Ѵ��ſ���\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }

    return 1;
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    if ( dir != "south" )
        return ::valid_leave(me, dir);

    if (!::valid_leave(me, dir))
        return 0;

    if ( (!(myfam = me->query("family")) || myfam["family_name"] != "������") )
          return notify_fail("����˫�ƺ�ʮ˵���������ӷ𣡱��ŵ������ﾲ�ޣ����˲��ô��š�\nʩ����ذɡ�\n");
    else 
          write("����˫�ֺ�ʮ�������ÿ���\n");
          return 1;
 }


