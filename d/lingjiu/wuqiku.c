//ROOM: wuqiku.c
inherit ROOM;
void create()
{
        set("short", "ޤ����");
        set("long",@LONG
���ǡ����չ������ӵı����⣬�㻷�����ܣ�����ǽ��Ƕ���˸�ʽ��
������ϸһ����ԭ����ǽ���ھ������������֮�οٳ����ӣ����о�����
���ڡ��㲻�ɰ��ޣ����þ��µ���ͷ����
LONG       );
        set("exits", ([
        "east" : __DIR__"changl5",
        ]));
        set("objects",([
        "/clone/weapon/zhujian" : 4,
        ]));
        setup();
        replace_program(ROOM);
}
