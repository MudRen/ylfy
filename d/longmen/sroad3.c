
inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
���������ѵ�С·�ϣ�������ϡ������ֺ���Ƭ����Ұ��һ�����峺
��СϪ��·ƽ�У�Ϫ���峺���ף�ˮ��������������ԵĿ�������ˮ����
������������һ��һ�����Ұɢ�������˵��������㡣
LONG );
        set("valid_startroom",1);
        set("outdoors","����");
        set("class","Ѫ����");
        set("exits", ([
                "northwest"  : __DIR__"sroad2",
                "northeast"  : __DIR__"sroad4",
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
