// chaoyang.c
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
������ǻ�ɽ�Ķ��塪�����壬춴˸���ƺ����Զ������������
С�·屳��ɽ�ӡ����������ϣ�����һ��������ӡ���ഫΪ��������项
��ɽʱ�����µġ�
LONG
    );
    set("exits", ([ /* sizeof() == 1 */
        "northeast" : __DIR__"zhenyue",
"westdown" : __DIR__"chaopath2",	
    ]));
    set("no_clean_up", 1);
    set("outdoors", "huashan" );
    setup();
    replace_program(ROOM);
}
